//
// Created by sergi on 09/12/2023.
//

#ifndef GRUPO3_ACT3_MULTIMEDIA_H
#define GRUPO3_ACT3_MULTIMEDIA_H

#include <iomanip>
#include "enums/GeneroMultimedia.h"
#include "enums/Calidad.h"
#include "Dynarray.h"
#include <iomanip>

using namespace std;

class Multimedia {
private:
    string titulo;
    GeneroMultimedia generoMultimedia;
    Calidad calidad;
    bool dispo;
    bool included;
    double precioExtra;

public:

    /**
     * Constructor paramterizado de contenido incluido en la tarifa
     * @param titulo Titulo de la serie/peli
     * @param generoMultimedia // Genero de la serie/peli
     * @param calidad // Calidad de la serie/peli
     * @param dispo // True -> Esta disponible | False -> No esta disponible
     */
    Multimedia(string titulo, GeneroMultimedia generoMultimedia, Calidad calidad, bool dispo) :
            titulo(titulo),
            generoMultimedia(generoMultimedia),
            calidad(calidad),
            dispo(dispo) {
        included = true;
        precioExtra = 0.0;
    }

    /**
     * Constructor parametrizado de contenido no incluido en la tarifa
     * @param titulo Titulo de la serie/peli
     * @param generoMultimedia // Genero de la serie/peli
     * @param calidad // Calidad de la serie/peli
     * @param dispo // True -> Esta disponible | False -> No esta disponible
     * @param precioExtra // Precio extra al no estar incluida
     */
    Multimedia(string titulo, GeneroMultimedia generoMultimedia, Calidad calidad, bool dispo, double precioExtra) :
            titulo(titulo),
            generoMultimedia(generoMultimedia),
            calidad(calidad),
            dispo(dispo),
            included(included),
            precioExtra(precioExtra) {
        included = false;
    }

    Multimedia(){};

    /**
     * Metodo para busacar una multimedia a partir del titulo
     * @param titulo Titlo de la multimedia a buscar
     * @param mult Dynarray de las multimedias
     * @return Multimedia con el titulo
     */
    void buscarTitulo(string titulo, Dynarray<Multimedia> &mult){
        bool encontrado;
        for(int i = 0; i < mult.capacity(); i++){
            if(titulo == mult.begin()[i].titulo){
                cout <<  mult.begin()[i].toString() << endl;
                encontrado = true;
            }
        }
        if(!encontrado){
            cout << "No se ha encontrado ninguna multimedia con el titulo especificado" << endl;
        }
    }

    void buscarGenero(GeneroMultimedia genero, Dynarray<Multimedia> &mult){
        bool encontrado;
        for(int i = 0; i < mult.capacity(); i++){
            if(genero == mult.begin()[i].generoMultimedia){
                cout <<  mult.begin()[i].toString() << endl;
                encontrado = true;
            }
        }
        if(!encontrado){
            cout << "No se ha encontrado ninguna multimedia con el genero especificado" << endl;
        }
    }

    void buscarCalidad(Calidad calidad, Dynarray<Multimedia> &mult){
        bool encontrado;
        for(int i = 0; i < mult.capacity(); i++){
            if(calidad == mult.begin()[i].getCalidad()){
                cout <<  mult.begin()[i].toString() << endl;
                encontrado = true;
            }
        }
        if(!encontrado){
            cout << "No se ha encontrado ninguna multimedia con la calidad especificada" << endl;
        }
    }

    const string &getTitulo() const {
        return titulo;
    }

    GeneroMultimedia getGeneroMultimedia() const {
        return generoMultimedia;
    }

    Calidad getCalidad() const {
        return calidad;
    }

    bool isDispo() const {
        return dispo;
    }

    bool isIncluded() const {
        return included;
    }

    double getPrecioExtra() const {
        return precioExtra;
    }

    void setDispo(bool dispo) {
        Multimedia::dispo = dispo;
    }

    void setIncluded(bool included) {
        Multimedia::included = included;
    }

    void setPrecioExtra(double precioExtra) {
        Multimedia::precioExtra = precioExtra;
    }

    string toString(){
        string dispoToString = (dispo) ? "Disponible" : "No disponible";
        string includedToString = (included) ? "Si" : "No";

        return "Multimedia: [Titulo: " + titulo +
        ", Genero: " + to_string(generoMultimedia) +
        ", Calidad: " + to_string(calidad) +
        ", " + dispoToString +
        ", Incluido con su tarifa: " + includedToString +
        ", Precio extra = " + to_string(precioExtra);
    }

    void toStringformDynarray(Dynarray<Multimedia> &mult){
        for(int i = 0; i < mult.capacity(); i++){
            cout << mult.begin()[i].toString() << endl;
        }
    }
};

#endif //GRUPO3_ACT3_MULTIMEDIA_H
