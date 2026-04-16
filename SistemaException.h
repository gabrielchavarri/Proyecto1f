//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_SISTEMAEXCEPTION_H
#define PROYECTO1F_SISTEMAEXCEPTION_H

#include <exception>
#include <string>
using namespace std;


class SistemaException : public exception {
protected:
    string mensaje;

public:
    explicit SistemaException(const string &msg) : mensaje(msg) {
    }

    const char *what() const noexcept override {
        return mensaje.c_str();
    }
};


#endif //PROYECTO1F_SISTEMAEXCEPTION_H
