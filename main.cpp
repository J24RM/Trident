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


011;Metapod;A;A;Kanto

*/


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream> // para el istringstream
#include <thread> // library for std::this_thread::sleep_for
#include <chrono> // libary for std::chrono::milliseconds
#include <fstream>  // Library for .txt 
using namespace std;



#include "Pokemon.h"

void mergeSplit(std::vector<Pokemon> &A, std::vector<Pokemon> &B, int low, int high);
void mergeArray(std::vector<Pokemon>& A, std::vector<Pokemon>& B, int low, int mid, int high);
void copyArray(std::vector<Pokemon>& A, std::vector<Pokemon>& B, int low, int high);


void agregarPoke(string _Npoke, string _Nombre, string _Tipo, string _Descripcion, string _Region, const std::string &nombreArchivo, std::vector<Pokemon> &pokemons){

	//Archivo

	string Text = _Npoke + ";" + _Nombre + ";" + _Tipo + ";" + _Descripcion + ";" + _Region + "\n";

	fstream archivo;

	archivo.open (nombreArchivo, fstream::app);

	archivo.seekp(1,archivo.ios::end);

	archivo << Text;

	archivo.close();

	//Objeto
	int Npoke = std::stoi(_Npoke);

	Pokemon poke(Npoke, _Nombre, _Tipo, _Descripcion, _Region);

	pokemons.push_back(poke); //Almacenar el pokemon 

}

//Merge

std::vector<Pokemon>& ordenaMerge(std::vector<Pokemon> &v) {
	std::vector<Pokemon> tmp(v.size());

	mergeSplit(v, tmp, 0 ,v.size() - 1);
    return v;
}


void mergeSplit(std::vector<Pokemon> &A, std::vector<Pokemon> &B, int low, int high) {

	int mid;

	if (low == high){
		return; 
	}

	mid = (high + low) / 2;

	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);

}

void mergeArray(std::vector<Pokemon>& A, std::vector<Pokemon> &B, int low, int mid, int high) {
	int i,j,k;

	i = low;

	j = mid + 1;

	k = low;

	while(i <= mid && j <= high){
		if (A[i].get_npoke() < A[j].get_npoke()){
			B[k] = A[i];
			i++;
		}
		else{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid){
		for (; j <= high; j++){
			B[k++] = A[j];
		}
	}

	else{
		for (; i <= high; i++){
			B[k++] = A[i];
		}
	}
	
}


void copyArray(std::vector<Pokemon>& A, std::vector<Pokemon> &B, int low, int high) {
	int i,j;

	i = low;

	j = high;

	for(; i <= high; i++){
		A[i] = B[i];
	}

}


 std::vector<Pokemon> cargarPokes(const std::string &nombreArchivo){


 	//Efecto de carga
 	cout << "Cargando";

    for (int i = 0; i < 3; i++) {
        cout << "." << flush;  
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "\nListo!" << endl;

	std::vector<Pokemon> pokemons;

	std::ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
    	std::cerr << "Error: no se pudo abrir el archivo " << nombreArchivo << "\n";
    	return pokemons; // Retorna vector vacío
	}	


	std::string linea;

	while(getline(archivo, linea)){
		std::istringstream ss(linea); //Conventir a stream
		string Nombre, Tipo, Descripcion, Region, strNpoke;
		int Npoke;

		//Desmenusar

		getline(ss, strNpoke, ';');
	    getline(ss, Nombre, ';');
	    getline(ss, Tipo, ';');
	    getline(ss, Descripcion, ';');
	    getline(ss, Region, ';');

		Npoke = std::stoi(strNpoke);


		//Crear

		Pokemon poke(Npoke, Nombre, Tipo, Descripcion, Region);

		//Almacenar

		pokemons.push_back(poke); //Almacenar el pokemon 

	}

	archivo.close();

	return pokemons;
}



int main(){

    std::vector<Pokemon> pokemons = cargarPokes("pokemons.txt");

    ordenaMerge(pokemons);

    int band = 1;
    int opc;

    cout << "\n Profesor OAK: Bienvenido a la Pokedex!!! \n en la Pokedex puedes registrar y ver la lista de tus pokemones \n La lista se ordena sola!!\n";

    cout << "Presiona ENTER para continuar";

    cin.get(); //Avanza hasta que le des enter


    while(band == 1){
        cout << "\n===== MENU Pokedex =====\n";
        cout << "1.- Agregar Pokemon\n";
        cout << "2.- Ver Pokemones\n";
        cout << "3.- Salir\n";
        cout << "Profesor OAK: Elije una acción\n";
        cin >> opc;

        if(opc == 1){
            cout << "\n--- Agregar un Pokemon ---\n";
            string _Npoke, _Nombre, _Tipo, _Descripcion, _Region;

            cout << "Numero de pokedex: ";
            cin >> _Npoke; 
            cin.ignore();

            cout << "Nombre: ";
            getline(cin, _Nombre);

            cout << "Tipo: ";
            getline(cin, _Tipo);

            cout << "Descripcion: ";
            getline(cin, _Descripcion);

            cout << "Region: ";
            getline(cin, _Region);

            agregarPoke(_Npoke, _Nombre, _Tipo, _Descripcion, _Region, "pokemons.txt", pokemons);

            // Ordenar después de agregar
            ordenaMerge(pokemons);

            cout << "Pokemon agregado correctamente.\n";
        }
        if(opc == 2){
            cout << "\n--- Lista de Pokemones ---\n";
            if (pokemons.empty()) {
                cout << "No hay pokemones cargados.\n";
            } else {
                for (int i = 0; i < pokemons.size(); i ++) {
                	cout << i;
                    pokemons[i].InfoPoke();
                    cout << "-------------------------\n";
                }
            }
        }
        else if(opc == 3){
            cout << "Saliendo del programa...\n";
            band = 0;
        }
        else{
            cout << "Opcion no valida, intenta de nuevo.\n";
        }
    }

    return 0;
}
