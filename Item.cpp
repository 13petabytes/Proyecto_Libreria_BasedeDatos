#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Item.h"
using namespace std;

//constructor y destructor

Item::Item(){};

Item::~Item(){};

//getter y setter

int Item::getNumero(){
  return numero;
}

void Item::setNumero(int numero_N){
  numero = numero_N;
}