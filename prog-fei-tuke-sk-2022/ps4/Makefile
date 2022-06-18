#  AUTHORED BY VOLODYMYR BOLGARIN ^_^
#
#  TWITTER: @bolgarin_v
#  MY GITHUB IS: @ONIQdevv
#  STUDENT AT Technická univerzita v Košiciach -> FEI

CC = -std=c11
CFLAGS = -Wall -Werror
LDLIBS = -lm
OUTPUT = bmp
SOURCES = main.c bmp.c transformations.c
OBJECTS = bmp.o transformations.o

all: codeanalysis $(OUTPUT)

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

$(OUTPUT): $(OBJECTS)
	gcc $(CC) $(CFLAGS) $^ main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

transformations.o: transformations.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

show: clean
	@clear
	@intro
	@echo "|"
	@echo "V"
	@echo "-------------------------------"
	@echo "Running word: show ..."
	@echo "-------------------------------"
	@echo "|"
	@echo "V"
	@echo "-------------------------------"
	@echo "App debug was started..."
	@echo "-------------------------------"
	@echo "|"
	@echo "V"
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $(SOURCES)
	gcc $(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o -g
	gcc $(CC) $(CFLAGS) -c bmp.c $(LDLIBS) -o bmp.o -g
	gcc $(CC) $(CFLAGS) -c transformations.c $(LDLIBS) -o transformations.o -g
	gcc $(CC) $(CFLAGS) $(OBJECTS) main.o $(LDLIBS) -o $(OUTPUT) -g
	@echo "|"
	@echo "V"
	echo "-------------------------------"
	@echo "Starting app..."
	@echo "-------------------------------"
	@echo "|"
	@echo "V"
	@valgrind  -s --leak-check=full --show-leak-kinds=all ./bmp
#	@./bmp

clean:
	@rm -rf *.o $(OUTPUT) bin/*

push:
	@git add .
	@git commit -a
	@git push