#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContieneA(char *fr, char *sr)
{
    char *frn[2], *srn[2];
    int fri[2] = {0}, sri[2] = {0};
    int i, fril[2] = {0}, sril[2] = {0};
    
    for (i = 0; i < strlen(fr); i++)
    {
        if(fr[i] == '-') break;
        fril[0]++;
    }

    fril[1] = strlen(fr) - fril[0] - 1;

    for (i = 0; i < strlen(sr); i++)
    {
        if(sr[i] == '-') break;
        sril[0]++;
    }

    sril[1] = strlen(sr) - sril[0] - 1;

    //printf("%d/%d %s\n", fril[0], fril[1], fr);
    //printf("%d/%d %s\n", sril[0], sril[1], sr);

    if((frn[0] = (char *)calloc(fril[0], sizeof(char))) == NULL) return 42069;
    if((frn[1] = (char *)calloc(fril[1], sizeof(char))) == NULL) return 42069;
    if((srn[0] = (char *)calloc(sril[0], sizeof(char))) == NULL) return 42069;
    if((srn[1] = (char *)calloc(sril[1], sizeof(char))) == NULL) return 42069;

    for ( i = 0; i < fril[0]; i++)
    {
        frn[0][i] = fr[i];
    }
    
    for (i = 0; i < fril[1]; i++)
    {
        frn[1][i] = fr[fril[0]+1+i];
    }

    for ( i = 0; i < sril[0]; i++)
    {
        srn[0][i] = sr[i];
    }
    
    for (i = 0; i < sril[1]; i++)
    {
        srn[1][i] = sr[sril[0]+1+i];
    }

    //printf("[%s-%s]\n", frn[0], frn[1]);
    //printf("[%s-%s]\n", srn[0], srn[1]);

    fri[0] = atoi(frn[0]);
    fri[1] = atoi(frn[1]);

    sri[0] = atoi(srn[0]);
    sri[1] = atoi(srn[1]);

    //printf("[%d-%d]\n", fri[0], fri[1]);
    //printf("[%d-%d]\n", sri[0], sri[1]);

    if(fri[0] >= sri[0] && fri[1] <= sri[1])
    {
        return 1;
    }
    if(sri[0] >= fri[0] && sri[1] <= fri[1])
    {
        return 1;
    }    

    return 0;
    
}

int main()
{
    FILE *pf;
    int i, frs = 0, srs = 0, sum = 0;
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
            if(buff[i] == ',') break;
            fr[i] = buff[i];
        }

        //printf("\n%c\n", buff[i]);
    
        for (i = 0; i < srs; i++)
        {
            sr[i] = buff[frs+1+i];
        }        
   
        //printf("%d/%d ", frs, srs);
        //printf("%s,%s----%s", fr, sr, buff);
        sum += ContieneA(fr, sr);

        free(fr);
        free(sr);
        fgets(buff, 49, pf);

    }

    printf("%d", sum);
    
    fclose(pf);

    return 0;
}
