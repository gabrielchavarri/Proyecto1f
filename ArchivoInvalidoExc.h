//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_ARCHIVOINVALIDOEXC_H
#define PROYECTO1F_ARCHIVOINVALIDOEXC_H

#include "SistemaException.h"

class ArchivoInvalidoExc : public SistemaException {
private:
    string ruta;

public:
    explicit ArchivoInvalidoExc(const string &ruta);

    string getRuta();
};


#endif //PROYECTO1F_ARCHIVOINVALIDOEXC_H
