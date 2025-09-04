CC = gcc
LINKERS = -lglfw -lGL
IPATH = /bin/acheron
DPATH = ./include/
CCFLAGS = -Wall -I$(DPATH)

install: compile
	@cp -f acheron $(IPATH)

compile:
	@mkdir bin
	@$(CC) -o bin/acheron $(CCFLAGS) src/*.c $(LINKERS) 

.PHONY = clean
clean: 
	@ rm -r bin

.PHONY = run
run:
	@./bin/acheron
