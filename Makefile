BIN := bin
SRC := src
INCLUDE := include

CC := gcc

CFLAGS := -Wall -Werror -I$(INCLUDE)

OBJECTS := $(SRC)/main.o $(SRC)/student.o $(SRC)/list.o
EXECUTABLE := students
ARGUMENTS := 

all: $(EXECUTABLE)

# $^ is $(OBJECTS)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN)/$(EXECUTABLE)

# students: src/main.o src/student.o
# 	gcc -Wall -Werror -Iinclude src/main.o src/student.o -o bin/students

run: $(EXECUTABLE)
	./$(BIN)/$(EXECUTABLE) $(ARGUMENTS)

clean:
	$(RM) $(OBJECTS) $(BIN)/$(EXECUTABLE)

.PHONY: all, run, clean
