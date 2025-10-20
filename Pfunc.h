#ifndef PFUNC_H 
#define PFUNC_H

#include <vector>
#include <string>
#include "Pokemon.h"
#include "sorting.h"
#include "Historial.h"

using namespace std;

void agregarPoke(string _Npoke, string _Nombre, string _Tipo, string _Descripcion, string _Region, const std::string &nombreArchivo, std::vector<Pokemon> &pokemons);

std::vector<Pokemon> cargarPokes(const std::string&);


#endif 