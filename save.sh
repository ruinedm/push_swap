#!/bin/bash
rm -rf xd.txt
# Check if the number of arguments is correct
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <space-separated-list-of-integers>"
    exit 1
fi


# echo "$(./push_swap "$@" | ./checker_linux "$@")"

# Run the provided push_swap command with the arguments and append the output to xd.txt
echo "$(./push_swap "$@")" >> xd.txt
