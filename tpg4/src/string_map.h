#ifndef TP4_PACALGO2_STRING_MAP_H
#define TP4_PACALGO2_STRING_MAP_H

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    string_map();

    /**
    CONSTRUCTOR POR COPIA
    * Construye un diccionario por copia.
    **/
    string_map(const string_map<T>& aCopiar);

    /**
    OPERADOR ASIGNACION
     */
    string_map& operator=(const string_map& d);

    /**
    DESTRUCTOR
    **/
    ~string_map();

    /**
    INSERT
    * Inserta un par clave, valor en el diccionario
    **/
    void insert(const pair<string, T>&);

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(const string &key) const;

    /**
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    -- Versión modificable y no modificable
    **/
    const T& at(const string& key) const;
    T& at(const string& key);

    /**
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    **/
    void erase(const string& key);

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    /**
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
    bool empty() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
    T &operator[](const string &key);

private:

    struct Nodo {
        Nodo();
        vector<Nodo*> siguientes;
        T* definicion;
        int hijos();
        void copiarNodo(Nodo*);
        void destruirDomino();
    };
    Nodo* raiz;
    int _size;
};

template<typename T>
string_map<T>::Nodo::Nodo() {
    vector<Nodo*> sig(256, nullptr);
    siguientes= sig;
    definicion= nullptr;
}

template<typename T>
int string_map<T>::Nodo:: hijos(){
    int res=0;
    for (int i = 0; i < 255; ++i) {
        if (siguientes[i]!= nullptr)
            res++;
    }
    return res;
}

template<typename T>
void string_map<T>::Nodo::copiarNodo(Nodo* n){
    if (n->definicion!= nullptr) {
        T* t= new T;
        *t = *(n->definicion);
        definicion = t;
    }
    for (int i = 0; i < 255; ++i) {
        if (n->siguientes[i]!= nullptr) {
            siguientes[i] = new Nodo;
            siguientes[i]->copiarNodo(n->siguientes[i]);
        }
    }
}

template <typename T>
void string_map<T>::Nodo::destruirDomino() {
    if (definicion!= nullptr)
        delete definicion;
    for (int i = 0; i < 255; ++i) {
        if(siguientes[i]!= nullptr)
            (siguientes[i])->destruirDomino();
    }
    delete this;
}

#include "string_map.hpp"

#endif //TP4_PACALGO2_STRING_MAP_H
