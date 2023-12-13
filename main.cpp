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

    return 0;
}

