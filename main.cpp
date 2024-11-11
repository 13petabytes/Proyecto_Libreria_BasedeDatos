#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "Item.h"
#include "Comic.h"
#include "Libro.h"
#include "Novela.h" 
#include "Registrador.h"
#include "Registrador2.h"
using namespace std;

int main() {
  //Deición del usuario para usar motor de busqueda
  cout<<"¿Cuál es el motor de búsqueda que quiere usar para navegar por el programa?"<< endl;
  cout<<"1) para arbol binario"<< endl;
  cout<<"2) para bubleSort + busqueda Secuancial"<< endl;
  cout<<"Una vez escogido un motor, tiene que reabrir el programa para usar el otro"<< endl;
  int motor;
  cin>>motor;
  //El main tiene estos ciclos whiles para hacegurar que el usuario incerte el numero pedido
  //Se rompen al incertar un caractar que no sea un numero
  //Se marcaran con el siguiente comentario:
  //W*
  while(motor != 1 && motor != 2){
    cout<<"Escoga una opción valida"<< endl;
    cout<<"1) para arbol binario"<< endl;
    cout<<"2) para bubleSort + busqueda Secuancial"<< endl;
  }
  if (motor ==1){
    //Main del Árbol binario
    //Declaración de objetos y vector
    vector<unique_ptr<Item>> items;
    Registrador<int> archivador;
    //Abrir archivo txt
    ifstream archi("Archibaje.txt");
    //Este if se encarga de leer si el archivo contiene contenido
    //En el caso de que lo tenga, ejecutara la función comerTXT de la clase Registrador
    if (archi.is_open()) {
      archi.seekg(0, std::ios::end);
      if (archi.tellg() == 0) {
        cout << "El programa iniciara su funcionamiento" << endl<<endl;
        archi.close();
      }else {
        archi.close();
        archivador.comerTXT();
      }
    } else {
      cerr << "No se pudo abrir el archivo." << endl;
    }
    //Primer menu para navegar en al vase de datos
    cout<<"Bienvenido al sistema de archivos"<<endl;
    cout<<"Incerte la opción que desea realizar:"<<endl;
    cout<<"1) para crear un nuevo item"<<endl;
    cout<<"2) para buscar un item"<<endl;
    cout<<"3) para salir"<<endl;
    int opcion;
    cin>>opcion;
    //W*
    while(opcion != 1 && opcion != 2 && opcion != 3){
      cout<<"Incerte una opción valida"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para salir"<<endl;
      cin>>opcion;
    }
    //El menu de buscar y archivar se enciarran en un while que confirma que no quiera alir el usuario
    while (opcion != 3){
    //ciclo para crear un nuevo item
    while (opcion == 1){
      // Se le solicitan la cantidad de objetos disponibles a archivar al usuario
      int nComics;
      int nLibros;
      int nNovelas;
      cout<<"Incerte el numero de Comics que va a archivar:"<<endl;
      cin>>nComics;
      cout<<"Incerte el numero de Libros que va a archivar:"<<endl;
      cin>>nLibros;
      cout<<"Incerte el numero de Novelas que va a archivar:"<<endl;
      cin>>nNovelas;
      //Mediante estos siclos for, se crean vercione unicas de los objetos, acorde a la cantidad que el usuario solicite 
        for (int i = 0; i < nComics; ++i){
          items.push_back(make_unique<Comic>());
        }
        for (int i = 0; i < nLibros; ++i){
          items.push_back(make_unique<Libro>());
        }
        for (int i = 0; i < nNovelas; ++i){
          items.push_back(make_unique<Novela>());
        }
      int tItems = nComics + nLibros + nNovelas;
      //Mediante la cantidad de items totales
      //Se van ejecutando las funcioens para crear los ids de los objetos
      //A la par de eso se van incertando en el arbol binario los ids
      for (int i = 0; i < tItems; ++i){
        items[i]->crearItem();
        items[i]->unirTXT();
        int y = items[i]->getNumero();
        archivador.add(y);
      }
      //Se finaliza el guardado de datos en el arbol binario
      //El archivaje en el txt se efectua al final del programa, para no generar problemas si el usuario queire agregar más datos
      cout<<"¿Qué desea hacer ahora?"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para salir"<<endl;
      cin>>opcion;
      //W*
      while(opcion != 1 && opcion != 2 && opcion != 3){
        cout<<"Incerte una opción valida"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para salir"<<endl;
        cin>>opcion;
      }
      }
    //ciclo para buscar item
    while(opcion == 2){
      //El buscador de objetos solo funciona con un id de objetoa la vez
      //Si el usuario quiere buscar otro objeto tiene que volver a seleccionar la opción de buscar objeto
      int numero;
      cout<<"Incerte el numero del item que va a buscar:"<<endl;
        cin>>numero;
      //Se llama a la función buscar
      archivador.buscar(numero);
      cout<<"¿Qué desea hacer ahora?"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para salir"<<endl;
      cin>>opcion;
      //W*
      while(opcion != 1 && opcion != 2 && opcion != 3){
        cout<<"Incerte una opción valida"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para salir"<<endl;
        cin>>opcion;
      }
    }
    }

  //se archiva el contenido del arbol
  archivador.archivar();

  cout<<endl<<"Adios";
  return 0;

} else if(motor == 2){
    //No cambia mucho el como esta estructurado, solo ciartas partesmuy concretas
    //La estructura general es la misma
    //Se definene variables y objetos apra el motor de busqueda
    vector<unique_ptr<Item>> items;
    Registrador2 archivador;
    //Interfaz para que el usuario decida que hacer
    cout<<"Bienvenido al sistema de archivos"<<endl;
    cout<<"Incerte la opción que desea realizar:"<<endl;
    cout<<"1) para crear un nuevo item"<<endl;
    cout<<"2) para buscar un item"<<endl;
    cout<<"3) para salir"<<endl;
    int opcion;
    cin>>opcion;
    //W*
    while(opcion != 1 && opcion != 2 && opcion != 3){
      cout<<"Incerte una opción valida"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para salir"<<endl;
      cin>>opcion;
    }
    //While para checar que el usuario no quiere seguir en el sistema
    while (opcion != 3){
    //ciclo para crear un nuevo item
    while (opcion == 1){
      //Se repite la creación de objetos unicos en el vector, imitando a la parte anterior
      int nComics;
      int nLibros;
      int nNovelas;
      int tItems;
      cout<<"Incerte el numero de Comics que va a archivar:"<<endl;
      cin>>nComics;
      cout<<"Incerte el numero de Libros que va a archivar:"<<endl;
      cin>>nLibros;
      cout<<"Incerte el numero de Novelas que va a archivar:"<<endl;
      cin>>nNovelas;
        for (int i = 0; i < nComics; ++i){
          items.push_back(make_unique<Comic>());
        }
        for (int i = 0; i < nLibros; ++i){
          items.push_back(make_unique<Libro>());
        }
        for (int i = 0; i < nNovelas; ++i){
          items.push_back(make_unique<Novela>());
        }
      tItems = nComics + nLibros + nNovelas;
      vector<int>valorI;
      //Aqui se da el principal cambio, en ves de estar todo el almasenaje de ids en el siclo for
      //Se llama a la función archivar tras haver guardados los ids en un vector int que se usa como variable necesria para la función archivar
      //Esto resulto mejor a la hora de evitar errores
      for (int i = 0; i < tItems; ++i){
        items[i]->crearItem();
        items[i]->unirTXT();
        int y = items[i]->getNumero();
        valorI.push_back(y);
      }
      //La función archivar en este caso tambien almacena los datos en el txt
      //Para provar el como funcionaria este hacercamiento en un sistema de almacenado más simple
      //Por los errores que dio en este se descarto la restrocturación del álbol binario para unir las funciones archivar y add
      archivador.archivar(valorI);
      cout<<"¿Qué desea hacer ahora?"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para salir"<<endl;
      cin>>opcion;
      //W*
      while(opcion != 1 && opcion != 2 && opcion != 3){
        cout<<"Incerte una opción valida"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para salir"<<endl;
        cin>>opcion;
      }
      }
    //ciclo para buscar item
    while(opcion == 2){
      //La logica que se sigue en el main es igual que con la del árbol binario
      int numero;
      cout<<"Incerte el numero del item que va a buscar:"<<endl;
        cin>>numero;
      archivador.buscar(numero);
      cout<<"¿Qué desea hacer ahora?"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para salir"<<endl;
      cin>>opcion;
      //W*
      while(opcion != 1 && opcion != 2 && opcion != 3){
        cout<<"Incerte una opción valida"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para salir"<<endl;
        cin>>opcion;
      }
    }
    }
  cout<<"Adios";
  return 0;
}

}
