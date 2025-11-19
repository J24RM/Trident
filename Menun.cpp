#include "Menun.h"
#include <iostream>
#include <thread>
#include <chrono>

void casoPrueba(std::vector<Pokemon> &pokemons ,int pk, stack<Historial> &historial );

int VerMenun(std::vector<Pokemon> &pokemons ,int opc, int pk, stack<Historial> &historial ){
    string ac;
    string des;
    cout << "\n===== MENU Pokedex =====\n";
    cout << "1.- Agregar Pokemon\n";
        cout << "2.- Ver Pokemones\n";
        cout << "3.- Consultar Pokemon\n";
        cout << "4.- Consultar Historial\n";
        cout << "5.- Consultar Pokemones Previamente Consultados \n";
        cout << "6.- Salir\n";
        cout << "Profesor OAK: Elije una acción\n";
        cin >> opc;
        cout << "\n---------------------------------\n";

        if(opc == 1){

            bool existe = false;
            cout << "\n--- Agregar un Pokemon ---\n";
            string _Npoke, _Nombre, _Tipo, _Descripcion, _Region;

            cout << "Numero de pokedex: ";
            cin >> _Npoke; 
            cin.ignore(); // Para que no se intrepongan los inputs

            cout << "Nombre: ";
            getline(cin, _Nombre);

            for (int i = 0; i < pokemons.size(); i ++) {
                    if(pokemons[i].get_npoke() == std::stoi(_Npoke) || pokemons[i].get_nombre() == _Nombre){
                        existe = true;
                    }
                }

            if(!existe){

                cout << "Tipo: ";
                getline(cin, _Tipo);

                cout << "Descripcion: ";
                getline(cin, _Descripcion);

                cout << "Region: ";
                getline(cin, _Region);

                agregarPoke(_Npoke, _Nombre, _Tipo, _Descripcion, _Region, "pokemons.txt", pokemons);

                ac = "Agregar";
                des =  "Se agrego a " + _Nombre + " (" + _Npoke + ")";

                Historial his;

                his.guardar(ac, des);

                historial.push(his);

                // Ordenar después de agregar
                ordenaMerge(pokemons);

                cout << "Pokemon agregado correctamente.\n";
        }

        else{
            cout << "El Pokemon ya existe \n";
        }

            return 1;
        }

        else if(opc == 2){
            cout << "\n--- Lista de Pokemones ---\n";
            if (pokemons.empty()) {
                cout << "No hay pokemones cargados.\n";
            } else {
                for (int i = 0; i < pokemons.size(); i ++) {
                    pokemons[i].InfoPoke();
                    cout << "-------------------------\n";
                }
            }
            ac = "Consulta";
            des = "Todos los Pokemones";

            Historial his;

            his.guardar(ac, des);

            historial.push(his);
            return 1;
        }

        else if (opc == 3) {
            cout << "\n Elije que el número de pokemon que quieres ver: ";
            cin >> pk;
            bool encontrado = false; 
            for (int i = 0; i < pokemons.size(); i++) {
                if (pokemons[i].get_npoke() == pk) {
                    pokemons[i].InfoPoke();
                    cout << "-------------------------\n";

                    ac = "Consulta";
                    des = "Se consulto la informacion del pokemon: " + pokemons[i].get_nombre() + " (" + to_string(pokemons[i].get_npoke()) + ")";

                    Historial his;
                    his.guardarPK(ac, des, 3, pk);
                    historial.push(his);
                    encontrado = true;

                    break; 
                }
            }
            if (!encontrado) {
                cout << "Pokemon con numero " << pk << " no encontrado.\n";
            }
            return 1;
        }

        else if (opc == 4) { 
        if (!historial.empty()) {
            Historial visor; 
            visor.VerH(historial);
        } else {
            cout << "\n--- Historial de Acciones ---\n";
            cout << "No se han realizado acciones todavia.\n";
        }

        Historial his;
        his.guardar("Consulta", "Se consulto el historial de acciones.");
        historial.push(his);
        return 1;
        }

        else if(opc == 5){
            stack<Historial> tempHis = historial;
            while(!tempHis.empty()){
                if(tempHis.top().get_accionId() == 3){
                    for (int i = 0; i < pokemons.size(); i++) {
                        if (pokemons[i].get_npoke() == tempHis.top().get_num()) {
                        pokemons[i].InfoPoke();
                        cout << "-------------------------\n";
                        break;
                        }
                    }
                }
                tempHis.pop();
            }
            return 1;
        }

        else if(opc == 6){
            cout << "Saliendo del programa";
            for (int i = 0; i < 3; i++) {
                cout << "." << flush;  
                this_thread::sleep_for(chrono::milliseconds(500));
            }            
            return 0;
        }

        else {
            cout << "Opcion no valida, intenta de nuevo.\n";
            return 1;
        }
}








