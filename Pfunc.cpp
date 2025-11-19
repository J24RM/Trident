#include "Pfunc.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

void agregarPoke(string _Npoke, string _Nombre, string _Tipo, string _Descripcion, string _Region, const std::string &nombreArchivo, std::vector<Pokemon> &pokemons){

	//Archivo

	string Text = _Npoke + ";" + _Nombre + ";" + _Tipo + ";" + _Descripcion + ";" + _Region + "\n";

	fstream archivo;

	archivo.open(nombreArchivo, fstream::app);

	archivo.seekp(1,archivo.ios::end);

	archivo << Text;

	archivo.close();

	//Objeto
	if (_Npoke.empty()) {
		std::cerr << "Error: Pokemon number cannot be empty" << std::endl;
		return;
	}
	int Npoke = std::stoi(_Npoke);

	Pokemon poke(Npoke, _Nombre, _Tipo, _Descripcion, _Region);

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


	std::string linea;

	while(getline(archivo, linea)){
		if (linea.empty()) {
			continue;
		}

		std::istringstream ss(linea); //Conventir a stream
		string Nombre, Tipo, Descripcion, Region, strNpoke;
		int Npoke;

		//Desmenusar

		getline(ss, strNpoke, ';');
	    getline(ss, Nombre, ';');
	    getline(ss, Tipo, ';');
	    getline(ss, Descripcion, ';');
	    getline(ss, Region, ';');

		if (strNpoke.empty()) {
			continue;
		}

		Npoke = std::stoi(strNpoke);


		//Crear

		Pokemon poke(Npoke, Nombre, Tipo, Descripcion, Region);

		//Almacenar

		pokemons.push_back(poke); 

	}

	archivo.close();

	return pokemons;
}