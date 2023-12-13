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
    /**
     * Constructor a vacío de Cancion
     */
    Cancion() {}
    /**
     * Constuctor que inicializa el album
     * @param tituloCancion El título de la cancion del album
     * @param grupo El grupo del album
     */
    Cancion(string tituloCancion, string grupo): tituloCancion(tituloCancion), grupo(grupo){}

    /**
     * Metodo para conseguir el grupo
     * @return Regresa el grupo del album
     */
    string getGrupo(){
        return grupo;
    }
    /**
     * Metodo para connseguir el titulo de la cancion
     * @return Regresa el titulo de la cancion
     */
    const string &getTituloCancion() const {
        return tituloCancion;
    }
    /**
     * Metodo to_string que muestra por pantalla los parametros
     * @return Regresa la cancion y el grupo
     */
    string To_String(){
        return "Cancion: " + tituloCancion + " , Grupo: " + grupo ;
    }
};

#endif //GRUPO3_ACT3_CANCION_H
