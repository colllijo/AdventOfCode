#!/bin/bash

#Check that script is run from root directory
if [[ ! ( "$0" =~ (\./)?scripts/createYear.sh ) ]]; then
	echo "Please run this script from the base directory as \"scripts/createYear.sh\"."
	exit 1
fi

if [[ $# -ne 1 ]]; then
	echo -e "\033[31mInvalid arguments supplied!\033[39m\nPlease make sure to run this command as 'scripts/createClass.sh <class name>'."
	exit 1
fi

echo -e "#ifndef COLL_AOC_RUNNER_AOC_DAY_H\n#define COLL_AOC_RUNNER_AOC_DAY_H\n\nclass {\n};\n\n#endif" > ./libs/
