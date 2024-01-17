#!/bin/bash

# Output file for failures
FAILURE_FILE="failures.txt"

# Variable to store total operations
TOTAL_OPERATIONS=0

# Function to generate a space-separated list of 200 random numbers
generate_random_numbers() {
    echo $(shuf -i 1-100 -n 100)
}

# Run the script 10 times with different sets of 200 numbers
for ((i = 1; i <= 1000; i++)); do
    echo "=== Run $i ==="

    # Generate random numbers
    ARG=$(generate_random_numbers)

    # Run the script logic
    OPERATION_COUNT=$(./push_swap $ARG | wc -l)
    TOTAL_OPERATIONS=$((TOTAL_OPERATIONS + OPERATION_COUNT))

    if [ $OPERATION_COUNT -lt 700 ]; then
        OK="OK"
    else
        OK="KO"
    fi

    # Capture the output of checker_linux
    CHECKER_OUTPUT=$(./push_swap $ARG | ./checker_linux $ARG)

    # Print the results
    echo "Number of operations: $OPERATION_COUNT"
    echo "CHECKER OUTPUT: $CHECKER_OUTPUT"

    # Check if OK is "OK" and checker output is "OK"
    if [ "$OK" = "OK" ] && [ "$CHECKER_OUTPUT" = "OK" ]; then
        echo "Success!"
    else
        # Append failures to the designated file
        echo "Failure! Run $i - Numbers used: $ARG" >> "$FAILURE_FILE"
    fi

    echo "================"
done

# Calculate and print the average number of operations
AVERAGE_OPERATIONS=$((TOTAL_OPERATIONS / 50))
echo "Average number of operations: $AVERAGE_OPERATIONS"
