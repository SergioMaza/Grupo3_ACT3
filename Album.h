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

class Album{
private:
    string tituloAlbum;
    GeneroMusica generoMusica;
    Dynarray<Cancion>* canciones;

public:

    // Constructor y metodos
    Album() : tituloAlbum(""), generoMusica(){}

    Album(string tituloAlbum, GeneroMusica generoMusica, Dynarray<Cancion>* cancion){
        Album::tituloAlbum = tituloAlbum;
        Album::generoMusica = generoMusica;
        Album::canciones = cancion;
    }


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
    void buscarCancion(string cancion, Dynarray<Album> &albumes) {
        bool found = false;
        for (int i = 0; i < albumes.capacity(); i++) {
            for(int j = 0; j < albumes.begin()[i].getCanciones()->capacity(); j++) {
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
    void buscarGrupo(string grupo, Dynarray<Album> &albumes) {
        bool found = false;
        for (int i = 0; i < albumes.capacity(); ++i) {
            for (int j = 0; j < albumes.begin()[i].getCanciones()->capacity(); ++j) {
                if(grupo == albumes.begin()[i].getCanciones()->begin()[j].getGrupo()){
                    cout << albumes.begin()[i].getCanciones()->begin()[j].To_String() << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "No se encontro ningun grupo" << endl;
        }
    }
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

    const string &getTituloAlbum() const {
        return tituloAlbum;
    }

    GeneroMusica getGeneroMusica() const {
        return generoMusica;
    }

    void setTituloAlbum(const string &tituloAlbum) {
        Album::tituloAlbum = tituloAlbum;
    }

    void setGeneroMusica(GeneroMusica generoMusica) {
        Album::generoMusica = generoMusica;
    }

    string toString(){
        return "Album: [Titulo: " + tituloAlbum +
               ", Genero: " + to_string(generoMusica);
    }

    void toStringformDynarray(Dynarray<Album> &albumes){
        for(int i = 0; i < albumes.capacity(); i++){
            cout << albumes.begin()[i].toString() << endl;
        }
    }

    Dynarray<Cancion> *getCanciones() const {
        return canciones;
    }

};

#endif //GRUPO3_ACT3_ALBUM_H
