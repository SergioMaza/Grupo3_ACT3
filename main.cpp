#include <iostream>
#include "Album.h"
#include "Multimedia.h"
#include "enums/Calidad.h"
#include "enums/GeneroMultimedia.h"
#include "enums/GeneroMusica.h"
#include "Dinarray.h"
#include "Cancion.h"

int main() {

   cout << "Album" << endl;
   cout << "---------------------" << endl;

       auto *albumes = new Dynarray<Album>(19);
       auto *canciones = new Dynarray<Cancion>(9);
       auto *cancion1 = new Cancion("Reina", "Mora");
       auto *cancion2 = new Cancion("Como has estau?", "Mora");
       canciones->insert(*cancion1);
       canciones->insert(*cancion2);
    for (int i = 0; i < canciones->capacity(); ++i) {
        cout << canciones->begin()[i].To_String() << endl;
    }
       auto *album1 = new Album("Estrella", Reggae, canciones);
       //auto *album2 = new Album("I got you babe", "The Dictators", Punk, a);
       //auto *album3 = new Album("The lazy song", "Bruno Mars", Reggae, a);
       //auto *album4 = new Album("Levels", "Avicii", Electronica, a);
       Album aux;

       albumes->insert(*album1);
       // albumes->insert(*album2);
       // albumes->insert(*album3);
       // albumes->insert(*album4);
       album1->buscarGrupo("Mora", *albumes);
       // album2->buscarCancion("I got you babe", *albumes);
       // album3->buscarGrupo("Bruno Mars", *albumes);
       // album4->buscarGenero(Electronica, *albumes);
    return 0;
}
