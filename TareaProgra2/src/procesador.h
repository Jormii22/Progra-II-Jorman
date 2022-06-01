#ifndef PROCESADOR_H
#define PROCESADOR_H

#include "arbol.h"
#include <fstream>
#include <vector>
#include <string>

class Procesador{
    private:
        Arbol* arbol;
        std::ifstream lector;
        std::ofstream escritor;
        std::vector<std::vector<std::string>> personas;
        std::vector<std::vector<std::string>> nominaV;
        std::vector<std::vector<std::string>> horasTrabajadas;
    public:
        Procesador();
        ~Procesador();
        void procesarArchivos();
        void leerPersonas();
        void leerNomina();
        void leerHoras();
        void escribirCSV();
};

#endif //PROCESADOR_H