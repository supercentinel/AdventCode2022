CC := gcc

TOPDIR:= .
INCLUDE:= ${TOPDIR}/include
SOURCE:= ${TOPDIR}/source

CFLAGS:= -I $(INCLUDE)

_DEPS:= stack.h
DEPS:= $(patsubst %,$(INCLUDE)/%,$(_DEPS))

_MAIN:= main.c
_SRC:= stack.c list.c
SRC:= $(patsubst %,$(SOURCE)/%,$(_SRC))
OBJ:= $(SRC:.c=.o) $(_MAIN:.c=.o)

# Program name
ifeq ($(OS), Windows_NT)
	EXE:= day5.exe
else
	EXE:= day5.o
endif

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o ${SOURCE}/*.o