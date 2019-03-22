docker image pull westonsfiala/ece590_final:latest
docker run --rm --volume ${PWD}:/source -it westonsfiala/ece590_final:latest bash -c "./build.sh"