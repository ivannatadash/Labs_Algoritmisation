#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include "Header.h" 
#include <Windows.h>

const int k_ocinok = 3;
const int k_max = 50;

int main()
{
    SetConsoleOutputCP(1251);
    int k = 0;
    zing a[50];

    k = vvid(a);

    printf("До сортування:\n");
    vivid(a, k);
    sort(a, 0, k - 1);
    printf("\nВідсортовано в алфавітному порядку:\n");
    vivid_strilka(a, k);
    poshuk2(a, k);

    return 0;

}