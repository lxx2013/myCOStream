CC      = gcc
cxx		= g++
YACC    = bison -y
LEX     = flex

PROGRAM := COStreamC
SRCDIRS := ../src
SRCEXTS := .c .cpp   # SRC 目录里相关的文件后缀

SHELL = /bin/sh
POBJ =  lex.o
#SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
#@$(foreach d,$(SRCDIRS), $(addprefix $(d)/*,$(SRCEXTS)))
all:
	@echo SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
	@echo OBJS = $(POBJ) $(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES))))