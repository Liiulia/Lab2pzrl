#include <stdlib.h>
#include <string.h>
#include "operation.h"

void print_usage() {
    printf("Usage:\n");
    printf("  ./sed_simplified input.txt -r \"regex\" \"replacement_text\"\n");
    printf("  ./sed_simplified input.txt -d \"regex\"\n");
    printf("  ./sed_simplified input.txt -i \"text_to_insert\"\n");
    printf("  ./sed_simplified input.txt -b \"text_to_append\"\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    const char *filename = argv[1];
    const char *mode = argv[2];
    const char *regex = argv[3];
    const char *text = argc > 4 ? argv[4] : NULL;

    if (strcmp(mode, "-r") == 0 && text) {
        replace_text(filename, regex, text);
    } else if (strcmp(mode, "-d") == 0) {
        delete_lines(filename, regex);
    } else if (strcmp(mode, "-i") == 0) {
        add_text(filename, text, 1);
    } else if (strcmp(mode, "-b") == 0) {
        add_text(filename, text, 0);
    } else {
        print_usage();
        return 1;
    }

    printf("Operation completed. Results saved to output.txt\n");
    return 0;
}
