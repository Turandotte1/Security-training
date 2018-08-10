#!/bin/bash

read -p "Enter class here: " class
if [ -z $class ]; then
    echo "Wrong Input"
fi
for i in `seq 1 254`; do
     host $class.$i | grep 'name pointer' | cut -d ' ' -f1,5
done
echo \n
