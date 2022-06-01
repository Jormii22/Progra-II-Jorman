#include <gtest/gtest.h>
#include "../src/nodo.h"

namespace
{
    TEST(Nodo_Test, Test_Creacion_Nodo)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        Nodo *nodo = new Nodo(1, 2);        

        int idActual = nodo->ObtenerID();
        int idEsperada = 1;

        int valorActual = nodo->ObtenerValor();
        int valorEsperado = 2;

        delete nodo;

        // Assert - valide los resultados
        EXPECT_EQ(idEsperada, idActual);
        EXPECT_EQ(valorEsperado, valorActual);
    }

    TEST(Nodo_Test, Test_Agregar_Nodo_Hijo)
    {
        /// AAA

        // Arrange - configurar el escenario
        Nodo *nodoPadre = new Nodo(1, 2);     

        // Act - ejecute la operación
        Nodo *nodoHijoEsperado = new Nodo(2, 7);   
        nodoPadre->InsertarHijo(nodoHijoEsperado);

        // Assert - valide los resultados
        vector<Nodo *> hijos = nodoPadre->ObtenerHijos();
        Nodo *nodoHijoActual = hijos[0];

        EXPECT_EQ(nodoHijoEsperado, nodoHijoActual);

        delete nodoHijoEsperado;
        delete nodoPadre;
    }
}