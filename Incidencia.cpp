#include "Incidencia.h"

Incidencia::Incidencia(const string &equipo_id, const string &severidad, int dia_reporte)
    : equipo_id(equipo_id),
      severidad(severidad),
      dia_reporte(dia_reporte),
      activa(true) {
}

string Incidencia::getEquipoId() const {
    return equipo_id;
}

string Incidencia::getSeveridad() const {
    return severidad;
}

int Incidencia::getDiaReporte() const {
    return dia_reporte;
}

bool Incidencia::estaActiva() const {
    return activa;
}

void Incidencia::resolver() {
    activa = false;
}

string Incidencia::Texto() const {
    return "Incidencia;" + equipo_id + ";" + severidad + ";dia=" + to_string(dia_reporte) + ";activa=" + (
               activa ? "SI" : "NO");
}
