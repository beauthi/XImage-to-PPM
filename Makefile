CC=gcc
SRC=converter.c
LDFLAGS=-lX11
BIN=converter

all: ${BIN}

clean:
	$(RM) $(BIN) $(BIN).o
