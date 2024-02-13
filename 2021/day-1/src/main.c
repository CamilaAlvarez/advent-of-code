/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/02/2024 11:50:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "include/parser.h"

#define WINDOW_SIZE 3

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Missing input file\n");
        exit(EXIT_FAILURE);
    }
    int number_entries;
    int *entries = parse_input(argv[1], &number_entries);
    int count_higher = 0;
    for (int i = 0; i < number_entries - 1; i++) {
        int window_a = 0, window_b = 0;
        for (int j = 0; j < WINDOW_SIZE; j++){
            window_a += entries[i + j];
            window_b += entries[i + 1 + j];
        }
        if (window_a < window_b) {
            count_higher++;
        }
    }
    printf("How many increased? %d\n", count_higher);
    free(entries);
    return 0;
}
