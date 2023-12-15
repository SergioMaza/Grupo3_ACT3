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

/**
 * Metodo que te deja alquilar y devolver un multimedia
 * @param titulo titulo de la multimedia que se quiere alquilar o devolver
 * @param mult dynarray de multimedia
 * @param e si es 0 se quiere alquilar la pelicula, si es 1 se quiere devolver
 */
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
                            if (!mult.begin()[i].isIncluded()){
                                cout << "No esta incluido, quieres pagar " << to_string(mult.begin()[i].getPrecioExtra()) << "?\n1. Si \n2. No" << endl;
                                if (!(cin >> opcion)) {
                                    throw runtime_error("Tienes que escribir un numero del 1 al 2");
                                }
                                if (opcion == 1){cout << "Alquilado!" << endl;
                                    mult.begin()[i].setDispo(FALSE);} else {
                                    cout << "No ha sido alquilado" << endl;
                                }
                            } else {cout << "Alquilado!" << endl;
                                mult.begin()[i].setDispo(FALSE);}

                        } else {
                            cout << "Lo siento pero no esta disponible!" << endl;
                        }

                    } else {
                        if (!mult.begin()[i].isDispo()) {
                            cout << "Devuelto!" << endl;
                            mult.begin()[i].setDispo(TRUE);
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

    //Canciones
    Cancion *casiNada1 = new Cancion("ElMundoBajoMisPies", "Subze");
    Cancion *casiNada2 = new Cancion("DeathRow", "Subze");
    Cancion *casiNada3 = new Cancion("Cryptolais", "Subze");
    Cancion *casiNada4 = new Cancion("CartaAMiDepresion", "Subze");
    Cancion *casiNada5 = new Cancion("VeniVidiVici", "Subze");
    Cancion *casiNada6 = new Cancion("Millennial", "Subze");
    Cancion *casiNada7 = new Cancion("CampeonDelMundo", "Subze");

    Cancion *rocketman1 = new Cancion("Rocketman", "Ambkor");
    Cancion *rocketman2 = new Cancion("Contigo", "Ambkor");
    Cancion *rocketman3 = new Cancion("Espejo", "Ambkor");
    Cancion *rocketman4 = new Cancion("ContandoEstrellas", "Ambkor");
    Cancion *rocketman5 = new Cancion("Alcatraz", "Ambkor");
    Cancion *rocketman6 = new Cancion("BarcosHundidos", "Ambkor");
    Cancion *rocketman7 = new Cancion("ATravesDeEllas", "Ambkor");

    Cancion *estrella1 = new Cancion("MediaLuna", "Mora");
    Cancion *estrella2 = new Cancion("Pasajero", "Mora");
    Cancion *estrella3 = new Cancion("Polvora", "Mora");
    Cancion *estrella4 = new Cancion("DondeSeAprendeAQuerer?", "Mora");
    Cancion *estrella5 = new Cancion("Reina", "Mora");
    Cancion *estrella6 = new Cancion("Fantasias", "Mora");
    Cancion *estrella7 = new Cancion("ElChacal", "Mora");
    Cancion *estrella8 = new Cancion("Laguna", "Mora");
    Cancion *estrella9 = new Cancion("Lokita", "Mora");
    Cancion *estrella10 = new Cancion("Pide", "Mora");
    Cancion *estrella11 = new Cancion("UnDeseo", "Mora");
    Cancion *estrella12 = new Cancion("Diamonds", "Mora");
    Cancion *estrella13 = new Cancion("Corcega", "Mora");
    Cancion *estrella14 = new Cancion("Marea", "Mora");
    Cancion *estrella15 = new Cancion("AyerYHoy", "Mora");

    Cancion *yoMinoriaAbsoluta1 = new Cancion("AFuego", "Extremoduro");
    Cancion *yoMinoriaAbsoluta2 = new Cancion("LaVeredaDeLaPuertaDeAtras", "Extremoduro");
    Cancion *yoMinoriaAbsoluta3 = new Cancion("HoyTeLaMetoHastaLasOrejas", "Extremoduro");
    Cancion *yoMinoriaAbsoluta4 = new Cancion("StandBy", "Extremoduro");
    Cancion *yoMinoriaAbsoluta5 = new Cancion("Menamoro", "Extremoduro");
    Cancion *yoMinoriaAbsoluta6 = new Cancion("LuceLaOscuridad", "Extremoduro");
    Cancion *yoMinoriaAbsoluta7 = new Cancion("CercaDelSuelo", "Extremoduro");
    Cancion *yoMinoriaAbsoluta8 = new Cancion("Puta", "Extremoduro");
    Cancion *yoMinoriaAbsoluta9 = new Cancion("BuitreNoComeAlpiste", "Extremoduro");
    Cancion *yoMinoriaAbsoluta10 = new Cancion("LaVieja", "Extremoduro");

    Cancion *clasicos1 = new Cancion("SerenadeNo13", "Mozart");
    Cancion *clasicos2 = new Cancion("TripleConcertoForViolin", "Beethoven");
    Cancion *clasicos3 = new Cancion("NocturneNo20", "Chopin");
    Cancion *clasicos4 = new Cancion("TheNutcracker", "Tchaikovsky");
    Cancion *clasicos5 = new Cancion("Overture", "Bach");
    Cancion *clasicos6 = new Cancion("TheFourSeasons", "Vivaldi");

    Cancion *electraHeart1 = new Cancion("BubblegumBitch", "Marina");
    Cancion *electraHeart2 = new Cancion("Primadonna", "Marina");
    Cancion *electraHeart3 = new Cancion("TeenIdle", "Marina");
    Cancion *electraHeart4 = new Cancion("HowToBeAHeartbreaker", "Marina");

    Cancion *nombreDireccion1 = new Cancion("NombreDireccion", "Kaze");
    Cancion *nombreDireccion2 = new Cancion("TKT", "Kaze");
    Cancion *nombreDireccion3 = new Cancion("ElPlan", "Kaze");
    Cancion *nombreDireccion4 = new Cancion("Relajateee", "Kaze");

    Cancion *theUnderratedYouth1 = new Cancion("Parents", "Yungblud");
    Cancion *theUnderratedYouth2 = new Cancion("Braindead", "Yungblud");
    Cancion *theUnderratedYouth3 = new Cancion("OriginalMe", "Yungblud");
    Cancion *theUnderratedYouth4 = new Cancion("CasualSabotage", "Yungblud");
    Cancion *theUnderratedYouth5 = new Cancion("HopeForTheUnderratedYouth", "Yungblud");
    Cancion *theUnderratedYouth6 = new Cancion("WaitingOnTheWeekend", "Yungblud");

    //dynarrays de canciones
    auto* casiNadaC = new Dynarray<Cancion>(1);
    casiNadaC->insert(*casiNada1);
    casiNadaC->insert(*casiNada2);
    casiNadaC->insert(*casiNada3);
    casiNadaC->insert(*casiNada4);
    casiNadaC->insert(*casiNada5);
    casiNadaC->insert(*casiNada6);
    casiNadaC->insert(*casiNada7);

    auto* rocketmanC = new Dynarray<Cancion>(1);
    rocketmanC->insert(*rocketman1);
    rocketmanC->insert(*rocketman2);
    rocketmanC->insert(*rocketman3);
    rocketmanC->insert(*rocketman4);
    rocketmanC->insert(*rocketman5);
    rocketmanC->insert(*rocketman6);
    rocketmanC->insert(*rocketman7);

    auto* estrellaC = new Dynarray<Cancion>(1);
    estrellaC->insert(*estrella1);
    estrellaC->insert(*estrella2);
    estrellaC->insert(*estrella3);
    estrellaC->insert(*estrella4);
    estrellaC->insert(*estrella5);
    estrellaC->insert(*estrella6);
    estrellaC->insert(*estrella7);
    estrellaC->insert(*estrella8);
    estrellaC->insert(*estrella9);
    estrellaC->insert(*estrella10);

    auto* yoMinoriaAbsolutaC = new Dynarray<Cancion>(1);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta1);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta2);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta3);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta4);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta5);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta6);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta7);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta8);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta9);
    yoMinoriaAbsolutaC->insert(*yoMinoriaAbsoluta10);

    auto* clasicosC = new Dynarray<Cancion>(1);
    clasicosC->insert(*clasicos1);
    clasicosC->insert(*clasicos2);
    clasicosC->insert(*clasicos3);
    clasicosC->insert(*clasicos4);
    clasicosC->insert(*clasicos5);
    clasicosC->insert(*clasicos6);

    auto* electraHeartC = new Dynarray<Cancion>(1);
    electraHeartC->insert(*electraHeart1);
    electraHeartC->insert(*electraHeart2);
    electraHeartC->insert(*electraHeart3);
    electraHeartC->insert(*electraHeart4);

    auto* nombreDireccionC = new Dynarray<Cancion>(1);
    nombreDireccionC->insert(*nombreDireccion1);
    nombreDireccionC->insert(*nombreDireccion2);
    nombreDireccionC->insert(*nombreDireccion3);
    nombreDireccionC->insert(*nombreDireccion4);

    auto* theUnderratedYouthC = new Dynarray<Cancion>(1);
    theUnderratedYouthC->insert(*theUnderratedYouth1);
    theUnderratedYouthC->insert(*theUnderratedYouth2);
    theUnderratedYouthC->insert(*theUnderratedYouth3);
    theUnderratedYouthC->insert(*theUnderratedYouth4);
    theUnderratedYouthC->insert(*theUnderratedYouth5);
    theUnderratedYouthC->insert(*theUnderratedYouth6);

    //albumes
    Album *album1 = new Album("CasiNada", Pop, casiNadaC);
    Album *album2 = new Album("Rocketman", HipHop, rocketmanC);
    Album *album3 = new Album("Estrella", Reggae, estrellaC);
    Album *album4 = new Album("YoMinoriaAbsoluta", Rock, yoMinoriaAbsolutaC);
    Album *album5 = new Album("Clasicos", Clasica, clasicosC);
    Album *album6 = new Album("ElectraHearth", Indie, electraHeartC);
    Album *album7 = new Album("NombreDireccion", Rap, nombreDireccionC);
    Album *album8 = new Album("TheUnderratedYouth", Punk, theUnderratedYouthC);

    //Dynarray de albumes
    auto* musica = new Dynarray<Album>(1);
    musica->insert(*album1);
    musica->insert(*album2);
    musica->insert(*album3);
    musica->insert(*album4);
    musica->insert(*album5);
    musica->insert(*album6);
    musica->insert(*album7);
    musica->insert(*album8);

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
                                seguir = true;
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
                                                    << "Selecciona un genero: \n1. Accion \n2. Comedia \n3. Drama \n4. Ciencia Ficcion \n5. Terror "
                                                       "\n6. Aventura \n7. Suspense \n8. Romance \n9. Musical \n10. Fantasia \n11. Volver"
                                                    << endl;
                                            if (!(cin >> opcion2)) {
                                                throw runtime_error("Tienes que escribir un numero del 1 al 11");
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
                                                case 11:
                                                    cout << "Volviendo al menu anterior..." << endl;
                                                    break;
                                                default:
                                                    throw runtime_error("Tienes que escribir un numero del 1 al 11");

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
                                cout << endl;
                                cout << "---------" << endl;
                                cout << "Escribe el titulo del multimedia que quieres alquilar: " << endl;
                                if (!(cin >> titulo)) {
                                    throw runtime_error("No se ha guardado el titulo");
                                }
                                alquilarODevolver(titulo, *multimedia, 0);
                                break;
                            case 4:
                                cout << endl;
                                cout << "---------" << endl;
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
                    while (true){
                        cout << endl;
                        cout << "---------" << endl;
                        cout << "Escoge una opcion: \n1. Ver toda la musica \n2. Buscar musica \n3. Volver" << endl;
                        if (!(cin >> opcion2)) {
                            throw runtime_error("Tienes que escribir un numero del 1 al 3");
                        }
                        switch(opcion2){
                            case 1:
                                musica->toString();
                                break;
                            case 2:
                                seguir = true;
                                while (seguir) {
                                    cout << endl;
                                    cout << "---------" << endl;
                                    cout
                                            << "Como quieres buscar la cancion: \n1. Buscar titulo de la cancion \n2. Buscar Grupo \n3. Buscar titulo del album \n4. Buscar genero \n5. Volver"
                                            << endl;
                                    if (!(cin >> opcion2)) {
                                        throw runtime_error("Tienes que escribir un numero del 1 al 3");
                                    }
                                    switch (opcion2) {
                                        case 1:
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout << "Escribe el titulo de la cancion que quieres buscar: " << endl;
                                            if (!(cin >> titulo)) {
                                                throw runtime_error("No se ha guardado el titulo");
                                            }
                                            buscarCancion(titulo, *musica);
                                            break;
                                        case 2:
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout << "Escribe el grupo de la cancion que quieres buscar: " << endl;
                                            if (!(cin >> titulo)) {
                                                throw runtime_error("No se ha guardado el grupo");
                                            }
                                            buscarGrupo(titulo, *musica);
                                            break;
                                        case 3:
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout << "Escribe el titulo del album que quieres buscar: " << endl;
                                            if (!(cin >> titulo)) {
                                                throw runtime_error("No se ha guardado el titulo");
                                            }
                                            buscarAlbum(titulo, *musica);
                                            break;
                                        case 4:
                                            cout << endl;
                                            cout << "---------" << endl;
                                            cout
                                                    << "Selecciona un genero: \n1. Pop \n2. Rock \n3. HipHop \n4. Rap \n5. Reggae "
                                                       "\n6. Indie \n7. Clasica \n8. Punk \n9. Volver"
                                                    << endl;
                                            if (!(cin >> opcion2)) {
                                                throw runtime_error("Tienes que escribir un numero del 1 al 10");
                                            }
                                            switch (opcion2) {
                                                case 1:
                                                    buscarGenero(Pop, *musica);
                                                    break;
                                                case 2:
                                                    buscarGenero(Rock, *musica);
                                                    break;
                                                case 3:
                                                    buscarGenero(HipHop, *musica);
                                                    break;
                                                case 4:
                                                    buscarGenero(Rap, *musica);
                                                    break;
                                                case 5:
                                                    buscarGenero(Reggae, *musica);
                                                    break;
                                                case 6:
                                                    buscarGenero(Indie, *musica);
                                                    break;
                                                case 7:
                                                    buscarGenero(Clasica, *musica);
                                                    break;
                                                case 8:
                                                    buscarGenero(Punk, *musica);
                                                    break;
                                                case 9:
                                                    cout << "Volviendo al menu anterior..." << endl;
                                                    break;
                                                default:
                                                    throw runtime_error("Tienes que escribir un numero del 1 al 8");

                                            }
                                            break;
                                        case 5:
                                            cout << "Volviendo al menu anterior..." << endl;
                                            seguir = false;
                                            break;
                                    }

                                }
                                break;
                            case 3:
                                cout << "Volviendo al menu anterior..." << endl;
                                break;
                            default:
                                throw runtime_error("Tienes que escribir un numero del 1 al 3");
                        }
                        if (opcion2 == 3){
                            break;
                        }
                    }

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
