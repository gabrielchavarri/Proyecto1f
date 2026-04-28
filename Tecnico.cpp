//
// Created by jr156 on 13/4/2026.
//
#include "Tecnico.h"

Tecnico::Tecnico(const string& nombre) : nombre(nombre), disponible(true) {}

string Tecnico::getNombre() const { return nombre; }

bool Tecnico::isDisponible() const { return disponible; }

void Tecnico::asignar() { disponible = false; }

void Tecnico::liberar() { disponible = true; }