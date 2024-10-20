#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include "Item.h"
using namespace std;

class Novela : public Item {
private:
  int novelaN;
public:
  //constructor y destructor
  Novela();
  ~Novela();
  //getter y setter
  int getNovelaN();
  void setNovelaN(int);
  //metodos
  void unirTXT() override;
  void crearItem() override;
};

//constructor y destructor
Novela::Novela(){}

Novela::~Novela(){}

//getter y setter
void Novela::setNovelaN(int novelaN_N) {
  novelaN = novelaN_N;
}

int Novela::getNovelaN() {
  return novelaN;
}

//metodos
void Novela::unirTXT() {
  numero = '3' + novelaN;
}

void Novela::crearItem() {
  int pasta;
  cout<<"Incerte el tipo de pasta de la novela:"<<endl;
  cout<<"1) para Dura"<<endl;
  cout<<"2) para Blanda"<<endl;
  cin>>pasta;
  while (pasta != 1 && pasta != 2){
    cout<<"Incerte una opción valida"<<endl;
    cout<<"1) para Dura"<<endl;
    cout<<"2) para Blanda"<<endl;
    cin>>pasta;
  };
  novelaN = pasta;
}
