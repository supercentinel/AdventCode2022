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
    char buffer[256], cmmnC[1];
    int bSize, i, j, bffO[52] = {0}, bffT[52] = {0};
    long int Psum = 0;

    if((pf = fopen("input.txt", "r")) == NULL) return -1;

    while (!feof(pf))
    {
        //j = 0;
        fgets(buffer, 255, pf);
        if((strcmp(buffer, "\n")) == 0) break;
        bSize = strlen(buffer);
        //if(bSize % 2 == 0) strcat(buffer, "\n");
        //printf("%s", buffer);
        
        //printf("size: %d\n", bSize);
        //printf("First compartment\n");
        for (i = 0; i < bSize/2; i++)
        {
            //printf("%c"/*%d"*/, buffer[i]/*, Eval(buffer[i])*/);
            bffO[Eval(buffer[i])] = 1;
        }
        //printf("\n");
        //printf("Second compartment\n");
        for (i = bSize/2; i < bSize ; i++)
        {
            //printf("%c"/*%d"*/, buffer[i]/*, Eval(buffer[i])*/);
            if(bffT[i] != '\n') bffT[Eval(buffer[i])] = 1;
        }

        for(i = 0; i < 52; i++)
        {
            if(bffO[i] == 1 && bffT[i] == 1)
            {
                j = (i+1);
            }
        }
        Psum += (long int)j;
        
        //printf("\nCommon value %d\n\n", j);
        memset(bffO, 0, sizeof(bffO));
        memset(bffT, 0, sizeof(bffT));

    }

    Psum = Psum - j;
    
    printf("Priority Sum = %d", Psum);


    fclose(pf);

    return 0;
}
