
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//void MaxMin( int matriz[][]);

int main(){

    int matriz[5][12];
    int auxsuma = 0;
    int max = 0;
    int min = 0;
    int mesMax = 0;
    int anioMax = 0;
    int mesMin = 0;
    int anioMin = 0;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;
            printf("Ganancias del  %d° año: %d\n",i+1, matriz[i][j]);
        }
        

    }
    
   for (int i = 0; i < 5; i++)
   {

    for (int j = 0; j < 12; j++)
    {
       auxsuma = auxsuma + matriz[i][j]; 
    }
      auxsuma = auxsuma / 12;

      printf("Promedio del año %d°: %d\n",i+1, auxsuma);
   }
   
    max = matriz[0][0];
    min = matriz[0][0];

  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 12; j++)
    {
        if (matriz[i][j] > max)
        {
          max = matriz[i][j];
          anioMax = i+1;
        mesMax = j+1;
        }
        
             

        if (matriz[i][j] < min)
        {
            min = matriz[i][j];
             anioMin = i+1;
            mesMin = j+1;
        }
        
        
           
        
        
        
 }        
   
    }

printf("La ganancia maxima es correspondiente al mes %d del %d° año\n", mesMax, anioMax);
 printf("La ganancia min es correspondiente al mes %d del %d° año\n", mesMin, anioMin);   
 printf("Ganancia maxima: %d\n", max);
 printf("Ganancia minima: %d\n", min); 

    return 0;
}

