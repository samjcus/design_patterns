CC = g++
CFLAGS = -Wall -Wextra

all: naive_duck.exe duck_simulator.exe

%.exe: %.cpp
	$(CC) $^ $(CFLAGS) -o $@

.PHONY: clean

clean:
	rm -f *.exe *~
