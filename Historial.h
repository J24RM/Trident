#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <string>
#include <stack>

using namespace std;

class Historial {
private:
    string accion;
    string detalles;
    int accionId;
    int num;

public:
    Historial();
    ~Historial();

    void guardar(string, string);
    void VerH(stack<Historial> &);
    void guardarPK(string , string , int , int );


    string get_accion() { return accion; }
    string get_detalles() { return detalles; }
    int get_accionId() { return accionId; }
    int get_num() { return num; }
};

#endif