/*
Emilia Cárdenas Lobatón
A01706807

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
#include "heap.h"

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
  int k;
  std::string s, j, m, v, l;
  List<std::string> lista;
  List<std::string> lista_tipo;
  List<int> lista_cantidad;
  List<int> lista_anio;
  Buscar<int> buscar;
  Buscar<std::string> buscar2;

  std::cout << "Quieres entrar (Si/No)?" << std::endl;
  std::cin >> s;

   while (s == "Si"){
    std::cout << "\nBienvenidx al organizador de photocards" 
    << std::endl;
    std::cout <<"Si no has hecho el paso 1 antes, hazlo primero"<< std::endl;
    std::cout << "Si eliminas un valor, no puedes oprimir 5"<< std::endl;
    std::cout << "Manten los 8 valores de la lista" << std::endl;
    std::cout << "Al no seguir las instrucciones, " << std::endl;
    std::cout << "el codigo no compilará" << std::endl;
    std::cout << "\n---Cargar valores     1" << std::endl;
    std::cout << "---Cambiar nombres    2" << std::endl;
    std::cout << "---Eliminar nombre    3" << std::endl;
    std::cout << "---Añadir otro nombre 4" << std::endl;
    std::cout << "----Ordenamiento      5" << std::endl;
    std::cout << "---Buscar nombre      6" << std::endl;
    std::cout << "---Ordenamiento Heap  7" << std::endl;
    std::cout << "Cual es tu eleccion?" << std::endl;
    std::cin >> k;

    if (k == 1){
      // Añadir valores a la lista
      std::string linea;
      int i = 1;
      std::cout << "Primero se agregan los nombres (strings)"<< std::endl; 
      std::cout << "Ingresa los nombres. Escribe 'salir' para finalizar:\n";
      while (true) {
        std::cout << "#" << i << " Ingresa un nombre: ";
        std::getline(std::cin, linea);
        
        if (linea.empty()) {
            continue;
        }
        if (linea == "salir") { 
            break;
        }
        
        lista.insertion(linea); 
        i++;
     }
      std::cout << "Se han ingresado " << i - 1 << " valores en la lista.\n";
      std::cout << "\nLista de nombres en order" << std::endl; 
      std::cout << lista.toStringForward() << std::endl;
      std::cout << "\nLista de nombres en reversa" << std::endl; 
      std::cout << lista.toStringBackward() << std::endl;

      std::ofstream archivo("nombres.txt");
      if (archivo.is_open()) {
        std::string lines = lista.toStringLines();
        for (int i = 0; i < lines.size(); i++) {
          archivo.put(lines[i]);
        }
        archivo.close();
      }

      int contador = 0;
      std::string linea2;
      std::cout << "\nAhora agrega los tipos Especial, Basica y POB (strings)"<<std::endl;
      while (contador < i-1) {
        std::cout << "Tipo " << contador + 1 << ": ";
        std::getline(std::cin, linea2);
        lista_tipo.insertion(linea2); 
        contador++;
     }

     std::ofstream archivo2("tipo.txt");
      if (archivo2.is_open()) {
        std::string lines = lista_tipo.toStringLines();
        for (int i = 0; i < lines.size(); i++) {
          archivo2.put(lines[i]);
        }
        archivo2.close();
      }
      
      int contador2 = 0;
      std::string input;
      std::cout << "\nAhora agrega los años de nacimiento (xxxx) (numeros)"<<std::endl;
      while (contador2 < i-1) {
        std::cout << "Año " << contador2 + 1 << ": ";
        std::getline(std::cin, input);
        int linea3 = std::stoi(input);
        lista_anio.insertion(linea3); 
        contador2++;
     }

      int contador3 = 0;
      std::string input2;
      std::cout << "\nAhora agrega la cantidad de photocards (numeros)"<<std::endl;
      while (contador3 < i-1) {
        std::cout << "Cantidad " << contador3 + 1 << ": ";
        std::getline(std::cin, input2);
        int linea4 = std::stoi(input2);
        lista_cantidad.insertion(linea4); 
        contador3++;
      }
    }

    if (k == 2){
      // Cambio de un valor
      std::cout << "\nDa el nuevo valor" << std::endl;
      std::cin >> m;
      std::cout << "Da el valor a cambiar" << std::endl; 
      std::cin >> l;
      std::cout << "\nAhora " << m << " esta en tus photocards"<< std::endl; 
      bool encontrar = lista.update(l,m);
      std::cout << "\nLista de nombres en order" << std::endl; 
      std::cout << lista.toStringForward() << std::endl;
      std::cout << "\nLista de nombres en reversa" << std::endl; 
      std::cout << lista.toStringBackward() << "\n" << std::endl;

      std::ofstream archivo("nombres.txt");
      if (archivo.is_open()) {
        std::string lines = lista.toStringLines();
        for (int i = 0; i < lines.size(); i++) {
          archivo.put(lines[i]);
        }
        archivo.close();
      }
    }

    if (k == 3){
      // Eliminacion de un valor
      std::cout << "\nDa el valor que quieres eliminar" << std::endl;
      std::cin >> m;
      std::string encontrar = lista.deleteValue(m);
      std::cout << "\nLista de nombres en order" << std::endl; 
      std::cout << lista.toStringForward() << std::endl;
      std::cout << "\nLista de nombres en reversa" << std::endl; 
      std::cout << lista.toStringBackward() << "\n" << std::endl;

      std::ofstream archivo("nombres.txt");
      if (archivo.is_open()) {
        std::string lines = lista.toStringLines(); 
        for (int i = 0; i < lines.size(); i++) {
            archivo.put(lines[i]);
        }
        archivo.close();
      }
    }

    if (k == 4){
      // Agregar un valor más / otra vez
      std::cout << "\nDa el valor nuevo a añadir" << std::endl;
      std::cin >> m;
      std::string encontrar = lista.insertion(m);
      std::cout << "\nLista de nombres en order" << std::endl; 
      std::cout << lista.toStringForward() << std::endl;
      std::cout << "\nLista de nombres en reversa" << std::endl; 
      std::cout << lista.toStringBackward() << "\n" << std::endl;

      std::ofstream archivo("nombres.txt");
      if (archivo.is_open()) {
        std::string lines = lista.toStringLines(); 
        for (int i = 0; i < lines.size(); i++) {
            archivo.put(lines[i]);
        }
        archivo.close();
      }
    }

    // Vectores de cada atributo
    std::vector<std::string> integrante = lista.toVector();
    std::vector<std::string> tipo = lista_tipo.toVector();
    std::vector<int> anio = lista_anio.toVector();
    std::vector<int> cantidad = lista_cantidad.toVector();

    if (k == 5){
      // Algoritmos de ordenamiento y busqueda
      std::cout << "\nOrden por nombre: " << std::endl;
      Cuatro<std::string,int,int,std::string> prueba3;
      std::tuple<std::vector<std::string>,std::vector<int>,std::vector<int>,
      std::vector<std::string>> resultado3 = prueba3.ordenBubbleTwo
      (integrante,cantidad,anio,tipo);
      printVectors(std::get<0>(resultado3), std::get<1>(resultado3), 
      std::get<2>(resultado3), std::get<3>(resultado3));

      std::cout << "\nOrden por año: " << std::endl;
      Cuatro<int,int,std::string,std::string> prueba1;
      std::tuple<std::vector<int>,std::vector<int>,std::vector<std::string>,
      std::vector<std::string>> resultado = prueba1.ordenBubbleTwo
      (anio,cantidad,integrante,tipo);
      printVectors(std::get<0>(resultado), std::get<1>(resultado), 
      std::get<2>(resultado), std::get<3>(resultado));
    }

    if (k == 6){
      //Algoritmo de busqueda
      std::cout << "\nQue nombre quieres buscar?" << std::endl;
      std::cin >> v;
      std::cout << "\nEn nombre a encontrar " << v << std::endl;
      std::cout << "Se encontro en la posición: " << 
      buscar2.busqSecuencialStr(integrante, v)  << std::endl;
    }

    if (k == 7){
      //Arbol heap
      Heap<int> heap(8);
      heap.addVector(cantidad);
      std::cout << "\nOrdena la cantidad de photocards" << std::endl;
      std::cout << "De Menor a Mayor" << std::endl;
      std::cout << heap.toString() << std::endl;
      std::cout << "De Mayor a Menor" << std::endl;
      std::cout << heap.toStringDescending() << std::endl;
    }

    std::cout << "\nQuieres volver a entrar (Si/No)?" << std::endl;
    std::cin >> s;
   }

  return 0;
}
