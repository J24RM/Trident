#include "Historial.h"
#include <iostream> 
#include <stack>

void Historial::guardar(string ac, string des) {
    accion = ac;
    detalles = des;
}

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
