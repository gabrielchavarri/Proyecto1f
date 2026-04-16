//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_EQUIPO_H
#define PROYECTO1F_EQUIPO_H

#include <string>

#include "MantStrategy.h"
using namespace std;

class Incidencia;

class Equipo {
protected:
    string id;
    float criticidad;
    float estado;
    int tiempo_inactivo;
    int incidencias_activas;
    MantStrategy *estrategia;

public:
    Equipo(const string &id, float criticidad, float estado);
    float calcularPrioridad() const;
    void degradar();
    virtual string getTipo() const;
    string getId() const;
    float getCriticidad() const;
    float getEstado() const;
    int getTiempoInactivo() const;
    int getIncidenciasActivas() const;
    void agregarIncidencia();
    void resolverIncidencia();
    virtual ~Equipo();
    void setEstado(float estado);
    void setStrategy(MantStrategy *strategy);
    virtual void aplicarMantenimiento();
    MantStrategy *getStrategy() const;
    void incrementarTiempoInactivo();
    void decrementarTiempoInactivo();
    void generarIncidencia();
};


#endif //PROYECTO1F_EQUIPO_H
