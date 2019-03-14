#!/bin/bash
# ^ Tell this script that it should be run by bash. Must be at top. Something can find this.

# If anything doesn't return 0 after running, exit.
set -o errexit

# If I try to use a variable that is not set, exit.
set -o nounset

# If we haven't built the container yet. Do so.
echo Building Elma container
docker build -t elma ./elma/

# Run docker again, but this time in the predone image provided by the professor.
docker run --rm --volume `pwd`:/source -it elma bash -c "./build.sh"