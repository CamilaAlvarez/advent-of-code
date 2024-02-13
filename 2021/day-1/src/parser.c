#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/parser.h"

#define MAX_ENTRIES 2500

int *parse_input(const char *input_filename, int *total_measurements) {
    int entries[MAX_ENTRIES];
    int number_entries;
    FILE *file;

    file = fopen(input_filename, "r");
    if (file == NULL) {
        printf("error while opening file %s\n", input_filename);
        exit(EXIT_FAILURE);
    }
    number_entries = 0;
    size_t n, read;
    char *line = NULL;
    read = 0;

    while((read = getline(&line, &n, file)) != -1) {
        if (strcmp(line, "\n") == 0) {
            continue;
        }
        // In real code we should use strtol and use error detection
        int measurement = atoi(line);
        entries[number_entries] = measurement;
        number_entries++;
    }
    int *m = malloc(sizeof(int)*number_entries);
    for (int i = 0; i < number_entries; i++) {
        m[i] = entries[i];
    }
    *total_measurements = number_entries;
    return m;
}
