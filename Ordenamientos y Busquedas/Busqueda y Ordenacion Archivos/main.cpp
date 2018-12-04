#include <cstdlib>
#include "Archivos.h"
#include "main.h"

int main(int argc, char *argv[])
{
    int ced;
    Archivo<Alumno> arc("datos.txt", funcion);
    arc.Abrir(ios::in);
    arc.Ordenar();
    arc.Cerrar();
    system("PAUSE");
    return EXIT_SUCCESS;
}
