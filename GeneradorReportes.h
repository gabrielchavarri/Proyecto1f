//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_GENERADORREPORTES_H
#define PROYECTO1F_GENERADORREPORTES_H
#include "Equipo.h"
#include <fstream>


class GeneradorReportes {
public:
    void generarReporteDiario(int dia,Equipo** atendidos,int cantidad,int backlog,float riesgo,std::ofstream& archivo);
};


#endif //PROYECTO1F_GENERADORREPORTES_H