//
// Created by jr156 on 13/4/2026.
//

#include "ColeccionEquipos.h"
ColeccionEquipos::ColeccionEquipos() {
    capacidad = 10;
    size = 0;
    equipos = new Equipo *[capacidad];
}

ColeccionEquipos::~ColeccionEquipos() {
    for (int i = 0; i < size; i++)
        delete equipos[i];
    delete[] equipos;
}

void ColeccionEquipos::agregar(Equipo* e) {
    if (size == capacidad) {
        capacidad *= 2;
        Equipo** nuevo = new Equipo*[capacidad];
        for (int i = 0; i < size; i++)
            nuevo[i] = equipos[i];
        delete[] equipos;
        equipos = nuevo;
    }
    equipos[size++] = e;
}

void ColeccionEquipos::ordenarPorPrioridad() {
    ordenador.ordenar(equipos, size);
}

Equipo *ColeccionEquipos::buscar(const string &id) {
    for (int i = 0; i < size; i++) {
        if (equipos[i]->getId() == id)
            return equipos[i];
    }
    return nullptr;
}

Equipo *ColeccionEquipos::obtener(int indice) {
    if (indice < 0 || indice >= size) return nullptr;
    return equipos[indice];
}

void ColeccionEquipos::degradarTodos() {
    for (int i = 0; i < size; i++)
        equipos[i]->degradar();
}

int ColeccionEquipos::getSize() const {
    return size;
}

void ColeccionEquipos::actualizarPrioridades() {
    for (int i = 0; i < size; i++) {
        if (equipos[i] != nullptr) {
            equipos[i]->calcularPrioridad();
        }
    }
}

