CC = gcc
LINKERS = -lglfw -lGL
IPATH = /usr/local/bin/acheron
DPATH = ./include/
CCFLAGS = -Wall -I$(DPATH)

install: compile
	@cp -f acheron $(IPATH)

compile:
	@$(CC) -o acheron $(CCFLAGS) src/*.c $(LINKERS) 

.PHONY = clean
clean: 
	@sudo rm acheron

.PHONY = run
run: compile
	@./acheron
