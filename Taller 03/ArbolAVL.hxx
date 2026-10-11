#ifndef ARBOLAVL_HXX
#define ARBOLAVL_HXX

#include "ArbolAVL.h"
#include <queue>
#include <stdexcept>

template <class T>
ArbolAVL<T>::ArbolAVL() : raiz(NULL) {}

template <class T>
ArbolAVL<T>::~ArbolAVL() { delete raiz; }

template <class T>
bool ArbolAVL<T>::esVacio() { return raiz == NULL; }

template <class T>
T ArbolAVL<T>::datoRaiz() {
    if (esVacio()) throw std::out_of_range("El arbol esta vacio");
    return raiz->obtenerDato();
}

template <class T>
int ArbolAVL<T>::altura() {
    if (esVacio()) return -1;
    return raiz->altura();
}

template <class T>
int ArbolAVL<T>::tamano() {
    if (esVacio()) return 0;
    return raiz->tamano();
}

// Actualiza los datos de un nodo sin recorrer sus subarboles.
template <class T>
void ArbolAVL<T>::actualizarNodo(NodoAVL<T>* nodo) {
    nodo->actualizarAltura();
    nodo->actualizarDistancia();
    nodo->actualizarTamano();
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarDerecha(NodoAVL<T>* n1) {
    NodoAVL<T>* n2 = n1->obtenerHijoIzq();
    NodoAVL<T>* intermedio = n2->obtenerHijoDer();
    n2->fijarHijoDer(n1);
    n1->fijarHijoIzq(intermedio);
    actualizarNodo(n1);
    actualizarNodo(n2);
    return n2;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarIzquierda(NodoAVL<T>* n1) {
    NodoAVL<T>* n2 = n1->obtenerHijoDer();
    NodoAVL<T>* intermedio = n2->obtenerHijoIzq();
    n2->fijarHijoIzq(n1);
    n1->fijarHijoDer(intermedio);
    actualizarNodo(n1);
    actualizarNodo(n2);
    return n2;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarIzqDer(NodoAVL<T>* nodo) {
    nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq()));
    return rotarDerecha(nodo);
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarDerIzq(NodoAVL<T>* nodo) {
    nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer()));
    return rotarIzquierda(nodo);
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::balancear(NodoAVL<T>* nodo) {
    if (nodo == NULL) return NULL;
    actualizarNodo(nodo);
    int diferencia = nodo->obtenerDistancia();
    if (diferencia > 1) {
        if (nodo->obtenerHijoIzq()->obtenerDistancia() >= 0)
            return rotarDerecha(nodo);
        return rotarIzqDer(nodo);
    }
    if (diferencia < -1) {
        if (nodo->obtenerHijoDer()->obtenerDistancia() <= 0)
            return rotarIzquierda(nodo);
        return rotarDerIzq(nodo);
    }
    return nodo;
}

// Insercion recursiva. Solo actualiza si se inserto un dato nuevo.
template <class T>
NodoAVL<T>* ArbolAVL<T>::balancearArbol(NodoAVL<T>* nodo, T val,
                                       bool& insertado) {
    if (nodo == NULL) {
        nodo = new NodoAVL<T>(val);
        insertado = true;
        return nodo;
    }
    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(balancearArbol(nodo->obtenerHijoIzq(), val, insertado));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(balancearArbol(nodo->obtenerHijoDer(), val, insertado));
    } else {
        insertado = false;
        return nodo;
    }
    if (!insertado) return nodo;
    return balancear(nodo);
}

template <class T>
bool ArbolAVL<T>::insertar(T val) {
    bool insertado = false;
    raiz = balancearArbol(raiz, val, insertado);
    return insertado;
}

