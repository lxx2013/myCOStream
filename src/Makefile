CC      = gcc
CXX		= g++
YACC    = bison -y
LEX     = flex
CFLAGS  = -I include
CXXFLAGS  = -I include

TAB = '	'
VPATH = .:bin:config
PROGRAM := a
SRCDIRS := src
OUTDIRS := bin
SRCEXTS := .c .cpp   # SRC 目录里相关的文件后缀

SHELL := /bin/sh
SOURCES := $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
POBJ := parser.o lexer.o
OBJS := $(POBJ) $(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(notdir $(filter %$(x),$(SOURCES)))))

# Rules for producing the executable.
#----------------------------------------------
all : $(PROGRAM)

parser.o: parser.y
	@mkdir -p bin
	$(YACC) -v --defines=include/token.hh config/parser.y 
	mv y.tab.c $(SRCDIRS)/parser.cc
	$(CXX) $(CPPFLAGS) $(CFLAGS) -DYYDEBUG -c $(SRCDIRS)/parser.cc -o $(OUTDIRS)/parser.o
lexer.o:  lexer.l
	@echo SOURCES$(TAB)= ${SOURCES}
	@echo OBJS$(TAB)= ${OBJS}
	$(LEX) config/lexer.l 
	mv lex.yy.c src/lexer.cc
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c src/lexer.cc -o bin/lexer.o


objs : $(OBJS)
%.o : $(SRCDIRS)/%.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS)  -o $(OUTDIRS)/$@ $<
%.o : $(SRCDIRS)/%.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)  -o $(OUTDIRS)/$@ $<
%.o : $(SRCDIRS)/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)  -o $(OUTDIRS)/$@ $<

$(PROGRAM) : $(OBJS)
ifeq ($(strip $(SRCEXTS)), .c) # C file
	$(CC) -o $(PROGRAM) $(LDFLAGS) $(foreach d,$(OBJS),$(addprefix $(OUTDIRS)/,$(d)))
else # C++ file
	$(CXX) -g -o  $(PROGRAM) $(LDFLAGS) $(foreach d,$(OBJS),$(addprefix $(OUTDIRS)/,$(d)))
endif


clean :
	@$(RM) src/lexer.cc include/token.hh src/parser.cc y.tab.[ch] y.output *.o  bin/* *.d *.out
count : 
	find . -maxdepth 1  -name "*[.l|.c|.h|Makefile]"  | xargs cat | wc -l