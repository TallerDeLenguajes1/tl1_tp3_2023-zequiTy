
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 5;

int main(){

 
char **v = (char**)malloc(sizeof(char)*5);

for (int i = 0; i < 5; i++)
{
    v[i]=(char*)malloc(sizeof(char)*40);

     printf("Ingrese el %d° nombre\n", i+1);
     gets(v[i]);
     //scanf("%s", &v[i]);

    
}

for (int i = 0; i < 5; i++)
{
    printf("El %d° nombre es:\n", i+1);
     puts(v[i]);
    // printf("El %d nombre es: %s\n", i+1, v[i]);
}



    return 0;
}

