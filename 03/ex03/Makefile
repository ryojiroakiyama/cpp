NAME		=	DiamondTrap
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -pedantic -MMD -MP -Wshadow -Wno-shadow -I $(INCDIR)
INCDIR		=	./include
SRCDIR		=	./src
SRCNAME		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp
SRCS		=	$(addprefix $(SRCDIR)/, $(SRCNAME))
OBJS		=	$(SRCS:.cpp=.o)
DEPS		=	$(OBJS:.o=.d)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) -rf *.dSYM
	$(RM) -rf $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re

-include $(DEPS)
