/*
Main.cpp

	Autor: Jesus Rodriguez

	Created on: 20/Sep/2025
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

    // cargar pokemones
    std::vector<Pokemon> pokemons = cargarPokes("pokemons.txt");

    stack<Historial> historial;

    // ordenar los pokemones
    ordenaMerge(pokemons);

    int band = 1;
    

    cout << "\n Profesor OAK: Bienvenido a la Pokedex!!! \n";

    cout << "-------------------------------------------\n \n";

    cout << "Presiona ENTER para continuar";

    cin.get(); 

    int opc;
    int pk;
    int elc;

    // loop de menu inicial
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