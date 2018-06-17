#	Filename: makefile
# 	Name: Dang Tran
#	ID: S856F975
#	Assignment: 3

hw3:	HotdogStand.o Money.o main.o
	g++ -Wall -o hw3 Money.o HotdogStand.o main.o

HotdogStand.o: HotdogStand.hpp
	g++ -Wall -c HotdogStand.cpp 

Money.o: Money.cpp
	g++ -Wall -c Money.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp 

clean:
	rm -f *.o
