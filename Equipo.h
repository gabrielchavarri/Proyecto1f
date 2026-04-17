//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_EQUIPO_H
#define PROYECTO1F_EQUIPO_H
#include <string>
#include "Incidencia.h"
#include "MantStrategy.h"
using namespace std;

class Equipo {
protected:
    string id;
    float criticidad;
    float estado;
    int tiempo_inactivo;
    Incidencia* incidencias[50];
    int totalIncidencias;
    MantStrategy* strategy;

public:
    Equipo(const string& id, float criticidad, float estado);
    virtual ~Equipo();

    float calcularPrioridad() const;
    void degradar();

    virtual void aplicarMant() = 0;
    virtual string getTipo() const = 0;

    void agregarIncidencia(Incidencia* inc);
    void resolverIncidencia();
    int getIncidenciasActivas() const;

    string getId() const;
    float getCriticidad() const;
    float getEstado() const;
    int getTiempoInactivo() const;
    void setEstado(float e);
    void setStrategy(MantStrategy* s);
    MantStrategy* getStrategy() const;
};



#endif //PROYECTO1F_EQUIPO_H
