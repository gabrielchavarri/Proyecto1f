//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_EQUIPO_H
#define PROYECTO1F_EQUIPO_H

#include <string>
using namespace std;

class Incidencia;

class Equipo {
protected:
    string id;
    float criticidad;
    float estado;
    int tiempo_inactivo;
    int incidencias_activas;

public:
    Equipo(const string &id, float criticidad, float estado);

    float calcularPrioridad() const;

    void degradar();

    virtual void aplicarMant() = 0;

    virtual string getTipo() const = 0;

    string getId() const;

    float getCriticidad() const;

    float getEstado() const;

    int getTiempoInactivo() const;

    int getIncidenciasActivas() const;

    void agregarIncidencia();

    void resolverIncidencia();

    virtual ~Equipo() = default;
};


#endif //PROYECTO1F_EQUIPO_H
