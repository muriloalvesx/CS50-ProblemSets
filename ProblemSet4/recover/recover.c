#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BYTES 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *memory = fopen(argv[1], "r");
    if (memory == NULL)
    {
        printf("Couldn't open the file\n");
        return 1;
    }
    printf("File opened successfully\n");

    BYTE buffer[BYTES];
    int counter = 0;
    char name[8];
    FILE *img = NULL;

    while (fread(buffer, 1, BYTES, memory) == BYTES)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(name, "%03i.jpg", counter++);
            img = fopen(name, "w");
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, BYTES, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }
    fclose(memory);

    return 0;
}
