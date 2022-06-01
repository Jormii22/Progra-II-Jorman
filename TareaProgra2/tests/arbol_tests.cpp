#include <gtest/gtest.h>
#include "../src/arbol.h"

namespace
{
    TEST(Arbol_Test, Test_Agregar_Raiz)
    {
        /// AAA

        // Arrange - configurar el escenario
        

        // Act - ejecute la operación
        Arbol *arbol = new Arbol(1, 2);

        int actual = arbol->ObtenerValor(1);
        int esperada = 2;

        delete arbol;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Arbol_Test, Test_Agregar_Valor_No_Raiz)
    {
        /// AAA

        // Arrange - configurar el escenario
        Arbol *arbol = new Arbol(1, 2);

        // Act - ejecute la operación
        arbol->InsertarValor(2, 7, 1);

        int actual = arbol->ObtenerValor(2);
        int esperada = 7;

        delete arbol;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }



}