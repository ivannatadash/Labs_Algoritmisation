#define _CRT_SECURE_NO_WARNINGS 

#include "Header.h" 
#define STR_MAX 100 

int main(int argc, char* argv[])
{
    char readFilename[STR_MAX];
    char tempFilename[] = "New.txt";

    if (argc == 1)
    {
        inputName(readFilename);
    }

    else
    {
        strcpy(readFilename, argv[1]);
    }

    FILE* fr, * fw;

      printf("Opening %s file...\n", readFilename);
    fr = fopen(readFilename, "r");

    if (fr == NULL)
    {
          printf("Cannot open file.\n");
          getchar();

       return 1;
    }

      printf("Creating %s file...\n", tempFilename);
    fw = fopen(tempFilename, "w");

    edit(fr, fw);

      printf("Closing both files...\n");
      fclose(fr);
      fclose(fw);
      files(readFilename, tempFilename);

      printf("Completed.\n");
      getchar();

      return 0;
}