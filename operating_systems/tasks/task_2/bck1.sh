#!/bin/bash

validate_arguments() {
    local script_name=$0
    local arguments_count=$1
    [[ $arguments_count -ne 4 ]] && echo "Usage: $script_name username target_backup backup_data time" && exit 124
}

main() {
    validate_arguments "$#"
    local username=$1
    local backup_data=$2
    local target_backup=$3
    local time=$4

    at "$time" <<ENDMARKER
    ./bck.sh "$username" "$backup_data" "$target_backup" 
ENDMARKER

    atq
    exit 0
}

main "$@"
