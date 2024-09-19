#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Libro.h"
using namespace std;

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
void Libro::unirTXT(){
  numero = '1'+ libroN;
}

void Libro::crearItem(){
  int tipo;
  cout<<"Incerte el tipo del Libro que va a archivar:"<<endl;
  cout<<"1) para psicologuía"<<endl;
  cout<<"2) para derecho"<<endl;
  cin>>tipo;
  while (tipo != 1 && tipo != 2){
    cout<<"Incerte una opción valida"<<endl;
    cout<<"1) para psicologuía"<<endl;
    cout<<"2) para derecho"<<endl;
    cin>>tipo;
  }
  libroN = tipo;
}