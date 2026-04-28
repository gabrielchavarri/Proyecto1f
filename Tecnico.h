#ifndef PROYECTO1F_TECNICO_H
#define PROYECTO1F_TECNICO_H

#include <string>
using namespace std;

class Tecnico {
private:
    string nombre;
    bool disponible;

public:
    Tecnico(const string& nombre);
    string getNombre() const;
    bool isDisponible() const;
    void asignar();
    void liberar();
};

#endif