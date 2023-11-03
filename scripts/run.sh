#!/bin/bash

#Check that script is run from root directory
if [[ ! ( "$0" =~ (\./)?scripts/run.sh ) ]]; then
	echo "Please run this script from the base directory as \"scripts/run.sh -y year -d day -p part\"."
	exit 1
fi

./scripts/build.sh
if [[ "$?" == "0" ]]; then
	time build/COLLAdventOfCode "$@"
fi
