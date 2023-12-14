#include <iostream>
#include <Windows.h> //para los colores de la consola
#include "Album.h"
#include "Multimedia.h"
#include "enums/Calidad.h"
#include "enums/GeneroMultimedia.h"
#include "enums/GeneroMusica.h"
#include "Dynarray.h"
#include "Cancion.h"
#include <limits> //para el correcto funcionamiento del try catch

void alquilarODevolver(string titulo, Dynarray<Multimedia> &mult, int e) {
    bool encontrado;
    int opcion;
    for (int i = 0; i < mult.capacity(); i++) {
        if (titulo == mult.begin()[i].getTitulo()) {
            cout << "Se ha encontrado: " << endl;
            cout << mult.begin()[i] << endl;
            if (e == 0) {
                cout << "Quieres alquilarlo? \n1. Si \n2. No" << endl;
            } else { cout << "Quieres devolverlo?\n1. Si \n2. No" << endl; }
            if (!(cin >> opcion)) {
                throw runtime_error("Tienes que escribir un numero del 1 al 2");
            }
            switch (opcion) {
                case 1:
                    if (e == 0) {
                        if (mult.begin()[i].isDispo()) {
                            cout << "Alquilado!" << endl;
                            mult.begin()[i].setDispo(FALSE);
                        } else {
                            cout << "Lo siento pero no esta disponible!" << endl;
                        }

                    } else {
                        if (!mult.begin()[i].isDispo()) {
                            cout << "Devuelto!" << endl;
                            mult.begin()[i].setDispo(FALSE);
                        } else {
                            cout << "No se puede devolver porque no estaba alquilado" << endl;
                        }

                    }
                    break;
                case 2:
                    if (e == 0) {
                        cout << "No ha sido alquilado" << endl;
                    } else {
                        cout << "No ha sido devuelto" << endl;
                    }

                    break;
                default:
                    throw runtime_error("Tienes que escribir un numero del 1 al 2");
            }
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se ha encontrado ninguna multimedia con el titulo especificado" << endl;
    }
}


int main() {
    //variables
    int opcion, opcion2;
    bool noAcept = true, seguir = true;
    string titulo;

    //Peliculas
    Multimedia *pelicula1 = new Multimedia("HarryPotterYLaPiedraFilosodal", Fantasia, FHD, true);
    Multimedia *pelicula2 = new Multimedia("DoraemonYElReinoDeKibo", Fantasia, UHD, true);
    Multimedia *pelicula3 = new Multimedia("Coco", Musical, UHD, true);
    Multimedia *pelicula4 = new Multimedia("ElReyLeon", Musical, UHD, true);
    Multimedia *pelicula5 = new Multimedia("RegresoAlFuturo", CienciaFiccion, FHD, true, 0.99);
    Multimedia *pelicula6 = new Multimedia("ComoEntrenarATuDragon", Fantasia, UHD, true);
    Multimedia *pelicula7 = new Multimedia("EntrevistaConElVampiro", Suspense, FHD, true);
    Multimedia *pelicula8 = new Multimedia("GuardianesDeLaGalaxiaVol1", CienciaFiccion, FHD, true, 3.99);


    //series
    Multimedia *serie1 = new Multimedia("RickYMorty", CienciaFiccion, UHD, true);
    Multimedia *serie2 = new Multimedia("BreakingBad", Drama, FHD, true);
    Multimedia *serie3 = new Multimedia("InazumaEleven", Accion, UHD, true);
    Multimedia *serie4 = new Multimedia("SaintSeiya", Accion, FHD, true);
    Multimedia *serie5 = new Multimedia("RanmaYMedio", Romance, FHD, true);
    Multimedia *serie6 = new Multimedia("DeathNote", Suspense, UHD, true);
    Multimedia *serie7 = new Multimedia("Castle", Comedia, UHD, true);
    Multimedia *serie8 = new Multimedia("DesafioChampionsSendokai", Accion, UHD, true);
    Multimedia *serie9 = new Multimedia("JujutsuKaisen", Fantasia, UHD, true);
    Multimedia *serie10 = new Multimedia("KimetsuNoYaiba", Aventura, UHD, true);
    Multimedia *serie11 = new Multimedia("Arcane", Fantasia, UHD, true);
    Multimedia *serie12 = new Multimedia("BokuNoHero", Fantasia, UHD, true);
    Multimedia *serie13 = new Multimedia("Parasyte", Terror, UHD, true);
    Multimedia *serie14 = new Multimedia("AssassinationClassroom", Comedia, UHD, true);
    Multimedia *serie15 = new Multimedia("Hearthstoper", Romance, FHD, true);
    Multimedia *serie16 = new Multimedia("PhineasYFerb", CienciaFiccion, FHD, true);
    Multimedia *serie17 = new Multimedia("HoraDeAventuras", Aventura, FHD, true);

    auto *multimedia = new Dynarray<Multimedia>(1);

    multimedia->insert(*pelicula1);
    multimedia->insert(*pelicula2);
    multimedia->insert(*pelicula3);
    multimedia->insert(*pelicula4);
    multimedia->insert(*pelicula5);
    multimedia->insert(*pelicula6);
    multimedia->insert(*pelicula7);
    multimedia->insert(*pelicula8);
    multimedia->insert(*serie1);
    multimedia->insert(*serie2);
    multimedia->insert(*serie3);
    multimedia->insert(*serie4);
    multimedia->insert(*serie5);
    multimedia->insert(*serie6);
    multimedia->insert(*serie7);
    multimedia->insert(*serie8);
    multimedia->insert(*serie9);
    multimedia->insert(*serie10);
    multimedia->insert(*serie11);
    multimedia->insert(*serie12);
    multimedia->insert(*serie13);
    multimedia->insert(*serie14);
    multimedia->insert(*serie15);
    multimedia->insert(*serie16);
    multimedia->insert(*serie17);

    cout << "------------------------------" << endl;
    cout << "         Bienvenido a " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_GREEN); // Cambia el color del texto en la consola
    cout << "          Spoty";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    cout << "Flix" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE); //reestablece el color del texto en la consola
    cout << "------------------------------" << endl;

    cout << endl;
    cout << endl;
    while (noAcept) {
        try {
            cout << "Aceptas la politica de privacidad? \n1. Si \n2. Si" << endl;
            if (!(cin >> opcion)) {
                throw runtime_error("Tienes que escribir un numero del 1 al 2");
            }
            if (opcion != 1 && opcion != 2) {
                throw runtime_error("Por favor acepta la politica de privacidad");
            } else { noAcept = false; }

        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            cin.clear(); // Restablece el valor del cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        }
    }

    cin.clear();
    noAcept = true;

    cout << endl;
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    cout << "Gracias por aceptar la politica de privacidad! :D" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << endl;
    cout << endl;

    while (noAcept) {
        try {

            cout << endl;
            cout << "---------" << endl;
            cout << "Por favor elije una opcion:" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                    FOREGROUND_RED); // Cambia el color del texto en la consola
            cout << "1. Multimedia" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                    FOREGROUND_GREEN); // Cambia el color del texto en la consola
            cout << "2. Musica" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "3. Salir" << endl;

            if (!(cin >> opcion)) {
                throw runtime_error("Tienes que escribir un numero del 1 al 3");
            }

            switch (opcion) {
                case 1:
                    while (true) {
                        cout << endl;
                        cout << "---------" << endl;
                        cout
                                << "Escoge una opcion: \n1. Ver multimedia \n2. Buscar multimedia\n3. Alquilar Multimedia \n4. Devolver multimedia \n5. Volver"
                                << endl;
                        cin.clear();
                        if (!(cin >> opcion2)) {
                            throw runtime_error("Tienes que escribir un numero del 1 al 5");
                        }

                        switch (opcion2) {
                            case 1:
                                multimedia->toString();
                                break;
                            case 2:
                                while (seguir) {
                                    cout << endl;
                                    cout << "---------" << endl;
                                    cout
                                            << "Como quieres buscar multimedia: \n1. Por calidad \n2. Por genero \n3. Por titulo \n4. Volver"
                                            << endl;
                                    if (!(cin >> opcion2)) {
                                        throw runtime_error("Tienes que escribir un numero del 1 al 4");
                                    }
                                    switch (opcion2) {
                                        case 1:
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout << "Selecciona la calidad: \n1. FHD \n2. UHD \n3. volver" << endl;
                                            if (!(cin >> opcion2)) {
                                                throw runtime_error("Tienes que escribir un numero del 1 al 3");
                                            }
                                            switch (opcion2) {
                                                case 1:
                                                    buscarCalidad(FHD, *multimedia);
                                                    break;
                                                case 2:
                                                    buscarCalidad(UHD, *multimedia);
                                                    break;
                                                case 3:
                                                    cout << "Volviendo al menu anterior..." << endl;
                                                    break;
                                                default:
                                                    throw runtime_error("Tienes que escribir un numero del 1 al 3");
                                            }
                                            break;
                                        case 2 :
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout
                                                    << "Selecciona un genero: \n1.Accion \n2. Comedia \n3. Drama \n4. Ciencia Ficcion \n5. Terror "
                                                       "\n6. Aventura \n7. Suspense \n8. Romance \n9. Musical \n10. Fantasia"
                                                    << endl;
                                            if (!(cin >> opcion2)) {
                                                throw runtime_error("Tienes que escribir un numero del 1 al 10");
                                            }
                                            switch (opcion2) {
                                                case 1:
                                                    buscarGenero(Accion, *multimedia);
                                                    break;
                                                case 2:
                                                    buscarGenero(Comedia, *multimedia);
                                                    break;
                                                case 3:
                                                    buscarGenero(Drama, *multimedia);
                                                    break;
                                                case 4:
                                                    buscarGenero(CienciaFiccion, *multimedia);
                                                    break;
                                                case 5:
                                                    buscarGenero(Terror, *multimedia);
                                                    break;
                                                case 6:
                                                    buscarGenero(Aventura, *multimedia);
                                                    break;
                                                case 7:
                                                    buscarGenero(Suspense, *multimedia);
                                                    break;
                                                case 8:
                                                    buscarGenero(Romance, *multimedia);
                                                    break;
                                                case 9:
                                                    buscarGenero(Musical, *multimedia);
                                                    break;
                                                case 10:
                                                    buscarGenero(Fantasia, *multimedia);
                                                    break;
                                                default:
                                                    throw runtime_error("Tienes que escribir un numero del 1 al 10");

                                            }
                                            break;
                                        case 3:
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout << "Escribe el titulo que quieres buscar: " << endl;
                                            if (!(cin >> titulo)) {
                                                throw runtime_error("No se ha guardado el titulo");
                                            }
                                            buscarTitulo(titulo, *multimedia);
                                            break;
                                        case 4:
                                            cout << "Volviendo al menu anterior..." << endl;
                                            seguir = false;
                                            break;
                                    }
                                }
                                break;
                            case 3:
                                cout << "Escribe el titulo del multimedia que quieres alquilar: " << endl;
                                if (!(cin >> titulo)) {
                                    throw runtime_error("No se ha guardado el titulo");
                                }
                                alquilarODevolver(titulo, *multimedia, 0);
                                break;
                            case 4:
                                cout << "Escribe el titulo del multimedia que quieres devolver: " << endl;
                                if (!(cin >> titulo)) {
                                    throw runtime_error("No se ha guardado el titulo");
                                }
                                alquilarODevolver(titulo, *multimedia, 1);
                                break;
                            case 5:
                                cout << "Volviendo al menu anterior..." << endl;
                                break;
                            default:
                                throw runtime_error("Tienes que escribir un numero del 1 al 5");
                        }

                        if (opcion2 == 5) {
                            break;
                        }
                    }
                    break;

                case 2:
                    cout << "Opción Multimedia" << endl;  // Aquí debes poner la lógica correspondiente
                    break;

                case 3:
                    noAcept = false;
                    cout << "Hasta la proxima!" << endl;
                    break;

                default:
                    throw runtime_error("Tienes que escribir un numero del 1 al 3");
            }

        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}
