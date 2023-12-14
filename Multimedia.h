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
            precioExtra(precioExtra) {
        included = false;
    }

    Multimedia() {};

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

    friend std::ostream& operator<<(std::ostream&os, const Multimedia& mul) {
        string dispoToString = (mul.dispo) ? "Disponible" : "No disponible";
        string includedToString = (mul.included) ? "Si" : "No";

        string generoToString = "Sin clasificar";
        switch (mul.generoMultimedia) {
            case 0:
                generoToString = "Accion";
                break;
            case 1:
                generoToString = "Comedia";
                break;
            case 2:
                generoToString = "Drama";
                break;
            case 3:
                generoToString = "CienciaFiccion";
                break;
            case 4:
                generoToString = "Terror";
                break;
            case 5:
                generoToString = "Aventura";
                break;
            case 6:
                generoToString = "Suspense";
                break;
            case 7:
                generoToString = "Romance";
                break;
            case 8:
                generoToString = "Musical";
                break;
            case 9:
                generoToString = "Fantasia";
                break;

        }

        string precioExtraToString = (mul.getPrecioExtra()) == 0 ? "No" : to_string(mul.getPrecioExtra()) ;

        string calidadToString = (mul.calidad) ? "FHD" : "UHD";
        os << (mul.getTitulo() +
               ", Genero: " + generoToString +
               ", Calidad: " + calidadToString +
               ", " + dispoToString +
               ", Incluido con su tarifa: " + includedToString +
               "\n Precio extra = " + precioExtraToString);
        return os;
    }

};

/**
 * Metodo para buscar una multimedia a partir del titulo
 * @param titulo Titlo de la multimedia a buscar
 * @param mult Dynarray de las multimedias
 */
void buscarTitulo(string titulo, Dynarray<Multimedia> &mult) {
    bool encontrado;
    for (int i = 0; i < mult.capacity(); i++) {
        if (titulo == mult.begin()[i].getTitulo()) {
            cout << mult.begin()[i] << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se ha encontrado ninguna multimedia con el titulo especificado" << endl;
    }
}

/**
 * Metodo para buscar una multimedia a partir del genero
 * @param genero Genero de la multimedia a buscar
 * @param mult Dynarray de las multimedias
 */
void buscarGenero(GeneroMultimedia genero, Dynarray<Multimedia> &mult) {
    bool encontrado;
    for (int i = 0; i < mult.capacity(); i++) {
        if (genero == mult.begin()[i].getGeneroMultimedia()) {
            cout << mult.begin()[i] << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se ha encontrado ninguna multimedia con el genero especificado" << endl;
    }
}

/**
 * Metodo para buscar una multimedia a partir de la calidad
 * @param calidad Calidad de la multimedia a buscar
 * @param mult Dynarray de las multimedias
 */
void buscarCalidad(Calidad calidad, Dynarray<Multimedia> &mult) {
    bool encontrado;
    for (int i = 0; i < mult.capacity(); i++) {
        if (calidad == mult.begin()[i].getCalidad()) {
            cout << mult.begin()[i] << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se ha encontrado ninguna multimedia con la calidad especificada" << endl;
    }
}

#endif //GRUPO3_ACT3_MULTIMEDIA_H
