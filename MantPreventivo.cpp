//
// Created by jr156 on 13/4/2026.
//

#include "MantPreventivo.h"
#include "Equipo.h"
void MantPreventivo::aplicar(Equipo* eq) {
    eq->setEstado(eq->getEstado()+ 10);
    if (eq->getEstado() >100)
        eq->setEstado(100);
}