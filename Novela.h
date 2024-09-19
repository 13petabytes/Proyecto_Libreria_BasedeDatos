#ifndef Novelas_h
#define Novelas_h
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
  ~Novela() override;
  //getter y setter
  int getNovelaN();
  void setNovelaN(int);
  //metodos
  void unirTXT() override;
  void crearItem() override;
};
#endif //Novelas_h