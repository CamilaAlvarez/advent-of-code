/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2024 17:46:54
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

#define FORWARD "forward"
#define DOWN "down"
#define UP "up"
#define SPLIT_VALUE " "

int main(int argc, char const *argv[]){
    // TODO: add argument verification
    size_t read = 0, n = 0;
    char *line = NULL;
    int vertical = 0, horizontal = 0, aim = 0, depth = 0;

    FILE *file = fopen(argv[1], "r");

    while((read = getline(&line, &n, file)) != -1) {
        char *token, *number_token;
        token = strtok(line, SPLIT_VALUE);
        while(token != NULL){
            number_token = strtok(NULL, SPLIT_VALUE);
            if (number_token == NULL) break;
            int value_token = atoi(number_token); 
            if(strcmp(token, FORWARD) == 0){
                // TODO: use strtol instead of atoi
                horizontal += value_token;
                depth += (aim * value_token); 
            }
            else if(strcmp(token, DOWN) == 0){
                vertical += value_token;
                aim += value_token;
            }
            else if(strcmp(token, UP) == 0){
                vertical -= atoi(number_token);
                aim -= value_token;
            }
            token = number_token;
        }
    }
    printf("---------- Part 1 ---------- \n");
    printf("Horizontal: %d\n", horizontal);
    printf("Vertical: %d\n", vertical);
    printf("Result h x v: %d\n", horizontal * vertical);
    printf("---------- Part 2 ---------- \n");
    printf("Horizontal: %d\n", horizontal);
    printf("Vertical: %d\n", depth);
    printf("Result h x v: %d\n", horizontal * depth);
    return 0;
}
