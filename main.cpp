/*
Emilia Cárdenas Lobatón
A01706807

Primer avance

Organizador de cartas (photocards)
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include "ordenar.h"
#include "busqueda.h"

// Función para hacer el vector a string
template <class T>
std::string arrayToString(const std::vector<T> &v) {
  std::stringstream aux;
  aux << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    aux << ", " << v[i];
  }
  aux << "]";
  return aux.str();
}

// Función para imprimir el vector conjunto
template <class T1, class T2, class T3, class T4>
  void printVectors(const std::vector<T1>& v1, const std::vector<T2>& v2,
const std::vector<T3>& v3, const std::vector<T4>& v4) {
    for (unsigned int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " -> " << v2[i] << " -> " << v3[i] << 
          " -> " << v4[i] << std::endl;
    }
}

int main(){
  // Vectores de cada atributo
  std::vector<int> cantidad = {298,81,75,83,98,63,36,48};
  std::vector<int> anio = {2000,1999,2000,1998,1997,2001,2000,2000};
  std::vector<std::string> integrante = {"Jisung","Changbin","Seungmin",
  "Minho","Chan","Jeongin","Hyunjin","Felix"};
  std::vector<std::string> tipo = {"POB","Especial","Basica","POB", "POB",
  "Basica","Especial","Basica"};

  //Algoritmo de búsqueda
  Buscar<int> buscar;
  Buscar<std::string> buscar2;

  //Algoritmo de ordenamiento
  std::cout << "Orden:" << std::endl;
  std::cout << "\nOrden por cantidad: " << std::endl;
  Cuatro<int,int,std::string,std::string> prueba1;
  std::tuple<std::vector<int>,std::vector<int>,std::vector<std::string>,
    std::vector<std::string>> resultado = prueba1.ordenBubbleTwo
    (cantidad,anio,integrante,tipo);
  printVectors(std::get<0>(resultado), std::get<1>(resultado), 
  std::get<2>(resultado), std::get<3>(resultado));

  std::cout << "\nEn cantidad encontrar el 81 en posición 4" << std::endl;
  std::cout << "Se encontro en la posición: " << 
    buscar.busqSecuencialInt(cantidad,81)  << std::endl;
  
  std::cout << "\n\nOrden por año: " << std::endl;
  Cuatro<int,int,std::string,std::string> prueba2;
  std::tuple<std::vector<int>,std::vector<int>,std::vector<std::string>,
    std::vector<std::string>> resultado2 = prueba2.ordenBubbleTwo
    (anio,cantidad,integrante,tipo);
  printVectors(std::get<0>(resultado2), std::get<1>(resultado2), 
  std::get<2>(resultado2), std::get<3>(resultado2));

  std::cout << "\nEn cantidad encontrar el 1999 en posición 2" << std::endl;
  std::cout << "Se encontro en la posición: " << 
    buscar.busqSecuencialInt(anio,1999)  << std::endl;

  std::cout << "\n\nOrden por nombre: " << std::endl;
  Cuatro<std::string,int,int,std::string> prueba3;
  std::tuple<std::vector<std::string>,std::vector<int>,std::vector<int>,
    std::vector<std::string>> resultado3 = prueba3.ordenBubbleTwo
    (integrante,cantidad,anio,tipo);
  printVectors(std::get<0>(resultado3), std::get<1>(resultado3), 
  std::get<2>(resultado3), std::get<3>(resultado3));

  std::cout << "\nEn cantidad encontrar Jisung en posición 5" << std::endl;
  std::cout << "Se encontro en la posición: " << 
    buscar2.busqSecuencialStr(integrante,"Jisung")  << std::endl;

  std::cout << "\n\nOrden por tipo: " << std::endl;
  Cuatro<std::string,std::string,int,int> prueba4;
  std::tuple<std::vector<std::string>,
    std::vector<std::string>,std::vector<int>,std::vector<int>> 
    resultado4 = prueba4.ordenBubbleTwo
    (tipo,integrante,anio,cantidad);
  printVectors(std::get<0>(resultado4), std::get<1>(resultado4), 
  std::get<2>(resultado4), std::get<3>(resultado4));

  std::cout << "\nEn cantidad encontrar Limitada en posición -1" << std::endl;
  std::cout << "Se encontro en la posición: " << 
    buscar2.busqSecuencialStr(tipo,"Limitada")  << std::endl;

  return 0;
}