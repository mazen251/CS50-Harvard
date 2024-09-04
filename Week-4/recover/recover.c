#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Incorrect usage. Please provide the filename.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Unable to open the file.\n");
        return 1;
    }

    FILE *img = NULL;
    BYTE buffer[512];
    char filename[8];
    int counter = 0;

    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            if (!img)
            {
                printf("Error creating image file.\n");
                fclose(file);
                return 1;
            }
            
            fwrite(buffer, sizeof(BYTE), 512, img);
            counter++;
        }
        else if (counter > 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }

    if (img)
    {
        fclose(img);
    }
    
    fclose(file);
    
    return 0;
}
