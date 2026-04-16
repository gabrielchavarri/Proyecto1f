//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_MANTSTRATEGY_H
#define PROYECTO1F_MANTSTRATEGY_H
#include <vector>
#include <iostream>
class Equipo;

class MantStrategy {
public:
    virtual void aplicar(Equipo * equipo )=0;
    virtual ~MantStrategy(){};
};


#endif //PROYECTO1F_MANTSTRATEGY_H