void casoPrueba(std::vector<Pokemon> &pokemons ,int pk, stack<Historial> &historial ){

    string ac;
    string des;
    bool existe = false;
    // Agregar Pokemon
    cout << "\n--- Agregar un Pokemon ---\n";
    string _Npoke, _Nombre, _Tipo, _Descripcion, _Region;

    _Npoke = "151";
    cout << "Numero de pokedex: " << _Npoke << "\n"; 

    _Nombre = "Mew";
    cout << "Nombre: " << _Nombre << "\n";

    for (int i = 0; i < pokemons.size(); i ++) {
        if(pokemons[i].get_npoke() == std::stoi(_Npoke) || pokemons[i].get_nombre() == _Nombre){
            existe = true;
        }
    }
    if(!existe){
        _Tipo = "Normal";
        cout << "Tipo: " << _Tipo << "\n";        

        _Descripcion = "Se dice que es el ancestro de todos los pokemones, debido a que contiene el ADN de todos";
        cout << "Descripcion: " << _Descripcion << "\n";

        _Region = "Kanto";
        cout << "Region: " << _Region << "\n";

        agregarPoke(_Npoke, _Nombre, _Tipo, _Descripcion, _Region, "pokemons.txt", pokemons);

        ac = "Agregar";
        des =  "Se agrego a " + _Nombre + " (" + _Npoke + ")";

        Historial his;

        his.guardar(ac, des);

        historial.push(his);

        ordenaMerge(pokemons);

        cout << "Pokemon agregado correctamente.\n";
    }
    else{
        cout << "El Pokemon ya existe \n";
    }

    // Ver todos los pokemones
    cout << "\n--- Lista de Pokemones ---\n";
    if (pokemons.empty()) {
        cout << "No hay pokemones cargados.\n";
    } 
    else {
        for (int i = 0; i < pokemons.size(); i ++) {
                pokemons[i].InfoPoke();
                cout << "-------------------------\n";
            }
    }
    ac = "Consulta";
    des = "Todos los Pokemones";

    Historial his2;

    his2.guardar(ac, des);

    historial.push(his2);
    
    // Ver a Pikachu
    cout << "\n Elije que el número de pokemon que quieres ver: " << pk << "\n";
    pk = 25;
    for (int i = 0; i < pokemons.size(); i++) {
        if (pokemons[i].get_npoke() == pk) {
            pokemons[i].InfoPoke();
            cout << "-------------------------\n";

            ac = "Consulta";
            des = "Se consulto la informacion del pokemon: " + pokemons[i].get_nombre() + " (" + to_string(pokemons[i].get_npoke()) + ")";

            Historial his3;
            his3.guardarPK(ac, des, 3, pk);
            historial.push(his3);
        

            break; 
        }
    }

    // Ver Historial de acciones
    if (!historial.empty()) {
        Historial visor; 
        visor.VerH(historial);
    } else {
        cout << "\n--- Historial de Acciones ---\n";
        cout << "No se han realizado acciones todavia.\n";
    }

    Historial his4;
    his4.guardar("Consulta", "Se consulto el historial de acciones.");
    historial.push(his4);

    // Ver a Mew
    cout << "\n Elije que el número de pokemon que quieres ver: " << pk << "\n";
    pk = 151;
    for (int i = 0; i < pokemons.size(); i++) {
        if (pokemons[i].get_npoke() == pk) {
            pokemons[i].InfoPoke();
            cout << "-------------------------\n";

            ac = "Consulta";
            des = "Se consulto la informacion del pokemon: " + pokemons[i].get_nombre() + " (" + to_string(pokemons[i].get_npoke()) + ")";

            Historial his5;
            his5.guardarPK(ac, des, 3, pk);
            historial.push(his5);
        

            break; 
        }
    }

    // Ver historial de pokemones vistos
    stack<Historial> tempHis = historial;
    while(!tempHis.empty()){
        if(tempHis.top().get_accionId() == 3){
            for (int i = 0; i < pokemons.size(); i++) {
                if (pokemons[i].get_npoke() == tempHis.top().get_num()) {
                    pokemons[i].InfoPoke();
                    cout << "-------------------------\n";
                    break;
                    }
                }
            }
            tempHis.pop();
        }

}