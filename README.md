# Proyecto: Libreria bade de datos
Verción de c++ = 12.2.0

El proyecto tiene el proposito de ser una base de datos funcional, para una libreria de una casa. Los datos seran guardados en un txt, que sera leido y modificado por el programa, ordenando los datos por el numero de su id.

## Descripción del avance 1
El primer avance ordenava los ids de los objetos mediante booble sort, estos ids eran generados por objetos de cada clase de items que se podia almacenar. Este ordenamiento mediante booble sort lo efectuaba la misma clase que registrava los archivos.

## Descripción del avance 2
En este avance se modifico la clase que Registrador los datos, para que en vez de funcionar con un booble sort, funcione como un arbol binario, el cual tambien registra los datos.
La clase registrador tiene dos funciones principales, comerTXT y archivar.
Estas funciones se ejecutan siemrpe en el programa.
La primera, comer TXT, lo que hace es que almacena todos lo datos del txt en el arbol, para despues borrarlos, esto debido a que posteriormente, con el comendo archivar, se guardata toda la información del arbol en el txt, la información se guarla en el orden despelgado por la función "inorder" vista en clase.

### Cambios sobre el primer avance
1. Elimincación de archivos .cpp para las clases. Esto se deve a que al compilar dava problemas, definiendose todo en los .h.
2. Se modifico la clase Registrador para que sea un arbol binario. Esto debido a que no hay inconvenientes en que no se puede almacenar unidades repetidas al ser el proyecto para una libreria de pequeña escala.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
![image](https://github.com/user-attachments/assets/79bf25ff-3254-4176-bafb-054b3c79d4b0)
El usuario tiene que indicar que quiere hacer agregar objetos, buscar o salir del programa.
![image](https://github.com/user-attachments/assets/073380d4-3798-409a-887a-85f2bdbfa534)
Si el ususario agrega, se le pide el indicar que cantidad de cada objeto disponible a archivar, para despues contestar pregunta para generar el ID.
![image](https://github.com/user-attachments/assets/5d9f4a7e-6903-4ea5-9aa0-73ae297e4fe2)
Si el usuario quiere buscr un item tiene que incertar el numero del mismo.

A el usuario se le va indicando que puede y que no puede poner, todo se controla incertando numeros.

## Descripción de las salidas del avance de proyecto
Si el archivo a buscar se encuentra en la base de datos.
![image](https://github.com/user-attachments/assets/01cf1c51-880d-46e4-96dd-2cc49f2346ab)
Si no se encuestra en la base de datos.
![image](https://github.com/user-attachments/assets/e4435fdc-79dc-40aa-89c1-45f1b22259ca)
Salida del sistema, aqui se guardan todos los datos, si hay nada para guardar marca error al archiuvar y se cierra el programa.
![image](https://github.com/user-attachments/assets/f5a00609-a6d8-4266-9ad7-efe9b095abb5)
![image](https://github.com/user-attachments/assets/5f38c042-90e5-4ad4-b684-8173bcd5e44d)

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

Considero que logre cumplir con esta unidad de formación, puesto a que fui capaz de evaluar que necesitava cambiar en el funcionamiento de un arbol binario, para poder implementarlo en el proyecto, a la par de entender el porque me convenia más el que pa clase Registrador funcionara como un arbol binario que como lo tenia antes. La rasone de esto es que la incerción en el arbol es más eficiente, ordenando el dato en el proceso, devido al ordenamiento limpio caracteristico de los arboles binarios.

### SICT0302: Toma decisiones

Considero que de momento he tenido una toma de deciociones adecuadas, puesto a que el como estoy planteando el algoritmo, al tener como base el arbol binario, es muy facil el agregar nuevas funciones. Lo unico es que antes de eso tendria que replñantear el funcionameiento de la creación de IDs, pero el sistema para ordenarlas y erchivarlas ya estaria compelto, con la posibilidad de actualziarlo.

### SICT0303: Implementa acciones científicas

Considero que laimplementación del mecanismo de lectura de archivos esta bien implementado, al estar fucionado dentro del arbol binario, compactando así el almacenamiento y ordenamiento en una sola función. 
