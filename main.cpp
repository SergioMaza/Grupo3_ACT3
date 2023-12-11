#include <iostream>
#include "Album.h"
#include "Multimedia.h"
#include "enums/Calidad.h"
#include "enums/GeneroMultimedia.h"
#include "enums/GeneroMusica.h"
#include "Dinarray.h"

int main() {

   cout << "Album" << endl;
   cout << "---------------------" << endl;

   auto *albumes = new Dynarray<Album>(1);
   auto *album1 = new Album("Set fire to the rain", "Adele", Pop, "21");
   auto *album2 = new Album("i got you babe", "The Dictators", Punk, "Go girl crazy!");
   Album aux;
   albumes->insert(*album1);
   albumes->insert(*album2);
   album1->buscarTitulo("Set fire to the rain", *albumes);
   album2->buscarAlbum("Go girl crazy!", *albumes);


    return 0;
}
