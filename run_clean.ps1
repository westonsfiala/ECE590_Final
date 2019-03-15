# Run docker again, but this time in the predone image provided by the professor.
#docker image pull klavins/elma:latest
#docker run --rm --volume ${PWD}:/source -it klavins/elma:latest bash -c "./clean.sh"

#docker image pull westonsfiala/ece590_final:latest
#docker run --rm --volume ${PWD}:/source -it westonsfiala/ece590_final:latest bash -c "./clean.sh"

docker run --rm --volume ${PWD}:/source -it ece590_final:latest bash -c "./clean.sh"