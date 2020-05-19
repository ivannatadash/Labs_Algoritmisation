#include <stdio.h> 
#include <cstdarg> 
#include <stdarg.h> 
#include <math.h> 
#define K 4 

double func1(int n, double d1, ...)
{
    double result = 0;
    char sign = 1;

    for (double* args = &d1; args < &d1 + n; args++)
    {

        if (sign) 
        {
            result += *args * *args;
            sign = 0;
        }

        else 
        {
            result -= *args * *args;
            sign = 1;
        }

    }

   return sqrt(fabs(result));

}

double func2(int n, ...) 
{
    double* dou = (double*)((&n) + 1);
    int* in = (int*)((&n) + 1);
    int pek = 0;
    double rs = 0;

    for (int i = 0; i < K; ++i) 
    {
        if (n == 1) 
        {
            pek *= (-1);
            pek += *in * *in;
            in++;
        }

        if (n == 2)
        {
            rs *= (-1);
            rs += *dou * *dou;
            dou++;
        }

    } 
      if (rs != 0) 
      {
        return sqrt(fabs(rs));
      }

      else
      {
          rs = pek;
          return sqrt(fabs(rs));
      }

}

double func3(char choise[], ...) 
{

    double result = 0;
    int in = 0;
    long lon = 0;
    double dou = 0;
    char* ch = choise;
    va_list va;
    va_start(va, choise);

    while (*ch != '\0') 
    {
        result *= (-1);

        if (*ch == 'i') 
        {
            in = va_arg(va, int);
            result += (double)in * in;
        }

        if (*ch == 'd') 
        {
            dou = va_arg(va, double);
            result += dou * dou;
        }

        if (*ch == 'l') 
        {
            lon = va_arg(va, long);
            result += (double)lon * lon;
        }

        ch++;

    }

    va_end(va);

  return sqrt(fabs(result));

}

int main(void) 
{
    char d1[5] = "iidd";

    puts("\nResult :\n");
    printf("\n1 %lf", func1(4, 2.0, 4.0, 17.3, 14.7));
    printf("\n2 %lf", func2(2, 2.0, 4.0, 17.3, 14.7)); 
    printf("\n3 %lf", func3(d1, 2, 4, 17.3, 14.7));    

    return 0;
}
