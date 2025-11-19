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
#include <sstream> 
#include <fstream>  
#include <thread>

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
    

    cout << "\n Profesor OAK: Bienvenido a la Pokedex!!! \n";

    cout << "-------------------------------------------\n \n";

    cout << "Presiona ENTER para continuar";

    cin.get(); 

    int opc;
    int pk;
    int elc;


    while(band == 1){
    	cout << "\nElije una opción\n";
    	cout << "1.- Programa Normal\n";
    	cout << "2.- Casos de Prueba\n";
    	cout << "3.- Salir \n";

    	cin >> elc;

    	if(elc == 1){
    		while(band == 1){
    		band = VerMenun(pokemons, opc, pk, historial);
    		}
    	}

    	if(elc == 2){
    		casoPrueba(pokemons, pk, historial);	
    	}

    	if(elc == 3){
    		cout << "Saliendo del programa";
            for (int i = 0; i < 3; i++) {
                cout << "." << flush;  
                this_thread::sleep_for(chrono::milliseconds(500));
            }            
            band = 0;
    	}
    }

    return 0;
}