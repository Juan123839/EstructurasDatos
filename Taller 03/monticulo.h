#ifndef __MONTICULO_H__
#define __MONTICULO_H__

#include <queue>
#include <vector>
#include <list>
#include <functional>
#include <cstddef>
template <class T>
class monticulo {
private:
    typedef std::priority_queue<T, std::vector<T>, std::greater<T> > TMinHeap;
    TMinHeap datos;
    TMinHeap borrados;
    std::size_t cantidad;

    void limpiarCima();

public:
    monticulo();
    ~monticulo();
    bool esVacio();
    std::size_t tamano();
    void insert(T val);
    bool erase(T val);
    void inordenEnLista(std::list<T>& lista);
};

#include "monticulo.hxx"
#endif