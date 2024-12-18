# Proyecto: Librería base de datos



El proyecto tiene el propósito de ser una base de datos funcional, para una librería de una casa. Los datos serán guardados en un txt, que será leído y modificado por el programa, ordenando los datos por el número de su id.

## Descripción del avance 1
El primer avance ordena los ids de los objetos mediante bubble sort, estos ids eran generados por objetos de cada clase de items que se podía almacenar. Este ordenamiento mediante bubble sort lo efectuaba la misma clase que registraba los archivos.

## Descripción del avance 2
En este avance se modificó la clase que Registrador los datos, para que en vez de funcionar con un bubble sort, funcione como un árbol binario, el cual también registra los datos.
La clase registrador tiene dos funciones principales, comerTXT y archivar.
Estas funciones se ejecutan siempre en el programa.
La primera, comer TXT, lo que hace es que almacena todos lo datos del txt en el árbol, para después borrarlos, esto debido a que posteriormente, con el comando archivar, se guardará toda la información del árbol en el txt, la información se guarda en el orden desplegado por la función "inorder" vista en clase.

### Cambios sobre el primer avance
1. Eliminación de archivos .cpp para las clases. Esto se debe a que al compilar daba problemas, definiéndose todo en los .h.
2. Se modificó la clase Registrador para que sea un árbol binario. Esto debido a que no hay inconvenientes en que no se puede almacenar unidades repetidas al ser el proyecto para una librería de pequeña escala.

## Descripción del avance 3
En el penúltimo avance del proyecto, se enfocó a la corrección de errores presentes en el segundo avance, a la par de actualizar y reintegrar en el código la clase Registrador del primer avance, en la forma de una nueva clase llamada Registrador2. A la par de este último cambio, el usuario puede elegir cuál de los dos registradores usar, cada vez que se corre el código solo se puede usar uno de los dos registradores, para usar el otro se tiene que volver a correr el código.

### Cambios sobre el segundo avance
1. Inclusión de la clase Registrador2
2. Actualización de las clases Novela, Comic y Libro para que el código se cree adecuadamente, a la par de expandir los tipos de libros y novelas que se pueden almacenar
3. Actualización del main para que el usuario puede decidir cual motor de búsqueda quiere usara
4. Comentarios en el código que lo explica

## Descripción del avance final
Este último avance se enfocó en correcciones puntuales del código y de este mismo documento, que buscaban mejorar la utilidad del programa para el usuario.

### Cambios sobre el tercer avance
1. Inclusión de método para revisar datos guardados, a la par de ser desplegados todos los datos, tras agregar datos nuevos.
2. Reemplazo de bubble sort por merge sort
3. Corrección de errores de la función "comer", del árbol binario.

   
## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

g++ -std=c++17 main.cpp 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

./entrega_final

## Descripción de las entradas del avance de proyecto
Como entrada el programa requiere del archivo Archibaje, el cual se requiere para combinar los nuevos datos con los ya existentes, asegurándose de que el archivo posea los datos ordenados. A la par se requiere de que el usuario vaya insertando los datos requeridos, estos son de carácter numérico, en el caso de que se inserte un carácter que no sea un número arábigo, con los símbolos occidentales, de insertar otro tipo de carácter el programa se rompe.

## Descripción de las salidas del avance de proyecto
Como resultado de la ejecución del programa, se tendrían dos resultados posibles, el primero si el usuario archivo nuevos elementos, y el segundo si busco elementos, estos dos escenarios no son excluyentes, si se agregan datos, el txt Archibaje se vería modificado, si se busca un dato, se desplegará en pantalla si el archivo estaba en el sistema o no. Si no se modifica el archivo, si el usuario empleó la clase Registrador con árbol binario, se tendría como salida la reescritura del archivo sin cambios.
Si el usuario emplea la función encargada de desplegar la base de datos, se desplegará la base de datos, siendo esta la única salida que se puede repetir múltiples veces, sin contar el mensaje de valor encontrado o no encontrado.

## Casos de prueba
El programa actualmente cuenta con cuatro casos de prueba para las funciones de busqueda, tres referidas a los datos actualmente almacenados en el programa, 110, 211 y 301, si se inserta esos números al solicitarse el id para buscar, marcará que se encuentran en la base de datos, si se inserta cualquier otro valor, se marcará que no existe.

Las funciones encargadas de almacenar datos, se comprobarán almacenando cualquier combinación de datos que no dé como resultado los ids ya almacenados.
El dato nuevo podrá ser buscado. Si se emplea la nueva función se podrá ver la base de datos,

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

