#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
// #include "funciones.h"

#define MAX 20
#define VACIO 0
#define ACTIVO 1
#define BORRADO 2

struct agenda
{
    char nombre[50];
    long int dni;
    char email[25];
    char direccion[20];
    int edad;
    int estado;
};

typedef struct agenda agenda;


void menu();
void inicializador(agenda datos[20]);
agenda datos[20];

void alta(agenda datos[20]);
void baja(agenda datos[20]);
void mostrar(agenda datos[20]);
void mostrarActivos(agenda datos[20]);
void grafico(agenda datos[20]);
void buscar(agenda datos[20]);
int main()
{


    
    inicializador(datos);

    int op = 0;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1 : alta(datos); break;
            case 2 : baja(datos); break;
            case 3 : buscar(datos); break;
            case 4 : mostrarActivos(datos); break;
            case 5 : mostrar(datos); break;
            case 6 : grafico(datos);break;
            case 7: op=7; break;
            system("cls");
        }

    }while(op!= 7);
    return 0;
}

void inicializador(agenda datos[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(datos[i].nombre, "");
        datos[i].dni = 0;
        strcpy(datos[i].email, "NULA");
        strcpy(datos[i].direccion, "NULA");
        datos[i].edad = 0;
        datos[i].estado = VACIO;
    }
}

void menu(){
    system("color 17");
    printf("                                                                                                                    \n");
    printf("                                             Elija una opcion \a                                                    \n");
    printf("                                                                                                                    \n");
    printf("                                             1.Agregar persona                                                      \n");
    printf("                                                                                                                    \n");
    printf("                                             2.Borrar persona                                                       \n");
    printf("                                                                                                                    \n");
    printf("                                             3.Busqueda de nombre                                                   \n");
    printf("                                                                                                                    \n");
    printf("                                             4.Activos                                                              \n");
    printf("                                                                                                                    \n");
    printf("                                             5.Imprimir lista ordenada por  nombre                                  \n");
    printf("                                                                                                                    \n");
    printf("                                             6.Imprimir grafico                                                     \n");
    printf("                                                                                                                    \n");
    printf("                                             7.Salir                                                                \n");
    printf("                                                                                                                    \n");
    printf("                                                                                                                      \n");
    printf("                                           Seleccione una opcion: " );
}

void alta(agenda datos[20]);
void baja(agenda datos[20]);
void mostrar(agenda datos[20]);
void mostrarActivos(agenda datos[20]);
void grafico(agenda datos[20]);
void buscar(agenda datos[20]);

void alta(agenda datos[MAX])
{
    system("cls");
    printf("\n                                               1.Agregar Registro                                                 \n");
    for (int i = 0; i < MAX; i++)
    {
        if (datos[i].estado == VACIO)
        {
            fflush(stdin);
            printf("\n                   ******** Ingrese nombre y apellido : ");

            scanf("%s", datos[i].nombre);
            fflush(stdin);

            printf("\n                   ******** Ingrese numero de DNI: ");
            scanf("%ld", &datos[i].dni);

            fflush(stdin);

            printf("\n                   ******** Ingrese email: ");
            scanf("%s", &datos[i].email);

            fflush(stdin);
            printf("\n                   ******** Ingrese direccion : ");
            scanf("%s", datos[i].direccion);

            fflush(stdin);
            printf("\n                   ******** Ingrese edad : ");
            scanf("%d", &datos[i].edad);

            printf("\n                                      Ingresado correctamente\n ");
            printf("                                                                                                                    \n");
            system("pause");
            system("cls");

            datos[i].estado = ACTIVO;

            break;
        }
    }
}

void baja(agenda datos[MAX])
{
    system("cls");
    char aux[10];
    fflush(stdin);
    printf("                                                                   \n");
    printf("                                                 2.borrado         \n");
    printf("\n                      *******>   Ingrese el nombre que quiere eliminar:   ");
    scanf("%s", aux);
    system("cls");
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(datos[i].nombre, aux) == 0)
        {
            datos[i].estado = BORRADO;
        }
    }
    printf("                                                                   \n");
    printf("                                                 Borrado           \n");
}

