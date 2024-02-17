CFLAGS = -Wall -g -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer
LDFLAGS = -fsanitize=address -fsanitize=leak

all:
	gcc main.c -o main
	@./main
	@rm main

clean:
	@rm main
