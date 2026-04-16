#include "EquiposLaboratorio.h"
#include <iostream>

EquiposLaboratorio::EquiposLaboratorio(const string& id, float criticidad, float estado, const string& tipo_lab)
    : Equipo(id, criticidad, estado) {
    this-> tipo_lab = tipo_lab;
    this-> sensor_activo = true;
}

void EquiposLaboratorio::aplicarMant() {
    estado += 10.0;
    tiempo_inactivo = 0;
    if (estado > 100.0)
        estado = 100.0;
}

string EquiposLaboratorio::getTipo() const {
    return "Laboratorio";
}
void EquiposLaboratorio::calibrarSensor() {
    if (!sensor_activo) {
        sensor_activo = true;
        cout << "Sensor calibrado en equipo " << id << endl;
    } else {
        cout << "Sensor ya estaba activo en equipo " << id << endl;
    }
}

bool EquiposLaboratorio::isSensorActivo() const {
    return sensor_activo;
}