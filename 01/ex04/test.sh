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

#test
printf "${GREEN}5 arguments${RESET}\n"
./replace files/test1.txt ryojiro akiyama bbbbbbb

printf "${GREEN}file don't exist${RESET}\n"
./replace files/no_file ryojiro akiyama

printf "${GREEN}test1.txt s1 null string${RESET}\n"
./replace files/test1.txt "" akiyama

printf "${GREEN}test1.txt s2 null string${RESET}\n"
./replace files/test1.txt ryojiro ""

printf "${GREEN}test1.txt simple test${RESET}\n"
./replace files/test1.txt ryojiro akiyama
diff -y --suppress-common-lines files/test1.txt files/test1.replace | GREP_COLOR='0;35' egrep --color=auto -e '$|ryojiro' -e 'akiyama|$'
# `display difference side by side` | `color the string matches "ryojiro" or "akiyama"`

printf "${GREEN}test1.txt s1 dose not exist${RESET}\n"
./replace files/test1.txt bbbbbb akiyama
diff -y --suppress-common-lines files/test1.txt files/test1.replace

printf "${GREEN}test2.txt(no last newline) simple test${RESET}\n"
./replace files/test2.txt ryojiro akiyama
diff -y --suppress-common-lines files/test2.txt files/test2.replace | GREP_COLOR='0;35' egrep --color=auto -e 'ryojiro|$' -e 'akiyama|$'

printf "${GREEN}test2.txt(no last newline) s1 dose not exit${RESET}\n"
./replace files/test2.txt akiyama akiyama
diff -y --suppress-common-lines files/test2.txt files/test2.replace

printf "${GREEN}test3(empty file) simple test${RESET}\n"
./replace files/test3 ryojiro akiyama
diff -y --suppress-common-lines files/test3 files/test3.replace
