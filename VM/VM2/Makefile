##
## Makefile for Abstract_vm in /home/chambi_r//.ssh/abstractvm-2014-caille_c
## 
## Made by raphael chambily
## Login   <chambi_r@epitech.net>
## 
## Started on  Tue Feb 15 11:02:37 2011 raphael chambily
## Last update Sat Feb 19 14:49:24 2011 raphael chambily
##

NAME    = avm

SRCS    = main.cpp	\
	VmStack.cpp	\
	exception.cpp	\
	Line.cpp	\
	Tasks.cpp

OBJS    = $(SRCS:.cpp=.o)

CC      = g++

RM      = rm -f

CXXFLAGS  += -Wextra -Wall -W

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all     : $(NAME)

clean   :
	$(RM) $(OBJS)

fclean  : clean
	$(RM) $(NAME)

re      : fclean all
