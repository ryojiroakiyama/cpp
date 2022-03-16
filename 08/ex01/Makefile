NAME	= span
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic -I $(INCDIR)

INCDIR	= .
SRCDIR	= .
OBJDIR	= ./obj
DPSDIR	= ./dps

SRCNAME	= 	main.cpp \
			span.cpp \
			test.cpp
SRCS	= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJS	= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
DPS		= $(addprefix $(DPSDIR)/, $(notdir $(SRCS:.cpp=.d)))

.PHONY: all
all: $(OBJDIR) $(DPSDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS)  -MMD -MP -MF $(DPSDIR)/$(notdir $(<:.cpp=.d)) -c $< -o $@

-include $(DPS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DPSDIR):
	mkdir -p $(DPSDIR)

.PHONY: clean
clean:
	$(RM) -rf $(OBJDIR) $(DPSDIR)

.PHONY: fclean
fclean: clean
	$(RM) -f $(NAME)

.PHONY: re
re: fclean all

#.PHONY: test
#test:
#	bash test.sh
