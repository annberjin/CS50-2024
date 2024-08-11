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

    FILE *input_file = fopen(argv[1], "r");

    // If file can't be opened for reading
    if (input_file == NULL)
    {
        return 1;
    }

    FILE *output_file = NULL;
    uint8_t buffer[512];
    char *filename = malloc(8 * sizeof(char));
    const int blocksize = 512;
    int counter = 0;

    while (fread(buffer, sizeof(char), blocksize, input_file))
    {
        // Bitwise arithmetic for the fourth byte -> 1111 0000 + 1110 0000 = 1110 0000
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // Closes files that are already written
            if (counter > 0)
            {
                fclose(output_file);
            }

            // Stores the file name to the string filename
            sprintf(filename, "%03i.jpg", counter);
            output_file = fopen(filename, "w");
            counter++;
        }

        // Writes to exisiting files
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), blocksize, output_file);
        }
    }

    free(filename);
    fclose(input_file);
    fclose(output_file);
    return 0;
}
