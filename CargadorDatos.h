//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_CARGADORDATOS_H
#define PROYECTO1F_CARGADORDATOS_H

#include "ColeccionEquipos.h"
#include "Incidencia.h"
#include "ArchivoInvalidoExc.h"
#include "FormatoInvalidoExc.h"
#include <cstdio>
#include <string>
using namespace std;

class CargadorDatos {
public:
    void cargarEquipos(const string& ruta, ColeccionEquipos& coleccion);
    void cargarIncidencias(const string& ruta, ColeccionEquipos& coleccion);

private:
    string leerCampo(const string& linea, const string& clave);
};


#endif //PROYECTO1F_CARGADORDATOS_H