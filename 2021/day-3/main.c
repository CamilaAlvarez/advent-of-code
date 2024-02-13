/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2024 21:25:24
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
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int number_columns = 0;
    int* number_zeros, *number_ones;
    size_t read = 0, n;
    char *line = NULL;
    bool first_row = true;
    FILE *file = fopen(argv[1], "r");
    size_t row_len;
    while((read = getline(&line, &n, file)) != -1){
        line[strcspn(line, "\n")] = 0;
        if (first_row){
            row_len = strlen(line);
            number_zeros = calloc(row_len, sizeof(int));
            number_ones = calloc(row_len, sizeof(int));
            first_row = false;
        }
        for(int i = 0; i < row_len; i++){
            if (line[i] == '0') {
                number_zeros[i]++;
            } else if (line[i] == '1') {
                number_ones[i]++;
            }
        }
    }
    int gamma = 0, epsilon = 0;
    // we're assuming there won't be an equal number of ones and zeros
    for (int i = 0; i < row_len; i++){
        if (number_zeros[i] > number_ones[i]){
            epsilon += (int)pow(2, row_len - 1 - i);
        } else {
            gamma += (int)pow(2, row_len - 1 - i);
        }
    }
    free(line);
    printf("Gamma: %d\n", gamma);
    printf("Epsilon: %d\n", epsilon);
    printf("Result: %d\n", gamma * epsilon);
    return 0;
}
