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

#define MAX_LENGTH_BITS 256
#define MAX_ENTRIES 1000

int to_decimal(char *binary, int binary_len) {
    int number = 0;
    for (int i = 0; i < binary_len; i++){
        char digit = binary[i];
        if (digit == '1'){
            number += (int)pow(2, binary_len-i-1);
        }
    }
    return number;
}

int main(int argc, char const *argv[]){
    size_t read = 0, n;
    char *line = NULL;
    bool first_row = true;
    char **lines = malloc(sizeof(char[MAX_LENGTH_BITS])*MAX_ENTRIES);
    for(int i = 0; i < MAX_ENTRIES; i++) {
        lines[i] = malloc(sizeof(char)*MAX_LENGTH_BITS);
    }
    char **lines2 = malloc(sizeof(char[MAX_LENGTH_BITS])*MAX_ENTRIES);
    for(int i = 0; i < MAX_ENTRIES; i++) {
        lines2[i] = malloc(sizeof(char)*MAX_LENGTH_BITS);
    }
    char **zeroes = malloc(sizeof(char[MAX_LENGTH_BITS])*MAX_ENTRIES);
    for(int i = 0; i < MAX_ENTRIES; i++) {
        zeroes[i] = malloc(sizeof(char)*MAX_LENGTH_BITS);
    }
    char **ones = malloc(sizeof(char[MAX_LENGTH_BITS])*MAX_ENTRIES);
    for(int i = 0; i < MAX_ENTRIES; i++) {
        ones[i] = malloc(sizeof(char)*MAX_LENGTH_BITS);
    }
    FILE *file = fopen(argv[1], "r");
    size_t row_len, number_lines = 0;
    while((read = getline(&line, &n, file)) != -1){
        line[strcspn(line, "\n")] = 0;
        if (first_row){
            row_len = strlen(line);
            first_row = false;
        }
        strcpy(lines[number_lines], line);
        strcpy(lines2[number_lines], line);
        number_lines++;
    }
    free(line);
    int bit = 0, number_results = number_lines;
    while(bit < row_len && number_results > 1){
        int nz = 0, no = 0;
        for (int i = 0; i < number_results; i++) {
            if (lines[i][bit] == '0') {
                strcpy(zeroes[nz], lines[i]);
                nz++;
            } else if (lines[i][bit] == '1'){
                strcpy(ones[no], lines[i]);
                no++;
            }
        }
        char **aux;
        if(no >= nz) {
            aux = lines;
            lines = ones;
            ones = aux;
            number_results = no;
        } else if (no < nz) { 
            aux = lines;
            lines = zeroes;
            zeroes = aux;
            number_results = nz;
        }
        bit++;
    }
    bit = 0, number_results = number_lines;
    while(bit < row_len && number_results > 1){
        int nz = 0, no = 0;
        for (int i = 0; i < number_results; i++) {
            if (lines2[i][bit] == '0') {
                strcpy(zeroes[nz], lines2[i]);
                nz++;
            } else if (lines2[i][bit] == '1'){
                strcpy(ones[no], lines2[i]);
                no++;
            }
        }
        char **aux;
        if(no < nz) {
            aux = lines2;
            lines2 = ones;
            ones = aux;
            number_results = no;
        } else if (no >= nz) { 
            aux = lines2;
            lines2 = zeroes;
            zeroes = aux;
            number_results = nz;
        }
        bit++;
    }
    printf("Oxygen rating: %s\n", lines[0]);
    printf("CO2 rating: %s\n", lines2[0]);
    int oxygen = to_decimal(lines[0], row_len), co2 = to_decimal(lines2[0], row_len);
    printf("Oxygen (%d) x CO2 (%d) = %d\n", oxygen, co2, oxygen*co2);
    free(lines);
    free(lines2);
    free(zeroes);
    free(ones);
    return 0;
}
