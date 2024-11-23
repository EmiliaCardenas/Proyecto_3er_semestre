/*
Proyecto Organizador de cartas de K-pop
Emilia Cárdenas Lobatón
A01706807

Este apartado define los algoritmos de arbol heap
Arregla los valores de forma de un arbol heap
el cual tiene que estar balanceado en sus nodos

Promedio: O(log n)
Peor: O(n log n)
*/

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	int size;
	int count;

	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

public:
	Heap(int) ;
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T) ;
	void addVector(std::vector<T>& valores);
	void clear();
	std::string toString();
	std::string toStringDescending();
};

template <class T> //Constructor
Heap<T>::Heap(int sze) {
	size = sze;
	data = new T[size];
	count = 0;
}

template <class T> //Destructor
Heap<T>::~Heap() {
	delete [] data;
	data = 0;
	size = 0;
	count = 0;
}

template <class T> //verifica si esta vacia la lista
bool Heap<T>::empty() const {
	return (count == 0);
}

template <class T> //verifica si esta llena la lista
bool Heap<T>::full() const {
	return (count == size);
}

template <class T> //calcula quien es el padre
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T> //calcula el nodo que se encuentra a la izquierda
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2*pos)+1);
}

template <class T> //calcula el nodo que se encuentra a la derecha
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2*pos)+2);
}


/*
swap - cambia el orden de los valores

Se utiliza el sort para poder cambiar de lugar
los valores para poder utilizarlos en un for
Utilizanndo un auxiliar para poder conseguirlo

@param int i debe ser: un int del vector
@param int j debe ser: un int del vector
@return
*/
template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

/*
heapify - Función que ajusta la posición de un nodo

Recursivamente ajusta el nodo en la posición dada
comparando con sus hijos
y aplicando swap si es requerido

@param unsigned int pos debe ser: el índice del nodo a ajustar
@return
*/
template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int izq = left(pos);
	unsigned int der = right(pos);
	unsigned int min = pos;

	if (izq <= count && data[izq] < data[min]) {
		min = izq;
	}
	if (der <= count && data[der] < data[min]) {
		min = der;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

/*
add - Función que añade un nuevo valor al heap.

Inserta un nuevo valor en el heap
El nuevo valor se coloca en la última posición 
y luego se ajusta hacia arriba

@param T val debe ser: el valor que se añadirá al heap
@return
*/
template <class T>
void Heap<T>::add(T val)  {
    unsigned int pos = count;
    count++;
    while (pos > 0 && val < data[parent(pos)]) {
        data[pos] = data[parent(pos)];
        pos = parent(pos);
    }
    data[pos] = val;
}

/*
addVector - Función que añade múltiples valores al heap a partir de un vector

Recorre cada elemento del vector 
y lo inserta en el heap utilizando la función add

@param std::vector<T>& valores debe ser: el vector con los valores a añadir
@return
*/
template <class T>
void Heap<T>::addVector(std::vector<T>& valores) {
    for (T& val : valores) {
        add(val);
    }
}

/*
toString - función para hacer el vector a string

Recorre cada valor desde el inicio, para ir guardandolo en un
auxiliar, el cual al final se imprime.

@param 
@return aux.str debe ser: el auxiliar vuelto a un string
*/
template <class T>
std::string Heap<T>::toString(){
    std::stringstream aux;

	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << ", ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}

/*
toStringDescending - función para hacer el vector a string

Recorre cada valor desde el inicio, para ir guardandolo en un
auxiliar, el cual al final se imprime
Es opuesto al toString, ya que va en manera desendente

@param 
@return aux.str debe ser: el auxiliar vuelto a un string
*/
template <class T>
std::string Heap<T>::toStringDescending(){
    std::stringstream aux;

    aux << "[";
    for (int i = count - 1; i >= 0; i--) {  // Comenzamos desde el último índice
        if (i != count - 1) {
            aux << ", ";
        }
        aux << data[i];
    }
    aux << "]";
    return aux.str();
}

#endif
