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
//MergeSort + busquedaSecuancial

//Devido a la disposición del archivo, se señalara que parte coresponde a bubleSort y cual a busqueda Secuancial en las funciones, devido a que ninguna se dedica explusivamente a ordenar o a buscar
//Aqui arriva se aclarara como se señala cada parte y sus casos corespondientes

//MS = MergeSort
//El sistema de ordenamiento merge sort, nos ofrece a primera vista, un metodo de ordenamiento de complejidad similar al de un arbol binario, O(n logn).
//Si bien esto nos podria dar la impleción de que se comportan de forma similar, esto implicaria que tienen una velocidad de respuesta igual, solo cuando se trata de manegar un solo valor,
//si se agregan más valores la diferencia entre metodos se acresenta cadavez más, de echo a partir de las 11 unidades a ordenar, el metodo tardaria más que uno lineal.
//Esto sirve para demostar lo mucho que pueden variar los casos con el agregado una sola variable.
//Los casos de este metodo de ordenamiento siempre se representan con la misma ecuación, O(n logn), esto devido al funcionamiento del metodo.
//El mejor caso se presentaria si la lisata ya esta ordenada o solo dos valores estan desordenados de talmanera que solo se tiene que intercambiar sus lugares.
//El peor caso para este metodo, se da si la lista a ordenar se encuentra ordenada de forma inversa al como el metodo ordena lso numeros.
//El caso promedio se encontraria en el punto dedio de los dos anteriores.

/*codigo:
void copyArray(vector<int>& A, vector<int>& B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void mergeArray(vector<int>& A, vector<int>& B, int low, int high, int mid) {
    int k = low;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high) {
        B[k] = A[j];
        j++;
        k++;
    }

    copyArray(A, B, low, high);
}

void mergeSplit(vector<int>& A, vector<int>& B, int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;

        mergeSplit(A, B, low, mid);
        mergeSplit(A, B, mid + 1, high);

        mergeArray(A, B, low, high, mid);
    }
}

vector<int> ordenar(const vector<int>& lista) {
    vector<int> v(lista);
    vector<int> tmp(v.size());

    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}
*/

// Búsqueda Secuencial = BSl
// Se opta por este tipo de búsqueda debido a su fácil implementación y una preferencia personal por este método.
// En este caso, nuestros casos se definen por la misma función, pero esta vez es de O(n) (n = número de datos), debido a que la cantidad de evaluaciones es igual a la cantidad de datos.
// Mejor caso: el valor se encuentra al inicio, por lo que el recorrido por la lista se pausa en la primera comparación.
// Peor caso: el valor está al final; en este caso, tenemos que recorrer toda la lista.
// Caso promedio: este caso se encuentra entre el mejor y el peor caso, o cerca de la mitad de la lista, teniendo que hacer más de una comparación, pero sin evaluar todos los datos.

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


//MS
void copyArray(vector<int>& A, vector<int>& B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

//MS
void mergeArray(vector<int>& A, vector<int>& B, int low, int high, int mid) {
    int k = low;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high) {
        B[k] = A[j];
        j++;
        k++;
    }

    copyArray(A, B, low, high);
}

//MS
void mergeSplit(vector<int>& A, vector<int>& B, int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;

        mergeSplit(A, B, low, mid);
        mergeSplit(A, B, mid + 1, high);

        mergeArray(A, B, low, high, mid);
    }
}

//MS
vector<int> ordenar(const vector<int>& lista) {
    vector<int> v(lista);
    vector<int> tmp(v.size());

    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}

void archivar(vector<int>& lista) {
    // Leer todos los valores actuales del archivo
    ifstream archivo_lectura("Archibaje.txt");
    if (!archivo_lectura) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    string line;
    int valor;
    while (getline(archivo_lectura, line)) {
        stringstream aux(line);
        aux >> valor;
        lista.push_back(valor); // Agregar valores existentes al vector
    }
    archivo_lectura.close();

    // Ordenar la lista completa (nuevos + existentes)
    lista = ordenar(lista);

    // Sobrescribir el archivo con la lista ordenada
    ofstream archivo("Archibaje.txt", ios::trunc);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (int num : lista) {
        archivo << num << endl;
    }
    archivo.close();


}

//Esta función tiene un nievel de complejidad lineal, O(n), siendo n el numero de valores a desplegar
//El mejor caso se da si solo hay un valor.
//El peor caso no existe, ya que siempre existiria un peor caso ipotetico, por lo que se puede representar como O(∞), a diferencia de los otros dos casos.
//El caso promedio se encontraria entre estos dos.
void desplegar(){
    vector<int> cadenaN;
    int lineaAlmacenar;

    ifstream archivo( "Archibaje.txt" );
    while(!archivo.eof()){
        archivo>>lineaAlmacenar;
        cadenaN.push_back(lineaAlmacenar);
    }

    int i = 0;
    while (i < cadenaN.size()) {
        std::cout << cadenaN[i] << endl;
        i++;
    }
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
    cout<<endl<<"La Figura se encuentra en la base de datos"<<endl;
    int i = 0;

    while (i < cadenaN.size()) {
        std::cout << cadenaN[i] << " ";
        i++;
    }
};

};
