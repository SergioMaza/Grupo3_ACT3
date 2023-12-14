//
// Created by sergi on 09/12/2023.
//

#ifndef GRUPO3_ACT3_ALBUM_H
#define GRUPO3_ACT3_ALBUM_H

#include "enums/GeneroMusica.h"
#include "Dynarray.h"
#include "Cancion.h"
#include <iomanip>

using namespace std;

class Album {
private:
    string tituloAlbum;
    GeneroMusica generoMusica;
    Dynarray<Cancion> *canciones;

public:

    // Constructor y metodos
    /**
     * Constructor a vacío de Album
     */
    Album() : tituloAlbum(""), generoMusica() {}

    /**
     * Constructor parametrizado de Album
     * @param tituloAlbum Titulo del album
     * @param generoMusica Genero musica del album
     * @param cancion Cancion del album
     */
    Album(string tituloAlbum, GeneroMusica generoMusica, Dynarray<Cancion> *cancion) {
        Album::tituloAlbum = tituloAlbum;
        Album::generoMusica = generoMusica;
        Album::canciones = cancion;
    }

    /**
     * getter de titulo del album
     * @return Regresa el titulo del album
     */
    const string &getTituloAlbum() const {
        return tituloAlbum;
    }

    /**
     * getter de genero musical
     * @return Regresa el genero de musica del album
     */
    GeneroMusica getGeneroMusica() const {
        return generoMusica;
    }


    /**
     * getter de canciones
     * @return canciones
     */
    Dynarray<Cancion> *getCanciones() const {
        return canciones;
    }

    string cancionesToString () const{
        return canciones->to_String();
    }

    /**
     * Te genera un string que te devuelve el album y el genero
     * @return el titulo del album y el genero
     */
    string toString() {
        string genero = "No especificado";

        switch (generoMusica){
            case 0:
                genero = "Pop";
                break;
            case 1:
                genero = "Rock";
                break;
            case 2:
                genero = "HipHop";
                break;
            case 3:
                genero = "Rap";
                break;
            case 4:
                genero = "Reggae";
                break;
            case 5:
                genero = "Indie";
                break;
            case 6:
                genero = "Clasica";
                break;
            case 7:
                genero = "Punk";
                break;
        }
        return "Album: [Titulo: " + tituloAlbum +
               ", Genero: " + genero;
    }

    friend std::ostream& operator<<(std::ostream&os, const Album& al) {
        string genero = "No especificado";

        switch (al.getGeneroMusica()){
            case 0:
                genero = "Pop";
                break;
            case 1:
                genero = "Rock";
                break;
            case 2:
                genero = "HipHop";
                break;
            case 3:
                genero = "Rap";
                break;
            case 4:
                genero = "Reggae";
                break;
            case 5:
                genero = "Indie";
                break;
            case 6:
                genero = "Clasica";
                break;
            case 7:
                genero = "Punk";
                break;
        }
        string c = al.cancionesToString();
        os << (al.getTituloAlbum() +
               ", Genero: " + genero + "\nCanciones:\n" + c);
        return os;
    }


};

/**
* Función que busca el album recorriendo toda la lista
* a partir del titulo del album
* @param tituloAlbum Titulo del album a buscar
* @param albumes La lista a buscar
*/
void buscarAlbum(string tituloAlbum, Dynarray<Album> &albumes) {
    bool found = false;
    for (int i = 0; i < albumes.capacity(); i++) {
        if (tituloAlbum == albumes.begin()[i].getTituloAlbum()) {
            found = true;
            cout << albumes.begin()[i] << endl;
        }
    }
    if (!found) {
        cout << "No se encontro ninguna cancion" << endl;
    }
}

/**
* Función que busca el album recorriendo toda la lista
* a partir de la cancion
* @param cancion Cancion a buscar
* @param albumes La lista en la cual se busca
*/
void buscarCancion(string cancion, Dynarray<Album> &albumes) {
    bool found = false;
    for (int i = 0; i < albumes.capacity(); i++) {
        for (int j = 0; j < albumes.begin()[i].getCanciones()->capacity(); j++) {
            if (cancion == albumes.begin()[i].getCanciones()->begin()[j].getTituloCancion()) {
                found = true;
                cout << albumes.begin()[i].toString() + ", "+ albumes.begin()[i].getCanciones()->begin()[j].to_String() +"]" << endl;
            }
        }
    }
    if (!found) {
        cout << "No se encontro ningun album" << endl;
    }
}

/**
 * Función que busca el album recorriendo toda la lista
 * a partir del grupo
* @param grupo Grupo a buscar
* @param albumes La lista en la cual se busca
*/
void buscarGrupo(string grupo, Dynarray<Album> &albumes) {
    bool found = false;
    for (int i = 0; i < albumes.capacity(); ++i) {
        for (int j = 0; j < albumes.begin()[i].getCanciones()->capacity(); ++j) {
            if (grupo == albumes.begin()[i].getCanciones()->begin()[j].getGrupo()) {
                cout << albumes.begin()[i].toString() + ", "+ albumes.begin()[i].getCanciones()->begin()[j].to_String() +"]" << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No se encontro ningun grupo" << endl;
    }
}

/**
 * Función que busca el album recorriendo toda la lista
 * a partir del género de musica
 * @param generoMusica El genero a buscar en tu lista
 * @param albumes La lista que tiene que recorrer
 */
void buscarGenero(GeneroMusica generoMusica, Dynarray<Album> &albumes) {
    bool found = false;
    for (int i = 0; i < albumes.capacity(); i++) {
        if (generoMusica == albumes.begin()[i].getGeneroMusica()) {
            found = true;
            cout << albumes.begin()[i] << endl;
        }
    }
    if (!found) {
        cout << "No se encontro ningun genero" << endl;
    }
}

#endif //GRUPO3_ACT3_ALBUM_H
