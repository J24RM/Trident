#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream> // para el istringstream
#include <fstream>  // Library for .txt 
using namespace std;


#ifndef POKEMON_H_
#define POKEMON_H_

class Pokemon
{

private:
	int Npoke;
	string Nombre;
	string Tipo;
	string Descripcion;
	string Region;

public:
	//Constructores
	Pokemon(int _Npoke, string _Nombre, string _Tipo, string _Descripcion, string _Region);
	Pokemon();

	//setters
	void set_npoke(int _Npoke){
		Npoke = _Npoke;
	}

	void set_nombre(string _Nombre){
		Nombre = _Nombre;
	}

	void set_tipo(string _Tipo){
		Tipo = _Tipo;
	}

	void set_descripcion(string _Descripcion){
		Descripcion = _Descripcion;
	}

	void set_region(string _Region){
		Region = _Region;
	}

	//Getters

	int get_npoke(){
		return Npoke;
	}

	string get_nombre(){
		return Nombre;
	}

	string get_tipo(){
		return Tipo;
	}

	string get_descripcion(){
		return Descripcion; 
	}

	string get_region(){
		return Region;
	}

	//Funciones

	void InfoPoke(){

	cout << "Numero de pokedex: " << Npoke << "\n";

	cout << "Nombre: " << Nombre << "\n";

	cout << "Tipo: " << Tipo << "\n";

	cout << "Descripcion: " << Descripcion << "\n";

	cout << "Region: " << Region << "\n";
}

};

//Constructores

Pokemon::Pokemon(int _Npoke, string _Nombre, string _Tipo, string _Descripcion, string _Region){
	Npoke = _Npoke;
	Nombre = _Nombre;
	Tipo = _Tipo;
	Descripcion = _Descripcion;
	Region = _Region;

}
Pokemon::Pokemon() : Npoke(0), Nombre(""), Tipo(""), Descripcion(""), Region("") {}


#endif