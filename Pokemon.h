#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream> 
#include <fstream>  
using namespace std;


#ifndef POKEMON_H_
#define POKEMON_H_

class Pokemon
{

private:
	int Npoke;
	string Nombre;
	string Tipo1;
	string Tipo2;
	string Descripcion;
	string Region;

public:
	//Constructores
	Pokemon(int _Npoke, string _Nombre, string _Tipo1, string _Tipo2, string _Descripcion, string _Region){
	Npoke = _Npoke;
	Nombre = _Nombre;
	Tipo1 = _Tipo1;
	Tipo2 = _Tipo2;
	Descripcion = _Descripcion;
	Region = _Region;

	}

	Pokemon() : Npoke(0), Nombre(""), Tipo1(""), Tipo2(""), Descripcion(""), Region("") {}	

	//setters
	void set_npoke(int _Npoke){
		Npoke = _Npoke;
	}

	void set_nombre(string _Nombre){
		Nombre = _Nombre;
	}

	void set_tipos(string _Tipo1, string _Tipo2){
		Tipo1 = _Tipo1;
		Tipo2 = _Tipo2;
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

	// Si solo tiene un tipo
	if (Tipo2 == "Nada"){
		cout << "Tipo: " << Tipo1 << "\n";
	}
	// Si tiene dos tipos
	else{
		cout << "Tipos: " << Tipo1 << " y " << Tipo2 << "\n";
	}

	cout << "Descripcion: " << Descripcion << "\n";

	cout << "Region: " << Region << "\n";
}

};



#endif