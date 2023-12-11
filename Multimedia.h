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
     * Metodo para buscar una multimedia a partir del titulo
     * @param titulo Titlo de la multimedia a buscar
     * @param mult Dynarray de las multimedias
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

    /**
     * Metodo para buscar una multimedia a partir del genero
     * @param genero Genero de la multimedia a buscar
     * @param mult Dynarray de las multimedias
     */
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

    /**
     * Metodo para buscar una multimedia a partir de la calidad
     * @param calidad Calidad de la multimedia a buscar
     * @param mult Dynarray de las multimedias
     */
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

    /**
     * Metodo para conseguir el titulo
     * @return Titulo
     */
    const string &getTitulo() const {
        return titulo;
    }

    /**
     * Metodo para conseguir el genero
     * @return Genero
     */
    GeneroMultimedia getGeneroMultimedia() const {
        return generoMultimedia;
    }

    /**
     * Metodo para conseguir la calidad
     * @return Calidad
     */
    Calidad getCalidad() const {
        return calidad;
    }

    /**
     * Metodo para sabe la disponibilidad de un archivo multimedia
     * @return True -> Esta disponible | False -> No esta disponible
     */
    bool isDispo() const {
        return dispo;
    }

    /**
     * Metodo para saber si la multimedia esta incluida o no con la tarifa basica
     * @return True -> Esta incluida | False -> No esta incluida
     */
    bool isIncluded() const {
        return included;
    }

    /**
     * Metodo para conseguir el precio extra
     * @return Precio extra
     */
    double getPrecioExtra() const {
        return precioExtra;
    }

    /**
     * Metodo para establecer la disponibilidad
     * @param dispo Disponibilidad a establecer
     */
    void setDispo(bool dispo) {
        Multimedia::dispo = dispo;
    }

    /**
     * Metodo para establecer si esta o no incluido
     * @param included Si esta o no incluido en la tarifa basica
     */
    void setIncluded(bool included) {
        Multimedia::included = included;
    }

    /**
     * Metodo para establecer el precio extra
     * @param precioExtra Precio Extra
     */
    void setPrecioExtra(double precioExtra) {
        Multimedia::precioExtra = precioExtra;
    }

    /**
     * Metodo toString de Multimedia
     * @return toString de Multimedia
     */
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

    /**
     * Metodo para imprimir la multimedia en un Dynarray
     * @param mult Array de multimedias
     */
    void toStringformDynarray(Dynarray<Multimedia> &mult){
        for(int i = 0; i < mult.capacity(); i++){
            cout << mult.begin()[i].toString() << endl;
        }
    }
};

#endif //GRUPO3_ACT3_MULTIMEDIA_H
