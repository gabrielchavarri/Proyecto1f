//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_EQUIPOCRITICO_H
#define PROYECTO1F_EQUIPOCRITICO_H

#include "Equipo.h"


class EquipoCritico : public Equipo {
private:
    float nivel_riesgo;
    string protocolo_esp;

public:
    EquipoCritico(const string &id, float criticidad, float estado, const string &protocolo);

    void aplicarMant() override;

    string getProtocoloEsp() const;

    void activarProtocolo();

    float getNivelRiesgo() const;
};


#endif //PROYECTO1F_EQUIPOCRITICO_H