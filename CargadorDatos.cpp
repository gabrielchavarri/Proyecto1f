//
// Created by jr156 on 13/4/2026.
//
#include "CargadorDatos.h"
#include "EquipoCritico.h"
#include "EquiposLaboratorio.h"
#include <cstdio>
#include <cstring>

void CargadorDatos::cargarEquipos(const string& ruta, ColeccionEquipos& coleccion) {
    FILE* archivo = fopen(ruta.c_str(), "r");
    if (!archivo)
        throw ArchivoInvalidoExc(ruta);

    char linea[256];
    int nro = 0;
    while (fgets(linea, sizeof(linea), archivo)) {
        nro++;
        string s(linea);
        if (s.empty() || s[0] == '#') continue;

        string id = leerCampo(s, "");
        string tipo = leerCampo(s, "tipo=");
        string crit = leerCampo(s, "criticidad=");
        string est  = leerCampo(s, "estado=");

        if (id.empty() || tipo.empty() || crit.empty() || est.empty())
            throw FormatoInvalidoExc("campos faltantes", nro);

        float criticidad = stof(crit);
        float estado = stof(est);

        if (tipo == "CRITICO") {
            string protocolo = leerCampo(s, "protocolo=");
            coleccion.agregar(new EquipoCritico(id, criticidad, estado, protocolo));
        } else if (tipo == "LAB") {
            string categoria = leerCampo(s, "categoria=");
            coleccion.agregar(new EquiposLaboratorio(id, criticidad, estado, categoria));
        } else {
            throw FormatoInvalidoExc("tipo desconocido: " + tipo, nro);
        }
    }
    fclose(archivo);
}

void CargadorDatos::cargarIncidencias(const string& ruta, ColeccionEquipos& coleccion) {
    FILE* archivo = fopen(ruta.c_str(), "r");
    if (!archivo)
        throw ArchivoInvalidoExc(ruta);

    char linea[256];
    int nro = 0;
    while (fgets(linea, sizeof(linea), archivo)) {
        nro++;
        string s(linea);
        if (s.empty() || s[0] == '#') continue;

        string equipoId = leerCampo(s, "INC;");
        string severidad = leerCampo(s, "severidad=");
        string dia = leerCampo(s, "dia=");

        if (equipoId.empty() || severidad.empty() || dia.empty())
            throw FormatoInvalidoExc("campos faltantes en incidencia", nro);

        Equipo* eq = coleccion.buscar(equipoId);
        if (eq == nullptr)
            throw FormatoInvalidoExc("equipo no encontrado: " + equipoId, nro);

        eq->agregarIncidencia(new Incidencia(equipoId, severidad, stoi(dia)));
    }
    fclose(archivo);
}

string CargadorDatos::leerCampo(const string& linea, const string& clave) {
    if (clave.empty()) {
        // primer campo antes del primer ';'
        size_t pos = linea.find(';');
        if (pos == string::npos) return "";
        return linea.substr(0, pos);
    }
    size_t pos = linea.find(clave);
    if (pos == string::npos) return "";
    pos += clave.size();
    size_t fin = linea.find(';', pos);
    if (fin == string::npos) fin = linea.find('\n', pos);
    if (fin == string::npos) fin = linea.size();
    return linea.substr(pos, fin - pos);
}