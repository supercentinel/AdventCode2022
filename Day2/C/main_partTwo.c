#include <stdio.h>
#include <stdlib.h>

/*
A Piedra 1
B Papel 2
C tijeras 3

Pierdo = 0 -> X
Empate = 3 -> Y
Gano = 6 -> Z

*/

int jajanken(char rv, char me)
{
    /*
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
    */
    switch (me)
    {
    case 'X':
        printf("Lose\n");
        switch (rv)
        {
        case 'A':
            return 0 + ('C' - 64);
        break;
        case 'B':
            return 0 + ('A' - 64);
        break;
        case 'C':
            return 0 + ('B' - 64);
        break;
        }
    break;
    case 'Y':
        printf("Tie\n");
        return 3 + (rv - 64);
    break;
    case 'Z':
        printf("Win\n");
        switch (rv)
        {
        case 'A':
            return 6 + ('B' - 64);
        break;
        case 'B':
            return 6 + ('C' - 64);
        break;
        case 'C':
            return 6 + ('A' - 64);
        break;
        
        default:
            break;
        }
    break;

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
