#include <gtest/gtest.h>
#include "Envio.h"

namespace {
  TEST(Envio_Test, Envio_FedEx_Test){
    /// AAA

    // Arrange
    Envio* fedex = new Envio(70, 14);

    // Act
    double actual = fedex->CalculoEnvio();
    double esperado = 45;
    
    // Assert
    EXPECT_EQ(esperado, actual);
  }

  TEST(Envio_Test, Envio_Postal_Test){
    /// AAA

    // Arrange
    Envio* postal = new Envio(30, 20, 1);

    // Act
    double actual = postal->CalculoEnvio();
    double esperado = 12;
    
    // Assert
    EXPECT_EQ(esperado, actual);
  }
}