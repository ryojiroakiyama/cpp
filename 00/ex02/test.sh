#!/bin/bash
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
BOLD="\033[1m"
UNDERLINE="\033[4m"
BOLD_UNDERLINE="\033[1;4m"
RESET="\033[0m"

printf "${GREEN}without close${RESET}\n"
diff -y <(cat 19920104_091532.log | cut -d " " -f 2 | grep -v "close") <(./bank | cut -d " " -f 2 | grep -v "close")
printf "${GREEN}about close${RESET}\n"
diff -y <(cat 19920104_091532.log | cut -d " " -f 2 | grep "close") <(./bank | cut -d " " -f 2 | grep "close" | sort)
