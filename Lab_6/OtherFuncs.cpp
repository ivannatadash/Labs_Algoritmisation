#define _CRT_SECURE_NO_WARNINGS 

#include "Header.h" 
#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 

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

double seredne(int i, zing* a, int k)
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


void poshuk2(zing* a, int k)
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

    printf(" Двоє студентів з максимальним рейтингом:\n");

    for (i = 0; i < 2; i++)
    {
        printf("%s", a[i].prizvishe_imya);
    }

}

void znak()
{
    printf("\n-----------------------------------\n");
}

void vivid_strilka(zing* a, int k)
{
    int j = 0, i = 0;
    zing* vasya;

    for (vasya = &a[0]; vasya < &a[k]; vasya++, i++)
    {
        printf("%20s ", vasya->prizvishe_imya);
        znak();
        printf("|%3.3lf|", seredne(i, a, k));

        for (j = 0; j < k_ocinok; j++)
        {
            printf(" |%3d|", vasya->reyting[j]);
        }

        znak();

    }

}