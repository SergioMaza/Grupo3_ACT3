#include <iostream>
#include "Album.h"
#include "Multimedia.h"
#include "enums/Calidad.h"
#include "enums/GeneroMultimedia.h"
#include "enums/GeneroMusica.h"
#include "Dinarray.h"
#include "Cancion.h"

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

int main() {

   cout << "Album" << endl;
   cout << "---------------------" << endl;

       auto *albumes = new Dynarray<Album>(19);
       auto *canciones1 = new Dynarray<Cancion>(9);
       auto *canciones2 = new Dynarray<Cancion>(9);
       auto *cancion1 = new Cancion("Reina", "Mora");
       auto *cancion2 = new Cancion("Como has estau?", "Mora");
       auto *cancion3 = new Cancion("Hey mor", "Feid");
       canciones1->insert(*cancion1);
       canciones1->insert(*cancion2);
       canciones2->insert(*cancion3);
       auto *album1 = new Album("Estrella", Reggae, canciones1);
       auto *album2 = new Album("Feli cumpleannos ferxxo", Reggae, canciones2);

       albumes->insert(*album1);
       albumes->insert(*album2);
       album1->buscarGrupo("Feid", *albumes);
       album1->buscarAlbum("Estrella", *albumes);
       album1->buscarGenero(Reggae,*albumes);
       album1->buscarCancion("Reina", *albumes);
    return 0;
}

