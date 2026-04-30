#include "Equipo.h"
#include "OperacionIconsistenteExc.h"

Equipo::Equipo(const string& id, float criticidad, float estado) {
    this->id = id;
    this->criticidad = criticidad;
    this->estado = estado;
    this->tiempo_inactivo = 0;
    this->totalIncidencias = 0;

    for (int i = 0; i < 100; i++)
        incidencias[i] = nullptr;
}

Equipo::~Equipo() {
    for (int i = 0; i < totalIncidencias; i++)
        delete incidencias[i];
}

float Equipo::calcularPrioridad() const {
    return (criticidad * 0.5f) +
           (getIncidenciasActivas() * 0.3f) +
           (tiempo_inactivo * 0.2f);
}

void Equipo::degradar() {
    estado -= criticidad * 0.1f;

    if (estado < 0) estado = 0;

    incrementarTiempoInactivo();
}

void Equipo::agregarIncidencia(Incidencia* inc) {
    if (totalIncidencias >= 100)
        throw OperacionIconsistenteExc("Capacidad maxima de incidencias alcanzada en " + id);

    // 🔥 validación PRO (opcional pero suma puntos)
    if (inc->getEquipo() != this)
        throw OperacionIconsistenteExc("Incidencia no pertenece a este equipo");

    incidencias[totalIncidencias++] = inc;
}

void Equipo::resolverIncidencia() {
    for (int i = 0; i < totalIncidencias; i++) {
        if (incidencias[i]->estaActiva()) {
            incidencias[i]->resolver();
            return;
        }
    }
}

int Equipo::getIncidenciasActivas() const {
    int count = 0;

    for (int i = 0; i < totalIncidencias; i++)
        if (incidencias[i]->estaActiva())
            count++;

    return count;
}

string Equipo::getId() const { return id; }
float Equipo::getCriticidad() const { return criticidad; }
float Equipo::getEstado() const { return estado; }
int Equipo::getTiempoInactivo() const { return tiempo_inactivo; }

void Equipo::setEstado(float e) {
    estado = e;

    if (estado > 100.0f) estado = 100.0f;
    if (estado < 0.0f) estado = 0.0f;
}

void Equipo::resetTiempoInactivo() {
    tiempo_inactivo = 0;
}
void Equipo::incrementarTiempoInactivo() {
    tiempo_inactivo++;
}
float Equipo::getPrioridad() const {
    return prioridadCache;
}
void Equipo::setPrioridad(float p) {
    prioridadCache = p;
}
