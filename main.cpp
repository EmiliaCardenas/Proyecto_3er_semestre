/*
Emilia Cárdenas Lobatón
A01706807

Segundo avance

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
#include "listas.h"

/*
arrayToString - función para hacer el vector a string

Recorre cada valor desde el inicio, para ir guardandolo en un
auxiliar, el cual al final se imprime.

@param std::vector<T> &v debe ser: un vector
@return aux.str debe ser: el auxiliar vuelto a un string
*/
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

/*
printVectors - función para imprimir los 4 vectores ligados

Recorre mediante un for cada valor, de cada factor para
poder imprimirlos juntos, de manera ordenada.

@param std::vector<T> &v1 debe ser: un vector
@param std::vector<T> &v2 debe ser: un vector
@param std::vector<T> &v3 debe ser: un vector
@param std::vector<T> &v4 debe ser: un vector
@return
*/
template <class T1, class T2, class T3, class T4>
  void printVectors(const std::vector<T1>& v1, const std::vector<T2>& v2,
const std::vector<T3>& v3, const std::vector<T4>& v4) {
    for (unsigned int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " -> " << v2[i] << " -> " << v3[i] << 
          " -> " << v4[i] << std::endl;
    }
}

int main(){
  int k, j, m;
  std::string s;
  List<int> lista;
  Buscar<int> buscar;
  Buscar<std::string> buscar2;

  std::cout << "Quieres entrar (Si/No)?" << std::endl;
  std::cin >> s;

   while (s == "Si"){
    std::cout << "\nBienvenidx al organizador de photocards" 
    << std::endl;
    std::cout << "Si no has hecho el paso 1 antes, hazlo primero" << std::endl;
    std::cout << "Si eliminas un valor, no puedes oprimir 5" << std::endl;
    std::cout << "\n---Agregar cantidad  1" << std::endl;
    std::cout << "---Buscar Valor      2" << std::endl;
    std::cout << "---Cambiar Valor     3" << std::endl;
    std::cout << "---Eliminar Valor    4" << std::endl;
    std::cout << "---Ordenamiento      5" << std::endl;
    std::cout << "Cual es tu eleccion?" << std::endl;
    std::cin >> k;

    if (k == 1){
      // Añadir valores a la lista
      std::cout << "\nDebes añadir 8 valores numericos" << std::endl;
      for (int i = 0; i < 8; i++){
        std::cout << "Valor: " << std::endl;
        std::cin >> j;
        lista.insertion(j);
      }
      std::cout << lista.toStringForward() << std::endl;
      std::cout << lista.toStringBackward() << std::endl;
    }

    if (k == 2){
      // Busqueda de un valor en la lista
      std::cout << "\nDa el valor que quieres buscar" << std::endl;
      std::cin >> m;
      int encontrar = lista.search(m);
      std::cout << "\nEncontrar posición de "<< m << std::endl;
      std::cout << "Se encontro en la posición: " << encontrar << std::endl;
    }

    if (k == 3){
      // Cambio de un valor
      std::cout << "\nDa el valor que quieres cambiar" << std::endl;
      std::cin >> m;
      std::cout << "En que posición?" << std::endl;
      std::cin >> j;
      int encontrar = lista.update(j,m);
      std::cout << lista.toStringForward() << std::endl;
      std::cout << lista.toStringBackward() << "\n" << std::endl;
    }

    if (k == 4){
      // Eliminacion de un valor
      std::cout << "\nDa el valor que quieres eliminar" << std::endl;
      std::cin >> m;
      int encontrar = lista.deleteValue(m);
      std::cout << lista.toStringForward() << std::endl;
      std::cout << lista.toStringBackward() << "\n" << std::endl;
    }

    // Vectores de cada atributo
    std::vector<int> anio = {2000,1999,2000,1998,1997,2001,2000,2000};
    std::vector<std::string> integrante = {"Jisung","Changbin","Seungmin",
    "Minho","Chan","Jeongin","Hyunjin","Felix"};
    std::vector<std::string> tipo = {"POB","Especial","Basica","POB", "POB",
    "Basica","Especial","Basica"};
    std::vector<int> cantidad = lista.toVector();

    if (k == 5){
      // Algoritmos de ordenamiento y busqueda
      std::cout << "\nOrden por cantidad: " << std::endl;
      Cuatro<int,int,std::string,std::string> prueba1;
      std::tuple<std::vector<int>,std::vector<int>,std::vector<std::string>,
      std::vector<std::string>> resultado = prueba1.ordenBubbleTwo
      (cantidad,anio,integrante,tipo);
      printVectors(std::get<0>(resultado), std::get<1>(resultado), 
      std::get<2>(resultado), std::get<3>(resultado));

      std::cout << "\nEn anio encontrar el 2001 en posición 7" 
      << std::endl;
      std::cout << "Se encontro en la posición: " << 
      buscar.busqSecuencialInt(anio,2001)  << std::endl;

      std::cout << "\nOrden por nombre: " << std::endl;
      Cuatro<std::string,int,int,std::string> prueba3;
      std::tuple<std::vector<std::string>,std::vector<int>,std::vector<int>,
      std::vector<std::string>> resultado3 = prueba3.ordenBubbleTwo
      (integrante,cantidad,anio,tipo);
      printVectors(std::get<0>(resultado3), std::get<1>(resultado3), 
      std::get<2>(resultado3), std::get<3>(resultado3));

      std::cout << "\nEn cantidad encontrar Jisung en posición 5" 
      << std::endl;
      std::cout << "Se encontro en la posición: " << 
      buscar2.busqSecuencialStr(integrante,"Jisung")  << std::endl;
    }

    std::cout << "\nQuieres volver a entrar (Si/No)?" << std::endl;
    std::cin >> s;
   }
  return 0;
}
