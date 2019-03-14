
Write-Output "Building Elma container"
docker build -t elma ./elma/

# Run docker again, but this time in the predone image provided by the professor.
docker run --rm --volume ${pwd}:/source -it elma bash -c "./build.sh"