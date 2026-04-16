//
// Created by jr156 on 15/4/2026.
//

#include "Ordenador_T.h"

void Ordenador_T::ordenar(Equipo **arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        acomodar(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        Equipo *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        acomodar(arr, i, 0);
    }
}

int Ordenador_T::busquedaBinaria(Equipo **arr, int n, const string &id) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid]->getId() == id) return mid;
        if (arr[mid]->getId() < id) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

void Ordenador_T::acomodar(Equipo **arr, int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && arr[izq]->calcularPrioridad() > arr[mayor]->calcularPrioridad())
        mayor = izq;
    if (der < n && arr[der]->calcularPrioridad() > arr[mayor]->calcularPrioridad())
        mayor = der;

    if (mayor != i) {
        Equipo *temp = arr[i];
        arr[i] = arr[mayor];
        arr[mayor] = temp;
        acomodar(arr, n, mayor);
    }
}
