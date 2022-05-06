#ifndef ENVIO_H
#define ENVIO_H

class Envio{
  //Variables
  private:
    double peso;
    double kilometros;
    int clase;
    int tipoEnvio;
  //Métodos
  public:
    Envio(double peso, double kilometros, int clase);
    Envio(double peso, double kilometros);
    ~Envio(){};
    double CalculoEnvio(); 
    int getTipo(){ return tipoEnvio; };
};

#endif //ENVIO_H
