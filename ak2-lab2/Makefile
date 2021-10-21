CXX = g++
CXXFLAGS = -g -Wall

all: main

main: main.o calculator.a
	$(CXX) $(CXXFLAGS) main.o -o main -L. -l:calculator.a


main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<


calculator.a: calculator.o
	$(AR) $(ARFLAGS) $@ $^


calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -rf main *.o *.a
