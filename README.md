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
Este ultimo avance se enfoco en correciones puntuales del codigo y de este mismo documento, que buscaban mejorar la utilidad del programa para el usuario.

### Cambios sobre el tercer avance
1. Inclución de metodo para revisar datos gruardados
2. Remplazo de bubble sort por merge sort
3. Correción de errores de la función "comer", del arbol binario.

   
## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

g++ -std=c++17 main.cpp 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

./tercer_avance 

## Descripción de las entradas del avance de proyecto
Como entrada el programa requiere del archivo Archibaje, el cual se requiere para combinar los nuevos datos con los ya existentes, asegurándose de que el archivo posea los datos ordenados. A la par se requiere de que el usuario vaya insertando los datos requeridos, estos son de carácter numérico, en el caso de que se inserte un carácter que no sea un número arábigo, con los símbolos occidentales, de insertar otro tipo de carácter el programa se rompe.

## Descripción de las salidas del avance de proyecto
Como resultado de la ejecución del programa, se tendrían dos resultados posibles, el primero si el usuario archivo nuevos elementos, y el segundo si busco elementos, estos dos escenarios no son excluyentes, si se agregan datos, el txt Archibaje se vería modificado, si se busca un dato, se desplegará en pantalla si el archivo estaba en el sistema o no. Si no se modifica el archivo, si el usuario empleó la clase Registrador con árbol binario, se tendría como salida la reescritura del archivo sin cambios.

## Casos de prueba
El programa actualmente cuenta con cuatro casos de prueba para las funciones de busqueda, tres referidas a los datos actualmente almacenados en el programa, 110, 211 y 301, si se inserta esos números al solicitarse el id para buscar, marcará que se encuentran en la base de datos, si se inserta cualquier otro valor, se marcará que no existe.

Las funciones encargadas de almacenar datos, se comprobarán almacenando cualquier combinación de datos que no dé como resultado los ids ya almacenados.
El dato nuevo podrá ser buscado.

## Desarrollo de competencias

Se efectuaron comentarios en el programa, donde se profundiza en la funcionalidad y en la complejidad de los casos solicitados.

### SICT0301: Evalúa los componentes

El programa emplea dos propuestas de ordenamiento y búsqueda. El la primera (en la clase Registrador 2) y menos optimizada, tenemos el uso de Bubble Sort y Búsqueda Secuencial, teniendo estos una complejidad de O(n^2), por parte del metodo de ordenamiento, y de O(n). Por otro lado la clase Registrador, al emplear un árbol binario, su complejidad algorítmica es de O(log n), por lo que presenta un caso promedio de uso mejor, tanto en busqueda como en ordenamiento de datos, a la par que el peor caso posible es significativamente mejor. A continuación se presenta una gráfica que representa esto, la línea azul representa el Bubble Sort, la roja la Búsqueda Secuencial y la última el árbol binario:
![image](https://github.com/user-attachments/assets/30cb02a2-6bed-4179-aa93-c27a86d5b3c2)


### SICT0302: Toma decisiones

Si bien en esta entrega se tomaron decisiones en las que no se concretizo en un modelo en el que se decante una preferencia por un sistema de ordenamiento u otro, este punto y el siguiente se formularán a favor de la implementación del árbol binario como unico metodo de ordenamiento y búsqueda.

Como bien se explicó en la competencia anterior, el árbol binario presenta una complejidad algorítmica mucho mejor que los métodos empleados en la clase Registrador2, por lo que para una mejor efectividad del software, el árbol binario es simplemente mejor. Con respecto a las funciones encargadas a interactuar con el archivo txt, el árbol binario presenta una implementaciones bastante sencillas, las cuales dan pie a más de una modificación de los datos del árbol por ejecución del programa, pero siempre registrando sólo una vez los datos en el archivo.

### SICT0303: Implementa acciones científicas

Para este proyecto se emplearon las notaciones asintóticas para el correcto análisis del rendimiento de las funciones, al encontrarse que el árbol binario funciona con una complejidad logarítmica, siendo solo superada por una complejidad constante, O(1), el manejo de bases de datos es significativamente mejor que con la implementación del ordenamiento por Bubble sort y búsqueda mediante Búsqueda Secuencial. Esta diferencia es despreciable en bases de datos chicas, pero muy notable en bases de datos grandes. Como ejemplo, si se tiene una base de datos de 100 elementos, el sistema de Bubble sort, si se tiene una base de datos de tamaño 100 y pasa a ser de tamaño 1000, tardaría un total de 100 ms, con un tiempo de referencia de 1 ms. Mientras que el árbol binario, en el mismo caso, tarda aproximadamente 1.5 ms.

  #Cálculos:

![image](https://github.com/user-attachments/assets/4660c715-e33d-4698-8141-17e4ce8a01b0)


