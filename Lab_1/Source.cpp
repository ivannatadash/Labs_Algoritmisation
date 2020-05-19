#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct stud zing;

struct stud
{
   char prizvishe_imya[80];   int reyting[5];
};

   const int k_ocinok = 3;
   const int k_max = 50;
   int k = 0;
   zing a[50];

void vvid();
void sort();
void vivid();
void poshuk2();
void vivid_strilka();
void znak();

int main()
{
    system("chcp 1251");
    system("cls");
    vvid();
    printf("�� ����������:\n");
    vivid();
    sort();
    printf("\n³���������� � ���������� �������:\n");
    vivid_strilka();
    poshuk2();

  return 0;

}

void vvid()
{
    printf("������ ������� ��������:\n");
    scanf_s("%d", &k);
  if (k > k_max) k = k_max;
  int i, j, c;
  for (i = 0; i < k; i++)
  {
       printf("������ ������� � ��'�:\n");
    while ((c = getchar()) != '\n' && c != EOF);  
       fgets(a[i].prizvishe_imya, 80, stdin);

    for (j = 0; j < k_ocinok; j++)
    {
       printf("������ ������:\n");
       scanf_s("%d", &(a[i].reyting[j]));
    }

  }

}

void vivid()
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


void sort()
{
    int i, j;
    zing tmp;

    for (i = 0; i < k; i++)
    {
        for (j = 1; j < k; j++)
        {
            if (strcmp(a[j - 1].prizvishe_imya, a[j].prizvishe_imya) > 0)
            {
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

double seredne(int i)
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


int poshuk_max(int propusk)
{
    int i, j;
    int i_max;
    double c_max, c; 

    if (propusk != 0)
    {
        c_max = seredne(0);
        i_max = 0;
    }

    else
    {
        c_max = seredne(1);
        i_max = 1;
    }

    for (i = 1; i < k; i++)
    {
        if (i == propusk) continue;
        c = seredne(i);
        if (c_max < c)
        {
            c_max = c;
            i_max = i;
        }

    }

      printf("|%lf|", c_max);

  return i_max;

}


void poshuk2()
{
    printf(" ��� �������� � ������������ ���������: \n");
  int i1 = poshuk_max(-1); 
    printf("%s", a[i1].prizvishe_imya);
  int i2 = poshuk_max(i1);
    printf("%s \n", a[i2].prizvishe_imya);
}

void znak()
{
    printf("\n-----------------------------------\n");
}

void vivid_strilka()
{
    int j = 0, i = 0;
    zing* vasya;

    for (vasya = &a[0]; vasya < &a[k]; vasya++, i++)
    {
          printf("%20s ", vasya->prizvishe_imya);
        znak();
          printf("|%3.3lf|", seredne(i));

        for (j = 0; j < k_ocinok; j++)
        {
            printf(" |%3d|", vasya->reyting[j]);
        }

        znak();
    }

}