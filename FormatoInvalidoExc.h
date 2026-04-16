//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_FORMATOINVALIDOEXC_H
#define PROYECTO1F_FORMATOINVALIDOEXC_H

#include "SistemaException.h"

class FormatoInvalidoExc : public SistemaException {
private:
    int linea;

public:
    FormatoInvalidoExc(const string &msg, int linea);

    int getLinea() const;
};


#endif //PROYECTO1F_FORMATOINVALIDOEXC_H