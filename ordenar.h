#ifndef ORDENAR_H_
#define ORDENAR_H_
#include <iostream>
#include <vector>
#include <string>

// Función de swap de valores
template <class T>
void swap(std::vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Class de Sort para 1 parametro
template <class T>
class Orden{
    public:
    std::vector<T> ordenBubble(std::vector<T> &v);
};

template <class T>
std::vector<T> Orden<T>::ordenBubble(std::vector<T> &v){
    for (int i = v.size() - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                swap(v, j, j + 1);
            }
        }
    }
    return v;
};

// Class de Sort para 4 parametros
template <class T1, class T2, class T3, class T4>
class Cuatro{
    public:
    std::tuple<std::vector<T1>, std::vector<T2>, std::vector<T3>, 
std::vector<T4>> ordenBubbleTwo(std::vector<T1> &v1, std::vector<T2> 
&v2, std::vector<T3> &v3, std::vector<T4> &v4);
};

template <class T1, class T2, class T3, class T4>
std::tuple<std::vector<T1>, std::vector<T2>, std::vector<T3>, 
std::vector<T4>> Cuatro<T1,T2,T3,T4>::ordenBubbleTwo(std::vector<T1> &v1, 
std::vector<T2> &v2, std::vector<T3> &v3, std::vector<T4> &v4){
        for (int i = 0; i < v1.size() - 1; i++) {
            for (int j = 0; j < v1.size() - i - 1; j++){
            if (v1[j] > v1[j+1]){
                swap(v1, j, j + 1);
                swap(v2, j, j + 1);
                swap(v3, j, j + 1);
                swap(v4, j, j + 1);
            }
        }
    }
    return std::tuple<std::vector<T1>, std::vector<T2>, std::vector<T3>, 
        std::vector<T4>>(v1, v2, v3, v4);
}

#endif