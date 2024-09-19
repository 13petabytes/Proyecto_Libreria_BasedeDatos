#ifndef Item_h
#define Item_h
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
using namespace std;

class Item{
protected:
    int numero;
public:
    //contructor y destructor
    Item();
    virtual ~Item() = 0;
    //getter y setter
    int getNumero();
    void setNumero(int);
    //metodos
    virtual void unirTXT() = 0;
    virtual void crearItem() = 0;
};
#endif //Item_h