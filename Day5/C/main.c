#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "list.h"

int readStracks(FILE *pf, List *stacks)
{
    int i, j, k;
    char buff[9][100];
    char *data;

    for(i = 0; i < 9; i++)
    {
        fgets(buff[i], 99, pf);
    }

    for (i = 0; i < 9; i++)
    {
        k = 0;

        for (j = 0; j < strlen(buff[i]); j++)
        {
        
            if (buff[8-i][j-1] == '[')
            {
                if((data = (char *)malloc(sizeof(char))) == NULL) return -1;
                *data = buff[8-i][j];

                stack_push(stacks[k], data);

                printf(" stack %d: %c\n", k, *data);

                k++;
                free(data);
            }
            
        }
        
    }
    
    /*
    for ( i = 0; i < 9; i++)
    {
        printf("%s", buff[i]);
    }
    */
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int a, i;
    FILE *pf;

    List stacks;
    Stack stack;

    for (i = 0; i < 9; i++)
    {
        list_init(&stacks, );
    }
    

    if((pf = fopen("input.txt", "r")) == NULL) return 1;

    a = readStracks(pf, *stacks);


    for ( i = 0; i < 9; i++)
    {
        stack_destroy(&stacks[i]);
    }
    

    fclose(pf);

    return 0;
}
