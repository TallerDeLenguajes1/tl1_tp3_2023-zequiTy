

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 5;

int main(){

 char *v[5];
 char *aux;

int p;

//v = (char *)malloc(sizeof(char) * 5);
aux = (char *)malloc(sizeof(char) * 40);
for (int i = 0; i < 5; i++)
{
    printf("Ingrese el %d° nombre:\n", i+1);
        gets(aux);

    p = strlen(aux);

    v[i] = malloc(sizeof(char)*p);

    strcpy(v[i], aux);
    
    
}

for (int i = 0; i < 5; i++)
{
        printf("El %d nombre es: %s\n", i+1, v[i]);
    
    
}




    return 0;
}
