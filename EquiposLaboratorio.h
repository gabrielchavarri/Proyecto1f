//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_EQUIPOSLABORATORIO_H
#define PROYECTO1F_EQUIPOSLABORATORIO_H

#include "Equipo.h"


class EquiposLaboratorio : public Equipo {
private:
    string tipo_lab;
    bool sensor_activo;

public:
    EquiposLaboratorio(const string &id, float criticidad, float estado, const string &tipo_lab);

    void aplicarMant() const;

    string getTipo() const override;

    void calibrarSensor() const;

    bool SensorActivo() const;
};


#endif //PROYECTO1F_EQUIPOSLABORATORIO_H
