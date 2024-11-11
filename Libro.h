#include <fstream>
#include <string>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include "Item.h"
using namespace std;

//Definición de la subclase libro
//En el programa se considera como clase libro a los que sean de caracter educativo
//Despreciando en esta clase a las novelas, las cuales tienen la sulla propia
//Esto se decidio así devido a que en la bliblioteca de mi casa, y en cualquier otra, existe una divición tasita entre los libros academicos y los de entretenimietno

class Libro: public Item{
private:
//Variable int que ayuda a la modificación de la variable numero, heredada de Item
  int libroN;
public:
  //constructor y destructor
  Libro();
  ~Libro();
  //getter y setter
  int getLibroN();
  void setLibroN(int);
  //metodos
  //comentarios detallados abajo
  //Se encarga de definir la variable numero
  void unirTXT() override;
  //Se crea el id el objeto
  void crearItem() override;
};
//constructor y destructor
Libro::Libro(){};

Libro::~Libro(){};

//getter y setter
void Libro::setLibroN(int librotN_N){
  libroN = librotN_N;
}

int Libro::getLibroN(){
  return libroN;
}

//metodos
//Para la diferenciación de este grupo de objetos, se decidio que las sentenas fueran el numero 100
void Libro::unirTXT(){
  numero = 100 + libroN;
}

void Libro::crearItem() {
  //Se definene las variables
  int tipo;
  int pasta;

  //Se le solisita al usuario la información del libro
  cout << "Inserte el tipo del Libro que va a archivar:" << endl;
  cout << "1) para Psicología" << endl;
  cout << "2) para Derecho" << endl;
  cout << "3) para Filosofía" << endl;
  cout << "4) para Programación" << endl;
  cout << "5) para Estadística" << endl;
  cin >> tipo;
  
  //W*
  while (tipo < 1 || tipo > 5) {
    cout << "Inserte una opción válida" << endl;
    cout << "1) para Psicología" << endl;
    cout << "2) para Derecho" << endl;
    cout << "3) para Filosofía" << endl;
    cout << "4) para Programación" << endl;
    cout << "5) para Estadística" << endl;
    cin >> tipo;
  }

  cout << "Inserte el tipo de pasta del libro:" << endl;
  cout << "1) para Dura" << endl;
  cout << "2) para Blanda" << endl;
  cin >> pasta;
  
  //W*
  while (pasta != 1 && pasta != 2) {
    cout << "Inserte una opción válida" << endl;
    cout << "1) para Dura" << endl;
    cout << "2) para Blanda" << endl;
    cin >> pasta;
  }

  //Se unifican los valores dados en la variable libroN
  libroN = tipo * 10 + pasta;
}
