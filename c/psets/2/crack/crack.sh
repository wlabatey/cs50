#!/usr/bin/env bash

# Script to automate cracking of hashes in list for CS50 pset2 "crack" challenge.

CRACK_BIN="./crack1"

declare -a hashes=( "50xcIMJ0y.RXo" "50mjprEcqC/ts" "50GApilQSG3E2"
                    "50n0AAUD.pL8g" "50CcfIk1QrPr6" "509nVI8B9VfuA"
                    "50JIIyhDORqMU" "50JGnXUgaafgc" "51u8F0dkeDSbY"
                    "50cI2vYkF0YU2" )

for hash in "${hashes[@]}"; do
    echo "Cracking hash: ${hash}"
    time ${CRACK_BIN} ${hash}
done
