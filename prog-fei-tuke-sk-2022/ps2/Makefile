#  AUTHORED BY VOLODYMYR BOLGARIN ^_^
#
#  TWITTER: @bolgarin_v
#  MY GITHUB IS: @ONIQdevv
#  STUDENT AT Technická univerzita v Košiciach -> FEI

# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wconversion
SOURCES= main.c k.c hof.c ui.c
OUTPUT=game
OBJECTS=main.o k.o hof.o ui.o
LDLIBS= -lm -lcurses

# targets
all: codeanalysis $(OUTPUT)

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o k.o hof.o ui.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

k.o: k.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

hof.o: hof.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

ui.o: ui.c
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
	$(CC) $(CFLAGS) -c hof.c $(LDLIBS) -o hof.o
	$(CC) $(CFLAGS) -c k.c $(LDLIBS) -o k.o
	$(CC) $(CFLAGS) -c ui.c $(LDLIBS) -o ui.o
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(OUTPUT) -g
	@echo "|"
	@echo "V"
	@echo "-------------------------------"
	@echo "Starting app..."
	@echo "-------------------------------"
	@echo "|"
	@echo "V"
	@valgrind ./game

push:
	@git add .
	@git commit -a
	@git push

