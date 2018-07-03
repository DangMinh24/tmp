#Author: DANG TRAN
#ID	:	S856F75
#File: Assignment4
CC=g++
CFLAG=-Wall -std=c++11


.PHONY: hw4
hw4: HotdogStand.o Money.o main.o NonMember.o
	$(CC) $(CFLAG) -o hw4 main.o Money.o HotdogStand.o NonMember.o

main.o: main.cpp
	$(CC) $(CFLAG) -c main.cpp

Money.o: Money.cpp 
	$(CC) $(CFLAG) -c Money.cpp

HotdogStand.o: HotdogStand.cpp
	$(CC) $(CFLAG) -c HotdogStand.cpp

NonMember.o:
	$(CC) $(CFLAG) -c NonMember.cpp

.PHONY: clean
clean:
	rm -f *.o