/*
Proyecto Organizador de cartas de K-pop
Emilia Cárdenas Lobatón
A01706807

Este apartado define los algoritmos de busqueda a utilizar
Se utiliza una busqueda Secuencial Iterativa
Mejor: O(1)
Promedio: O(n)
Peor: O(n)
El cual busca la posicion del valor dado
*/
#ifndef BUSQUEDA_H_
#define BUSQUEDA_H_
#include <iostream>
#include <vector>

//Clase para el algoritmo de busqueda
template <class T>
class Buscar{
    public:
    int busqSecuencialInt(std::vector<T>& v, int val);
    int busqSecuencialStr(std::vector<T>& v, std::string val);
};

/*
busqSecuencialInt - busqueda iteratiba del tipo integrer

Utilizando un verctor y un valor dado, el algoritmo
busca por cada valor del vector hasta encontralo.
Sumando uno por cada paso de valor y así tener su posicion

@param std::vector<T> &v debe ser: un vector
@param int i debe ser: un int del vector
@return int i debe ser: un int positivo
*/
template <class T>
int Buscar<T>::busqSecuencialInt(std::vector<T>& v, int val){
  for(int i=0; i<v.size();i++){
    if (v[i] == val){
      return i;
    }
  }
  return -1;
};

/*
busqSecuencialStr - busqueda iteratiba del tipo string

Utilizando un verctor y un valor dado, el algoritmo
busca por cada valor del vector hasta encontralo.
Sumando uno por cada paso de valor y así tener su posicion

@param std::vector<T> &v debe ser: un vector
@param string val debe ser: un string del vector
@return int i debe ser: un int positivo
*/
template <class T>
int Buscar<T>::busqSecuencialStr(std::vector<T>& v, std::string val){
  for(int i=0; i<v.size();i++){
    if (v[i] == val){
      return i;
    }
  }
  return -1;
};

#endif
