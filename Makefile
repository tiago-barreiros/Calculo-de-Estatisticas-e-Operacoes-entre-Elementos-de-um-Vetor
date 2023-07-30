SOURCEFILES = $(wildcard *.c) # Forma de obter os nomes de ficheiros .c. Neste caso todos os ficheiros com extensão .c serão armazenados na
# variável SOURCEFILES.
OBJECTS = $(SOURCEFILES:%.c=%.o) # Substitui em cada ficheiro da lista de ficheiros em SOURCEFILES, a extensão .c por .o

CC = gcc

EXE = main-team-9.exe

.PHONY: all, clean, execute

all: execute

execute : $(EXE)
	./$<

$(EXE) : $(OBJECTS)
	$(CC) -o $@ $^ -lm
	
%.o : %.c
	$(CC) -c $< -lm

clean :
	rm *.o
	echo:"Ficheiros .o eliminados."
