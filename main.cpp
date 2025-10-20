/*
Main.cpp

	Autor: Jesus Rodriguez

	Created on: 20/Sep/2025

	003;Venusaur;Grass/Poison;"The plant blooms when it is absorbing solar energy. It stays on the move to seek sunlight.";Kanto
	004;Charmander;Fire;"Obviously prefers hot places. When it rains, steam is said to spout from the tip of its tail.";Kanto
	005;Charmeleon;Fire;"When it swings its burning tail, it elevates the temperature to unbearably high levels.";Kanto
	006;Charizard;Fire/Flying;"Spits fire that is hot enough to melt boulders. Known to cause forest fires unintentionally.";Kanto
	007;Squirtle;Water;"After birth, its back swells and hardens into a shell. Powerfully sprays foam from its mouth.";Kanto
	008;Wartortle;Water;"Often hides in water to stalk unwary prey. For swimming fast, it moves its ears to maintain balance.";Kanto
	009;Blastoise;Water;"A brutal Pokémon with pressurized water jets on its shell. They are used for high speed tackles.";Kanto
	010;Caterpie;Bug;"Its short feet are tipped with suction pads that enable it to relentlessly climb trees and walls.";Kanto

*/


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream> // para el istringstream
#include <fstream>  // Library for .txt 
using namespace std;



#include "Pokemon.h"
#include "sorting.h"
#include "Historial.h"
#include "Menun.h"
#include "Pfunc.h"
#include <stack>

int main(){

    std::vector<Pokemon> pokemons = cargarPokes("pokemons.txt");

    stack<Historial> historial;

    ordenaMerge(pokemons);

    int band = 1;
    

    cout << "\n Profesor OAK: Bienvenido a la Pokedex!!! \n Ahora puedes ver tu historial de busqueda!!!!! \n";

    cout << "-------------------------------------------\n \n";

    cout << "Presiona ENTER para continuar";

    cin.get(); //Avanza hasta que le des enter

    int opc;
    int pk;


    while(band == 1){
    	band = VerMenun(pokemons, opc, pk, historial);
    }

    return 0;
}
