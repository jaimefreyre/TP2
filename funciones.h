#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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
// agenda datos[20];

void alta(agenda datos[20]);
void baja(agenda datos[20]);
void mostrar(agenda datos[20]);
void mostrarActivos(agenda datos[20]);
void grafico(agenda datos[20]);
void buscar(agenda datos[20]);

#endif // FUNCIONES_H_INCLUDED