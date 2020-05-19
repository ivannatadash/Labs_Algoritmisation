#include <stdio.h>
#define SIZE 5 

void Function(int* n)
{
    int U = 0;

    while (*n)
    {
        U *= 10;
        U += (*n % 10);
        *n /= 10;
    };

    *n = U;

}

int main()
{

    int i, z, M[SIZE];
      printf("Massiv:\n");

    for (i = 0; i < SIZE; i++)

    {
          scanf_s("%d", &z);
        M[i] = z;

    }

    for (i = 0; i < SIZE; i++)
    {
        Function(&M[i]);
    }

      printf("New massiv:\n");

      for (i = 0; i < SIZE; i++)
      {
          printf("%d ", M[i]);
      }

    return 0;
}