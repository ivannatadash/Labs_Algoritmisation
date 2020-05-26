#define _CRT_SECURE_NO_WARNINGS 

#include "Header.h" 

void inputName(char* r)
{
    printf("Enter file name to edit: ");
    gets_s(r, STR_MAX);
    
   // gets_s(r, STR_MAX, stdin);
}

void edit(FILE* fr, FILE* fw)
{
      printf("Editing files...\n");
    int mainStarted = 0, brackets = 0;
    char str[STR_MAX];

    while (fgets(str, STR_MAX, fr) != NULL)
    {
        if (!mainStarted)
        {
            if (strstr(str, "int main(") != NULL) 
            {
                mainStarted = 1;
            }

              fprintf(fw, "%s", str);
        }

        else
        {
            if (!strcmp(str, "{\n"))
            {
                  fprintf(fw, "%s", str);
                brackets++;
            }

            else if (!strcmp(str, "}\n") && brackets == 1)
            {
                mainStarted = 0;
                brackets = 0;
                  fprintf(fw, "%s", str);
            }

            else
            {
                for (int i = 0; i < STR_MAX; i++)
                {
                    if (str[i] == '\0')
                        break;

                    else
                    {
                        if (str[i] == '{')
                            brackets++;
                        else if (str[i] == '}')
                            brackets--;

                    }

                }

            }

        }

    }
    fprintf(fw, "\n}");
}

void files(char* r, char* t)
{
    printf("Removing %s file...\n", r); 
    remove(r);
    printf("Renaming %s file to %s...\n", t, r);
    rename(t, r);
}
