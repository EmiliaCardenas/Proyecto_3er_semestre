/*
Proyecto Organizador de cartas de K-pop
Emilia Cárdenas Lobatón
A01706807

Este apartado define los algoritmos de listas ligadas - doble ligadas
Crea listas, las cuales pueden ser modificacdas utilizadas variadamente
Listas ligadas
Promedio: Θ(n)
Peor: O(n)

Listas Doble ligadas
Promedio: Θ(n)
Peor: O(n)
*/
#ifndef LISTAS_H_
#define LISTAS_H_
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <class T> class List;

//Clase para la creacion de nodos
template <class T>
class Link {
private:
  Link(T);
  Link(T, Link<T>*, Link<T>*);
  Link(const Link<T>&);

  T	    value;
  Link<T> *next;
  Link<T> *prev;

  friend class List<T>;
};

template <class T> //Constructor por defult
Link<T>::Link(T val) : value(val), next(0), prev(0)  {}

template <class T> //Construtor inicializado
Link<T>::Link(T val, Link* nxt, Link* prv) : value(val), next(nxt), prev(prv) {}

template <class T> //Asignación de valores
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next), prev(source.previous){}

//Clase para la creacion de la lista
template <class T> 
class List{
    public:
    List();
    List(const List<T>&);

    std::string toStringForward() const;
    std::string toStringBackward() const;
    T insertion(T val); 
    T search(T val);
    T update(T val,T val2);
    T deleteValue(T val);

    std::vector<T> toVector() const; 

    private:
    Link<T> *head;
    Link<T> *tail;
    int 	size;
};

template <class T> //Constructor por defult
List<T>::List() : head(NULL), tail(NULL), size(0) {}

/*
insertion - funcion que inserta los valores en la lista

Inserta los valores dados en el main, en el orden en el
que la funcion es mandada a llamar. Empezando desde la cola
para poder utilizarla como doblemente ligada.

@param T val debe ser: un valor dependiendo del main
@return T val debe ser: un valor dependiendo del parametro

Listas ligadas
Promedio: Θ(1)
Peor: O(1)

Listas Doble ligadas
Promedio: Θ(1)
Peor: O(1)
*/
template <class T>
T List<T>::insertion(T val){
  Link<T> *nuevo = new Link<T>(val);

  if (tail == NULL) {
    head = nuevo;
    tail = nuevo; 
  } else {
    tail->next = nuevo; 
    nuevo -> prev = tail;
    tail = nuevo;
  }
  size++;
  
  return val;
}

/*
search - funcion que busca los valores en la lista dando su posicion

Busca el valor recorriendo la lista y sumando uno a la
posicion para cuando el valor sea encontrado, devuelva
el valor de donde se encuentra

@param T val debe ser: un valor dependiendo del main
@return int pos debe ser: un int positivo

Listas ligadas
Promedio: Θ(1)
Peor: O(1)

Listas Doble ligadas
Promedio: Θ(1)
Peor: O(1)
*/
template <class T>
T List<T>::search(T val){
  Link<T> *nuevo;
  nuevo = head;
  int pos = 0;
  while (nuevo != 0){
    if (nuevo -> value == val){
      return pos +1;
    }
    pos++;
    nuevo = nuevo -> next;
  }
  return -1;
}

/*
update - funcion que cambia el valor en una posicion dada

Busca el valor recorriendo la lista, hasta llegar a la posicion dada
cambiando los valores y rescribiendolo. Haciendo que
al volver a llamar la lista, esta tenga el valor cambiado

@param T val debe ser: la posicion dependiendo del main
@param T val2 debe ser: un valor dependiendo del main
@return T debe ser: el valor el cual fue cambiado, junto a la lista
*/
template <class T>
T List<T>::update(T val, T val2){
  Link<T> *nuevo = head;
  int i = 0;

  while (nuevo != NULL){
    if (i == val){
      T aux = nuevo -> value;
      nuevo -> value = val2;
      return aux;
    }
    i++;
    nuevo = nuevo -> next;
  }
  return T();
}

/*
toVector - funcion que vuelve la lista en un vector

Recorre toda la lista y los va rescribiendo en un vector
nuevo. Para poder utilizarlo con otros algoritmos que 
reciben vectores

@param
@return std::vector<T> vec debe ser: el nuevo vector, 
con los valores de la lista
*/
template <class T>
std::vector<T> List<T>::toVector() const {
    std::vector<T> vec;
    Link<T> *current = head;

    while (current != NULL) {
        vec.push_back(current->value);
        current = current->next;
    }

    return vec;
}

/*
toStringForward - funcion que imprime la lista en orden ascendente

Recorre cada valor desde la cabeza, para ir guardandolo en un
auxiliar, el cual al final se imprime.
@param
@return aux.str debe ser: el auxiliar vuelto a un string
*/
template <class T>
std::string List<T>::toStringForward() const {
  std::stringstream aux;
  Link<T> *p;

  p = head;
  aux << "[";
  while (p != 0) {
    aux << p->value;
    if (p->next != 0) {
      aux << ", ";
    }
    p = p->next;
  }
  aux << "]";
  return aux.str();
}

/*
toStringForward - funcion que imprime la lista en orden descendente

Recorre cada valor desde la cola, para ir guardandolo en un
auxiliar, el cual al final se imprime.

@param
@return aux.str debe ser: el auxiliar vuelto a un string
*/
template <class T>
std::string List<T>::toStringBackward() const {
  std::stringstream aux;
  Link<T> *p = tail;
  aux << "[";
  while (p != 0) {
    aux << p->value;
    if (p->prev!= 0) {
      aux << ", ";
    }
    p = p->prev;
  }
  aux << "]";
  return aux.str();
}

/*
deleteValue - funcion que elimina el valor dado

Recorre cada valor de la lista hasta poder llegar
a tener el valor igual al dado. Una vez lo encuentra
lo elimina, y regresa los valores sin el que
se elimino.

@param T val debe ser: la posicion dependiendo del main
@return T eliminado debe ser: los valores de la lista sin el
valor eliminado
*/
template <class T>
T List<T>::deleteValue(T val){
  Link<T>* current = head;
  Link<T>* prev = NULL;
  T eliminado;

  if (current->value == val) {
    eliminado = current->value;
    head = current->next;

    if (head != NULL) {
      head->prev = NULL;
    } else {
      tail = NULL;
    }
    delete current;
    size--;
    return eliminado;
  }
  
  while (current != NULL && current->value != val) {
    prev = current;
    current = current->next;
  }
  
  eliminado = current->value;
  prev->next = current->next;

  if (current->next != NULL) {
    current->next->prev = prev;
  } else {
    tail = prev;
  }

  delete current;
  size--;
  return eliminado;
}

#endif
