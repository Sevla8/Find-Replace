OFILES = substituor.o \
         assignor.o \
         tools.o \
         main.o

FLAGS = -Wall -ansi -pedantic -g

exe : $(OFILES)
	gcc $(FLAGS) -o exe $(OFILES)

substituor.o : substituor.c substituor.h
	gcc -c substituor.c

assignor.o : assignor.c assignor.h
	gcc -c assignor.c

tools.o : tools.c tools.h
	gcc -c tools.c

main.o : main.c
	gcc -c main.c

.PHONY : clean

clean :
	rm -f $(OFILES) exe