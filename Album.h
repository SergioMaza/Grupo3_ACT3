//
// Created by sergi on 09/12/2023.
//

#ifndef GRUPO3_ACT3_ALBUM_H
#define GRUPO3_ACT3_ALBUM_H

#include "enums/GeneroMusica.h"
#include "Dynarray.h"
#include <iomanip>

using namespace std;

class Album{
private:
    string tituloAlbum;
    string grupo;
    string album;
    GeneroMusica generoMusica;
    string canciones[100];

public:

    // Constructor y metodos
    Album() : tituloAlbum(""), grupo(""), generoMusica(), album(""){}

    Album(string tituloAlbum, string grupo, GeneroMusica generoMusica, string album): tituloAlbum(tituloAlbum), grupo(grupo), generoMusica(generoMusica), album(album){}

    void buscarTitulo(string tituloAlbum, Dynarray<Album> &albumes) {
        bool found = false;
        for (int i = 0; i < albumes.capacity(); i++) {
            if (tituloAlbum == albumes.begin()[i].tituloAlbum) {
                found = true;
                cout << albumes.begin()[i].toString() << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ninguna cancion" << endl;
        }
    }
    void buscarAlbum(string album, Dynarray<Album> &albumes) {
        bool found = false;
        for (int i = 0; i < albumes.capacity(); i++) {
            if (album == albumes.begin()[i].album) {
                found = true;
                cout << albumes.begin()[i].toString() << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ningun album" << endl;
        }
    }
    void buscarGrupo(string grupo, Dynarray<Album> &albumes) {
        bool found = false;
        for (int i = 0; i < albumes.capacity(); i++) {
            if (grupo == albumes.begin()[i].grupo) {
                found = true;
                cout << albumes.begin()[i].toString() << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ningun grupo" << endl;
        }
    }
    void buscarGenero(GeneroMusica generoMusica, Dynarray<Album> &albumes) {
        bool found = false;
        for (int i = 0; i < albumes.capacity(); i++) {
            if (generoMusica == albumes.begin()[i].generoMusica) {
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

    const string &getGrupo() const {
        return grupo;
    }

    GeneroMusica getGeneroMusica() const {
        return generoMusica;
    }

    const string &getAlbum() const {
        return album;
    }

    void setTituloAlbum(const string &tituloAlbum) {
        Album::tituloAlbum = tituloAlbum;
    }

    void setGrupo(const string &grupo) {
        Album::grupo = grupo;
    }

    void setGeneroMusica(GeneroMusica generoMusica) {
        Album::generoMusica = generoMusica;
    }

    void setAlbum(const string &album) {
        Album::album = album;
    }
    string toString(){

        return "Album: [Titulo: " + tituloAlbum +
               ", Grupo: " + grupo +
               ", Album: " + album +
               ", Genero: " + to_string(generoMusica);
    }
    void toStringformDynarray(Dynarray<Album> &albumes){
        for(int i = 0; i < albumes.capacity(); i++){
            cout << albumes.begin()[i].toString() << endl;
        }
    }

};

#endif //GRUPO3_ACT3_ALBUM_H
