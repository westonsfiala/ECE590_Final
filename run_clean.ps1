# If we haven't downloaded the container yet. Do so.
if (docker images -q klavins/ecep520:cppenv-http == "" )
{
    Write-Output "Pulling image from online"
    docker image pull klavins/ecep520:cppenv-http
}

# Run docker again, but this time in the predone image provided by the professor.
docker run --rm --volume ${pwd}:/source -it klavins/ecep520:cppenv-http bash -c "./clean.sh"