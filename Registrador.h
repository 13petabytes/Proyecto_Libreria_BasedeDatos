#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <cstring>

using namespace std;

//Definición de la clase que se encarga de manipular el arbol
//para los casos de uso de las funciones, al ser definidos los mejores, peores y promedios de las mismas, se empleara n para simbolizar el numero de nodos
//se aclara que el arbol no se ordena, por lo que al agregar más valores, tendera a desvalancearse

template <class T> class Registrador;

template <class T>
class Node {
private:
	//Variables
	T value;
	Node *left, *right;

	//función privada que aun no se encuentra en un estado ene l que el usuario al use
	Node<T>* succesor();

public:
	//Constructores
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	//Metodos actualmente usados
	void add(T);
	bool find(T);
	void inorder(std::stringstream&) const;
	//Metodos para funciones para opciones proccimas a ser agregadas
	void remove(T);
	void removeChilds();
	//Se aclara que la clase registrador es amiga
	friend class Registrador<T>;
};

//Se definen contrctores
template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}


//Se define la función add
//para los casos de esta función se hace un simil con la clase busqueda
//El caso promedio para esta función es que el valor a agregar sea O(log n), esto en un desbalanceado
//En el mejor caso seria igual de O(log n), pero estando el arbol balanceado
//En el peor caso se agregaria el valor al final de un arbol desvalanciado, siaendo similar agregarlo a la cola de una lista, O(n)
template <class T>
void Node<T>::add(T val) {

	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

//Se define la función find
//para esta función nuestro mejor caso de busqueda, ignorando al nodo raíz, se nos presenta si el arbol esta balanciado, lo caul si el arbol es de pocos valores va a tender a serlo, O(log n)
//nuestro caso promedio, siendo si el arbol esta desbalanceado, nuestra notación big O se designa como O(logn)
//el peor caso se da si el valor se encuentra al final del arbol, estando este desbalanceado, en esta se recorrerian todos los nodos, O(n)
template <class T>
bool Node<T>::find(T val) {

	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	} return false;
}

//se define la función succesor
//en esta los esenarios no varian de la función find, porloque solo se aclaran su notación asintótica
//mejor caso: O(log n)
//caso promedio: O(log n)
//peor caso: O(n)
template <class T>
Node<T>* Node<T>::succesor() {


	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}


//se define la función remove
//en esta los esenarios no varian de la función find, porloque solo se aclaran su notación asintótica
//mejor caso: O(log n)
//caso promedio: O(log n)
//peor caso: O(n)
template <class T>
void Node<T>::remove(T val) {

	Node<T> * succ, *old;

	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				succ = right->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

//en este caso, y diferenciandonos de los casos anteriores, nuestros casos promedios y mejores nov avarian, pero si lo haria el peor, disminullendose la cantidad de nodos a recorrer en 1
//mejor caso: O(log n)
//caso promedio: O(log n)
//peor caso: O(n - 1)
template <class T>
void Node<T>::removeChilds() {

	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

//se define la función inorder, que se emplea en la clase Registrador para almacenar en el txt
//la complejidad de la misma es de O(n), siendo n el numero de valores almacenados
//su mejor caso seria con un valor en el arbol
//su peor es un imposible, al siempre poder haber más velores en el arbol, O(∞)
//su caso promedio enta entre los dos anteriores
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 0) {
		aux << endl;
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}


using namespace std;

//Definición de clase encargada de la interacción/comunicación con el main y el usuario, con las funciones de la clase Node

template <class T>
class Registrador {
private:
	//definición de variables
    Node<T> *root;
public:
    // Constructor y destructor
    Registrador() : root(0){};
    ~Registrador(){};

    // Métodos

	
	bool empty() const{
		//Función para verificar que el arbol no este vasio
		return (root == 0);
	};

	//Llamado de la función ad tras la confirmación de que no existe el numero
	//Los casos para esta función serian el resultado de la convicación de los de add y el peor de find, esto puesto a que se recorreria todo el arbol si no existe el valor, quedando así
	//mejor: O(log n) + O(n)
	//peor: O(2n)
	//promedio: O(log n) + O(n)
	void add(T val){

		if(root != 0){
		if (!root->find(val)){
			root->add(val);
		}
		} else {
		root = new Node<T>(val);
	}};

	void archivar() {
		//Se archiva el contenido del arbol, ordenado por el metodo "inorder"
		if (root == nullptr) {
			cout << "El árbol está vacío. No hay nada que archivar." << endl;
			return;
		}

		//Se almacena el contenido del arbol en una variable strinbgstram, para posteriormente guardarlo en el archivo

		ofstream archivo("Archibaje.txt",  ios::app);  // Abrir el archivo en modo de escritura
		if (!archivo.is_open()) {
			cerr << "Error al abprir el archivo." << endl;
			return;
		}

		stringstream aux;
		root->inorder(aux);  // Llama a inorder para llenar aux con el contenido del árbol

		if (aux.str().empty()) {
			cout << "Advertencia: El stringstream está vacío después de llamar a inorder." << endl;
		} else {
			archivo << aux.str();
			cout << "El contenido se ha guardado en Archibaje.txt" << endl;
		}

		archivo.close();
	}

	//La complejidad de la función es de O(n)
	//Los casos son los mismos que con la función inorder
	void desplegar() const{
		stringstream aux;
		root->inorder(aux);  // Llama a inorder para llenar aux con el contenido del árbol
		cout<<endl<<aux.str()<<endl<<endl;
	}

	//Llamado de la función find de la clase Node
	//Los casos son los mismos que con la clase find
	//mejor caso: O(log n)
	//caso promedio: O(log n)
	//peor caso: O(n)
	void buscar(T val) const{
		if (root != 0) {
		bool x = root->find(val);
		if (x == true){
			cout << endl << "Se encuentra en la base de datos." << endl;
		} else{
			cout << endl << "No se encuentra en la base de datos."<< endl;
		}
		} else {
		cout << endl << "Error" << endl;
		}
		desplegar();
	};

	// Esta función se encarga de almacenar el contenido del archivo de texto en el árbol binario,
	// para posteriormente borrar el contenido del archivo.
	// Con esto, se garantiza que la función `archivar` sea la última en ser ejecutada en el programa
	// y se asegura el correcto almacenamiento de los datos.
	void comerTXT() {

		// Se abre el archivo
		ifstream archi("Archibaje.txt");
		if (!archi) {
			cerr << "Error al abrir el archivo." << endl;
			return;
		}

		// Se define una variable auxiliar para leer línea por línea
		string auxstr;

		// Se insertan los datos del archivo en el árbol binario,
		// tras transformar cada línea en un entero con `stoi()`
		while (getline(archi, auxstr)) {
			if (!auxstr.empty()) { // Se asegura que no se procesen líneas vacías
				try {
					add(stoi(auxstr));
				} catch (const invalid_argument& e) {
					// Manejo de errores si la línea no contiene un número válido
					cerr << "Error: no se pudo convertir la línea a un número entero: " << auxstr << endl;
				}
			}
		}

		// Se cierra el archivo, para posteriormente borrarlo
		// Se realiza en este orden para evitar problemas durante la compilación
		archi.close();

		// Se abre nuevamente el archivo en modo truncado para vaciar su contenido
		ofstream archi2("Archibaje.txt", ios::trunc);
		if (!archi2) {
			cerr << "Error al intentar limpiar el archivo." << endl;
		}
	}



};
