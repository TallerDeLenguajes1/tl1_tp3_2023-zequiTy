#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct  Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
 }Cliente;


void cargarDatos(Cliente * nCliente, int cant);
void cargarProducto(Producto * productos, int cantProductos);
float precioProducto(int cantidad, float precio);
void mostrarDatos(Cliente * nCliente, int cant);
void vaciarMemoria(Cliente * nCliente, int cant);


int main(){


srand(time(NULL));

int cantClientes;
int aux = 0;
Cliente * usuario;

    while (aux == 0)
    {
        printf("Ingrese cantidad de clientes:\n");
        scanf("%d", &cantClientes);
        

        if (cantClientes<=5)
        {
            usuario =(Cliente*)malloc(sizeof(Cliente)*cantClientes);
            
   cargarDatos(usuario, cantClientes);
    mostrarDatos(usuario, cantClientes);
            aux = 1;
        }else
        {
            printf("La cantidad de clientes es superior a 5.\n");
            printf("Ingrese cantidad de clientes:\n");
            scanf("%d", &cantClientes);
        
        }
        
        

    }
    
    vaciarMemoria(usuario, cantClientes);

    return 0;
}

void cargarDatos(Cliente * nCliente, int cant){

char * aux = malloc(sizeof(char)*30);
int tipo = 0;
int cantProdct=0;

    for (int i = 0; i < cant; i++)
    {
        nCliente[i].ClienteID = i+1;

        printf("%d° cliente\n", nCliente[i].ClienteID);
        printf("Nombre:\n");
        fflush(stdin);
        gets(aux);

        nCliente[i].NombreCliente = (char*)malloc(sizeof(char)*strlen(aux));

        strcpy(nCliente[i].NombreCliente, aux);

        nCliente[i].CantidadProductosAPedir = rand()%5+1;

        cantProdct = nCliente[i].CantidadProductosAPedir;

        nCliente[i].Productos = (Producto*)malloc(nCliente[i].CantidadProductosAPedir*sizeof(Producto));

           cargarProducto(nCliente[i].Productos, cantProdct);
        
        
        
    }

    free(aux);
    
}

void cargarProducto(Producto * productos, int cantProductos){

for (int j = 0; j < cantProductos; j++)
{
    productos[j].ProductoID = 1+j;
    productos[j].Cantidad = rand()%10+1;
    productos[j].PrecioUnitario =(rand()%901+100)/10;
    productos[j].TipoProducto = (char*)malloc(sizeof(char)*20);
    productos[j].TipoProducto = *(TiposProductos + rand()%5);
}


}

float precioProducto(int cantidad, float precio){

return(cantidad*precio);

}
void mostrarDatos(Cliente * nCliente, int cant){

float total = 0;

    for (int l = 0; l < cant; l++)
    {
       printf("CLIENTE:\n");
       printf("ID:%d\n", nCliente[l].ClienteID);
       printf("Nombre: %s\n", nCliente[l].NombreCliente);
       printf("Cantidad de productos: %d\n", nCliente[l].CantidadProductosAPedir);

       for (int k = 0; k < nCliente[l].CantidadProductosAPedir; k++)
       {
        printf("ID del productp: %d\n", nCliente[l].Productos[k].ProductoID);
        printf("Cantidad: %d\n",nCliente[l].Productos[k].Cantidad);
        printf("Precio unitario: %.2f\n", nCliente[l].Productos[k].PrecioUnitario);
        printf("Tipo: %s\n",nCliente[l].Productos[k].TipoProducto);

        total = total + precioProducto(nCliente[l].Productos[k].Cantidad, nCliente[l].Productos[k].PrecioUnitario);

       }
       
        printf("Total a pagar: %.2f\n", total);

    }
    
}

void vaciarMemoria(Cliente * nCliente, int cant){


    for (int i = 0; i < cant; i++)
    {

        free(nCliente->Productos);

        nCliente++;
    }

    
}
/*
 for (int i = 0; i < cant; i++)
    {
       printf("CLIENTE:\n");
       printf("ID:%d\n", nCliente->ClienteID);
       printf("Nombre: %s\n", nCliente->NombreCliente);
       printf("Cantidad de productos: %d\n", nCliente->CantidadProductosAPedir);

       for (int k = 0; k < nCliente->CantidadProductosAPedir; k++)
       {
        printf("ID del productp: %d\n", nCliente->Productos[k].ProductoID);
        printf("Cantidad: %d\n",nCliente->Productos[k].Cantidad);
        printf("Precio unitario: %.2f\n", nCliente->Productos[k].PrecioUnitario);
        printf("Tipo: %s\n",nCliente->Productos[k].TipoProducto);

        total = total + precioProducto(nCliente->Productos[k].Cantidad, nCliente->Productos[k].PrecioUnitario);

       }
       
        printf("Total a pagar: %.2f\n", total);

       nCliente++;

    }*/