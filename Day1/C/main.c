#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *pTfl;
    char s[10];
    int Et = 0, EMax = 0, EMax2, EMax3, aux =0;

    if((pTfl = fopen("input.txt", "r")) == NULL) return -1;

    while (!feof(pTfl))
    {
        fgets(s, 9, pTfl);

        aux = atoi(s);

        Et += aux;

        if(strcmp("\n", s) == 0)
        {
            if (Et > EMax)
            {
                EMax3 = EMax2;
                EMax2 = EMax;
                EMax = Et;
            }

            Et = 0;

        }
    }
    
    printf("ELF WITH MOST CAL = %d\n", EMax);
    printf("SECOND ELF WITH MOST CAL = %d\n", EMax2);
    printf("THIRD ELF WITH MOST CAL = %d\n", EMax3);

    printf("TOP TOTAL = %d\n", EMax + EMax2 + EMax3);
    
    fclose(pTfl);

    return 0;
}
