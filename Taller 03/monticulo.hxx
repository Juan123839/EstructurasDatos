#ifndef __MONTICULO_HXX__
#define __MONTICULO_HXX__

template <class T>
monticulo<T>::monticulo() : cantidad(0) {
}

template <class T>
monticulo<T>::~monticulo() {
}

template <class T>
bool monticulo<T>::esVacio() {
    return cantidad == 0;
}

template <class T>
std::size_t monticulo<T>::tamano() {
    return cantidad;
}

// Mientras la cima de datos coincida con la cima de borrados, se descartan.
template <class T>
void monticulo<T>::limpiarCima() {
    while (!datos.empty() && !borrados.empty() && datos.top() == borrados.top()) {
        datos.pop();
        borrados.pop();
    }
}

template <class T>
void monticulo<T>::insert(T val) {
    datos.push(val);
    ++cantidad;
}

template <class T>
bool monticulo<T>::erase(T val) {
    if (cantidad == 0) return false;
    borrados.push(val);
    --cantidad;
    limpiarCima();
    return true;
}

// Salida ordenada (de menor a mayor): se trabaja sobre copias de los
// monticulos, sacando la cima uno a uno y saltando los datos borrados.
template <class T>
void monticulo<T>::inordenEnLista(std::list<T>& lista) {
    TMinHeap d = datos;
    TMinHeap b = borrados;
    while (!d.empty()) {
        if (!b.empty() && d.top() == b.top()) {
            d.pop();
            b.pop();
        } else {
            lista.push_back(d.top());
            d.pop();
        }
    }
}

#endif