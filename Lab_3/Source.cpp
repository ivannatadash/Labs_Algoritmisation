#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct stud zing;

struct stud 
{
    char prizvishe_imya[80];
    int reyting[5];
};

 int vvid(zing* a, int k_max, int k_ocinok);
void sort(zing* a, int first, int last);
void vivid(zing* a, int k, int k_ocinok);
void poshuk2(zing* a, int k, int k_ocinok);
void vivid_strilka(zing* a, int k, int k_ocinok);
void znak();

int main()
{
    system("chcp 1251");
    system("cls");
    const int k_ocinok = 3;
    const int k_max = 50;

    int k = 0;
    zing a[50];

    k = vvid(a, 50, k_ocinok);

    printf("До сортування:\n");
    vivid(a, k, k_ocinok);
    sort(a, 0, k - 1);
    printf("\nВідсортовано в алфавітному порядку:\n");
    vivid_strilka(a, k, k_ocinok);
    poshuk2(a, k, k_ocinok);

   return 0;

}

int vvid(zing* a, int k_max, int k_ocinok)
{

    int k;
    int i = 0, j, c, d = 1;

    while (d == 1)
    {
          printf("Введіть прізвище і ім'я:\n");
          fgets(a[i].prizvishe_imya, 80, stdin);

        for (j = 0; j < k_ocinok; j++)
        {
            printf("Введіть оцінку:\n");
            scanf_s("%d", &(a[i].reyting[j]));
        }

        i++;

        printf("\n 0 - стоп, 1 - наступний\n ");
        scanf_s("%d", &d);

        while ((c = getchar()) != '\n' && c != EOF); //to clear buffer  

    }

     k = i;

   return k;

}

void vivid(zing* a, int k, int k_ocinok)
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

void sort(zing* a, int first, int last) 
{

    zing temp;
    int i, j, pivot;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j) 
        {

            while (strcmp(a[i].prizvishe_imya, a[pivot].prizvishe_imya) <= 0 && i < last)
                i++;
            while (strcmp(a[j].prizvishe_imya, a[pivot].prizvishe_imya) > 0)
                j--;
            if (i < j) 
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        sort(a, first, j - 1);
        sort(a, j + 1, last);

    }

}

double seredne(int i, zing* a, int k, int k_ocinok)
{
    int j;
    double rez = 0;

    for (j = 0; j < k_ocinok; j++)
    {
        rez += a[i].reyting[j];
    }

    rez /= k_ocinok;
   return rez;

}

void poshuk2(zing* a, int k, int k_ocinok)
{
    int i, j;
    zing tmp;
    double seredne_j_1, seredne_j;

    for (i = 0; i < k; i++)
    {
        for (j = 1; j < k; j++)
        {

            {
                int i1 = j - 1;
                int j1;
                double rez = 0;

                for (j1 = 0; j1 < k_ocinok; j1++)
                {
                    rez += a[i1].reyting[j1];
                }

                seredne_j_1 = rez / k_ocinok;
            }

            {
                int i1 = j;
                int j1;
                double rez = 0;

                for (j1 = 0; j1 < k_ocinok; j1++)
                {
                    rez += a[i1].reyting[j1];
                }

                seredne_j = rez / k_ocinok;

            }

            if (seredne_j_1 < seredne_j)
            {
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;

            }

        }

    }

      printf(" Двоє студентів з максимальним рейтингом:: \n");
    for (i = 0; i < 2; i++)
    {
        printf("%s", a[i].prizvishe_imya);
    }

}

void znak()
{
    printf("\n-----------------------------------\n");
}

void vivid_strilka(zing* a, int k, int k_ocinok)
{
    int j = 0, i = 0;
    zing* vasya;

    for (vasya = &a[0]; vasya < &a[k]; vasya++, i++)
    {

          printf("%20s ", vasya->prizvishe_imya);
        znak();
          printf("|%3.3lf|", seredne(i, a, k, k_ocinok));

        for (j = 0; j < k_ocinok; j++)
        {
            printf(" |%3d|", vasya->reyting[j]);
        }

        znak();
    }

}