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
using namespace std;

int main() {
  //Declaración de objetos y vector
  vector<unique_ptr<Item>> items;
  Registrador archivador;
  cout<<"Bienvenido al sistema de archivos"<<endl;
  cout<<"Incerte la opción que desea realizar:"<<endl;
  cout<<"1) para crear un nuevo item"<<endl;
  cout<<"2) para buscar un item"<<endl;
  cout<<"3) para salir"<<endl;
  int opcion;
  cin>>opcion;
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
    int nComics;
    int nLibros;
    int nNovelas;
    int tItems;
    cout<<"Incerte el numero de Comics que va a archivar:"<<endl;
    cin>>nComics;
    cout<<"Incerte el numero de Libros que va a archivar:"<<endl;
    cin>>nLibros;
    cout<<"Incerte el numero de Figuras que va a archivar:"<<endl;
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
    int x = 0;
    while (x =! tItems, x++){
      items[x]->crearItem();
    }
    x = 0;
    vector<int>valorI;
    while (x =! tItems, x++){
      int y = items[x]->getNumero();
      valorI.push_back(y);
    }
    archivador.archivar(valorI);
    cout<<"¿Qué desea hacer ahora?"<<endl;
    cout<<"1) para crear un nuevo item"<<endl;
    cout<<"2) para buscar un item"<<endl;
    cout<<"3) para salir"<<endl;
    cin>>opcion;
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
    int numero;
    cout<<"Incerte el numero del item que va a buscar:"<<endl;
      cin>>numero;
    archivador.buscar(numero);
    cout<<"¿Qué desea hacer ahora?"<<endl;
    cout<<"1) para crear un nuevo item"<<endl;
    cout<<"2) para buscar un item"<<endl;
    cout<<"3) para salir"<<endl;
    cin>>opcion;
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