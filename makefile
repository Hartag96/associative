all: testmap testbook

testmap: testmap.o
	g++ -g -Wall $^ -o $@

testbook: testbook.o
	g++ -g -Wall $^ -o $@

testmap.o: testmap.cpp Employee.h map_template.h
	g++ -g -c -Wall $< -o $@

testbook.o: testbook.cpp book.h map_template.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm testmap.o testbook.o testmap testbook
