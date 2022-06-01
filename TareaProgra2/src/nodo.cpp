#include "nodo.h"

Nodo::Nodo(int id, string nombre, string apellido,
 string email, int tipoN){
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipo = tipoN;
}

Nodo::~Nodo() 
{
    for (Nodo *hijo : this->hijos)
    {
        delete hijo;
    }
}

void Nodo::InsertarHijo(Nodo *hijo)
{
    this->hijos.push_back(hijo);
}

int Nodo::ObtenerID()
{
    return this->id;
}

int Nodo::getIDPadre(){
    return this->padre->ObtenerID();
}

string Nodo::getNombre(){
    return this->nombre;
}

string Nodo::getApellido(){
    return this->apellido;
}

string Nodo::getEmail(){
    return this->email;
}

int Nodo::getTipo(){
    return this->tipo;
}

double Nodo::getSalarioBruto(){
    return this->salarioBruto;
}

double Nodo::getMontoHoras(){
    return this->montoHora;
}

int Nodo::getHoras(){
    return this->horas;
}

void Nodo::AsignePadre(Nodo *padre)
{
    this->padre = padre;
}

vector<Nodo *> Nodo::ObtenerHijos()
{
    return this->hijos;
}

void Nodo::setSalarioBruto(double salario){
    this->salarioBruto = salario;
}

void Nodo::setMontoHora(double montoHora){
    this->montoHora = montoHora;
}

void Nodo::setHoras(int horas){
    this->horas = horas;
}