#!/bin/bash

#Check that script is run from root directory
if [[ ! ( "$0" =~ (\./)?scripts/createYear.sh ) ]]; then
	echo "Please run this script from the base directory as \"scripts/createYear.sh\"."
	exit 1
fi

# Check that correct amount of arguments are supplied
if [[ $# -ne 1 ]]; then
	echo -e "\033[31mInvalid arguments supplied!\033[39m\nPlease make sure to run this command as 'scripts/createYear.sh <Year to create>'."
	exit 1
# Check that a number is supplied
elif [[ !($1 =~ ^[0-9]+$) ]]; then
	echo -e "\033[31mInvalid argument supplied!\033[39m\nPlease make sure to pass a year as argument like 'scripts/createYear.sh <Year to create>'."
	exit 1
elif [[ $1 -lt 2015 ]]; then
	echo -e "\033[96mSkipping:\033[39m No Advent of Code before 2015."
	exit 0
fi

year=$1
sources=""
addDays=""

# Check that years haven't already been created
if [[ -d "input/$year" && -d "src/$year" && -d "iclude/$year" ]]; then
	echo -e "\033[96mSkipping:\033[39m Year already exists."
	exit 0
fi

mkdir -p "input/$year" "src/$year"

# Copy day templates
for day in {1..25}; do
	# Add day to sources
	sources+="src/$year/day$day.h src/$year/day$day.cpp "
	addDays+="\tyears->setDay($year, $day, new Day${day}_$year);\n"

	if [[ -f "src/$year/day$day.cpp" || -f "src/$year/day$day.h" ]]; then
		continue
	fi

	cp "template/day.h" "src/$year/day$day.h"
	cp "template/day.cpp" "src/$year/day$day.cpp"

	# Adjust to fit day
	sed -i "s/DAY_H/DAY_$day\_$year\_H/g; s/\(\<Day\>\)/\1$day\_$year/g" "src/$year/day$day.h"
	sed -i "s/day.h/day$day.h/g; s/\(\<Day\>\)/\1$day\_$year/g; s/AoCDay(0, 0)/AoCDay($year, $day)/g" "src/$year/day$day.cpp"
done

# Add days.h containing all the days
if [[ ! (-f "src/$year/days.h") ]]; then
	cp "template/days.h" "src/$year/days.h"
	sed -i "s/DAYS_H/DAYS_$year\_H/g;" "src/$year/days.h"
fi

# Update CMakeLists.txt
cmakeFile=""
addSources="false"

while IFS= read -r line; do
	# Check for start of "year" section
    if [[ "$line" == "# Add sources for the years" ]]; then
    	addSources="true"
    fi

	# Add sources
	if [[ "$addSources" == "true" ]]; then
		if [[ "$line" == "set(SOURCES_$year ${sources}src/$year/days.h)" ]]; then
			addSources="false"
		elif [[ "$line" == "" ]]; then
			addSources="false"
			cmakeFile+="set(SOURCES_$year ${sources}src/$year/days.h)\n"
		fi
	fi

	cmakeFile+="$line\n"
done < CMakeLists.txt

echo -e "$cmakeFile" > CMakeLists.txt
perl -i -pe 's/(add_executable\((\$\{\b(?!SOURCES_'"$year"'\b)\w+\}[ ]?)*)\)/$1 \${SOURCES_'"$year"'})/g' CMakeLists.txt
sed -i 's/    /\t/g' CMakeLists.txt

# Add days in main.cpp
mainFile=""
addInclude="false"
addFunctionDefinition="false"
addFunctionCall="false"

while IFS= read -r line; do
	# Check for start of "year" section
    if [[ "$line" == "// Include all the days" ]]; then
    	addInclude="true"
	elif [[ "$line" == "// SetDays Functions" ]]; then
		addFunctionDefinition="true"
	elif [[ "$line" == "void setYears(AoCYears *years)" ]]; then
		addFunctionCall="true"
	fi

	# Add include
	if [[ "$addInclude" == "true" ]]; then
		if [[ "$line" == "#include \"$year/days.h\"" ]]; then
			addInclude="false"
		elif [[ "$line" == "" ]]; then
			addInclude="false"
			mainFile+="#include \"$year/days.h\"\n"
		fi
	fi

	# Add definition
	if [[ "$addFunctionDefinition" == "true" ]]; then
		if [[ "$line" == "void setDays$year(AoCYears *years);" ]]; then
			addFunctionDefinition="false"
		elif [[ "$line" == "" ]]; then
			addFunctionDefinition="false"
    		mainFile+="void setDays$year(AoCYears *years);\n"
    	fi
	fi

	# Add call
	if [[ "$addFunctionCall" == "true" ]]; then
		if [[ "$line" == *"setDays$year(years);"* ]]; then
    		addFunctionCall="false"
    	elif [[ "$line" == "}" ]]; then
    		addFunctionCall="false"
    		mainFile+="\tsetDays$year(years);\n"
    	fi
	fi

    mainFile+="$line\n"
done < src/main.cpp

if [[ ! ("$mainFile" == *"void setDays$year(AoCYears *years)\n"*) ]]; then
	mainFile+="\nvoid setDays$year(AoCYears *years)\n{\n$addDays}"
fi

echo -e "$mainFile" > src/main.cpp
sed -i 's/    /\t/g' src/main.cpp

# Build once so that the incremental builds are faster
./scripts/build.sh
