#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check proper usage
    if (argc > 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *forensic_image = fopen(argv[1], "r");

    // Check if file is opened properly
    if (forensic_image == NULL)
    {
        return 1;
    }

    uint8_t buffer[512];
    int counter = 0;

    // Memory for name format
    char *filename = malloc(8);
    FILE *output_file = NULL;

    while (fread(buffer, 1, 512, forensic_image) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Closes file if already exist
            if (counter > 0)
            {
                fclose(output_file);
            }

            // Stores the file name to the string filename
            sprintf(filename, "%03i.jpg", counter);
            output_file = fopen(filename, "w");
            counter++;
        }

        // Writes to file if exists
        if (output_file != NULL)
        {
            fwrite(buffer, 1, 512, output_file);
        }
    }

    free(filename);
    fclose(forensic_image);
    fclose(output_file);
    return 0;
}
