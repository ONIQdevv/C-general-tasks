#  AUTHORED BY VOLODYMYR BOLGARIN ^_^
#
#  TWITTER: @bolgarin_v
#  MY GITHUB IS: @ONIQdevv
#  STUDENT AT Technická univerzita v Košiciach -> FEI

CC = -std=c11
CFLAGS = -Wall -Werror -Wconversion
LDLIBS = -lm
OUTPUT = ps5
SOURCES = main.c backpack.c command.c container.c game.c item.c parser.c room.c world.c
OBJECTS = main.o backpack.o command.o container.o game.o item.o parser.o room.o world.o

all: codeanalysis $(OUTPUT)

codeanalysis: $(SOURCES)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 $^

$(OUTPUT): $(OBJECTS)
	gcc $(CC) $(CFLAGS) $^ main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

backpack.o: backpack.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

command.o: command.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

container.o: container.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

game.o: game.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

item.o: item.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

parser.o: parser.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

room.o: room.c
	gcc $(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

world.o: world.c
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
	gcc $(CC) $(CFLAGS) -c container.c $(LDLIBS) -o container.o -g
	gcc $(CC) $(CFLAGS) -c backpack.c $(LDLIBS) -o backpack.o -g
	gcc $(CC) $(CFLAGS) -c command.c $(LDLIBS) -o command.o -g
	gcc $(CC) $(CFLAGS) -c game.c $(LDLIBS) -o game.o -g
	gcc $(CC) $(CFLAGS) -c item.c $(LDLIBS) -o item.o -g
	gcc $(CC) $(CFLAGS) -c parser.c $(LDLIBS) -o parser.o -g
	gcc $(CC) $(CFLAGS) -c room.c $(LDLIBS) -o room.o -g
	gcc $(CC) $(CFLAGS) -c world.c $(LDLIBS) -o world.o -g
	gcc $(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(OUTPUT) -g
	@echo "|"
	@echo "V"
	@echo "-------------------------------"
	@echo "Starting app..."
	@echo "-------------------------------"
	@echo "|"
	@echo "V"
#	@valgrind  -s --leak-check=full --show-leak-kinds=all ./ps5
	@./ps5

clean:
	@rm -rf *.o $(OUTPUT) bin/*

push:
	@git add .
	@git commit -a
	@git push