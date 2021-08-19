CC = g++
CFLAGS = -g -Wall -std=c++11

src = $(wildcard *.cc)
target = $(patsubst %.cc, %.exe, ${src})

.PHONY: all clean

%.exe:%.cc
	$(CC) ${CFLAGS} $^ -o $@

all: ${target}

clean:
	rm ${target}

