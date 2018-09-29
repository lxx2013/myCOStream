CC      = gcc
CXX		= g++
YACC    = bison -y
LEX     = flex

PROGRAM := COStreamC
SRCDIRS := .
OUTDIRS := bin
SRCEXTS := .c .cpp   # SRC 目录里相关的文件后缀

SHELL = /bin/sh
	@echo SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
	@echo OBJS = $(POBJ) $(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES)))) 


# Rules for producing the executable.
#----------------------------------------------
all : lex $(PROGRAM)

lex:  c4.l
	@echo $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(OUTDIRS)/*,$(SRCEXTS))))
	@echo $(POBJ) $(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES)))) 
	@mkdir -p bin
	$(LEX) c4.l 
	mv lex.yy.c bin/lex.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I. -c bin/lex.c -o bin/lex.o

objs : $(OBJS)
%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS)  -o bin/$@ $<
%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)  -o bin/$@ $<

$(PROGRAM) : $(OBJS)
ifeq ($(strip $(SRCEXTS)), .c) # C file
	$(CC) -o $(PROGRAM) bin/$(OBJS) $(LDFLAGS)
else # C++ file
	$(CXX) -o $(PROGRAM) bin/$(OBJS) $(LDFLAGS)
endif


clean :
	@$(RM) lex.c lex.yy.c parser.c y.tab.[ch] y.output *.o  bin/* *.d