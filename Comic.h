#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include "Item.h"
using namespace std;

class Comic: public Item{
private:
  int comicN;
public:
  //constructor y destructor
  Comic(){};
  ~Comic(){};
  //getter y setter
  int getComicN();
  void setComicN(int);
  //metodos
  void unirTXT() override;
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
  numero = '2'+ comicN;
}

void Comic::crearItem(){
  int tipo;
  int pasta;
  
  cout<<"Incerte el tipo de Comic que va a archivar:"<<endl;
  cout<<"1) para Marvel"<<endl;
  cout<<"2) para DC"<<endl;
  cout<<"3) para Otro"<<endl;
  cin>>tipo;
  cout<<endl<<comicN<<endl;
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
  while (pasta != 1 && pasta != 2){
    cout<<"Incerte una opción valida"<<endl;
    cout<<"1) para Dura"<<endl;
    cout<<"2) para Blanda"<<endl;
    cin>>pasta;
  }
  
  comicN = tipo + pasta;
}