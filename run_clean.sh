#!/bin/bash
# ^ Tell this script that it should be run by bash. Must be at top. Something can find this.

# If anything doesn't return 0 after running, exit.
set -o errexit

# If I try to use a variable that is not set, exit.
set -o nounset

# If we haven't downloaded the container yet. Do so.
if [[ "$(docker images -q klavins/ecep520:cppenv-http 2> /dev/null)" == "" ]]; then
    echo Pulling image from online
    docker image pull klavins/ecep520:cppenv-http
fi


# Run docker again, but this time in the predone image provided by the professor.
docker run --rm --volume `pwd`:/source -it klavins/ecep520:cppenv-http bash -c "./clean.sh"