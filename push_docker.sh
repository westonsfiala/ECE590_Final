
echo Building Elma container
docker build -t ece590_final ./elma/

docker tag ece590_final:latest westonsfiala/ece590_final:latest

docker image push westonsfiala/ece590_final:latest