# Proyecto_3er_semestre

## Organizador de cartas de K-pop (photocards)
Este proyecto trata de ser un organizador de photocards, las cuales son tarjetas de colección del género musical K-pop. Incluye tambien funciones para añadir, buscar, cambiar el valor o eliminarlas. Siendo un sistema el cual requiere la interacción del usuario, y con instrucciones especificas para que el usuario pueda interactuar de manera correcta, sin que el codigo deje de funcionar. Y es muy importante leer las instrucciones dentro del programa para que todo llegue a compilar sin errores.

***Especificamente dice que tienen que ser 8 valores exactos, y si no son cargados en el primer paso, el codigo no va a compilar. O si es que no se respeta la cantidad de 8 valores impuestos.***

Los atributos son:

Año - Año de nacimiento del integrante

Cantidad - Número de tarjetas por integrante

Tipo - Si es POB, regular o especial

Integrante - El nombre de los integrantes. Esta ultima es parte de una lista, la cual puede ser editada y utilizada de diferentes maneras. Al igual que tiene añadido un archivo con los nombres, los cuales pueden ser directamente editados en el .txt.

### Finalidad primer avance
La finalidad es poder organizar los componentes en orden alfabético o numéricamente ascendente. Se intenta demostrar cómo se haría con cada tema de manera individual y como sería si se ordenarán de manera ligada. Uniendo los cuatro atributos en el ordenamiento. A su vez se creó un algoritmo de búsqueda de integrales y de strings, para poder saber la posición de cierto valor del vector. 

**Correciones:** Agregar la complejidad de las funciones en el código.

### Finalidad segundo avance
Añadir las listas doblemente enlazadas, junto con la añadidura de los comentarios necesarios en las funciones. Las listas traen consigo diferentes funciones para poder interactuar con ellas. Empezando con añadir valores limitados a la lista, poder buscar su posición en la lista, cambiar un valor con su posición y por ultimo eliminar el valor. Para al final convertirlo en un vector a utilizar junto con las funciones vistas en el primer avance.

**Correciones:** Agregar la complejidad de las funciones en el readme de manera detallada.

### Finalidad tercer avance
Añadir algun tipo de arbol, en est caso heap para poder demostrar el funcionamiento más eficiente de estos. Tiene una función parecida al algoritmo de busqueda, pero en este caso, internamente lo hace más eficiente. Al igual que la correción de ciertos problemas de logica en el main para llegar a conseguir el resultado final.

**Correciones:** Agregar la inclución de un archivo de texto.

### Correciones finales: 
Habilitar la edición de varios factores en el archivo de texto. Añadir la complejidad final del código. 

### Complejidad de las listas doblemente enlazadas
Las listas doblemente ligadas son estructuras de datos donde cada nodo puede referenciar al siguiente nodo y al anterior, facilitando el acceso bidireccional. 
El promedio en estas listas es Θ(n), con un rendimiento en el peor de los casos de O(n) cuando se busca un valor en una lista larga. El mejor caso, cuando el valor se encuentra en el primer nodo, es O(1).
Al insertar un elemento en una lista doblemente ligada, la operación tiene una complejidad promedio de O(1). Sin embargo, si se requiere buscar una posición específica, la inserción se degrada a O(n) debido al tiempo necesario para localizarla. 
Cambiar el valor de un nodo es O(1) cuando la posición es conocida, pues solo requiere actualizar el contenido del nodo.
Eliminar un nodo también puede lograrse en O(1) si se conoce el nodo a eliminar, pero implica O(n) si es necesario buscar su ubicación.

### Complejidad de algoritmo de ordenamiento
Bubble Sort, este método organiza los elementos de un vector en orden ascendente mediante una serie de comparaciones y cambios de posición entre elementos adyacentes. Bubble Sort tiene una eficiencia de Ω(n), en el mejor de los casos con los elementos casí completamente ordenados. En promedio, su complejidad es Θ(n²), y en el peor caso la eficienciaes O(n²) debido a las múltiples iteraciones necesarias para organizar el conjunto de datos.

### Complejidad de algoritmo de busqueda
Búsqueda Secuencial Iterativa, este método recorre los elementos de una lista o vector de forma lineal hasta encontrar el valor buscado o llegar al final de la lista. En el mejor caso, la complejidad es O(1), realizando una sola comparación. Sin embargo, en promedio y en el peor caso, la complejidad es O(n), dado que puede ser necesario recorrer toda la lista para encontrar el elemento o confirmar su ausencia.

### Complejidad de algoritmo de arbol heap
En un árbol Heap, los elementos se organizan de tal manera que cada nodo cumple con la propiedad de Heap, donde el valor de cada nodo es mayor o menorque el de sus hijos. Para la inserción, la complejidad en el mejor caso es O(1) si el elemento se coloca directamente en su posición correcta. Sin embargo, en promedio y en el peor caso, la complejidad es O(log n) debido a que puede ser necesario recorrer hasta la altura del árbol (log n).

### Complejidad del codigo
Una vez analizando el uso de cada una de las funciones, y viendo su utilización dentro del main se puede llegar a la conclusión de que la complejidad del codigo es de O(n²). Puede llegar a cambiar dicha complejidad y ser multiplicada por el número de iteraciones del programa a realizar. Siendo que de todas maneras es una de las peores complejidades a tener, gastando mucho tiempo y memoria.
