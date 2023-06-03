#!/bin/bash

username=$(whoami)

(crontab -u "$username" -l ; echo "0 23 * * 0 /bin/bash ./bck.sh /home/$username /tmp") | crontab -u "$username" -

#remove job
at now +6 months <<ENDMARKER
crontab -u "$username" -l | grep -v '/bin/bash ./bck.sh /home/$username /tmp'  | crontab -u "$username" -
ENDMARKER

