#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include "Item.h"
using namespace std;

//Definición de la subclase Novela
//Al igual que en la clase libro, se hace la aclaración que la diferenciación entre libros academicos, aqui titulados como libros, y novelas
//se efectua con el fin de imitar la dispoción u ordenamientos de libros que se hacen en las bibliotecas

class Novela : public Item {
private:
//Variable int que ayuda a la modificación de la variable numero, heredada de Item
  int novelaN;
public:
  //constructor y destructor
  Novela();
  ~Novela();
  //getter y setter
  int getNovelaN();
  void setNovelaN(int);
  //metodos
  //Se detallan abajo
  //Se encarga de definir la variable heredada de item, numero
  void unirTXT() override;
  //Se encarga de solicitarle los datos al usuario apra el id
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
//En esta clase, las sentenas que diferencian al id como uno de una novela, es el numero 300
void Novela::unirTXT() {
  numero = 300 + novelaN;
}

void Novela::crearItem() {
  //se definen variables
  int pasta;
  int genero;
  //Se le soliciatan datos al usuario
  cout<<"Incerte el tipo de pasta de la novela:"<<endl;
  cout<<"1) para Dura"<<endl;
  cout<<"2) para Blanda"<<endl;
  cin>>pasta;
  //W*
  while (pasta != 1 && pasta != 2){
    cout<<"Incerte una opción valida"<<endl;
    cout<<"1) para Dura"<<endl;
    cout<<"2) para Blanda"<<endl;
    cin>>pasta;
  };
  cout << "Seleccione el género de la novela:" << endl;
  cout << "1) Ciencia Ficción" << endl;
  cout << "2) Fantasía" << endl;
  cout << "3) Misterio" << endl;
  cout << "4) Romance" << endl;
  cout << "5) Terror" << endl;
  cin >> genero;
  //W*
  while (genero < 1 || genero > 5) {
    cout << "Inserte una opción válida" << endl;
    cout << "1) Ciencia Ficción" << endl;
    cout << "2) Fantasía" << endl;
    cout << "3) Misterio" << endl;
    cout << "4) Romance" << endl;
    cout << "5) Terror" << endl;
    cin >> genero;
  }
  //Se unifica todo en la variable novelaN
  novelaN = genero*10 +pasta;
}
