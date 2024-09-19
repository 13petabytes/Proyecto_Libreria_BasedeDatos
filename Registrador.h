#ifndef Registrador_h
#define Registrador_h
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <cstring>
using namespace std;

class Registrador{
private:
  vector<int> txt;
  void cambio(vector<int> &lista,int i, int j){

    int aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;  
  };
public:
  //constructor y destructor
  Registrador();
  ~Registrador();
  //getter y setter
  vector<int> getTxt();
  void setTxt(vector<int>);
  //metodos
  void archivar(vector<int> &lista);
  void buscar(int);

};
#endif //Registrador_h