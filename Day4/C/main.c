#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pf;
    int i, frs, srs, fg;
    char buff[50], *fr, *sr;
    
    if((pf = fopen("input.txt", "r")) == NULL) return 1;

    fgets(buff, 49, pf);

    while (!feof(pf))
    {
        frs = 0;
        srs = 0;

        for( i = 0; i < strlen(buff); i++)
        {
            if (buff[i] == ',') break;
            frs++;
        }
        
        srs = strlen(buff) - frs - 2;

        if((fr = (char *)calloc(frs, sizeof(char))) == NULL) return 1;
        if((sr = (char *)calloc(srs, sizeof(char))) == NULL) return 1;

        for (i = 0; i < frs; i++)
        {
            if(buff[i] == ',')
            {
                fg = i;
                break;
            }
            
            fr[i] = buff[i];
        }

        //printf("\n%c\n", buff[i]);

        for (i = srs+1; i < strlen(buff)-1; i++)
        {
            printf("%c\n", buff[i]);
            //printf("d%c\n", buff[i]);
            if(buff[i] == '\n') break;
            //sr[i] = buff[i];
        }        
        
        printf("%d/%d ", frs, srs);
        printf("%s,%s----%s", fr, sr, buff);
        free(fr);
        free(sr);
        fgets(buff, 49, pf);

    }
    



    fclose(pf);

    return 0;
}
