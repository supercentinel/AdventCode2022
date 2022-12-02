#include <stdio.h>
#include <stdlib.h>

/*
A -- X Piedra 1
B -- Y Papel 2
C -- Z tijeras 3

Pierdo = 0
Empate = 3
Gano = 6

*/

int jajanken(char rv, char me)
{
    rv = rv + 23;
    if(rv == me)
    {
        printf(" Tie\n");
        return 3 + (me - 87);
    }
    if ((me == 90 && rv == 88))
    {
        printf(" Lose\n");
        return 0 + (me - 87);
    }
    
    if (rv < me || (me == 88 && rv == 90))
    {
        printf(" Win\n");
        return 6 + (me - 87);
    }
    else
    {
        printf(" Lose\n");
        return 0 + (me - 87);
    }

}

int main(int argc, char const *argv[])
{
    FILE *pf;
    char elf, me;
    int score = 0, totalScore = 0;


    if((pf = fopen("input.txt", "r")) == NULL)return -1;

    while (!feof(pf))
    {

        if((elf = fgetc(pf)) == EOF) break; 
        fgetc(pf);
        me = fgetc(pf);
        fgetc(pf);
        printf("elf: %c, me: %c", elf, me);
        score = jajanken(elf, me);
        totalScore += score;
        printf("match score : %d\n", score);

    }
    
    printf("Total score: %d\n" ,totalScore);

    fclose(pf);

    return 0;
}
