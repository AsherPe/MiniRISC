CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/main.c src/cpu.c
OUT = build/mini_risc

run: $(OUT)
	./$(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
