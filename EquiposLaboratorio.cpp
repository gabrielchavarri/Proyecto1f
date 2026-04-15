//
// Created by jr156 on 13/4/2026.
//

#include "EquiposLaboratorio.h"
#include <iostream>

EquiposLaboratorio::EquiposLaboratorio(const string& id, float criticidad, float estado, const string& tipo_lab): Equipo(id, criticidad, estado){
    this->tipo_lab = tipo_lab;
    this->sensor_activo = sensor_activo;
}

void EquiposLaboratorio::aplicarMant(){
    estado  += 10;

}

string EquiposLaboratorio::getTipo() const {
}

void EquiposLaboratorio::calibrarSensor(){
    sensor_activo = true;
    cout << "Sensor calibrando en equipo "<< id << endl;

}

bool EquiposLaboratorio::SensorActivo() const {
    return sensor_activo;
}
