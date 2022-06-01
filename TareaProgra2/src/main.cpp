#include "procesador.h"

int main() {
    //Se crea el procesador de archivos
    Procesador* procesador = new Procesador();
    procesador->procesarArchivos();
    return 0;
}