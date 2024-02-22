CC = gcc
CFLAGS = -Wall -Wextra -g -pedantic
# -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer
LDFLAGS = -fsanitize=address -fsanitize=leak

ifeq ($(OS),Windows_NT)
    OUTFILE = a.exe
else
    OUTFILE = a.out
endif

all:
	@$(CC) $(CFLAGS) test_hash.c
	@./$(OUTFILE)

clean:
	@rm main
