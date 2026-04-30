//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_OPERACIONICONSISTENTEEXC_H
#define PROYECTO1F_OPERACIONICONSISTENTEEXC_H


#include "SistemaException.h"

class OperacionIconsistenteExc : public SistemaException {
private:
    string contexto;
public:
    explicit OperacionIconsistenteExc(const string& contexto);
    string getContexto() const;
};

#endif //PROYECTO1F_OPERACIONICONSISTENTEEXC_H