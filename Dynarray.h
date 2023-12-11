//
// Created by sergi on 06/12/2023.
//
#include <iostream>
#include <unordered_map>

#ifndef ACTIVIDADINDIVIDUAL3_DYNARRAY2_H
#define ACTIVIDADINDIVIDUAL3_DYNARRAY2_H
using namespace std;

template<typename T>
class Dynarray {
private:
    T *first; // Puntero que apunta al primer elemento
    size_t count; // Numero de elementos guardados
    size_t max_count; // Numero de elementos maximos

public:
    /**
     * Constructor vacio que reserva un
     * bloque de memoria de tamaño T
     */
    Dynarray() {
        first = new T;
        count = 0;
        max_count = 1;
    }

    /**
     * Constructor parametrizado que reserva un bloque size en memoria
     * @param size Tamaño de la memoria a reservar
     */
    Dynarray(size_t size) {
        first = new T[size]; // Reservando en memoria un bloque de tamaño "size" de tipo T
        count = 0;
        max_count = size;
    }

    /**
     * Destructor para el puntero first
     */
    ~Dynarray() {
        delete[] first;
    }

    // Devuelve el size total del dynarray
    auto size() { return max_count; }

    // Devuelve el espacio ocupado por el dynarray
    auto capacity(){ return count; }

    // Devuelve el puntero first
    // Especificando un indice [i] puedes conseguir el objeto guardado en ese indice
    auto begin() -> T * { return first; }

    /**
     * Metodo para insertar un elemento
     * @param elemento Elemento a insertar
     */
    void insert(T &elemento) {
        if (count >= max_count) { // Esta lleno
            alloc(); // Reedistribucion de memoria
        }
        first[count] = elemento;
        count++;
    }

    /**
     * Funcion para duplicar tamaño del array
     * Se hara creando un nuevo array del doble de tamaño del anterior
     * Copiando los elementos del primero al segundo
     * Y eliminando el antiguo
     */
    void alloc() {
        T *aux = new T[max_count * 2]; // Nuevo array con el doble de capacidad
        for (int i = 0; i < count; i++) {
            aux[i] = first[i];
        }
        T *aux2 = first; // Haces que aux2 apunte a la direccion de first, para no perder la referencia y poder eliminarlo
        first = aux; // Que first apunte a la primera direccion de memoria del nuevo array
        max_count = max_count * 2; // Para actualizar la variable
        delete[] aux2; // No borra el puntero, borra el antiguo array
    }

    /**
     * Metodo toString
     */
    void toString() {
        for (int i = 0; i < count; i++) {
            cout << first[i] << endl;
        }
    }

};

#endif //ACTIVIDADINDIVIDUAL3_DYNARRAY2_H
