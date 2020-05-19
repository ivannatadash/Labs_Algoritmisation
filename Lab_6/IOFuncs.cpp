#define _CRT_SECURE_NO_WARNINGS 

#include "Header.h" 
#include <stdio.h> 

static const int STR_MAX = 80;

int vvid(zing* a)
{
    int k;
    int i = 0, j, c, d = 1;

    while (d == 1)
    {
        printf("Введіть прізвище і ім'я:\n");
        fgets(a[i].prizvishe_imya, STR_MAX, stdin);

        for (j = 0; j < k_ocinok; j++)
        {
            printf("Введіть оцінку:\n");
            scanf("%d", &(a[i].reyting[j]));
        }

        i++;

        printf("\n 0 - stop, 1 - next\n ");
        scanf("%d", &d);

        while ((c = getchar()) != '\n' && c != EOF);

    }

    k = i;

    return k;

}



void vivid(zing* a, int k)
{
    int i, j;

    for (i = 0; i < k; i++)
    {
        printf("%20s ", a[i].prizvishe_imya);

        for (j = 0; j < k_ocinok; j++)
        {
            printf(" %3d ", a[i].reyting[j]);
        }

        printf("\n");

    }

}