#include "arbol.h"
#include "nodo.h"

Arbol::Arbol(int idNodoRaiz, string nombre, string apellido, string email, 
    int tipo, int idNodoPadre)
{
    // Agregar nodo raíz
    this->raiz = new Nodo(idNodoRaiz, nombre, apellido, email, 
    tipo);
    this->indiceNodos.insert( std::pair<int, Nodo *>(idNodoRaiz, this->raiz) );
}

Arbol::~Arbol()
{
    delete this->raiz;
}

void Arbol::InsertarNodo(int nuevoID, string nombre, string apellido, string email, 
    int tipo, int idPadre)
{
    Nodo *nuevoNodo = new Nodo(nuevoID, nombre, apellido, email, tipo);

    // Quién es el padre?
    Nodo *nodoPadre = this->indiceNodos.at(idPadre);

    nodoPadre->InsertarHijo(nuevoNodo);
    nuevoNodo->AsignePadre(nodoPadre);

    // Agregar nuevo nodo al índice
    this->indiceNodos.insert( std::pair<int, Nodo *>(nuevoID, nuevoNodo) );
}

Nodo* Arbol::getNodo(int idNodo)
{
    Nodo* nodoConElValor = this->indiceNodos.at(idNodo);
    return nodoConElValor;
}