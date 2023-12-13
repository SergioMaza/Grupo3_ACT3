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
     * Te genera un string que te devuelve el album y el genero
     * @return el titulo del album y el genero
     */
    string toString() {
        return "Album: [Titulo: " + tituloAlbum +
               ", Genero: " + to_string(generoMusica);
    }

    /**
     * Te muestra los albumes por pantalla
     * @param albumes
     */
    void toStringformDynarray(Dynarray<Album> &albumes) {
        for (int i = 0; i < albumes.capacity(); i++) {
            cout << albumes.begin()[i].toString() << endl;
        }
    }

    /**
     * getter de canciones
     * @return canciones
     */
    Dynarray<Cancion> *getCanciones() const {
        return canciones;
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
            cout << albumes.begin()[i].toString() << endl;
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
                cout << albumes.begin()[i].toString() << endl;
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
                cout << albumes.begin()[i].getCanciones()->begin()[j].To_String() << endl;
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
            cout << albumes.begin()[i].toString() << endl;
        }
    }
    if (!found) {
        cout << "No se encontro ningun genero" << endl;
    }
}

#endif //GRUPO3_ACT3_ALBUM_H
