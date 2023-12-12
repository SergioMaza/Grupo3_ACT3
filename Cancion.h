//
// Created by Vidhi on 12/12/2023.
//

#ifndef GRUPO3_ACT3_CANCION_H
#define GRUPO3_ACT3_CANCION_H
#include <iostream>
using namespace std;

class Cancion{
private:
    string grupo;
    string tituloCancion;
public:
    Cancion() {}

    Cancion(string tituloCancion, string grupo): tituloCancion(tituloCancion), grupo(grupo){}

    string getGrupo(){
        return grupo;
    }

    void setGrupo(const string &grupo) {
        Cancion::grupo = grupo;
    }

    const string &getTituloCancion() const {
        return tituloCancion;
    }

    void setTituloCancion(const string &tituloCancion) {
        Cancion::tituloCancion = tituloCancion;
    }

    string To_String(){
        return "Cancion: " + tituloCancion + " , Grupo: " + grupo ;
    }
};

#endif //GRUPO3_ACT3_CANCION_H
