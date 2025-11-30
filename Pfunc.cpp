/*
	En este codigo estan las funciones para aceder al archivo.txt donde esta almacenada la información de los pokemon.

	Funcionalidades:
		- Agregar Pokemones al archivo.txt
		- Cargar los pokemones al programa
*/


#include "Pfunc.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>


void agregarPoke(string _Npoke, string _Nombre, string _Tipo1, string _Tipo2, string _Descripcion, string _Region, const std::string &nombreArchivo, std::vector<Pokemon> &pokemons){

	//Archivo

	// Guardar en un string los datos del Pokemon
	string Text = _Npoke + ";" + _Nombre + ";" + _Tipo1 + ";" + _Tipo2 + ";" + _Descripcion + ";" + _Region + "\n";

	fstream archivo;

	// Abrir el archivo
	archivo.open(nombreArchivo, fstream::app);

	archivo.seekp(1,archivo.ios::end);

	// Guardar el hilo de texto con los datos del Pokemon en el archivo
	archivo << Text;

	archivo.close();

	//Objeto
	if (_Npoke.empty()) {
		std::cerr << "Error: Pokemon number cannot be empty" << std::endl;
		return;
	}
	int Npoke = std::stoi(_Npoke);

	// Creacion del Pokemon
	Pokemon poke(Npoke, _Nombre, _Tipo1, _Tipo2, _Descripcion, _Region);

	pokemons.push_back(poke); //Almacenar el pokemon 

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
    	return pokemons; 
	}	

	// Sacar los datos del archivo para cargarlos como objetos de tipo Pokemon
	std::string linea;

	while(getline(archivo, linea)){
		if (linea.empty()) {
			continue;
		}

		std::istringstream ss(linea); //Conventir a stream
		string Nombre, Tipo1, Tipo2, Descripcion, Region, strNpoke;
		int Npoke;

		//Desmenusar
		getline(ss, strNpoke, ';');
	    getline(ss, Nombre, ';');
	    getline(ss, Tipo1, ';');
	    getline(ss, Tipo2, ';');
	    getline(ss, Descripcion, ';');
	    getline(ss, Region, ';');

		if (strNpoke.empty()) {
			continue;
		}

		Npoke = std::stoi(strNpoke);


		//Crear
		Pokemon poke(Npoke, Nombre, Tipo1, Tipo2, Descripcion, Region);

		//Almacenar
		pokemons.push_back(poke); 

	}

	archivo.close();

	return pokemons;
}
