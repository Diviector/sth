CC=gcc
FLAGS=-Wall -Wextra -Werror
BUILD_PATH=./build
PROGRAM=sth

all: sth

sth: $(PROGRAM).c $(BUILD_PATH)
	$(CC) $(FLAGS) $(PROGRAM).c -o $(BUILD_PATH)/$(PROGRAM)

$(BUILD_PATH):
	mkdir $(BUILD_PATH)

clean:
	rm -rf $(BUILD_PATH)
