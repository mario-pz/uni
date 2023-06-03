#! /bin/bash

main () {
    
while getopts :u:s opt; do
    case $opt in
    u) 
       uflag=true
       if [[ ! -z "$OPTARG" ]]; then
         username=$OPTARG
         [[ $(grep -c ^"${username}": /etc/passwd) -eq 0 ]] && echo "There is no username '$username'" && exit 1
         ps -u $username
       else
         ps -eaf
       fi
       ;;
    s) 
        sflag=true 

       if [[ ! -z "$OPTARG" ]]; then
         state=$OPTARG
         [[ $state -ne "S|R|Z" ]] && echo "There wrong state input" && exit 2
        #  
       else
         ps -eaf
       fi


        ;;
    \?) 
        echo "Not valid switch"
    esac
done

}


main "$@"
