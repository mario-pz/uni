#!/bin/bash

validate_arguments() {
    local script_name=$0
    local arguments_count=$1
    [[ $arguments_count -ne 3 ]] && echo "Usage: $script_name username target_backup backup_data" && exit 124
}

validate_username() {
    local username=$1
    [[ $(grep -c ^"${username}": /etc/passwd) -eq 0 ]] && echo "There is no username '$username'" && exit 1
}

validate_path() {
    local path="$1"
    [[ ! -e $path ]] && echo "Invalid path $path" && exit 2
}

main() {
    validate_arguments "$#"
    local username=$1
    validate_username "$username"
    local backup_data=$2
    local backup_data_path="/home/$username/$backup_data"
    validate_path "$backup_data_path"
    local target_backup=$3
    local target_backup_path="/home/$username/$target_backup"

    local tar_args
    [[ -e $target_backup_path && -f $target_backup_path ]] && tar_args=rvf || tar_args=cvf
    [[ -d $target_backup_path ]] && target_backup_path="$target_backup_path/$backup_data"

    tar -"$tar_args" "$target_backup_path" "$backup_data_path"

    result=$?
    if [[ $result -ne 0 ]]; then
        echo "Could not take backup, errors in tar command"
        exit 125
    fi

    echo "these are the current contets of your backup file"
    tar -tvf "$target_backup_path"
    exit 0
}

main "$@"
