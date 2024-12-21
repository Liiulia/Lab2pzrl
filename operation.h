#ifndef OPERATION_H
#define OPERATION_H

void replace_text(const char *filename, const char *regex, const char *replacement);
void delete_lines(const char *filename, const char *regex);
void add_text(const char *filename, const char *text, int to_front);

#endif
