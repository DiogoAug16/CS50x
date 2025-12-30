#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int buffer_size = 512;
    BYTE buffer[buffer_size];

    FILE *img = NULL;          // current JPEG file
    int file_count = 0;        // number of recovered JPEGs
    char filename[8];          // e.g., 000.jpg

    while (fread(buffer, 1, buffer_size, card) == buffer_size)
    {
        // Check if this block is the start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG if one is open
            if (img != NULL)
            {
                fclose(img);
            }

            // Open new JPEG
            sprintf(filename, "%03d.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file %s\n", filename);
                return 1;
            }

            file_count++;
        }

        // If a JPEG is open, write the block to it
        if (img != NULL)
        {
            fwrite(buffer, 1, buffer_size, img);
        }
    }

    // Close any remaining file
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
