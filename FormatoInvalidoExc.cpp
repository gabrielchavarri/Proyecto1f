//
// Created by jr156 on 13/4/2026.
//

#include "FormatoInvalidoExc.h"

FormatoInvalidoExc::FormatoInvalidoExc(const string &msg, int linea)
    : SistemaException("Formato invalido en linea " + to_string(linea) + ": " + msg), linea(linea) {
}

int FormatoInvalidoExc::getLinea() const {
    return linea;
}
