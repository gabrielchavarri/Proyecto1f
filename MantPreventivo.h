//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_MANTPREVENTIVO_H
#define PROYECTO1F_MANTPREVENTIVO_H
#include "Equipo.h"
#include "MantStrategy.h"


class MantPreventivo : public MantStrategy {
    public:
    void aplicar(Equipo * equipo) override ;


};


#endif //PROYECTO1F_MANTPREVENTIVO_H