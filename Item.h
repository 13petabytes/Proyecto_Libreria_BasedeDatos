#ifndef Item_h
#define Item_h
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>

using namespace std;

//Clase padre de las clases que se encargan de crear los ids

class Item{
protected:
    //Variable universal para la clase y sus herederas
    //Su existencia es para la correcta aplicación del ciclo for que crea los ids, que se encuentra en el main
    //Los ids estan pensados para ser de 3 digitos
    //Las clases herederas comparten la caracteristica de que la sentena descrive el tipo de objero
    //Las decenas definen genero de libro, novela o comic y las unidades definen el tipo de pasta
    int numero;
public:
    //contructor y destructor
    Item(){};
    ~Item(){};
    //getter y setter
    int getNumero(){
        return numero;};
    void setNumero(int numero_N){
        numero = numero_N;};
    //metodos
    //Las dos funcioens principales se declaran como virtuales para modificarlas a convenienza en las clases hijas
    virtual void unirTXT() = 0;
    virtual void crearItem() = 0;
};
#endif //Item_h
