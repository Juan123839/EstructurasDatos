#ifndef NODOAVL_HXX
#define NODOAVL_HXX

#include "NodoAVL.h"

template <class T>
NodoAVL<T>::NodoAVL() : dato(), hijoIzq(NULL), hijoDer(NULL),
    alturaAVL(0), distancia(0), tamanoAVL(1) {}

template <class T>
NodoAVL<T>::NodoAVL(T val) : dato(val), hijoIzq(NULL), hijoDer(NULL),
    alturaAVL(0), distancia(0), tamanoAVL(1) {}

template <class T>
NodoAVL<T>::~NodoAVL() {
    delete hijoIzq;
    delete hijoDer;
}

template <class T>
T NodoAVL<T>::obtenerDato() { return dato; }

template <class T>
void NodoAVL<T>::fijarDato(T val) { dato = val; }

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq() { return hijoIzq; }

template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T>* nodo) { hijoIzq = nodo; }

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer() { return hijoDer; }

template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T>* nodo) { hijoDer = nodo; }

template <class T>
bool NodoAVL<T>::esHoja() { return hijoIzq == NULL && hijoDer == NULL; }

// Consulta la altura guardada: O(1).
template <class T>
int NodoAVL<T>::altura() { return alturaAVL; }

// Solo consulta las alturas guardadas de los dos hijos: O(1).
template <class T>
void NodoAVL<T>::actualizarAltura() {
    int altIzq = -1;
    int altDer = -1;
    if (hijoIzq != NULL) altIzq = hijoIzq->altura();
    if (hijoDer != NULL) altDer = hijoDer->altura();
    int maxAltura = altIzq;
    if (altDer > altIzq) maxAltura = altDer;
    alturaAVL = 1 + maxAltura;
}

template <class T>
int NodoAVL<T>::tamano() { return tamanoAVL; }

template <class T>
void NodoAVL<T>::actualizarTamano() {
    int tamIzq = 0;
    int tamDer = 0;
    if (hijoIzq != NULL) tamIzq = hijoIzq->tamano();
    if (hijoDer != NULL) tamDer = hijoDer->tamano();
    tamanoAVL = 1 + tamIzq + tamDer;
}

template <class T>
int NodoAVL<T>::obtenerDistancia() { return distancia; }

template <class T>
void NodoAVL<T>::actualizarDistancia() {
    int altIzq = -1;
    int altDer = -1;
    if (hijoIzq != NULL) altIzq = hijoIzq->altura();
    if (hijoDer != NULL) altDer = hijoDer->altura();
    distancia = altIzq - altDer;
}

template <class T>
void NodoAVL<T>::PreOrden() {
    std::cout << dato << " ";
    if (hijoIzq != NULL) hijoIzq->PreOrden();
    if (hijoDer != NULL) hijoDer->PreOrden();
}

template <class T>
void NodoAVL<T>::InOrden() {
    if (hijoIzq != NULL) hijoIzq->InOrden();
    std::cout << dato << " ";
    if (hijoDer != NULL) hijoDer->InOrden();
}

template <class T>
void NodoAVL<T>::PosOrden() {
    if (hijoIzq != NULL) hijoIzq->PosOrden();
    if (hijoDer != NULL) hijoDer->PosOrden();
    std::cout << dato << "\n";
}

#endif
