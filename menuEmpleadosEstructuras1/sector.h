#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

#endif // SECTOR_H_INCLUDED

int cargarDescripcionSector(int id, eSector sectores[], int tam, char desc[]);

void mostrarSectores(eSector sectores[], int tam);

void mostrarSector(eSector sector);

int validarIdSector(int id, eSector sectores[], int tam);
