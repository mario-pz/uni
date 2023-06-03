#!/bin/bash

validate_arguments() {
    local script_name=$0
    local arguments_count=$1
    [[ $arguments_count -ne 3 ]] && echo "Usage: $script_name directory1 directory2 directory_for_common_files" && exit 124
}

validate_directory() {
    local path=$1
    [[ ! -d "/$path/" ]] && echo "$path is not a directory" && exit 124
}

compare_directories() {
    local directory1=$1
    local directory2=$2
    diff -s "$directory1" "$directory2"
}

extract_file_paths_from_diff_output_by_pattern() {
    local diff_output=$1
    local regex_pattern=$2
    local file_paths
    file_paths=$(echo "$diff_output" | grep "$regex_pattern")
    echo "$file_paths"
}

extract_paths_of_common_files_from_diff_output() {
    local diff_output=$1
    local paths_of_common_files
    paths_of_common_files=$(extract_file_paths_from_diff_output_by_pattern "$diff_output" "identical" | cut -d " " -f2)
    echo "$paths_of_common_files"
}

print_dir_unique_files() {
    local diff_output=$1
    local directory_selected=$2
    local dir_unique_file_rows 
    dir_unique_file_rows=$(extract_file_paths_from_diff_output_by_pattern "$diff_output" "$directory_selected:")
    local dir_files
    dir_files=$(echo "$dir_unique_file_rows" | cut -d : -f2 | cut -c 2-)
    echo "Files in $directory_selected only"
    echo "$dir_files"

    print_dir_unique_files_total_size "$dir_files" "$directory_selected"
}

print_dir_unique_files_total_size() {
    local dir_files
    readarray -t dir_files < <(echo "$1")
    local directory_selected=$2
    local file_paths=()
    for file in "${dir_files[@]}"; do
        file_paths+=("$directory_selected"/"$file")
    done
    du -bhc "${file_paths[@]}" | tail -1
}

print_common_files() {
    local paths_of_common_files=$1
    local common_files
    common_files=$(echo "$paths_of_common_files" | cut -d ":" -f2 | rev | cut -d "/" -f1 | rev)
    echo "Files in both directories: "
    echo "$common_files"
    print_total_size_of_common_files "$paths_of_common_files"
}

print_total_size_of_common_files() {
    local paths_of_common_files=$1
    local paths_of_common_files_arr
    readarray -t paths_of_common_files_arr < <(echo "$paths_of_common_files")
    du -bhc "${paths_of_common_files_arr[@]}" | tail -1
}

transfer_common_files() {
    local directory1=$1
    local directory2=$2
    local destination_directory=$3
    local paths_of_common_files="$4"
    local common_files
    readarray -t common_files < <(echo "$paths_of_common_files" | rev | cut -d "/" -f1 | rev)

    for i in "${common_files[@]}"; do
        mv "${directory1}/${i}" "${destination_directory}/${i}"
        rm "${directory2}/${i}"
        ln "${destination_directory}/${i}" "${directory1}/${i}"
        ln "${destination_directory}/${i}" "${directory2}/${i}"
    done
}

main() {
    validate_arguments "$#"

    local directory1=$1
    local directory2=$2
    local directory_for_common_files=$3

    validate_directory "$directory1"
    validate_directory "$directory2"
    validate_directory "$directory_for_common_files"

    local diff_output
    local paths_of_common_files
    diff_output=$(compare_directories "$directory1" "$directory2")
    print_dir_unique_files "$diff_output" "$directory1"
    echo ""
    print_dir_unique_files "$diff_output" "$directory2"
    echo ""
    paths_of_common_files=$(extract_paths_of_common_files_from_diff_output "$diff_output")
    print_common_files "$paths_of_common_files"
    transfer_common_files "$directory1" "$directory2" "$directory_for_common_files" "$paths_of_common_files"
    exit 0
}

main "$@"
