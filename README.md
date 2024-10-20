# Proyecto: Libreria bade de datos
El proyecto tiene el proposito de ser una base de datos funcional, para una libreria de una casa. Los datos seran guardados en un txt, que sera leido y modificado por el programa, ordenando los datos por el numero de su id.

## Descripción del avance 1
El primer avance ordenava los ids de los objetos mediante booble sort, estos ids eran generados por objetos de cada clase de items que se podia almacenar. Este ordenamiento mediante booble sort lo efectuaba la misma clase que registrava los archivos.

## Descripción del avance 2
En este avance se modifico la clase que Registrador los datos, para que en vez de funcionar con un booble sort, funcione como un arbol binario, el cual tambien registra los datos.

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



## Descripción de las salidas del avance de proyecto
Escribe aquí la descripción de los resultados de la ejecución de tu programa.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Si lograste este criterio en el primer avance, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Si lograste este criterio en el primer avance, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.
