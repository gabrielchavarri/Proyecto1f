cmake_minimum_required(VERSION 4.1)
project(Proyecto1f)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1f main.cpp
        Equipo.cpp
        Equipo.h
        EquiposLaboratorio.cpp
        EquiposLaboratorio.h
        EquipoCritico.cpp
        EquipoCritico.h
        Incedencia.cpp
        Incedencia.h
        ColeccionEquipos.cpp
        ColeccionEquipos.h
        Tecnico.cpp
        Tecnico.h
        MantStrategy.cpp
        MantStrategy.h
        MantPreventivo.cpp
        MantPreventivo.h
        MantCorrectivo.cpp
        MantCorrectivo.h
        Ordenador_T.cpp
        Ordenador_T.h
        CargadorDatos.cpp
        CargadorDatos.h
        GeneradorReportes.cpp
        GeneradorReportes.h
        SistemaException.cpp
        SistemaException.h
        ArchivoInvalidoExc.cpp
        ArchivoInvalidoExc.h
        FormatoInvalidoExc.cpp
        FormatoInvalidoExc.h
        OperacionIconsistenteExc.cpp
        OperacionIconsistenteExc.h
        Simulador.cpp
        Simulador.h)
