#!/bin/bash
# ^ Tell this script that it should be run by bash. Must be at top. Something can find this.

# If anything doesn't return 0 after running, exit.
set -o errexit

# If I try to use a variable that is not set, exit.
set -o nounset

# Make everything for running the fraction tests.
make all

# Run the tests for fraction.
# echo "Running unit tests from ELMA"
# mkdir -p copiedTests;
# cp /usr/local/src/elma/test/bin/test copiedTests/
# ./copiedTests/test