#!/bin/bash
# ^ Tell this script that it should be run by bash. Must be at top. Something can find this.

# If anything doesn't return 0 after running, exit.
set -o errexit

# If I try to use a variable that is not set, exit.
set -o nounset

# Run docker again, but this time in the predone image provided by the professor.
# docker image pull klavins/elma:latest
# docker run --rm --volume `pwd`:/source -it klavins/elma:latest bash -c "./build.sh"

docker image pull westonsfiala/ece590_final:latest
docker run --rm --volume `pwd`:/source -it westonsfiala/ece590_final:latest bash -c "./build.sh"

