
students: main.o heap.o
	g++ -o students main.o heap.o

main.o: main.cpp date.h address.h student.h
	g++ -c main.cpp

heap.o: heap.cpp date.h address.h student.h
	g++ -c heap.cpp

run: students
	./students

debug: students
	gdb ./students

clean:
	rm -f students *.o

valgrind: students
	valgrind --leak-check=full ./students

