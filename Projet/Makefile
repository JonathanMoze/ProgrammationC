CFLAGS= -std=c11 -Wall -Wextra -pedantic -g
LDFLAGS=

all: exe test

exe: file_exe
test: googletest gtest

# dependencies
file_exe: File.o Liste.o Element.o main.o 
	$(CC) File.o Liste.o Element.o main.o -o test

main.o: main.c File.h Element.h Liste.h 


File.o:  File.h Element.h 

Liste.o: Liste.h Element.h

Element.o: Element.c Element.h



gtest_all: Test.o File_cpp.o Liste_cpp.o Element_cpp.o 
	g++ -pthread -std=c++11 Test.o File_cpp.o Liste_cpp.o Element_cpp.o -o gtest_all -L./googletest/build/lib -lgtest

File_cpp.o:  File.c File.h Element.h 
	g++ -pthread -std=c++11 -I./googletest/googletest/include -g -c File.c -o File_cpp.o

Liste_cpp.o: Liste.h Liste.c Element.h
	g++ -pthread -std=c++11 -I./googletest/googletest/include -g -c Liste.c -o Liste_cpp.o

Element_cpp.o: Element.c Element.h    
	g++ -pthread -std=c++11 -I./googletest/googletest/include -g -c Element.c -o Element_cpp.o

Test.o : Test.cpp FileTest.h File.h ListeTest.h Liste.h
	g++ -pthread -std=c++11 -I./googletest/googletest/include -g -c Test.cpp
    
gtest: gtest_all
	./gtest_all

googletest:
	(git clone git://github.com/google/googletest.git ; cd googletest ; mkdir build ; cd build ; cmake .. ; make)

clean:
	rm -f *.o file_exe test gtest_all

clean_all: clean
	rm -rf ./googletest