#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * > ./a.out https://www.baidu.com/s\?wd\=%E7%BC%96%E7%A8%8B
 * https://www.baidu.com/s?wd=编程
 *
*/

struct decoder
{
    const char *input;
    char *output;
    const char *input_cursor;
    char *output_cursor;
};

int decoder_init(struct decoder *self, const char *input)
{
    self->input = input;
    self->output = calloc(1, strlen(input) + 1);
    if (self->output == NULL)
    {
        return 2;
    }
    self->input_cursor = input;
    self->output_cursor = self->output;
    return 0;
}

void decoder_cleanup(struct decoder *self)
{
    free(self->output);
}

int decoder_consume(struct decoder *self)
{
    char tempbuff[3];
    char ch;
    ch = *self->input_cursor;
    if (ch == '\0')
    {
        return 0;
    }
    if (ch != '%')
    {
        *self->output_cursor++ = *self->input_cursor++;
        return 1;
    }
    tempbuff[0] = *(self->input_cursor + 1);
    tempbuff[1] = *(self->input_cursor + 2);
    tempbuff[2] = '\0';

    *self->output_cursor++ = strtol(tempbuff, NULL, 16);
    self->input_cursor += 3;

    return 1;
}

char *decoder_decode(struct decoder *self)
{
    while (decoder_consume(self))
        ;
    *self->output_cursor = '\0';
    return self->output;
}

int main(int argc, char const *argv[])
{
    struct decoder decoder;
    const char *input;
    int r;

    if (argc != 2)
    {
        fprintf(stderr, "[ERROR]: Usage: ./a.out input-url\n");
        return 1;
    }
    input = argv[1];

    r = decoder_init(&decoder, input);
    if (r != 0)
    {
        fprintf(stderr, "decode failed");
        return r;
    }

    printf("%s\n", decoder_decode(&decoder));

    return 0;
}
