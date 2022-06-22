echo "stopping cs128env container"
docker stop cs128env
echo "removing cs128env container"
docker rm cs128env
echo "running new cs128env container"
sh .helpers/setup-mac.sh