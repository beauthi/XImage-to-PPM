CC=gcc
SRC=converter.c
#LDFLAGS=-lpthread -lX11
#CFLAGS=-g -pthread
BIN=converter

all: ${BIN}

clean:
	$(RM) $(BIN) $(BIN).o
