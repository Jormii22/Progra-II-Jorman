#include <iostream>
#include "Envio.h"
#include <vector>

int main() {
  std::vector<Envio*> arregloEnvios;
  arregloEnvios.resize(6);
  arregloEnvios[0] = new Envio(30, 20, 3);//punteros sin inicializar
  arregloEnvios[1] = new Envio(15, 12, 2);
  arregloEnvios[2] = new Envio(16, 8, 1);
  arregloEnvios[3] = new Envio(9, 7, 3);
  arregloEnvios[4] = new Envio(6, 13, 2);
  arregloEnvios[5] = new Envio(14, 20, 1);
  
  for (Envio* envio : arregloEnvios) {
    if (envio->getTipo() == 1) { //decide el tipo de envio que se utiliza
      std::cout<<"Envio tipo Postal: "<<envio->CalculoEnvio()<<std::endl;
    } else {
      std::cout<<"Envio tipo FedEx: "<<envio->CalculoEnvio()<<std::endl;
    }
  }
}