#!/bin/bash

# This is a build script that allows us to build the project via a bash script (not CMAKE)
pwd
echo "Removing artifacts first..."
rm -rf *.gch > /dev/null # Remove artifacts first if applicable and pipe output to the abyss

echo "Running G++ compiler command..."
g++ -I./hdr ./hdr/*.h ./src/*.cpp -o ./build/application # build all our .cpp and .h files

echo "Giving execution privileges to compiled file..."
chmod +x ./build/application # Give our build script execution privileges
#clear
echo "Running compiled file..."
printf "\n\nvvvvvvvvv APPLICATION OUTPUT BELOW vvvvvvvvv\n\n\n"
./build/application # Run the script

printf "\n\n========= END APPLICATION =========\n\n"
echo "All done! Cleanup will parse through now..."
rm -rf ./*.gch > /dev/null