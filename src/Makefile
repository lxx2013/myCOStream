CC      = gcc
CXX		= g++
YACC    = bison -y
LEX     = flex
CFLAGS  = -I include

TAB = '	'
VPATH = .:bin:config
PROGRAM := a
SRCDIRS := src
OUTDIRS := bin
SRCEXTS := .c .cpp   # SRC 目录里相关的文件后缀

SHELL = /bin/sh
SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
POBJ = parser.o lexer.o
OBJS = $(POBJ) $(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(notdir $(filter %$(x),$(SOURCES)))))

# Rules for producing the executable.
#----------------------------------------------
parser.o: parser.y
	$(YACC) -v --defines=include/token.hh config/parser.y 
	mv y.tab.c $(OUTDIRS)/parser.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -DYYDEBUG -c $(OUTDIRS)/parser.c -o $(OUTDIRS)/parser.o
lexer.o:  lexer.l
	@echo SOURCES$(TAB)= ${SOURCES}
	@echo OBJS$(TAB)= ${OBJS}
	@mkdir -p bin
	$(LEX) config/lexer.l 
	mv lex.yy.c src/lexer.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c src/lexer.c -o bin/lexer.o


objs : $(OBJS)
%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS)  -o $(OUTDIRS)/$@ $<
%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)  -o $(OUTDIRS)/$@ $<

all : $(PROGRAM)
$(PROGRAM) : $(OBJS)
ifeq ($(strip $(SRCEXTS)), .c) # C file
	$(CC) -o $(PROGRAM) $(LDFLAGS) $(foreach d,$(OBJS),$(addprefix $(OUTDIRS)/,$(d)))
else # C++ file
	$(CXX) -o $(PROGRAM) $(LDFLAGS) $(foreach d,$(OBJS),$(addprefix $(OUTDIRS)/,$(d)))
endif


clean :
	@$(RM) lex.c lex.yy.c parser.c y.tab.[ch] y.output *.o  bin/* *.d *.out
count : 
	find . -maxdepth 1  -name "*[.l|.c|.h|Makefile]"  | xargs cat | wc -l