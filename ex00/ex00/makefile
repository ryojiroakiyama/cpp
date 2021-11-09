NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -MMD -MP
-include $(DEPS)
DEPS = $(OBJS:.o=.d)
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

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
