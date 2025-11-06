#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int* numeros = (int*) malloc(3 * sizeof(int));
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;
    printf("\n\n\n%d\n\n\n", numeros[2]);

    numeros = (int*) realloc(numeros, 5 * sizeof(int));
    numeros[3] = 40;
    numeros[4] = 50;
    printf("\n\n\n%d\n\n\n", numeros[4]);
    return 0;
}
