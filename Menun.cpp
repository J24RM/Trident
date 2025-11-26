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
            string _Npoke, _Nombre, _Tipo1, _Tipo2, _Descripcion, _Region;

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
                int opct;
                int topc;
                string tipos[18] = {"Acero", "Agua", "Bicho", "Dragon", "Electrico", "Fantasma", "Fuego", " Hada", "Hielo", "Lucha", "Normal", "Planta", "Psiquico", 
                    "Roca", "Siniestro", "Tierra", "Veneno", "Volador"};
                cout << "¿El pokemon es Doble Tipo?\n";
                cout << "1.- Si \n";
                cout << "2.- No \n";
                cin >> opct;

                // Doble Tipo
                if(opct == 1){
                    int A = 0;
                    while(A == 0){
                        cout << "\n Pokemon Doble-Tipo elejido \n";
                        cout << "Elije el tipo primario: \n";

                        // Imprimir toda la lista de tipos
                        for(int i = 0; i < 18; i++){
                            cout << i+1 << ".- " << tipos[i] << "\n"; 
                        }

                        cin >> topc;
                        topc -= 1;

                        if(topc <= 0 || topc > 18){
                            cout << "Opcion No valida \n";
                        }

                        else{
                            _Tipo1 = tipos[topc];
                            cout << "Se eligio el tipo: " << tipos[topc] << "\n";
                            A = 1;
                        }
                    }


                    A = 0;
                    while (A == 0){
                        cout << "\n Pokemon Doble-Tipo elejido \n";
                        cout << "Elije el tipo secundario: \n";

                        // Imprimir toda la lista de tipos
                        for(int i = 0; i < 18; i++){
                            cout << i+1 << ".- " << tipos[i] << "\n"; 
                        }

                        cin >> topc;
                        topc -= 1;

                        if(topc <= 0 || topc > 18){
                            cout << "Opcion No valida \n";
                        }

                        else{
                            _Tipo2 = tipos[topc];
                            cout << "Se eligio el tipo: " << tipos[topc] << "\n";
                            A = 1;
                        }
                    }
                }


                // Mono Tipo
                else{
                    int A = 0;
                    while(A == 0){
                        cout << "\n Pokemon Mono-Tipo elejido \n";
                        cout << "Elije el tipo primario: \n";

                        // Imprimir toda la lista de tipos
                        for(int i = 0; i < 18; i++){
                            cout << i+1 << ".- " << tipos[i] << "\n"; 
                        }

                        cin >> topc;
                        topc -= 1;

                        if(topc <= 0 || topc > 18){
                           cout << "Opcion No valida \n";
                        }

                        else{
                            _Tipo1 = tipos[topc];
                            _Tipo2 = "Nada";
                            cout << "Se eligio el tipo: " << tipos[topc] << "\n";
                            A = 1;
                        }
                    }

                }
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Descripcion: ";
                getline(cin, _Descripcion);

                cout << "Region: ";
                getline(cin, _Region);

                agregarPoke(_Npoke, _Nombre, _Tipo1, _Tipo2, _Descripcion, _Region, "pokemons.txt", pokemons);

                ac = "Agregar";
                des =  "Se agrego a " + _Nombre + " (" + _Npoke + ")";

                Historial his;

                his.guardar(ac, des);

                historial.push(his);

                // Ordenar después de agregar
                ordenaMerge(pokemons);

                          
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
                for (int i = 1; i < pokemons.size(); i ++) {
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
            if(!tempHis.empty()){
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
            else{
                cout << "No se han consultado pokemones todavia\n";
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
    string _Npoke, _Nombre, _Tipo1, _Tipo2, _Descripcion, _Region;

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
        _Tipo1 = "Normal";
        cout << "Tipo: " << _Tipo1 << "\n";   

        _Tipo2 = "Nada";
        cout << "Tipo: " << _Tipo2 << "\n";

        _Descripcion = "Se dice que es el ancestro de todos los pokemones, debido a que contiene el ADN de todos";
        cout << "Descripcion: " << _Descripcion << "\n";

        _Region = "Kanto";
        cout << "Region: " << _Region << "\n";

        agregarPoke(_Npoke, _Nombre, _Tipo1, _Tipo2, _Descripcion, _Region, "pokemons.txt", pokemons);

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
        for (int i = 1; i < pokemons.size(); i ++) {
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
    pk = 25;
    cout << "\n Elije que el número de pokemon que quieres ver: " << pk << "\n";
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
    pk = 151;
    cout << "\n Elije que el número de pokemon que quieres ver: " << pk << "\n";
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