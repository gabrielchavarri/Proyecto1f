//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_INCEDENCIA_H
#define PROYECTO1F_INCEDENCIA_H

#include <string>
using namespace std;

class Equipo;

class Incidencia {
private:
    string equipo_id;
    string severidad;
    int dia_reporte;
    bool activa;

public:
    Incidencia(const string &equipo_id, const string &severidad, int dia_reporte);

    string getEquipoId() const;

    string getSeveridad() const;

    int getDiaReporte() const;

    bool estaActiva() const;

    void resolver();

    string Texto() const;
};


#endif //PROYECTO1F_INCEDENCIA_H
