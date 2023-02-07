#!/usr/bin/env bash
# Script to run bank record system

FILE="data.csv"
if [[ ! -e "$FILE" ]]; then
	touch "$FILE";
fi;

gcc ./*.c -o bank_system
cp ./bank_system /usr/bin/bank_system
