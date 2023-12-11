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
     * Metodo para eliminar un elemento basado en su posicion
     * @param posicion Posicion del elemento a eliminar
     */
    void eliminar(size_t posicion) {
        if (posicion >= count) { // La posicion supera el numero de elementos que hay
            cout << "La posicion no es valida" << endl;
        } else {
            for (size_t i = posicion; i < count - 1; i++) {
                first[i] = first[i + 1];
            }
            count--;
        }
    }

    /**
     * Metodo para busacar un elemento
     * @param elemento Elemento a buscar
     * @return True-> Encontrado / False-> No encontrado
     */
    bool search(T elemento) {
        for (size_t i = 0; i < count; i++) {
            if (elemento == first[i]) { return true; }
        }
        return false;
    }

    /**
     * Metodo para ordenar alfabeticamente el dynarray
     * sabiendo que las letras se representan como numeros en ASCII
     * por lo que a < b < c ...
     */
    void ordenarAlfabeticamente() {
        for (int i = 0; i < count - 1; i++) { // Recorre el dynarray
            for (int j = i + 1; j < count; j++) { // Recorre el dynarray una posicion por delante
                if (first[i] > first[j]) {
                    // Intercambiar caracteres
                    char aux = first[i];
                    first[i] = first[j];
                    first[j] = aux;
                }
            }
        }
    }

    /**
     * Metodo para buscar una cadena de texto
     * @param cadena Cadena de texto a buscar
     * @return True-> Encontrada / False-> No encontrada
     */
    bool buscarCadena(string cadena) {
        int aux = 0;
        for (int i = 0; i < count; i++) { // Recorre el dynarray
            if (cadena[aux] == first[i]) {
                aux++;
            }
            if (aux == cadena.length()) {
                return true;
            }
        }
        return false;
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
     * Metodo para sumar todos los
     * elementos del dynarray
     * @return Suma de todos los elementos
     */
    T suma() {
        static_assert(is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value,
                      "La suma se debe realizar con un int, double o float"); // Comprueba que es el tipo de dato correcto
        T sumaTot = 0;
        for (int i = 0; i < count; i++) {
            sumaTot += first[i];
        }
        return sumaTot;
    }

    /**
     * Metodo para calcular el promedio
     * de todos los elementos del dynarray
     * @return Suma de todos los elementos del dynarray
     */
    T promedio() {
        static_assert(is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value,
                      "La suma se debe realizar con un int, double o float"); // Comprueba que es el tipo de dato correcto
        return suma() / count;
    }

    /**
     * Metodo para calcular la moda
     * de todos los elementos del dynarray
     * Si no hay un elemento que se repita mas que el resto -> Moda=-1
     * @return Moda del dynarray (-1 -> No hay moda)
     */
    T moda() {
        unordered_map<T, int> repes; // Almacenamiento calve-valor para el tipo T y su numero de repeticiones
        T moda;
        int maxRepes = 0;

        static_assert(is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value,
                      "La suma se debe realizar con un int, double o float"); // Comprueba que es el tipo de dato correcto
        for (int i = 0; i < count; i++) { // Recorre el dynarray
            repes[first[i]]++; // Si first[i] existe lo incrementa en 1, sino crea una nueva clave con valor 1
        }

        for (const auto &entry: repes) { // entry es cada par(clave, valor)
            if (entry.second == maxRepes) {
                moda = -1;
                maxRepes = entry.second;
            } else if (entry.second > maxRepes) {
                moda = entry.first;
                maxRepes = entry.second;
            }

        }

        return moda;
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
