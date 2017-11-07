questao_1 = ./bin/questao_1
questao_2 = ./bin/questao_2
questao_3 = ./bin/showprimos
questao_4 = ./bin/questao_4

BIN_DIR = ./bin
OBJ_DIR = ./build
LIB_DIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
TEST_DIR = ./test

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I.

OBJS_Q1 = $(OBJ_DIR)/questao_1/main.o
OBJS_Q2 = $(OBJ_DIR)/questao_2/main.o
OBJS_Q3 = $(OBJ_DIR)/questao_3/main.o
OBJS_Q4 = $(OBJ_DIR)/questao_4/main.o


RM = rm -rf

.PHONY: dir doxy clean questao_1 questao_2 questao_3 all

all: questao_1 questao_2 questao_3

questao_1: $(questao_1)

$(questao_1): CPPFLAGS += -I$(INC_DIR)/questao_1/
$(questao_1): $(OBJS_Q1)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao_1/main.o: $(SRC_DIR)/questao_1/main_q1.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

questao_2: $(questao_2)

$(questao_2): CPPFLAGS += -I$(INC_DIR)/questao_2/
$(questao_2): $(OBJS_Q2)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao_2/main.o: $(SRC_DIR)/questao_2/main_q2.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

questao_3: $(questao_3)

$(questao_3): CPPFLAGS += -I$(INC_DIR)/questao_3/
$(questao_3): $(OBJS_Q3)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao_3/main.o: $(SRC_DIR)/questao_3/main_q3.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

questao_4: $(questao_4)

$(questao_4): CPPFLAGS += -I$(INC_DIR)/questao_4/
$(questao_4): $(OBJS_Q4)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao_4/main.o: $(SRC_DIR)/questao_4/main_q4.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

dir:
	mkdir -p bin
	mkdir -p build/questao_1
	mkdir -p build/questao_2
	mkdir -p build/questao_3
	mkdir -p build/questao_4
	mkdir -p include/questao_1
	mkdir -p include/questao_2
	mkdir -p include/questao_3
	mkdir -p include/questao_4
	mkdir -p src/questao_1
	mkdir -p src/questao_2
	mkdir -p src/questao_3
	mkdir -p src/questao_4
	mkdir -p doc
	mkdir -p lib
	mkdir -p test

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	$(RM) $(DOC_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(BIN_DIR)/*
