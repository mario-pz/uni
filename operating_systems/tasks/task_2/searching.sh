#!/bin/bash

validate_arguments() {
    local script_name=$0
    local arguments_count=$1
    if [[ $arguments_count -ne 2 ]]; then
        echo "Usage: $script_name permissions_in_octal_value number_of_days"
        exit 124
    fi
}

is_valid_directory() {
    local path=$1
    if [[ ! -d "$path" ]]; then
        echo "$path is not a directory"
        return 1
    fi
    return 0
}

find_files_in_directory_by_permission() {
    local directory_path=$1
    local permissions=$2
    echo "File tree in directory $directory_path with permission in octal $permissions"
    find "$directory_path" -type f -perm "$permissions" -ls
}

find_files_in_directory_modified_last_days() {
    local directory_path=$1
    local number_of_days=$2
    echo "Files in directory $directory_path modified before $number_of_days days"
    find "$directory_path" -type f -mtime -"$number_of_days" -ls
}

find_subDirectories_lately_accessed_last_days() {
    local directory_path=$1
    local number_of_days=$2
    echo "Sub-categories in directory $directory_path accessed before $number_of_days days"
    find "$directory_path" -type d -atime -"$number_of_days" -ls
}

find_files_in_directory_with_read_rights_for_all_users() {
    local directory_path=$1
    echo "Files in directory $directory_path with read permissions for all users"
    ls -lp "$directory_path" | grep -E "^.(r..){3}" | grep -v /$
}

find_subDirectories_with_write_rights_not_only_by_owner() {
    local directory_path=$1
    echo "Sub-directories with write rights not only by owner"
    ls -lp "$directory_path" | grep -E "^..w.{2}(w|.{3}w).*/$"
}

main() {
    validate_arguments "$#"

    local permissions=$1
    local days=$2
    local choice
    local directory

    while :; do
        read -rp "Give directory name or 'exit': " choice
        if [[ $choice == "exit" ]]; then
            break
        fi

        if is_valid_directory "$choice"; then
            directory=$choice
            find_files_in_directory_by_permission "$directory" "$permissions"
            echo ""
            find_files_in_directory_modified_last_days "$directory" "$days"
            echo ""
            find_subDirectories_lately_accessed_last_days "$directory" "$days"
            echo ""
            find_files_in_directory_with_read_rights_for_all_users "$directory"
            echo ""
            find_subDirectories_with_write_rights_not_only_by_owner "$directory"
            echo ""
        fi
    done
    exit 0
}

main "$@"
