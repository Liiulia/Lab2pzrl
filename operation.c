    while (fgets(line, sizeof(line), input)) {
        if (regexec(&reg, line, 0, NULL, 0) != 0) {
            fputs(line, output);
        }
    }

    regfree(&reg);
    fclose(input);
    fclose(output);
}

void add_text(const char *filename, const char *text, int to_front) {
    FILE *input = fopen(filename, "r");
    if (!input) {
        perror("Error opening input file");
        return;
    }

    FILE *output = fopen("output.txt", "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input)) {
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        if (to_front) {
            fprintf(output, "%s%s\n", text, line);
        } else {
            fprintf(output, "%s%s\n", line, text);
        }
    }

    fclose(input);
    fclose(output);
}
