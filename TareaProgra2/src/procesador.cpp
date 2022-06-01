#include "procesador.h"
#include <iostream>
#define IMPUESTO 7

Procesador::Procesador(){
}

Procesador::~Procesador(){
}

void Procesador::procesarArchivos(){
    this->leerPersonas();
    this->leerNomina();
    this->leerHoras();
    int contadorHoras = 0;
    for(int index = 0; index < personas.size(); index++){
        if(index == 0){
            arbol = new Arbol(stoi(personas[index][0]), personas[index][1], personas[index][2]
            , personas[index][3], stoi(personas[index][4]), stoi(personas[index][5]));
        } else {
            arbol->InsertarNodo(stoi(personas[index][0]), personas[index][1], personas[index][2]
            , personas[index][3], stoi(personas[index][4]), stoi(personas[index][5]));
        }
    }
    for(int index = 0; index < nominaV.size(); index++){
        Nodo* aux = arbol->getNodo(stoi(nominaV[index][0]));
        aux->setSalarioBruto(stod(nominaV[index][1]));
    }
    for(int index = 0; index < horasTrabajadas.size(); index++){
        Nodo* aux = arbol->getNodo(stoi(horasTrabajadas[index][0]));
        aux->setMontoHora(stod(horasTrabajadas[index][1]));
        aux->setHoras(stoi(horasTrabajadas[index][2]));
    }
    this->escribirCSV();
    personas.clear();
    nominaV.clear();
    horasTrabajadas.clear();
}

/*
  Lee el archivo personas.txt
  Separar las palabras por cada espacio en blanco
  Almacena las palabras separadas en vectores
*/
void Procesador::leerPersonas(){
    std::string linea = "";
    int posInit = 0;
    int posFound = 0;
    std::string splitted = "";
    lector.open("../archivos/personas.txt");
    if(lector.is_open()){
        while(getline(lector, linea)){
            std::vector<std::string> aux;
            posInit = 0;
            posFound = 0;
            splitted = "";
            while(posFound >= 0){
                posFound = linea.find(" ", posInit);
                splitted = linea.substr(posInit, posFound - posInit);
                posInit = posFound + 1;
                aux.push_back(splitted);
            }
            personas.push_back(aux);
            aux.clear();
            linea = "";
        }
        lector.close();
    }else{
        std::cerr<<"No se pudo abrir el archivo personas.txt"<<std::endl;
    }
}

/*
  Lee el archivo nomina.txt
  Separar las palabras por cada espacio en blanco
  Almacena las palabras separadas en vectores
*/
void Procesador::leerNomina(){
    std::string linea = "";
    int posInit = 0;
    int posFound = 0;
    std::string splitted = "";
    lector.open("../archivos/nomina.txt");
    if(lector.is_open()){
        while(getline(lector, linea)){
            std::vector<std::string> aux;
            posInit = 0;
            posFound = 0;
            splitted = "";
            while(posFound >= 0){
                posFound = linea.find(" ", posInit);
                splitted = linea.substr(posInit, posFound - posInit);
                posInit = posFound + 1;
                aux.push_back(splitted);
            }
            nominaV.push_back(aux);
            aux.clear();
            linea = "";
        }
        lector.close();
    }else{
        std::cerr<<"No se pudo abrir el archivo nomina.txt"<<std::endl;
    }
}

/*
  Lee el archivo personas.txt
  Separar las palabras por cada espacio en blanco
  Almacena las palabras separadas en vectores
*/
void Procesador::leerHoras(){
    std::string linea = "";
    int posInit = 0;
    int posFound = 0;
    std::string splitted = "";
    lector.open("../archivos/horastrabajadas.txt");
    if(lector.is_open()){
        while(getline(lector, linea)){
            std::vector<std::string> aux;
            posInit = 0;
            posFound = 0;
            splitted = "";
            while(posFound >= 0){
                posFound = linea.find(" ", posInit);
                splitted = linea.substr(posInit, posFound - posInit);
                posInit = posFound + 1;
                aux.push_back(splitted);
            }
            horasTrabajadas.push_back(aux);
            aux.clear();
            linea = "";
        }
        lector.close();
    }else{
        std::cerr<<"No se pudo abrir el archivo personas.txt"<<std::endl;
    }
}

/*
    Crea el archivo salida.csv
    Separa la información necesaria por persona
    Calcula el monto neto, subtotal, impuestos a retener y total
*/
void Procesador::escribirCSV(){
    //double total = 0;
    double subtotal = 0;
    double impuestos = 0;
    escritor.open("../archivos/salida.csv");
    if(!escritor.is_open()){
        std::cerr<<"No se pudo crear el archivo salida.csv"<<std::endl;
    } else {
        escritor << "ID Empleado;Nombre Completo;Email;Nombre de Supervisor;Monto a pagar\n";
        Nodo* aux;
        std::string linea = "";
        double calculo = 0;
        double calculoT = 0;
        for(int index = 1; index <= 600; index++){
            linea = "";
            aux = arbol->getNodo(index);
            if(aux->getTipo() == 1){
                if(aux->ObtenerID() == 1){
                    linea += std::to_string(aux->ObtenerID())+";";
                    linea += aux->getNombre()+" "+aux->getApellido()+";";
                    linea += aux->getEmail()+";";
                    linea += aux->getNombre()+" "+aux->getApellido()+";";
                    calculo = (aux->getSalarioBruto()*IMPUESTO)/100;
                    impuestos += calculo;
                    subtotal += aux->getSalarioBruto()-calculo;
                    linea += std::to_string(aux->getSalarioBruto()-calculo)+"\n";
                    escritor << linea;
                } else {
                    linea += std::to_string(aux->ObtenerID())+";";
                    linea += aux->getNombre()+" "+aux->getApellido()+";";
                    linea += aux->getEmail()+";";
                    linea += arbol->getNodo(aux->getIDPadre())->getNombre()+" "+
                    arbol->getNodo(aux->getIDPadre())->getApellido()+";";
                    calculo = (aux->getSalarioBruto()*IMPUESTO)/100;
                    impuestos += calculo;
                    subtotal += aux->getSalarioBruto()-calculo;
                    linea += std::to_string(aux->getSalarioBruto()-calculo)+"\n";
                    escritor << linea;
                }
            } else {
                linea += std::to_string(aux->ObtenerID())+";";
                linea += aux->getNombre()+" "+aux->getApellido()+";";
                linea += aux->getEmail()+";";
                linea += arbol->getNodo(aux->getIDPadre())->getNombre()+" "+
                arbol->getNodo(aux->getIDPadre())->getApellido()+";";
                calculoT = aux->getMontoHoras()*aux->getHoras();
                subtotal += calculoT;
                linea += std::to_string(calculoT)+"\n";
                escritor << linea;
            }
        }
    }
    escritor << " ; ; ;Subtotal;";
    escritor << std::to_string(subtotal);
    escritor << "\n";
    escritor << " ; ; ;Impuestos a retener;";
    escritor << std::to_string(impuestos);
    escritor << "\n";
    escritor << " ; ; ;Total;";
    escritor << std::to_string(subtotal + impuestos);
    escritor << "\n";
    escritor.close();
}