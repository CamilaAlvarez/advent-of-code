GCC=gcc
PROG_NAME=diagnostic
SRC=src

all: $(PROG_NAME)
$(PROG_NAME): main.c
	$(GCC) -o $(PROG_NAME) -g $^
.PHONY: clean all
clean:
	rm $(PROG_NAME)

