#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <cstring>
#include "Registrador.h"
using namespace std;

//constructor y destructor
Registrador::Registrador(){};

Registrador::~Registrador(){};

//getter y setter
void Registrador::setTxt(vector<int> Txt_N){
  txt = Txt_N;
}

vector<int> Registrador::getTxt(){
  return txt;
}

//metodos

void Registrador::archivar(vector<int> &lista){
   for (int i = (lista.size() - 1); i >= 0; i--){

     for (int j = 0; j < i; j++){

       if (lista[j] > lista[ j + 1 ]){

         cambio(lista, j, j + 1);
       }
     }
   }
  txt = lista;
  ofstream archivo("Archibaje.txt", ios::app);
  int i = txt.size();
  int x = 0;
  while(x =! i, x++){
      archivo<<txt[i]<<endl;
    }
}


void Registrador::buscar(int numero){
  //variables
  int mitad;
  int inicio = 0;
  vector<int> cadenaN;
  int lineaAlmacenar;
  int fin;
  
  //definir vector de numeros
  ifstream archivo( "Archibaje.txt" );
  while(!archivo.eof()){
    archivo>>lineaAlmacenar;
    cadenaN.push_back(lineaAlmacenar);
  }
  
  //definir fin
  fin = cadenaN.size() - 1;
  
  //buscar numero
  while (inicio <= fin){
    mitad = (inicio + fin)/2;
    if (cadenaN[mitad] == numero){
      cout<<endl<<"La Figura se encuentra en la base de datos"<<endl;
      break;
    } else if (cadenaN[mitad] > numero){
      fin = mitad - 1;
    } else if (cadenaN[mitad] < numero){
      inicio = mitad + 1;
    } 
  }
  if (cadenaN[inicio] != numero){
    cout<<endl<<"La Figura no se encuentra en la base de datos"<<endl;
  }
  cout<<endl<<"La Figura se encuentra en la base de datos"<<endl;;
}
