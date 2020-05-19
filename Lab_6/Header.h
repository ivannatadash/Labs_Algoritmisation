#pragma once
#define HEADER_H 
#ifndef HEADER_H
#endif  

extern const int k_ocinok;
extern const int k_max;

struct stud
{
    char prizvishe_imya[80];
    int reyting[5];
};

typedef struct stud zing;

int vvid(zing* a);
void sort(zing* a, int first, int last);
void vivid(zing* a, int k);
void poshuk2(zing* a, int k);
void vivid_strilka(zing* a, int k);
void znak();


