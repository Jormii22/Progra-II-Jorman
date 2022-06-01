#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"
#include <map>

using namespace std;

class Arbol {
    Nodo *raiz;

    map<int, Nodo *> indiceNodos;

    public:
    Arbol(int idNodoRaiz, string nombre, string apellido, string email, 
    int tipo, int idNodoPadre);
    ~Arbol();

    void InsertarNodo(int idNodoRaiz, string nombre, string apellido, string email, 
    int tipo, int idNodoPadre);
    Nodo* getNodo(int id);
};

#endif