El programa emplea dos propuestas de ordenamiento y búsqueda. El la primera (en la clase Registrador 2) y menos optimizada, tenemos el uso de Merge Sort y Búsqueda Secuencial, teniendo estos una complejidad de O(n log n), por parte del método de ordenamiento, y de O(n). Por otro lado la clase Registrador, al emplear un árbol binario, su complejidad algorítmica es de O(log n), por lo que presenta un caso promedio de uso mejor, tanto en búsqueda como en ordenamiento de datos. 
Las complejidades de los motores para las 3 acciones principales que se efectúan se puede ver en esta tabla, donde se muestran los casos promedios, la razón de que el desplegar base de datos siempre sea O(n) se da porque siempre se tarda en proporción a la cantidad de datos, tanto porque en el motor del Registrador 2 se recorren todos los datos en orden y en el método semejante en el archivo Registrador, se emplea la función Inorder como apoyo, la cual recorre todo los datos del árbol uno por uno, concluyendo de nuevo con la complejidad de O(n). Los métodos de búsqueda al desplegar la base de datos, se les agrega la complejidad de la función desplegar. Ya que las funciones se pueden efectuar de manera independeinte, la complejidad general seria la función más grande.

![image](https://github.com/user-attachments/assets/807c6e4c-4fbd-4a00-a9d8-4b8cee8daccd)



Se efectuaron comentarios en el programa, donde se profundiza en la funcionalidad y en la complejidad de los casos solicitados. Más casos específicos como add de Registrador se aclaran en comentarios en el código, a la par de la complejidad de las funciones de la clase nodo empleada para el arbol binario. A la par de aclarar los mejores, peores y casos promedios. Se destaca el echo de que las funciones que tienen contacto con el usuario suelen tener más complejidad de lo que deverian tener hipoteticamente hablando, ya que son el conglomerado de más de una función, sumandoce las complejidades.

### Grafica funciones Registrador:
![image](https://github.com/user-attachments/assets/82a3f6c4-3715-402e-987d-3e319f5bbc9f)


### Grafica funciones Registrador 2:
![image](https://github.com/user-attachments/assets/57947239-5642-4a97-9d52-42857fc363f8)


### SICT0302: Toma decisiones

Si bien en esta entrega se tomaron decisiones en las que no se concretizo en un modelo en el que se decante una preferencia por un sistema de ordenamiento u otro, este punto y el siguiente se formularán a favor de la implementación del árbol binario como unico metodo de ordenamiento y búsqueda.

Como bien se explicó en la competencia anterior, el árbol binario presenta una complejidad algorítmica mucho mejor que los métodos empleados en la clase Registrador2, por lo que para una mejor efectividad del software, el árbol binario es simplemente mejor. Lo curioso de observar es el cómo evolucionan las complejidades al crecer los datos empleados, al tener el Mergesort una complejidad similar a la del árbol binario, O(n*logn) y O(logn), lo esperable es un comportamiento similar de ambos métodos, pero como se puede ver en la siguiente gráfica, en la que se comparan las dos complejidades con la del Bubblesort. Se mantiene el árbol binario como mejor método, pero se destaca el mejor funcionamiento del Mergesort sobre el Bubblesort. Esto se repite para el método de búsqueda de búsqueda secuencial, O(n), que siempre tiende a ser inferior al árbol binario.

![image](https://github.com/user-attachments/assets/965e5fb1-0cbd-45b2-a39a-e7a7e022bcc4)

### SICT0303: Implementa acciones científicas

Las funciones encargadas de la consulta de información, por cada motor son las siguientes:

Registrador:

void buscar(T val) const, está emplea como apoyo la función find de la clase node para recorrer el árbol, junto con la función desplegar, próxima a ser explicada.

void desplegar() const, esta se apoya de la función inorder de la clase node para recolectar los datos almacenados de manera óptima para su lectura.

Registrador 2:

void buscar(int numero), usa como método de busca la búsqueda secuencial, la cual va reduciendo en mitades cadáver más chicas, las base de datos a analizar, a base de ir comparando datos con el deseado a encontrar. Esta función se apoya del mismo método que la siguiente.

void desplegar(), este método lo único que hace es recorrer la lista termino por termino mientras despliega los datos, esto se hace con un ciclo while.

Las funciones encargadas de la lectura y edición de archivos son las siguientes:

Registrador:

Se divide las actividades, archivar escribe y comer lee.

void archivar(), se apoya de la función inorder, para guardar los datos en el txt.

void comerTXT(), se encarga de leer el txt para agregar los datos al árbol binario, para posteriormente eliminar el contenido del txt.


Registrador 2:

Se unifican las dos actividades en una sola función.

void archivar(vector<int>& lista),  se encarga de unificar los datos del txt y los que se desea añadir mediante el método Mergesort, para posteriormente reescribir el txt.
