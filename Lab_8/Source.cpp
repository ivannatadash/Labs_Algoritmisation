#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 

#include <string.h> 

#include <stdlib.h> 

#define LEN 150 

#define KR 100 

void Search(char* symb, int k);

char* massive[LEN + 1];



int main() {

    int input = 0;

    printf("Enter 0 if you want to input info from keyboard or 1 if you want to input info from a file.\n");

    scanf("%i", &input);

    char memory[LEN + 1], * m, ** symb = 0;

    int i = 0, nw = 0;

    puts("Enter a number to find words:");

    int k = 0;

    scanf("%d", &k);

    getchar();

    FILE* file;

    if (input == 1) {

        file = fopen("Text.txt", "r");

        while (fgets(memory, LEN, file) != NULL) {

            m = (char*)malloc(strlen(memory) + 1);

            if (m == NULL)

                break;

            strcpy(m, memory);

            massive[i++] = m;

        }



        fclose(file);

    }

    else {



        while (gets_s(memory) && i < KR && strcmp(memory, "")) {

            m = (char*)malloc(strlen(memory) + 1);

            if (m == NULL) {

                break;

            }

            strcpy(m, memory);

            massive[i++] = m;

        }

    }

    for (symb = massive; *symb != NULL; symb++) {

        Search(*symb, k);

    }

    symb = massive;

    while (*symb != NULL)

        free(*symb++);

    return 0;

}



void Search(char* symb, int k) {

    int kw = 1;

    char* pk = strtok(symb, " ,.-");

    while (pk != NULL && kw < k) {

        pk = strtok(NULL, " ,.-");

        ++kw;

        if (kw == k)

            break;

    }

    if (k != kw)

        puts("Not have");

    else puts(pk);

}