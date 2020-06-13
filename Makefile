CFLAGS = -O 
CC = g++ 

Test: test.o module.o         
	$(CC) $(CFLAGS) -o Test test.o module.o  

# object

test.o: test.cpp         
	$(CC) $(CFLAGS) -c test.cpp 
module.o: module.cpp  module.h # verRead.h stringFunc.h
	$(CC) $(CFLAGS) -c module.cpp 
verRead.h: verRead.h
	touch verRead.h
stringFunc.h: stringFunc.h
	touch stringFunc.h
clean:         
	rm -f core *.o