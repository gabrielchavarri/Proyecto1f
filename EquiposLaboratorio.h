//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_EQUIPOLABORATORIO_H
#define PROYECTO1F_EQUIPOLABORATORIO_H

#include "Equipo.h"

class EquiposLaboratorio : public Equipo {
private:
    string tipo_lab;
    bool sensor_activo;

public:
    EquiposLaboratorio(const string& id, float criticidad, float estado, const string& tipo_lab);
    void aplicarMant();
    string getTipo() const override;

    void calibrarSensor();
    bool isSensorActivo() const;
};

#endif //PROYECTO1F_EQUIPOSLABORATORIO_H
