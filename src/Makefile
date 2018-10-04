CC      = gcc
CXX		= g++
YACC    = bison -y
LEX     = flex
TAB = '	'
VPATH = .:bin
PROGRAM := a
SRCDIRS := .
OUTDIRS := bin
SRCEXTS := .c .cpp   # SRC 目录里相关的文件后缀

SHELL = /bin/sh
SOURCES = $(foreach d,$(SRCEXTS),$(wildcard *$(d)))
POBJ = lex.o
OBJS = $(POBJ) $(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES))))

# Rules for producing the executable.
#----------------------------------------------
all : lex.o $(PROGRAM)

lex.o:  c4.l
	@echo SOURCES$(TAB)= ${SOURCES}
	@echo OBJS$(TAB)= ${OBJS}
	@mkdir -p bin
	$(LEX) c4.l 
	mv lex.yy.c bin/lex.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I. -c bin/lex.c -o bin/lex.o

objs : $(OBJS)
%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS)  -o $(OUTDIRS)/$@ $<
%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)  -o $(OUTDIRS)/$@ $<

$(PROGRAM) : $(OBJS)
ifeq ($(strip $(SRCEXTS)), .c) # C file
	$(CC) -o $(PROGRAM) $(LDFLAGS) $(foreach d,$(OBJS),$(addprefix $(OUTDIRS)/,$(d)))
else # C++ file
	$(CXX) -o $(PROGRAM) $(LDFLAGS) $(foreach d,$(OBJS),$(addprefix $(OUTDIRS)/,$(d)))
endif


clean :
	@$(RM) lex.c lex.yy.c parser.c y.tab.[ch] y.output *.o  bin/* *.d *.out