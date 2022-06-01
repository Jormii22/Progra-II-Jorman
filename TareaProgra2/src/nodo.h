#ifndef NODO_H
#define NODO_H

#include <vector>
#include <string>

using namespace std;

class Nodo {
  private:
    int id;
    std::string nombre; 
    std::string apellido;
    string email;
    int tipo;
    double salarioBruto = 0;
    double montoHora = 0;
    int horas = 0;
    vector<Nodo *> hijos;
    Nodo *padre;

    public:
    Nodo(int id, string nombre, string apellido, string email, 
    int tipo);
    ~Nodo();

    void InsertarHijo(Nodo *hijo);
    
    int ObtenerID();
    void AsignePadre(Nodo *padre);
    int getIDPadre();
    void setSalarioBruto(double salario);
    void setMontoHora(double montoHora);
    void setHoras(int horas);
    string getNombre();
    string getApellido();
    string getEmail();
    int getTipo();
    double getSalarioBruto();
    double getMontoHoras();
    int getHoras();
    vector<Nodo *> ObtenerHijos();
};

#endif