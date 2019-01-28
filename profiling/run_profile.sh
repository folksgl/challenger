#!/bin/bash

# This bash script will run challenger with the commands from uci_commands.txt
# and run the gprof tool against the generated gmon.out file to obtain performance
# information.

profile_out_file=gmon.out
profile_uci_commands=uci_commands.txt

if [ -f gmon.out ]; then
    rm $profile_out_file
fi

cat $profile_uci_commands | ../challenger

gprof -b -p ../challenger gmon.out
