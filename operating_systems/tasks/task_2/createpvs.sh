#!/bin/bash
require_admin_password() {
    if [[ $UID != 0 ]]; then
        echo "Please run this script with sudo:"
        echo "sudo $0 $1"
        exit 1
    fi
}
validate_arguments() {
    local script_name=$0
    local arguments_count=$1
    if [[ $arguments_count -ne 4 ]]; then
        echo "Usage: $script_name ROOTFOLDER no_of_DBFOLDERS no_of_DATAFOLDERS USERNAME"
        exit 124
    fi
}

validate_rootfolder() {
    local rootfolder_path=$1
    if [[ ! -d "$rootfolder_path" ]]; then
        echo "There is no rootfolder in path: '$rootfolder_path'"
        exit 1
    fi
}

validate_username() {
    local username=$1
    if [[ $(grep -c ^"${username}": /etc/passwd) -eq 0 ]]; then
        echo "There is no username '$username'"
        exit 1
    fi
}

create_folders_for_user() {
    local rootfolder_path=$1
    local folders_number=$2
    local folder_base_name=$3
    local folders_count
    folders_count=$(ls -p "$rootfolder_path" | grep "$folder_base_name" | grep -Ec '(([0-9])+/)$')
    local starting_new_folder_number=$((folders_count + 1))
    local last_new_folder_number=$((starting_new_folder_number + folders_number - 1))
    local username=$4
    for ((i = starting_new_folder_number; i <= last_new_folder_number; i++)); do
        folder_name=$folder_base_name$i
        mkdir "$rootfolder_path"/"$folder_name"
        chown "$username" "$rootfolder_path"/"$folder_name"
    done
}

main() {
    require_admin_password "$*"
    validate_arguments "$#"
    validate_rootfolder "$1"
    validate_username "$4"
    create_folders_for_user "$1" "$2" "dbfolder" "$username"
    create_folders_for_user "$1" "$2" "datafolder" "$username"
    exit 0
}

main "$@"
