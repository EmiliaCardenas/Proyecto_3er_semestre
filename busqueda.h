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

//Busqueda para integrers
template <class T>
int Buscar<T>::busqSecuencialInt(std::vector<T>& v, int val){
  for(int i=0; i<v.size();i++){
    if (v[i] == val){
      return i;
    }
  }
  return -1;
};

//Busqeuda para strings
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