template <class T>
bool ArbolAVL<T>::eliminar(T val) {
    bool eliminado = false;
    raiz = eliminar(raiz, val, eliminado);
    return eliminado;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::obtenerMinimo(NodoAVL<T>* nodo) {
    if (nodo == NULL) return NULL;
    while (nodo->obtenerHijoIzq() != NULL)
        nodo = nodo->obtenerHijoIzq();
    return nodo;
}

// Encuentra y elimina el minimo en una sola bajada.
// El llamador garantiza que nodo no es NULL.
template <class T>
NodoAVL<T>* ArbolAVL<T>::eliminarMinimo(NodoAVL<T>* nodo, T& minimo) {
    if (nodo->obtenerHijoIzq() == NULL) {
        minimo = nodo->obtenerDato();
        NodoAVL<T>* reemplazo = nodo->obtenerHijoDer();
        nodo->fijarHijoDer(NULL);
        delete nodo;
        return reemplazo;
    }
    nodo->fijarHijoIzq(eliminarMinimo(nodo->obtenerHijoIzq(), minimo));
    return balancear(nodo);
}

// Eliminacion recursiva.
template <class T>
NodoAVL<T>* ArbolAVL<T>::eliminar(NodoAVL<T>* nodo, T val,
                                 bool& eliminado) {
    if (nodo == NULL) {
        eliminado = false;
        return NULL;
    }
    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(eliminar(nodo->obtenerHijoIzq(), val, eliminado));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), val, eliminado));
    } else {
        eliminado = true;
        // Incluye el caso de hoja y el caso con solo hijo derecho.
        if (nodo->obtenerHijoIzq() == NULL) {
            NodoAVL<T>* reemplazo = nodo->obtenerHijoDer();
            nodo->fijarHijoDer(NULL);
            delete nodo;
            return reemplazo;
        }
        if (nodo->obtenerHijoDer() == NULL) {
            NodoAVL<T>* reemplazo = nodo->obtenerHijoIzq();
            nodo->fijarHijoIzq(NULL);
            delete nodo;
            return reemplazo;
        }
        // Dos hijos: reemplaza el dato por el sucesor.
        T sucesor = nodo->obtenerDato();
        nodo->fijarHijoDer(eliminarMinimo(nodo->obtenerHijoDer(), sucesor));
        nodo->fijarDato(sucesor);
    }
    if (!eliminado) return nodo;
    return balancear(nodo);
}

template <class T>
bool ArbolAVL<T>::buscar(T val) {
    NodoAVL<T>* nodo = raiz;
    while (nodo != NULL) {
        if (val == nodo->obtenerDato()) return true;
        if (val < nodo->obtenerDato()) nodo = nodo->obtenerHijoIzq();
        else nodo = nodo->obtenerHijoDer();
    }
    return false;
}

template <class T>
void ArbolAVL<T>::PreOrden() {
    if (!esVacio()) raiz->PreOrden();
}

template <class T>
void ArbolAVL<T>::InOrden() {
    if (!esVacio()) raiz->InOrden();
}

template <class T>
void ArbolAVL<T>::PosOrden() {
    if (!esVacio()) raiz->PosOrden();
}

// Recorrido iterativo por niveles.
template <class T>
void ArbolAVL<T>::NivelOrden() {
    if (esVacio()) return;
    std::queue<NodoAVL<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        NodoAVL<T>* nodo = cola.front();
        cola.pop();
        std::cout << nodo->obtenerDato() << " ";
        if (nodo->obtenerHijoIzq() != NULL) cola.push(nodo->obtenerHijoIzq());
        if (nodo->obtenerHijoDer() != NULL) cola.push(nodo->obtenerHijoDer());
    }
}
template <class T>
bool ArbolAVL<T>::insert(T val) { return insertar(val); }

template <class T>
bool ArbolAVL<T>::erase(T val) { return eliminar(val); }

// Recorrido inorden que guarda los datos en una lista
template <class T>
void ArbolAVL<T>::inordenEnLista(NodoAVL<T>* nodo, std::list<T>& lista) {
    if (nodo == NULL) return;
    inordenEnLista(nodo->obtenerHijoIzq(), lista);
    lista.push_back(nodo->obtenerDato());
    inordenEnLista(nodo->obtenerHijoDer(), lista);
}

template <class T>
void ArbolAVL<T>::inordenEnLista(std::list<T>& lista) {
    inordenEnLista(raiz, lista);
}
#endif
