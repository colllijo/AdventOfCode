#!/bin/bash

#Check that script is run from root directory
if [[ ! ( "$0" =~ (\./)?scripts/build.sh ) ]]; then
	echo "Please run this script from the base directory as \"scripts/build.sh\"."
	exit 1
fi

cd build
make
if [[ "$?" == "0" ]]; then
	cd ~-
else
	cd ~-
	exit 1
fi
