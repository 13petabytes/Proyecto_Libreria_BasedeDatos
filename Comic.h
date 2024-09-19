#ifndef Comic_h
#define Comic_h
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include "Item.h"
using namespace std;

class Comic:public Item{
private:
  int comicN;
public:
  //constructor y destructor
  Comic();
  ~Comic() override;
  //getter y setter
  int getComicN();
  void setComicN(int);
  //metodos
  void unirTXT() override;
  void crearItem() override;
};
#endif //Comic_h