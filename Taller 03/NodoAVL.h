#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>

template <class T>
class NodoAVL {
protected:
    T dato;
    NodoAVL<T>* hijoIzq;
    NodoAVL<T>* hijoDer;
    int alturaAVL;
    int distancia;
    int tamanoAVL;

public:
    NodoAVL();
    NodoAVL(T val);
    ~NodoAVL();
    T obtenerDato();
    void fijarDato(T val);
    NodoAVL<T>* obtenerHijoIzq();
    void fijarHijoIzq(NodoAVL<T>* nodo);
    NodoAVL<T>* obtenerHijoDer();
    void fijarHijoDer(NodoAVL<T>* nodo);
    bool esHoja();
    int altura();
    void actualizarAltura();
    int tamano();
    void actualizarTamano();
    int obtenerDistancia();
    void actualizarDistancia();
    void PreOrden();
    void InOrden();
    void PosOrden();
};

#include "NodoAVL.hxx"
#endif
