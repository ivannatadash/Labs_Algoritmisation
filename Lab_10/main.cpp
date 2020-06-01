#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#define STR_MAX 50 

typedef struct tree_node 
{
    char num[STR_MAX];
    int dec;
    struct tree_node* left, * right, * parent;

} TreeNode;


void Input();
int QuinaryToDecimal(TreeNode*);
void AddNodeRecur(TreeNode*, TreeNode*);
void PrintTreeDirect(TreeNode*);
void PrintByDescending();
void PrintTreeSymetr(TreeNode*);
void CheckAdjacent(TreeNode*, int);
void DeleteTreeSymetr(TreeNode*);

TreeNode* FindNode(int);

TreeNode* root;

int main(void)

{

    Input();
    printf("\nTree:\n");
    PrintTreeDirect(root);
    PrintByDescending();
    CheckAdjacent(root, 0);
    printf("\nTree:\n");
    PrintTreeDirect(root);

    printf("\nSearch for a number: ");
    int num;
    scanf("%i", &num);
    TreeNode* f = FindNode(num);
    if (f != NULL)
    {
        printf("Number found!\n");
    }

    else
    {
        printf("There's no such number in a tree.\n");
    }

    DeleteTreeSymetr(root);
    getchar();
    getchar();

    return 0;
}

void Input()
{
    char filename[STR_MAX];
    printf("Enter file name: ");
    gets_s(filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Couldn't open file.\n");
        exit(1);
    }

    else
    {
        TreeNode* pel;
        char temp[STR_MAX];
        while (fgets(temp, STR_MAX, fp) != NULL)
        {
            strtok(temp, "\n");
            pel = (TreeNode*)malloc(sizeof(TreeNode));
            pel->left = pel->right = NULL;
            strcpy(pel->num, temp);
            QuinaryToDecimal(pel);
            AddNodeRecur(root, pel);
        }

    }

}


int QuinaryToDecimal(TreeNode* t)
{

    int len = strlen(t->num);
    int dec = 0;
    int curPow = (int)pow(5, (double)len - 1);

    for (int i = 0; i < len; i++)
    {
        if (t->num[i] > 52 || t->num[i] < 48)
        {
            t->dec = -1;
            return 0;
        }

        else
        {
            dec += (t->num[i] - '0') * curPow;
            curPow /= 5;
        }

    }

    t->dec = dec;
    return dec;

}

void AddNodeRecur(TreeNode* proot, TreeNode* pnew) 
{

    if (root == NULL)
    {
        root = pnew;
        root->parent = NULL;
        return;
    }

    if (pnew->dec == proot->dec) 
    {
        printf("\tElement %i already exists in the tree!\n", pnew->dec);
        free(pnew);
    }

    else
    {

        if (pnew->dec < proot->dec)
        {

            if (proot->left == NULL)
            {
                proot->left = pnew;
                pnew->parent = proot;
            }

            else
            {
                AddNodeRecur(proot->left, pnew);
            }
        }

        else
        {

            if (proot->right == NULL)
            {
                proot->right = pnew;
                pnew->parent = proot;
            }

            else
            {
                AddNodeRecur(proot->right, pnew);
            }

        }

    }

}



void PrintTreeDirect(TreeNode* proot)
{

    if (proot == NULL)
        return;

    printf("%i (%s) - ", proot->dec, proot->num);   

    PrintTreeDirect(proot->left);       
    PrintTreeDirect(proot->right);     
}



void PrintByDescending()
{
    printf("\n\nTree in descending order\n");

    printf("+-----------+-----------+\n");

    printf("|  Quinary  |  Decimal  |\n");

    printf("+-----------+-----------+\n");

    PrintTreeSymetr(root);

    printf("+-----------+-----------+\n");
}


void PrintTreeSymetr(TreeNode* proot)
{

    if (proot == NULL)

        return;

    PrintTreeSymetr(proot->right);     

    printf("|  %7s  |  %7i  |\n", proot->num, proot->dec);  

    PrintTreeSymetr(proot->left);      

}


void CheckAdjacent(TreeNode* proot, int side)
{
    if (proot == NULL)
        return;
    if (proot->parent == NULL) {}

    else if (proot->left == NULL && proot->parent->left == NULL)
    {

        if (side)
        {
            proot->parent->parent->right = proot;
        }

        else
        {
            proot->parent->parent->left = proot;
        }

        proot->left = proot->parent;

        proot->parent->right = NULL;

        proot->parent = proot->left->parent;

        proot->left->parent = proot;
    }

    CheckAdjacent(proot->left, 0);
    CheckAdjacent(proot->right, 1);

}


void DeleteTreeSymetr(TreeNode* proot)
{

    if (proot == NULL)
        return;

    DeleteTreeSymetr(proot->right);
    DeleteTreeSymetr(proot->left);
    free(proot);

}

TreeNode* FindNode(int key)   
{

    TreeNode* pnode = root;

    while (pnode != NULL)
    {                       

        if (key == pnode->dec)                      

            return pnode;

        else                             

            if (key < pnode->dec)

                pnode = pnode->left;      

            else

                pnode = pnode->right;    

    }

    return NULL;                             

}






