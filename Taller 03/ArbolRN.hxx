#ifndef __ARBOLRN_HXX__
#define __ARBOLRN_HXX__

template <class T>
ArbolRN<T>::ArbolRN() {
}

template <class T>
ArbolRN<T>::~ArbolRN() {
    datos.clear();
}

template <class T>
bool ArbolRN<T>::esVacio() {
    return datos.empty();
}

template <class T>
int ArbolRN<T>::tamano() {
    return datos.size();
}

template <class T>
void ArbolRN<T>::insertar(T val) {
    datos.insert(val);
}

template <class T>
bool ArbolRN<T>::eliminar(T val) {
    return datos.erase(val);
}

template <class T>
bool ArbolRN<T>::buscar(T val) {
    return datos.find(val) != datos.end();
}

template <class T>
void ArbolRN<T>::InOrden() {
    typename std::set<T>::iterator it;
    for (it = datos.begin(); it != datos.end(); ++it) {
        std::cout << *it << " ";
    }
}

template <class T>
bool ArbolRN<T>::insert(T val) {
    return datos.insert(val).second;
}

template <class T>
bool ArbolRN<T>::erase(T val) {
    return eliminar(val);
}

template <class T>
void ArbolRN<T>::inordenEnLista(std::list<T>& lista) {
    typename std::set<T>::iterator it;
    for (it = datos.begin(); it != datos.end(); ++it) {
        lista.push_back(*it);
    }
}
#endif