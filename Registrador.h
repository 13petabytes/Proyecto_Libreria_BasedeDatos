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

template <class T> class Registrador;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;

	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;

	friend class Registrador<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

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

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

using namespace std;

template <class T>
class Registrador {
private:
    Node<T> *root;
public:
    // Constructor y destructor
    Registrador() : root(0){};
    ~Registrador(){};

    // Métodos

//arbol binario

      bool empty() const{
    return (root == 0);
  };

    void add(T val){
    if(root != 0){
      if (!root->find(val)){
        root->add(val);
      }
    } else {
      root = new Node<T>(val);
    }};

    void archivar(){
      stringstream aux;
      if (!empty()){

        root->inorder(aux);

        ofstream archi("Archibaje.txt");

        if (archi.is_open()){
          archi << aux.str();
          archi.close();
          cout << endl << "El contenido se ha guardado en archivo.txt" << endl;
        }
      } else{
        cout<<endl<<"Error, no hay nada para archivar"<< endl;
      }
  };

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
  };

  void comerTXT(){
    ifstream archi("Archibajetxt");
    if(!archi) {
      cerr << "Error al abrir el archivo."<<endl;
    }
    string auxstr;
    stringstream aux;
    aux << archi.rdbuf();
    if (!aux.str().empty()){
      while(getline(archi, auxstr)){
        add(stoi(auxstr));
      }
    }
    archi.close();
    std::ofstream archi2("Archibaje.txt", std::ios::trunc);
  };

};