void buscar(agenda datos[MAX])
{
    char busca[20];
    int i;

    // system("cls");

    fflush(stdin);
    system("cls");
    printf("                                                                   \n");
    printf("                                3.Buscar contacto                  \n");
    printf("                                Ingrese nombre del contacto: ");
    gets(busca);

    for (i = 0; i < MAX; i++)
    {
        if (strcmpi(busca, datos[i].nombre) == 0)
        {
            printf("\n                        Nombre del contacto: %s\n\n", datos[i].nombre);
            printf("                          DNI: %ld\n\n", datos[i].dni);
            printf("                          Email: %s\n\n", datos[i].email);
            printf("                          Direccion: %s\n\n", datos[i].direccion);
            printf("                          Edad: %d\n\n", datos[i].edad);
        }
    }
    system("pause");
    system("cls");
}

void mostrar(agenda datos[MAX])
{
    system("cls");
    int i, j;
    char auxc[50], aux;

    for (i = 0; i < MAX - 1; i++)
    {
        for (j = 0; j < MAX - 1 - i; j++)
        {
            if (strcmp(datos[j].nombre, datos[j + 1].nombre) > 0)
            {

                strcpy(auxc, datos[j].nombre);
                strcpy(datos[j].nombre, datos[j + 1].nombre);
                strcpy(datos[j + 1].nombre, auxc);
            }
        }
    }

    printf("         5.Agenda ordenanda alfabeticamente        \n ");

    for (i = 0; i < MAX; i++)
    {

        if (strcmp(datos[i].nombre, "") != 0)
        {
            printf("\n      *******>    Nombre: %s\n", datos[i].nombre);
        }

        // printf("DNI: %l\n", datos[i].dni);
        // printf("E-mail: %d\n", datos[i].email);
        // printf("Dirección: %s\n", datos[i].direccion);
        // printf("Edad: %s\n", datos[i].edad);
        // printf("Estado: %s\n", datos[i].estado);
    }
    system("pause");
    system("cls");
}

void mostrarActivos(agenda datos[20])
{
    system("cls");
    printf("                                             4.Activos              \n");
    for (int i = 0; i < MAX; i++)
    {
        if (datos[i].estado == ACTIVO)
        {
            printf("\nNombre del contacto: %s\n", datos[i].nombre);
            printf("DNI: %ld\n", datos[i].dni);
            printf("Email: %s\n", datos[i].email);
            printf("Direccion: %s\n", datos[i].direccion);
            printf("Edad: %d\n", datos[i].edad);
        }
    }
    system("pause");
    system("cls");
}

void grafico(agenda datos[20])
{
    system("cls");
    int i, j, mayor = 0, fila;
    int arrayOrdenado[3];

    printf("                 6. Representacion de edades             \n ");
    printf("                        G R A F I C O                    \n\n\n\n");

    for (i = 0; i < 3; i++)
    {
        arrayOrdenado[i] = 0;
    }

    for (i = 0; i < MAX; i++)
    {
        if (datos[i].edad > 0 && datos[i].edad < 19 && datos[i].nombre != "")
        {
            arrayOrdenado[0]++;
        }
        else
        {
            if (datos[i].edad > 18 && datos[i].edad < 36 && datos[i].nombre != "")
            {
                arrayOrdenado[1]++;
            }
            if (datos[i].edad > 35 && datos[i].nombre != "")
            {
                arrayOrdenado[2]++;
            }
        }
    }

    if (arrayOrdenado[0] >= arrayOrdenado[1] && arrayOrdenado[0] >= arrayOrdenado[2])
    {
        mayor = arrayOrdenado[0];
    }
    else
    {
        if (arrayOrdenado[1] >= arrayOrdenado[0] && arrayOrdenado[1] >= arrayOrdenado[2])
        {
            mayor = arrayOrdenado[1];
        }
        if (arrayOrdenado[2] >= arrayOrdenado[0] && arrayOrdenado[2] >= arrayOrdenado[1])
        {
            mayor = arrayOrdenado[2];
        }
    }
    fila = mayor;

    for (i = 0; i < mayor; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arrayOrdenado[j] >= fila)
            {
                printf("  |**|**|\t\t");
            }
            else
            {
                printf(" \t");
            }
        }
        fila--;
        printf("\n");
    }

    printf("-18      Entre 19 & 35       +35\n\n");
    system("pause");
    system("cls");
}
