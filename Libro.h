#ifndef Libro_h
#define Libro_h
#include <fstream>
#include <string>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include "Item.h"
using namespace std;

class Libro:public Item{
private:
  int libroN;
public:
  //constructor y destructor
  Libro();
  ~Libro() override;
  //getter y setter
  int getLibroN();
  void setLibroN(int);
  //metodos
  void unirTXT() override;
  void crearItem() override;
};
#endif //Libro_h