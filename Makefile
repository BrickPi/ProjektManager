CC=gcc
CFLAGS=-Ipman -Wall -Wextra

DEPS = pman/configmanager.h

OBJ = pman/main.o pman/configmanager.o 


pman/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o pman/pman $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f pman/*.o