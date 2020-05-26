#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define STR_MAX 200 


typedef struct LongList
{
    long* n;
    struct LongList* prev, * next;
} ll;

ll* Input(ll*, int*);
void Output(ll*);
long MinList(ll*);
ll* Delete3TimesHigher(ll*, int*);
void FreeMemory(ll*, int);
ll* DeleteNum(ll*, int*);

void AddNum(ll*, int*);

int main(void)
{
    ll* start = NULL;
    int am;

    start = Input(start, &am);
    if (start == NULL) { return 1; }

    Output(start);

    start = Delete3TimesHigher(start, &am);

    Output(start);

    int user = 1;

    while (user != 0)
    {
        printf("Enter 1 - if you want to add another number\nEnter 2 - if you want to delete a number\nEnter 3 - if you want to output the list\nEnter 0 - if you want to exit\n");
        scanf_s("%i", &user);
        getchar();
        if (user == 3)
        {
            Output(start);
        }

        else if (user == 2)
        {
            start = DeleteNum(start, &am);
            printf("Done.\n");
        }

        else if (user == 1)
        {
            AddNum(start, &am);
            printf("Done.\n");
        }

    }

    FreeMemory(start, am);

    getchar();
    getchar();

    return 0;
}

ll* Input(ll* start, int* amount)
{
    int input;

    printf("Enter 0 if you want to input info from keyboard or 1 if you want to input info from a file.\n");
    scanf_s("%i", &input);
    getchar();

    ll* cur = start, * prev = start;
    prev = (ll*)malloc(sizeof(ll));
    start = prev;

    printf("How many numbers you want to enter? ");
    scanf_s("%i", amount);
    getchar();

    if (input)
    {
        char filename[STR_MAX];
        printf("Enter file name: ");
        gets_s(filename);

        FILE* fp = fopen(filename, "r");
        if (fp == NULL)
        {
            printf("Couldn't open file.\n");
            return NULL;
        }

        else
        {
            char temp[STR_MAX];
            fgets(temp, STR_MAX, fp);
            char* p = strtok(temp, " ");

            int count = 0;

            for (int i = 0; i < *amount; i++)
            {
                if (i != *amount - 1)
                {
                    cur = (ll*)malloc(sizeof(ll));
                    prev->next = cur;
                    cur->prev = prev;
                }

                long* d = (long*)malloc(sizeof(long));
                *d = atol(p);
                p = strtok(NULL, " ");
                prev->n = d;
                prev = cur;
            }
            cur->next = start;
            start->prev = cur;
        }
    }

    else
    {
        for (int i = 0; i < *amount; i++)
        {
            if (i != *amount - 1)
            {
                cur = (ll*)malloc(sizeof(ll));
                prev->next = cur;
                cur->prev = prev;
            }

            long* d = (long*)malloc(sizeof(long));
            printf("Enter %i number: ", i + 1);
            scanf_s("%li", d);
            getchar();
            prev->n = d;
            prev = cur;
        }

        cur->next = start;
        start->prev = cur;

    }

    return start;
}

void Output(ll* start)
{
    ll* pll = start;
    printf("\nNumbers: %li,", *pll->n);
    pll = pll->next;

    while (pll != start)
    {
        printf(" %li,", *pll->n);
        pll = pll->next;
    }

    printf("\n");

}

long MinList(ll* start)
{
    long min = *start->n;
    ll* pll = start->next;

    while (pll != start)
    {
        if (*pll->n < min)
        {
            min = *pll->n;
        }

        pll = pll->next;

    }

    return min;
}

ll* Delete3TimesHigher(ll* start, int* am)
{
    long min = MinList(start);
    ll* pll = start->next;
    ll* pr = start;

    while (1)
    {
        if (*start->n / min >= 3)
        {
            pll->prev = start->prev;
            start->prev->next = pll;
            free(start->n);
            free(start);
            start = pll;
            pr = start;
            pll = pll->next;
            *am = *am - 1;
        }

        else
        {
            break;
        }

    }
    pr = pr->next;
pll = pll->next;

while (pr != start)
{
    if (*pr->n / min >= 3)
    {
        pll->prev = pr->prev;
        pr->prev->next = pll;
        free(pr->n);
        free(pr);
        *am = *am - 1;
    }

    pr = pll;
    pll = pll->next;

}

return start;
}

void FreeMemory(ll* start, int am)
{
    ll* pll = start->next;
    ll* pr = start;

    for (int i = 0; i < am; i++)
    {
        free(pr->n);
        free(pr);
        pr = pll;
        pll = pll->next;
    }
}

ll* DeleteNum(ll* start, int* am)
{
    ll* pll = start->next;
    ll* pr = start;

    long num;
    printf("Enter what number you want to delete: ");
    scanf_s("%li", &num);
    getchar();

    if (num == *start->n)
    {
        pll->prev = pr->prev;
        pr->prev->next = pll;
        free(pr->n);
        free(pr);
        start = pll;

        return start;
    }

    pll = pll->next;
    pr = pr->next;

    while (pr != start)
    {
        if (num == *pr->n)
        {
            pll->prev = pr->prev;
            pr->prev->next = pll;
            free(pr->n);
            free(pr);
            *am = *am - 1;
            break;
        }

        pll = pll->next;
        pr = pr->next;

    }

    return start;
}

void AddNum(ll* start, int* am)
{

    ll* pll = start;
    ll* pr = start->prev;

    long* num = (long*)malloc(sizeof(long));
    printf("Enter what number you want to add: ");
    scanf_s("%li", num);
    getchar();

    ll* cur = (ll*)malloc(sizeof(ll));
    pll->prev = cur;
    pr->next = cur;
    cur->next = pll;
    cur->prev = pr;
    cur->n = num;
    *am = *am + 1;

}