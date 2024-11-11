#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <cstring>
#include <sstream>
using namespace std;

//Definición de clase Registrador2
//bubleSort + busquedaSecuancial

//Devido a la disposición del archivo, se señalara que parte coresponde a bubleSort y cual a busqueda Secuancial en las funciones, devido a que ninguna se dedica explusivamente a ordenar o a buscar
//Aqui arriva se aclarara como se señala cada parte y sus casos corespondientes

//BubleSort = BSt
//Se opto por este metodo al ser facilmente aplicable dentro de una función, ahorando la necesidad de llamar a una tersera función dentro de archivar y por un gusto personal por el metodo de ordenamiento
//n = numero de elementos de la lista
//peor caso: O(n^2), esto se deve a que el numero de comparaciones e intermabios es cuadratico, realizando el numero maximo de intercambios
//mejor caso: O(n^2), la notación asintónica es la misma, al no estar optimisada correctamente la función, teniendo que hacer comparaciones a todos los datos
//aunque es menos que en el peor caso, la complejidad no cambia, al subir el numero de comparaciones suve n veces
//nuestro caso promedio no difiere del peor, siendo igual de O(n^2), ya que nos encontrariamos en un numero de comparaciones entre el mejor y peor caso

/*codigo:    
    for (int i = lista.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lista[j] > lista[j + 1]) {
                cambio(lista, j, j + 1);
            }
        }
    }
*/

//Busqueda Secuancial = BSl
//Se opta por este tipo de busqueda por resones similares a las que se decidio usar BubleSort, facil implementación y gusto personal por el metodo de busqueda
//En este caso, nuestros casos se deinen por la misma función, pero esta vez es de O(n) (n = numero de datos), sevido a que la cantidad de evaluaciones es igual a la cantidad de datos
//Mejor caso, el valor se encuentra al inicio por lo que el recorido por la lista se pausa en la primera comparación
//Pero caso, el valñor esta al final, en este caso tenemos que recorrer toda la lista
//Caso promedio, este caso se encuentra entre el mejor y el peor caso o la mitad de la lista, teniendo que hacer más de una comparación, pero no se tiene que compara todos los datos

/*codigo:    
    while (inicio <= fin){
        mitad = (inicio + fin)/2;
        if (cadenaN[mitad] == numero){
        cout<<endl<<"La Figura se encuentra en la base de datos"<<endl;
        break;
        } else if (cadenaN[mitad] > numero){
        fin = mitad - 1;
        } else if (cadenaN[mitad] < numero){
        inicio = mitad + 1;
        } 
    }
*/


class Registrador2{
private:
//Definición de variable y de metodo privado
  vector<int> txt;
  void cambio(vector<int> &lista,int i, int j){
    int aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;  
  };
public:
  //constructor y destructor
  Registrador2(){};
  ~Registrador2(){};
  //getter y setter
  vector<int> getTxt(){
    return txt;
};
  void setTxt(vector<int> Txt_N){
  txt = Txt_N;
};
  //metodos
  void archivar(vector<int> &lista) {
    //En esta función, al haver dos instancias de BubleSor que siempre se ejecutan, nuestros casos serian el promedio del Bublesort y cualquier otro caso (incluyendo el promedio):
    //COmplejidades:
    //Mejor: O(2*n^2)
    //Peor: O(2*n^2)
    //Promedio: O(2*n^2)
    // BSt
    for (int i = lista.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lista[j] > lista[j + 1]) {
                cambio(lista, j, j + 1);
            }
        }
    }

    //se abre el archivo
    ofstream archivo("Archibaje.txt", ios::app);

    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    //se almacena
    txt = lista;
    int i = txt.size();
    int x = 0;
    while (x != i) {
        archivo << txt[x] << endl;
        x++;
    }
    archivo.close();  // Cerrar el archivo de escritura

    // Se verifica que el archivo no tenga datos no contemplados
    // para eso se realmacena el contenido del archivo en el vector lista
    // al final se almacena de nuevo
    ifstream archivo_lectura("Archibaje.txt");  // Abrir en modo de lectura

    if (!archivo_lectura) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    string line;
    int f;
    while (getline(archivo_lectura, line)) {
        stringstream aux(line);  // Convertir cada línea en stringstream
        aux >> f;
        lista.push_back(f);
    }
    archivo_lectura.close();

    //se borra el contenido del archivo
    std::ofstream archi2("Archibaje.txt", std::ios::trunc);
    // BSt
    //se repite al ahverse agregado datos al vector lista
    for (int i = lista.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lista[j] > lista[j + 1]) {
                cambio(lista, j, j + 1);
            }
        }
    }

    //se rearchiva el contenido
    txt = lista;
    i = txt.size();
    x = 0;
    archivo.open("Archibaje.txt", ios::out);  // Reabrir en modo de escritura
    while (x != i) {
        archivo << txt[x] << endl;
        x++;
    }
    archivo.close();
}

//Aclaración, la función de busqueda se considera que tambien interactua con el usuario, por eso se dice arriva que no solo realiza la busqueda
  void buscar(int numero){  
        //variables
    int mitad;
    int inicio = 0;
    vector<int> cadenaN;
    int lineaAlmacenar;
    int fin;
    
    //definir vector de numeros
    ifstream archivo( "Archibaje.txt" );
    while(!archivo.eof()){
        archivo>>lineaAlmacenar;
        cadenaN.push_back(lineaAlmacenar);
    }
    
    //definir fin
    fin = cadenaN.size() - 1;
    
    //BSl
    while (inicio <= fin){
        mitad = (inicio + fin)/2;
        if (cadenaN[mitad] == numero){
        cout<<endl<<"La Figura se encuentra en la base de datos"<<endl;
        break;
        } else if (cadenaN[mitad] > numero){
        fin = mitad - 1;
        } else if (cadenaN[mitad] < numero){
        inicio = mitad + 1;
        } 
    }
    if (cadenaN[inicio] != numero){
        cout<<endl<<"La Figura no se encuentra en la base de datos"<<endl;
    }
    cout<<endl<<"La Figura se encuentra en la base de datos"<<endl;;
    };
};
