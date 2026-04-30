#include "OperacionIconsistenteExc.h"

OperacionIconsistenteExc::OperacionIconsistenteExc(const string& contexto)
    : SistemaException("Operacion inconsistente: " + contexto), contexto(contexto) {}

string OperacionIconsistenteExc::getContexto() const {
    return contexto;
}