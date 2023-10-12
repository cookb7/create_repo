#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *file;
    FILE *outfile;


    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    outfile = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        fputc(c, outfile);
    }

    fclose(file);
    fclose(outfile);

    return 0;
}
