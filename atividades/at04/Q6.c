#include <stdio.h>
#define NUM_LETRAS 3
void ler3letras();
/*Definição de uma struct*/
typedef struct
{
    char Letra[NUM_LETRAS];
}registro;
registro No;
/************************/

int main(void)
{
    ler3letras();
    printf("\n======Letras======\n");
    for (int jContador = 0; jContador < NUM_LETRAS; jContador++)
    {
        printf("%c", No.Letra[jContador]);
        if(jContador < NUM_LETRAS - 1)
            printf(" | ");
    }
    printf("\n");
    return 0;
}

void ler3letras()
{
    int iContador = 0;
    while(iContador < NUM_LETRAS)
    {
        printf("Digite uma letra: ");
        No.Letra[iContador] = getchar();
        /*Pular uma linha do input para evitar leitura do char '\n'*/
        while(getchar() != '\n' );
        iContador++;
    }
}