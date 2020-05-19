#include <stdio.h>  
#define SIZE 5 

int Recursiya(int chislo, int d, int counter)
{

    if (d)
    {
        printf("%u\n", counter);
        return(Recursiya(chislo * 10 + d % 10, d / 10, ++counter));
    }

    else 

     return(chislo);
};

int Revers(int* chislo) 
{
    int* d = chislo;
      puts("\nCounter : ");
    return(Recursiya((*chislo) % 10, (*d) / 10, 1));

};

int main(void)
{
    int i, z = 0;
    int M[SIZE];
    puts("Enter the numbers:\n");

    for (int i = 0; i < SIZE; i++)
    {
        scanf_s("%d", &z);
        M[i] = z;
    }

    for (i = 0; i < SIZE; i++)
    {
        M[i] = Revers(&M[i]);
    }

      printf("\nNew massiv:\n");

    for (i = 0; i < SIZE; i++)
    {
      printf("%d ", M[i]);
    }

   return 0;

}
