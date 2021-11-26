NAME		=	Fixed
CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -pedantic -MMD -MP -I $(INCDIR)
INCDIR		=	./include
SRCDIR		=	./src
SRCNAME		=	main.cpp \
				Fixed.cpp
SRCS		=	$(addprefix $(SRCDIR)/, $(SRCNAME))
OBJS		=	$(SRCS:.cpp=.o)
DEPS		=	$(OBJS:.o=.d)
TEST		=	./test.sh

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) -rf *.dSYM
	$(RM) -f $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: $(NAME)
	$(TEST)

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re

-include $(DEPS)
