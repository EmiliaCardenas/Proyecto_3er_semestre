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
#include <fstream>

#include "ordenar.h"
#include "busqueda.h"
#include "listas.h"
#include "arbol.h"

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
  int k, l;
  std::string s, j, m;
  List<std::string> lista;
  Buscar<int> buscar;
  Buscar<std::string> buscar2;

  std::cout << "Quieres entrar (Si/No)?" << std::endl;
  std::cin >> s;

   while (s == "Si"){
    std::cout << "\nBienvenidx al organizador de photocards" 
    << std::endl;
    std::cout << "Si no has hecho el paso 1 antes, hazlo primero" << std::endl;
    std::cout << "Si eliminas un valor, no puedes oprimir 5" << std::endl;
    std::cout << "\n---Agregar valores  1" << std::endl;
    std::cout << "---Cambiar Valor      2" << std::endl;
    std::cout << "---Eliminar Valor     3" << std::endl;
    std::cout << "---Ordenamiento       4" << std::endl;
    std::cout << "Cual es tu eleccion?" << std::endl;
    std::cin >> k;

    if (k == 1){
      // Añadir valores a la lista
      std::cout << "\nDebes añadir 8 valores escritos" << std::endl; 
      std::ifstream archivo("ejemplo.txt");
      std::string linea;
      int contador = 0;

      if (archivo.is_open()) {
        while (getline(archivo, linea) && contador < 8) {
          std::cout << "Valor: " << linea << std::endl;
          lista.insertion(linea);
            contador++;
        }
      }
      archivo.close();
      std::cout << lista.toStringForward() << std::endl;
      std::cout << lista.toStringBackward() << std::endl;
    }

    if (k == 2){
      // Cambio de un valor
      std::cout << "\nDa el valor nuevo a cambiar" << std::endl;
      std::cin >> m;
      std::cout << "En que posición?" << std::endl;
      std::cin >> l;
      std::string encontrar = lista.update(l,m);
      std::cout << lista.toStringForward() << std::endl;
      std::cout << lista.toStringBackward() << "\n" << std::endl;
    }

    if (k == 3){
      // Eliminacion de un valor
      std::cout << "\nDa el valor que quieres eliminar" << std::endl;
      std::cin >> m;
      std::string encontrar = lista.deleteValue(m);
      std::cout << lista.toStringForward() << std::endl;
      std::cout << lista.toStringBackward() << "\n" << std::endl;
    }

    // Vectores de cada atributo
    std::vector<int> anio = {2000,1999,2000,1998,1997,2001,2000,2000};
    std::vector<std::string> integrante = lista.toVector();
    std::vector<std::string> tipo = {"POB","Especial","Basica","POB", "POB",
    "Basica","Especial","Basica"};
    std::vector<int> cantidad = {298,85,76,93,98,74,52,67};

    if (k == 4){
      // Algoritmos de ordenamiento y busqueda
      std::cout << "\nOrden por cantidad: " << std::endl;
      Cuatro<int,int,std::string,std::string> prueba1;
      std::tuple<std::vector<int>,std::vector<int>,std::vector<std::string>,
      std::vector<std::string>> resultado = prueba1.ordenBubbleTwo
      (cantidad,anio,integrante,tipo);
      printVectors(std::get<0>(resultado), std::get<1>(resultado), 
      std::get<2>(resultado), std::get<3>(resultado));

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
