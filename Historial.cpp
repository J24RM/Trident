/*
    Este codigo son las funciones de la clase historial, el historial se encarga de guarda las acciones que realizo el usuario y los pokemones que consulto.

    Funciones:
        - Ver historial
        - Guardar acción
        - Guardar pokemon consultado

    Para el pokemon consultado solo guardamos el numero de pokedex del pokemon, no toda su informacion
*/

#include "Historial.h"
#include <iostream> 
#include <stack>


// Guardado de acciones en el historial
void Historial::guardar(string ac, string des) {
    accion = ac;
    detalles = des;
}


// Guardado de Pokemones consultados en el historial
void Historial::guardarPK(string ac, string des, int id, int nu) {
    accion = ac;
    detalles = des;
    accionId = id;
    num = nu;
}


void Historial::VerH(stack<Historial> &his) {
    std::cout << "\n--- Historial de Acciones (Mas reciente primero) ---\n";
    if (his.empty()) {
        std::cout << "No se han realizado acciones todavia.\n";
    } else {
        stack<Historial> tempHis = his;
        while (!tempHis.empty()) {
            Historial accionActual = tempHis.top();
            std::cout << "Accion: " << accionActual.get_accion() << " | Detalles: " << accionActual.get_detalles() << std::endl;
            tempHis.pop();
        }
    }
}


Historial::Historial() {
    accion = "";
    detalles = "";
    accionId = 0;
    num = 0;
}


Historial::~Historial() {}
