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

printf $GREEN
./megaphone "shhhhh... I think the students are asleep..."
printf $MAGENTA
printf "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\n"
printf $GREEN
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
printf $MAGENTA
printf "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n"
printf $GREEN
./megaphone
printf $MAGENTA
printf "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"
printf $RESET
