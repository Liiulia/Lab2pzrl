#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h> 
#include "operation.h" 

void replace_text(const char *filename, const char *regex, const char *replacement)
{
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error opening input file");
        return;
    }

    FILE *output = fopen("output.txt", "w");
    if (!output)
    {
        printf("Error opening output file");
        fclose(input);
        return;
    }

    char line[1024];
    regex_t reg;
    regcomp(&reg, regex, REG_EXTENDED);

    while (fgets(line, sizeof(line), input))
    {
        char buffer[1024] = {0};
        char *cursor = line;
        regmatch_t match;

        while (regexec(&reg, cursor, 1, &match, 0) == 0)
        {
            strncat(buffer, cursor, match.rm_so);
            strcat(buffer, replacement);
            cursor += match.rm_eo;
        }
        strcat(buffer, cursor);
        fputs(buffer, output);
    }

    regfree(&reg);
    fclose(input);
    fclose(output);
}

void delete_lines(const char *filename, const char *regex) {
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
    regex_t reg;
    regcomp(&reg, regex, REG_EXTENDED);
    
    while (fgets(line, sizeof(line), input)
        {
        if (regexec(&reg, line, 0, NULL, 0) != 0) {
            fputs(line, output);
        }
    }

    regfree(&reg);
    fclose(input);
    fclose(output);
}

void add_text(const char *filename, const char *text, int to_front)
{
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        perror("Error opening input file");
        return;
    }

    FILE *output = fopen("output.txt", "w");
    if (!output)
    {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input))
    {
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        if (to_front)
        {
            fprintf(output, "%s%s\n", text, line);
        } else
        {
            fprintf(output, "%s%s\n", line, text);
        }
    }

    fclose(input);
    fclose(output);
}
