#include "EquipoCritico.h"
#include <iostream>

EquipoCritico::EquipoCritico(const string& id, float criticidad, float estado, const string& protocolo)
    : Equipo(id, criticidad, estado),
      nivel_riesgo(criticidad * 0.8f),
      protocolo_esp(protocolo) {
}

void EquipoCritico::aplicarMant() {
    estado += 20.0f;
    nivel_riesgo *= 0.7f;
    tiempo_inactivo = 0;
    if (estado > 100.0f)
        estado = 100.0f;
}

string EquipoCritico::getTipo() const {
    return "Critico";
}

void EquipoCritico::activarProtocolo() {
    cout << "Protocolo: " << protocolo_esp << " en " << id << endl;
}

float EquipoCritico::getNivelRiesgo() const {
    return nivel_riesgo;
}

string EquipoCritico::getProtocoloEsp() const {
    return protocolo_esp;
}