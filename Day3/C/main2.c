#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Eval(char c)
{
    if((c >= 65) && (c <= 90))
    {
        return c - 39;
    }else if((c >= 97) && (c <= 122))
    {
        return c - 97;
    }else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    FILE *pf;
    char buffers[3][256]; 
    int bSize, i, j, badge = 0, Psum = 0, bffs[3][52] = {0};

    if((pf = fopen("input.txt", "r")) == NULL)return -1;

    for (j = 0; j < 3; j++)
    {
        fgets(buffers[j], 255, pf);
    }
    
    while (!feof(pf))
    {
        for ( j = 0; j < 3; j++)
        {
            memset(bffs[j], 0, sizeof(bffs[j]));
            //if((strcmp(buffers[j], "\n")) == 0) break;
            //printf("%s", buffers[j]);
            bSize = strlen(buffers[j]);
            for ( i = 0; i < bSize; i++)
            {
                bffs[j][Eval(buffers[j][i])] = 1;
            }
        }

        for (i = 0; i < 52; i++)
        {
            if ((bffs[0][i] == 1 && bffs[1][i] == 1) && (bffs[1][i] == 1 && bffs[2][i] == 1))
            {
                badge = i+1;                
            }
            
        }

        Psum += badge;
        //printf("Group badege = %d\n", badge);

        for (j = 0; j < 3; j++)
        {
            fgets(buffers[j], 255, pf);
        }

    }

    printf("Psum = %d", Psum);
    
    fclose(pf);

    return 0;
}
