#include "Envio.h"

Envio::Envio(double peso, double kilometros, int clase){
  this->peso = peso; // definir variables
  this->kilometros = kilometros;
  this->clase = clase;
  this->tipoEnvio = 1;
}

Envio::Envio(double peso, double kilometros){
  this->peso = peso;
  this->kilometros = kilometros;
  this->clase = 0;
  this->tipoEnvio = 2;
}

double Envio::CalculoEnvio(){
  double total = 0;
  switch(this->tipoEnvio){ // decide el tipo de envio al ver la cantidad de parametros que se usan en el main, 2 para fedex y 3 para postal
    case 1: if(clase == 3){ //
              total+=(kilometros*0.0120);
            } else if(clase == 2){
              if(peso <= 3){
                total += (kilometros*0.0280);
              } else if ((peso > 4 || peso == 4) && (peso < 8 || peso == 8)){
                total += (kilometros*0.0530);
              } else {
                total += (kilometros*0.0750);
              }
            } else {
              if(peso <= 3){
                total += (kilometros*0.300);
              } else if ((peso > 4 || peso == 4) && (peso < 8 || peso == 8)){
                total += (kilometros*0.450);
              } else {
                total += (kilometros*0.600);
              }
            }
      break;
    case 2: total += 35;
            if(kilometros > 500){
              total+=15;
            }
            if(peso > 10){
              total+=10;
            }
      break;
  }
  return total;
}
