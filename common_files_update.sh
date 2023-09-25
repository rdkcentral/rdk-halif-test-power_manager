#!/usr/bin/env bash

# *
# * If not stated otherwise in this file or this component's LICENSE file the
# * following copyright and licenses apply:
# *
# * Copyright 2023 RDK Management
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# * http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *

######################################
# SCRIPT TO COPY COMMON FILES TO REPO
######################################

CFU_repo="H"

# Check with user if ut repo url is correct , else get the correct one
while true; do
        read -p "Is this script being run for HAL( enter H/h ) or HALTESTS( enter T/t )? " input
        case $input in
                [Hh] ) break
                ;;
                [Tt] ) CFU_repo="T"
                        break
                ;;
                * ) echo -e "Wrong input. Please try again"
                ;;
        esac
done

CURRENT_REPO=`git remote -vv | head -n1 | awk -F ' ' '{print $2}'`

if [ $CFU_repo == "H" ]; then
        CLONE_REPO=`echo $CURRENT_REPO | sed 's/hal.*/hal-hdmicec.git/g'`
else
        CLONE_REPO=`echo $CURRENT_REPO | sed 's/hal.*/haltest-hdmicec.git/g'`
fi


# Create temp workspace folder and clone HDMI CEC HAL repo and checkout feature branch
if [ ! -d workspace ]; then
	mkdir -p workspace       
	git clone ${CLONE_REPO} workspace/temp_repo -b feature/RDK-41512-hdmicec-hal-l2-review 2>/dev/null
fi


# Remove existing common files
rm -f README* LICENSE*f NOTICE* CONTRIBUTING* COPYING* &>/dev/null

# Copy updated common files from HDMI CEC HAL repo
cp workspace/temp_repo/LICENSE .
cp workspace/temp_repo/NOTICE .
cp workspace/temp_repo/CONTRIBUTING.md .
rm build*.sh &>/dev/null

read -p "Enter name of module : " module

if [ $CFU_repo == "H" ]; then
        cp workspace/temp_repo/build_ut.sh .
else
        cp workspace/temp_repo/build.sh .
        cp workspace/temp_repo/Makefile .
        cp workspace/temp_repo/README.md .
	if [ $CFU_repo == "T" ]; then
		find . -maxdepth 1  -iname README.md | xargs sed -n '/Index/q;p' > temp
		mv temp README.md
		find . -maxdepth 1 -iname README.md| xargs sed -i 's/HDMI/'"$module"'/g'
	fi
fi


cp workspace/temp_repo/docs/generate_docs.sh docs/

# Create soft links for COPYING and README.md
ln -s LICENSE COPYING
if [ $CFU_repo == "H" ]; then
	find . -iname generate_docs.sh |xargs sed -i 's/HDMI CEC HAL/'"$module HAL"'/g'
	read -p "Enter name of halSpec.md : " halspec
        ln -s ./docs/pages/${halspec} README.md
else
	find . -iname generate_docs.sh |xargs sed -i 's/HDMI CEC HAL/'"$module HAL Tests"'/g'
fi

# Now changes to docs/pages
cd ./docs/pages
rm -f LICENSE*  NOTICE* CONTRIBUTING* COPYING* # Remove existing common files

# Create soft links to corresponding files in root dir
ln -s ../../LICENSE LICENSE
ln -s ../../NOTICE NOTICE
ln -s ../../CONTRIBUTING.md CONTRIBUTING.md
ln -s ../../COPYING COPYING

cd - &>/dev/null
rm -rf workspace 2>/dev/null # Remove temp workspace dir

echo -e "All Done"
if [ $CFU_repo == "T" ]; then
	echo -e "PLEASE UPDATE ANY REQUIRED LINKS/CHANGES IN THE MAKEFILE"
fi
