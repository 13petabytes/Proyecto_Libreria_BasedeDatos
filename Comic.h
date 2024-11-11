#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include "Item.h"
using namespace std;

//Definición de la sublcase Comic

class Comic: public Item{
private:
  //Variable int que ayuda a la modificación de la variable numero, heredada de Item
  int comicN;
public:
  //constructor y destructor
  Comic(){};
  ~Comic(){};
  //getter y setter
  int getComicN();
  void setComicN(int);
  //metodos
  //comentarios detallados abajo
  //Se encarga de definir la variable numero
  void unirTXT() override;
  //Se encarga de pedirle al usuario los datos del objeto a registrar
  void crearItem() override;
};

//getter y setter

void Comic::setComicN(int comicN_N){
  comicN = comicN_N;
}
int Comic::getComicN(){
  return comicN;
}



//metodos
void Comic::unirTXT(){
//Se define la sentena del id como 200, esto para la correcta diferenciación de esta clase de objetos
  numero = 200 + comicN;
}

void Comic::crearItem(){
  //se definen variables
  int tipo;
  int pasta;
  
  //Se le pide al usuario que incerte numeros acorde a las caracteristicas del objeto a archivar
  cout<<"Incerte el tipo de Comic que va a archivar:"<<endl;
  cout<<"1) para Marvel"<<endl;
  cout<<"2) para DC"<<endl;
  cout<<"3) para Otro"<<endl;
  cin>>tipo;
  //W*
  while (tipo != 1 && tipo != 2 && tipo != 3){
    cout<<"Incerte una opción valida"<<endl;
    cout<<"1) para Marvel"<<endl;
    cout<<"2) para DC"<<endl;
    cout<<"3) para Otro"<<endl;
    cin>>tipo;
  }
  cout<<"Incerte el tipo de pasta del Comic:"<<endl;
  cout<<"1) para Dura"<<endl;
  cout<<"2) para Blanda"<<endl;
  cin>>pasta;
  //W*
  while (pasta != 1 && pasta != 2){
    cout<<"Incerte una opción valida"<<endl;
    cout<<"1) para Dura"<<endl;
    cout<<"2) para Blanda"<<endl;
    cin>>pasta;
  }
  //Se unifica todo en la variable comicN
  comicN = tipo*10 + pasta;
}
