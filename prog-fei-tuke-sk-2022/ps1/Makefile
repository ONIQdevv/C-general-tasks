#  AUTHORED BY VOLODYMYR BOLGARIN ^_^
#
#  TWITTER: @bolgarin_v
#  MY GITHUB IS: @ONIQdevv
#  STUDENT AT Technická univerzita v Košiciach -> FEI

# variables
CC=gcc
CFLAGS=-std=c11 -Werror -Wall
SOURCES=main.c bmp.c playfair.c
OUTPUT=show
OBJECTS=main.o bmp.o playfair.o
LDLIBS=-lm

# targets
all: codeanalysis $(OUTPUT)

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o bmp.o playfair.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

playfair.o: playfair.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

# remove compiled files
clean:
	rm -rf $(OUTPUT) *.o

show: clean
	@clear
	@cat ~/intro.txt
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
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o
	$(CC) $(CFLAGS) -c bmp.c $(LDLIBS) -o bmp.o
	$(CC) $(CFLAGS) -c playfair.c $(LDLIBS) -o playfair.o
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(OUTPUT) -g
	@echo "|"
	@echo "V"
	@echo "-------------------------------"
	@echo "Starting app..."
	@echo "-------------------------------"
	@echo "|"
	@echo "V"
	@valgrind ./show

push:
	@git add .
	@git commit -m "Ubuntu 20.04 LTS commit -->"
	@git push

