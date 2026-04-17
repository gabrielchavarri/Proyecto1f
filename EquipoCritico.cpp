//
// Created by jr156 on 13/4/2026.
//

#include "EquipoCritico.h"
#include <iostream>

EquipoCritico::EquipoCritico(const string &id, float criticidad, float estado, const string &protocolo) : Equipo(
    id, criticidad, estado) {
    this->nivel_riesgo = criticidad * 0.8;
    this->protocolo_esp = protocolo;
}

void EquipoCritico::aplicarMant() {
    estado += 20;
    nivel_riesgo *= 0.7;
    tiempo_inactivo = 0;
    if (estado > 100)
        estado = 100;
}

string EquipoCritico::getProtocoloEsp() const {
    return "Critico";
}

void EquipoCritico::activarProtocolo() {
    cout << "Protocolo activado: " << protocolo_esp << "en equipo" << id << endl;
}

float EquipoCritico::getNivelRiesgo() const {
    return nivel_riesgo;
}

string EquipoCritico::getTipo() const {
    return "Critico";
}


