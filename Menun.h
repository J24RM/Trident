#ifndef MENUN_H 
#define MENUN_H

#include <vector>
#include "Pokemon.h"
#include "sorting.h"
#include "Historial.h"
#include "Pfunc.h"
#include <stack>

int VerMenun(std::vector<Pokemon>& ,int, int, stack<Historial>&);
void casoPrueba(std::vector<Pokemon> &pokemons ,int pk, stack<Historial> &historial );

#endif 