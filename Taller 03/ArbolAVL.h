#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoAVL.h"
#include <list>

template <class T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;
    NodoAVL<T>* eliminar(NodoAVL<T>* nodo, T val, bool& eliminado);
    NodoAVL<T>* eliminarMinimo(NodoAVL<T>* nodo, T& minimo);
    void actualizarNodo(NodoAVL<T>* nodo);
    void inordenEnLista(NodoAVL<T>* nodo, std::list<T>& lista);

public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool buscar(T val);
    bool insertar(T val);
    bool eliminar(T val);
    NodoAVL<T>* rotarDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarIzquierda(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarIzqDer(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarDerIzq(NodoAVL<T>* nodo);
    NodoAVL<T>* balancear(NodoAVL<T>* nodo);
    NodoAVL<T>* obtenerMinimo(NodoAVL<T>* nodo);
    NodoAVL<T>* balancearArbol(NodoAVL<T>* nodo, T val, bool& insertado);
    void PreOrden();
    void InOrden();
    void PosOrden();
    void NivelOrden();
    bool insert(T val);
    bool erase(T val);
    void inordenEnLista(std::list<T>& lista);
};

#include "ArbolAVL.hxx"
#endif