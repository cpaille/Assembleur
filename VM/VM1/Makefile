##
## Makefile for makefile in /home/reboul_a//work/tek2/svn-projet-pitek/C++/vm_abstract
## 
## Made by anthony reboul
## Login   <reboul_a@epitech.net>
## 
## Started on  Thu Feb 24 10:36:40 2011 anthony reboul
## Last update Thu Feb 24 10:36:40 2011 anthony reboul
##

##############################
# Complete this to make it ! #
##############################
NAME 	= vm_abstract
SRCS	= main.cpp	\
	  Chipset.cpp	\
	  Operand.cpp	\
	  Cpu.cpp
#HEADERS =	
#########
# Extra #
#########
DOCDIR	= doc/latex
DOCNAME	= refman.pdf
################
# Optional add #
################
OPTI	= -O2

IPATH   = -I./includes -I./src/proc
OBJOPT  = $(OPTI) -W -Wall
CFLAGS  = $(OBJOPT) $(IPATH)
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lsfml-graphics -lsfml-window -lsfml-system -lncurses
LIBDEPS	= 
EXEOPT  = 
LDFLAGS = $(EXEOPT) $(LPATH) $(LIBDEPS)

#####################
# Macro Definitions #
#####################
AR	= ar r
RANLIB	= ranlib

CP	= cp
RM 	= /bin/rm -f

CC 	= g++

MAKE 	= make
SHELL	= /bin/sh

OBJS 	= $(SRCS:.cpp=.o)

.PHONY		: clean fclean re

#COMP	= gzip -9v
#UNCOMP	= gzip -df
#STRIP	= strip
#.SUFFIXES	: .h.Z .c.Z .h.gz .c.gz .c.z .h.z

##############################
# Basic Compile Instructions #
##############################

all		: $(NAME)

$(NAME)		: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
# For libraries
#	$(AR) $(NAME) $(OBJS)
#	$(RANLIB) $(NAME)

clean		:
	$(RM) $(OBJS) *~

fclean		: clean
	$(RM) $(NAME)

re		: fclean all

################
# Extra target #
################

# Doc
#
#
#doc		: Doxyfile $(HEADERS)
#	cd $(DOCDIR) && make
#	cp $(DOCDIR)/refman.pdf $(DOCNAME)

# Bonus

chocolate	:
	@echo "gcc milk.c -W --check-expiration-date -c milk.o"
	@echo "gcc cacao.c -W --grind -c cacao.o"
	@echo "gcc sugar.c -W -c sugar.o"
	@echo "gcc milk.o cacao.o sugar.o -o chocolate"
	@sleep 1
	@echo "._______________________."
	@echo "|   |   |   |   |   |   |"
	@echo "|   |   |   |   |   |   |"
	@echo "|---+---+---+---+---+---|"
	@echo "|   |   |   |   |   |   |"
	@echo "|   |   |   |   |   |   |"
	@echo "*-----------------------*"
