
all:
	gcc main.c -o main
	@./main
	@rm main

clean:
	@rm main
