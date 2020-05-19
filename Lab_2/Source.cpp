#include <stdio.h>
#include <stdlib.h>

void input(double**, int, int);
void print_matrix(double**, int, int);
int is_min(double*, int);
int delete_rows(double**, int, int);

int main()
{
    system("chcp 1251");
    system("cls");
    double** matrix = 0;
    int rows, collumns;

      printf("\n Введіть кількість рядків і стовпців: ");
      scanf_s("%d%d", &rows, &collumns);
      getchar();

    matrix = (double**)malloc(sizeof(int*) * rows);

      for (int i = 0; i < rows; ++i)

    matrix[i] = (double*)malloc(sizeof(int) * collumns);

      input(matrix, rows, collumns);
      printf("\n Введена матриця:\n");
      print_matrix(matrix, rows, collumns);

    int amount = delete_rows(matrix, rows, collumns);

      printf("\n Матриця без рядків в яких мінімальний елемент не перший:\n");
      print_matrix(matrix, rows - amount, collumns);
      printf("\n Кількість видалених рядків - %d\n", amount);
   
      free(matrix);
}

void input(double** matrix, int rows, int collumns)
{
      printf("\n Введіть елементи матриці [%dx%d]:\n", rows, collumns);
      for (int i = 0; i < rows; ++i) 
      {
           for (int j = 0; j < collumns; ++j)
                scanf_s("%lf", &(matrix[i][j]));
          getchar();
      }
}

void print_matrix(double** matrix, int rows, int collumns)
{
    if (!rows || !collumns) 
    {
        printf("Матриця пуста");
        return; 
    }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < collumns; ++j)
             printf("%lf ", matrix[i][j]);
        putchar('\n');
    }
}

int is_min(double* row, int amount_of_elements)  
{
    for (double* p = row + 1; p < row + amount_of_elements; ++p)
         if (*row > *p)
             return 1;
    return 0;
}

int delete_rows(double** matrix, int rows, int collumns)
{
    if (!rows)
        return 0;

    int amount = 0; 
    for (int i = 0; i < rows; ++i) {
        if (is_min(matrix[i], collumns)) {
            matrix[i] = 0;
            ++amount;
        }
    }

    for (int i = 0; i < rows; ++i)
        if (matrix[i] == 0)
            for (int j = i; j < rows; ++j)
                 matrix[j] = matrix[j + 1];

    return amount;
}