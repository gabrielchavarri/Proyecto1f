//
// Created by jr156 on 13/4/2026.
//

#include "ArchivoInvalidoExc.h"

ArchivoInvalidoExc::ArchivoInvalidoExc(const string &ruta)
    : SistemaException("Archivo invalido: " + ruta), ruta(ruta) {
}

string ArchivoInvalidoExc::getRuta() {
    return ruta;
}
