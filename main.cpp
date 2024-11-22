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
  //Decisión del usuario para usar motor de búsqueda
  cout<<"¿Cuál es el motor de búsqupeda que quiere usar para navegar por el programa?"<< endl;
  cout<<"1) para árbol binario"<< endl;
  cout<<"2) para MergeSort + búsqueda Secuencial"<< endl;
  cout<<"Una vez escogido un motor, tiene que reabrir el programa para usar el otro"<< endl;
  int motor;
  cin>>motor;
  //El main tiene estos ciclos while para asegurar que el usuario inserte el número pedido
  //Se rompen al insertar un carácter que no sea un número
  //Se marcarán con el siguiente comentario:
  //W*
  while(motor != 1 && motor != 2){
    cout<<"Escoja una opción válida"<< endl;
    cout<<"1) para árbol binario"<< endl;
    cout<<"2) para MergeSort + búsqueda Secuencial"<< endl;
  }
if (motor == 1){
    //Main del Árbol binario
    //Declaración de objetos y vector
    vector<unique_ptr<Item>> items;
    Registrador<int> archivador;
    //Abrir archivo txt
    ifstream archi("Archibaje.txt");
    //Este if se encarga de leer si el archivo contiene contenido
    //En el caso de que lo tenga, ejecutará la función comerTXT de la clase Registrador
    if (archi.is_open()) {
      archi.seekg(0, std::ios::end);
      if (archi.tellg() == 0) {
        cout << "El programa iniciará su funcionamiento" << endl<<endl;
        archi.close();
      }else {
        archi.close();
        archivador.comerTXT();
      }
    } else {
      cerr << "No se pudo abrir el archivo." << endl;
    }
    //Primer menú para navegar en la base de datos
    cout<<"Bienvenido al sistema de archivos"<<endl;
    cout<<"Inserte la opción que desea realizar:"<<endl;
    cout<<"1) para crear un nuevo item"<<endl;
    cout<<"2) para buscar un item"<<endl;
    cout<<"3) para ver base de datos"<<endl;
    cout<<"4) para salir"<<endl;
    int opcion;
    cin>>opcion;
    //W*
    while(opcion < 1 || opcion > 4){
      cout<<"Inserte una opción válida"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para ver base de datos"<<endl;
      cout<<"4) para salir"<<endl;
      cin>>opcion;
    }
    //El menú de buscar, archivar y desplegar se encierra en un while que confirma que no quiere salir el usuario
    while (opcion != 4){
      //ciclo para crear un nuevo item
      while (opcion == 1){
        // Se le solicitan la cantidad de objetos disponibles a archivar al usuario
        int nComics;
        int nLibros;
        int nNovelas;
        cout<<"Inserte el número de Comics que va a archivar:"<<endl;
        cin>>nComics;
        cout<<"Inserte el número de Libros que va a archivar:"<<endl;
        cin>>nLibros;
        cout<<"Inserte el número de Novelas que va a archivar:"<<endl;
        cin>>nNovelas;
        //Mediante estos ciclos for, se crean versiones únicas de los objetos, acorde a la cantidad que el usuario solicite 
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
        //Se van ejecutando las funciones para crear los IDs de los objetos
        //A la par de eso se van insertando en el árbol binario los IDs
        for (int i = 0; i < tItems; ++i){
          items[i]->crearItem();
          items[i]->unirTXT();
          int y = items[i]->getNumero();
          archivador.add(y);
        }
        //Se finaliza el guardado de datos en el árbol binario
        //El archivaje en el txt se efectúa al final del programa, para no generar problemas si el usuario quiere agregar más datos
        cout<<"¿Qué desea hacer ahora?"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para ver base de datos"<<endl;
        cout<<"4) para salir"<<endl;
        cin>>opcion;
        //W*
        while(opcion < 1 || opcion > 4){
          cout<<"Inserte una opción válida"<<endl;
          cout<<"1) para crear un nuevo item"<<endl;
          cout<<"2) para buscar un item"<<endl;
          cout<<"3) para ver base de datos"<<endl;
          cout<<"4) para salir"<<endl;
          cin>>opcion;
        }
      }
      //ciclo para buscar item
      while(opcion == 2){
        //El buscador de objetos solo funciona con un ID de objeto a la vez
        //Si el usuario quiere buscar otro objeto tiene que volver a seleccionar la opción de buscar objeto
        int numero;
        cout<<"Inserte el número del item que va a buscar:"<<endl;
        cin>>numero;
        //Se llama a la función buscar
        archivador.buscar(numero);
        cout<<"¿Qué desea hacer ahora?"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para ver base de datos"<<endl;
        cout<<"4) para salir"<<endl;
        cin>>opcion;
        //W*
        while(opcion < 1 || opcion > 4){
          cout<<"Inserte una opción válida"<<endl;
          cout<<"1) para crear un nuevo item"<<endl;
          cout<<"2) para buscar un item"<<endl;
          cout<<"3) para ver base de datos"<<endl;
          cout<<"4) para salir"<<endl;
          cin>>opcion;
        }
      }
      //ciclo para ver base de datos
      while(opcion == 3){
        archivador.desplegar();
        cout<<"¿Qué desea hacer ahora?"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para ver base de datos"<<endl;
        cout<<"4) para salir"<<endl;
        cin>>opcion;
        //W*
        while(opcion < 1 || opcion > 4){
          cout<<"Inserte una opción válida"<<endl;
          cout<<"1) para crear un nuevo item"<<endl;
          cout<<"2) para buscar un item"<<endl;
          cout<<"3) para ver base de datos"<<endl;
          cout<<"4) para salir"<<endl;
          cin>>opcion;
        }
      }
    }
    //se archiva el contenido del árbol
    archivador.archivar();

    cout<<endl<<"Adiós";
    return 0;
} else if(motor == 2){
    //No cambia mucho el cómo está estructurado, solo ciertas partes muy concretas
    //La estructura general es la misma
    //Se definen variables y objetos para el motor de búsqueda
    vector<unique_ptr<Item>> items;
    Registrador2 archivador;
    //Interfaz para que el usuario decida qué hacer
    cout<<"Bienvenido al sistema de archivos"<<endl;
    cout<<"Inserte la opción que desea realizar:"<<endl;
    cout<<"1) para crear un nuevo item"<<endl;
    cout<<"2) para buscar un item"<<endl;
    cout<<"3) para ver base de datos"<<endl;
    cout<<"4) para salir"<<endl;
    int opcion;
    cin>>opcion;
    //W*
    while(opcion < 1 || opcion > 4){
      cout<<"Inserte una opción válida"<<endl;
      cout<<"1) para crear un nuevo item"<<endl;
      cout<<"2) para buscar un item"<<endl;
      cout<<"3) para ver base de datos"<<endl;
      cout<<"4) para salir"<<endl;
      cin>>opcion;
    }
    //While para checar que el usuario no quiere seguir en el sistema
    while (opcion != 4){
      //ciclo para crear un nuevo item
      while (opcion == 1){
        //Se repite la creación de objetos únicos en el vector, imitando a la parte anterior
        int nComics;
        int nLibros;
        int nNovelas;
        int tItems;
        cout<<"Inserte el número de Comics que va a archivar:"<<endl;
        cin>>nComics;
        cout<<"Inserte el número de Libros que va a archivar:"<<endl;
        cin>>nLibros;
        cout<<"Inserte el número de Novelas que va a archivar:"<<endl;
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
        //Aquí se da el principal cambio, en vez de estar todo el almacenaje de IDs en el ciclo for
        //Se llama a la función archivar tras haber guardado los IDs en un vector int que se usa como variable necesaria para la función archivar
        //Esto resultó más conveniente para el MergeSort, ya que depende mucho de vectores
        for (int i = 0; i < tItems; ++i){
            items[i]->crearItem();
            items[i]->unirTXT();
            int y = items[i]->getNumero();
            valorI.push_back(y);
        }
        //Una vez terminado el ciclo, el valor del vector se usa en la función
        archivador.archivar(valorI);
        //Se repite el procedimiento para decidir qué hacer tras haber terminado el archivar
        cout<<"¿Qué desea hacer ahora?"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para ver base de datos"<<endl;
        cout<<"4) para salir"<<endl;
        cin>>opcion;
        //W*
        while(opcion < 1 || opcion > 4){
          cout<<"Inserte una opción válida"<<endl;
          cout<<"1) para crear un nuevo item"<<endl;
          cout<<"2) para buscar un item"<<endl;
          cout<<"3) para ver base de datos"<<endl;
          cout<<"4) para salir"<<endl;
          cin>>opcion;
        }
      }
      //ciclo para buscar un item
      while(opcion == 2){
        int numero;
        cout<<"Inserte el número del item que va a buscar:"<<endl;
        cin>>numero;
        //Aquí se da el segundo cambio más importante
        //Se llama a la función buscar, que depende del MergeSort
        archivador.buscar(numero);
        cout<<"¿Qué desea hacer ahora?"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para ver base de datos"<<endl;
        cout<<"4) para salir"<<endl;
        cin>>opcion;
        //W*
        while(opcion < 1 || opcion > 4){
          cout<<"Inserte una opción válida"<<endl;
          cout<<"1) para crear un nuevo item"<<endl;
          cout<<"2) para buscar un item"<<endl;
          cout<<"3) para ver base de datos"<<endl;
          cout<<"4) para salir"<<endl;
          cin>>opcion;
        }
      }
      //ciclo para ver base de datos
      while(opcion == 3){
        archivador.desplegar();
        cout<<"¿Qué desea hacer ahora?"<<endl;
        cout<<"1) para crear un nuevo item"<<endl;
        cout<<"2) para buscar un item"<<endl;
        cout<<"3) para ver base de datos"<<endl;
        cout<<"4) para salir"<<endl;
        cin>>opcion;
        //W*
        while(opcion < 1 || opcion > 4){
          cout<<"Inserte una opción válida"<<endl;
          cout<<"1) para crear un nuevo item"<<endl;
          cout<<"2) para buscar un item"<<endl;
          cout<<"3) para ver base de datos"<<endl;
          cout<<"4) para salir"<<endl;
          cin>>opcion;
        }
      }
    }
    cout<<endl<<"Adiós";
    return 0;
}

}
