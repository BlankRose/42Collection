#!/bin/sh
# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   Avaj Launcher - tasks.sh                        #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: lun. 19 juin 2023 16:21:08 CEST   #
#      ||  '-'                                                          #
# ********************************************************************* #

source_dir=src
package_name=AvajLauncher.jar
self_exec="sh tasks.sh"

set -e
cd "$(dirname "$0")"

# Compiles the java classes into objects
if [ "$1" = "compile" ]; then
	javac `find * -name "*.java"`
	echo "Successfully compiled Java objects!"

# Packages the project into an executable JAR (Java ARchive)
elif [ "$1" = "package" ]; then
	cd $source_dir
	sh ../tasks.sh compile # Ensure compilation before packaging
	jar cmf resources/Manifest.mf ../$package_name `find * -name "*.class"`
	echo "Successfully packaged into $package_name!"

# Removes all java .class objects
elif [ "$1" = "clear" ]; then
	rm `find * -name "*.class"`
	echo "Successfully cleared Java objects!"

# Runs the programm using the provided arguments
elif [ "$1" = "run" ]; then
	shift # Skips first argument
	java -jar $package_name "$@"

# Packages and run the programm using the provided
# scenario file (located in docs/Scenario.txt)
elif [ "$1" = "test" ]; then
	$self_exec package
	$self_exec run docs/Scenario.txt

# Displays the available tasks for this project
else
	echo "Available tasks for this project:"
	echo "================================="
	echo
	echo " - compile    : Compiles the java classes into objects"
	echo " - package    : Creates an executable JAR (Java ARchive)"
	echo " - clear      : Removes all java .class objects"
	echo " - run <args> : Executes main class with given arguments"
	echo " - test       : Packages and run the programm using default scenario file"
fi
