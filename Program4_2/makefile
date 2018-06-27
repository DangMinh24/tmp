#Author: DANG TRAN
#ID	:	S856F75
#File: Assignment4
CC=g++
CFLAG=-Wall
Money.o: Money.cpp 
	$(CC) $(CFLAG) -c Money.cpp

HotdogStand.o: HotdogStand.cpp
	$(CC) $(CFLAG) -c HotdogStand.cpp

main.o: main.cpp
	$(CC) $(CFLAG) -c main.cpp

.PHONY: hw4
hw4: HotdogStand.o Money.o main.o
	$(CC) $(CFLAG) -o hw4 main.o Money.o HotdogStand.o

.PHONY: clean
clean:
	rm -f *.o