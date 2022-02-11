CC=gcc
CFLAGS=-Ipman -Wall -Wextra

DEPS = pman/configmanager.h pman/iniparser.h pman/dictionary.h

OBJ = pman/main.o pman/configmanager.o pman/libiniparser.a


pman/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o pman/pman $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f pman/*.o