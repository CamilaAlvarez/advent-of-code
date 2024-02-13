GCC=gcc
CGFLAGS=-I.
SRC=src
BUILD_DIR=build
PROG_NAME=depth
MKDIR=mkdir -p

all: $(PROG_NAME)
$(PROG_NAME): $(SRC)/main.c
	$(MKDIR) $(BUILD_DIR)
	$(GCC) -o $(BUILD_DIR)/$(PROG_NAME) -g $^ $(CGFLAGS)
.PHONY: clean all
clean:
	rm -rf $(BUILD_DIR)
