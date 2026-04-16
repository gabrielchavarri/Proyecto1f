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
        Incidencia.cpp
        Incidencia.h
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
        Ordenador_T.h
        CargadorDatos.cpp
        CargadorDatos.h
        GeneradorReportes.cpp
        GeneradorReportes.h
        SistemaException.h
        ArchivoInvalidoExc.cpp
        ArchivoInvalidoExc.h
        FormatoInvalidoExc.cpp
        FormatoInvalidoExc.h
        OperacionIconsistenteExc.cpp
        OperacionIconsistenteExc.h
        Simulador.cpp
        Simulador.h
        Ordenador_T.cpp
        tareaMantenimiento.cpp
        tareaMantenimiento.h
        MaintenancePlanner.cpp
        MaintenancePlanner.h
)
