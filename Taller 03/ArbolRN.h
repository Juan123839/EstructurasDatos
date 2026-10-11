#ifndef __ARBOLRN_H__
#define __ARBOLRN_H__

#include <iostream>
#include <set>
#include <list>

template <class T>
class ArbolRN {
private:
    std::set<T> datos;

public:
    ArbolRN();
    ~ArbolRN();
    bool esVacio();
    int tamano();
    bool buscar(T val);
    void insertar(T val);
    bool eliminar(T val);
    void InOrden();

    bool insert(T val);
    bool erase(T val);
    void inordenEnLista(std::list<T>& lista);
};

#include "ArbolRN.hxx"
#endif