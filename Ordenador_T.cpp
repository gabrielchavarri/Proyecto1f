//
// Created by jr156 on 15/4/2026.
//

#include "Ordenador_T.h"

void Ordenador_T::ordenar(Equipo **arr, int n) {
  for (int i = 0; i < n - 1; i++) {
      int max = i;
      for (int j = i + 1; j < n; j++) {
          if (arr[j]->calcularPrioridad() > arr[max]->calcularPrioridad()) {
              max = j;
          }
      }
      if (max != i) {
          Equipo *aux = arr[i];
          arr[i] = arr[max];
          arr[max] = aux;
      }
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

