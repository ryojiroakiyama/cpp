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

EXECUTE="./convert"

test () 
{
	printf $GREEN
	echo "$EXECUTE $1"
	printf $RESET
	bash -c "$EXECUTE $1"
}

test "0"
test "a"
test "z"
test "100"
test "127"
