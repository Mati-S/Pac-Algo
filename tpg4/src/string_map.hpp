template <typename T>
string_map<T>::string_map(): raiz(nullptr),_size(0){
    // COMPLETAR
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
    if (d.raiz!= nullptr) {
        raiz= new Nodo();
        if ((d.raiz)->definicion != nullptr) {
            T* t = new T;
            *t= *((d.raiz)->definicion);
            raiz->definicion = t;
        }
        for (int i = 0; i < 255; ++i) {
            if ((d.raiz)->siguientes[i] != nullptr) {
                raiz->siguientes[i] = new Nodo();
                (raiz->siguientes[i])->copiarNodo((d.raiz)->siguientes[i]);
            }
        }
    }
    _size= d._size;
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
    if (raiz!= nullptr)
        raiz->destruirDomino();
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
    if(count(clave)== 0){
        //pair<string, *T> make_pair(clave, nullptr);
        Nodo* actual= raiz;
        int len= clave.size();
        for (int i = 0; i < len; ++i) {
            int j= int(clave[i]);
            if ((actual->siguientes)[j]== nullptr){
                Nodo* nuevo= new Nodo();
                (actual->siguientes)[j]=nuevo;
            }
            actual=(actual->siguientes)[j];
        }
        actual->definicion= new T;
        _size++;
    }
    return at(clave);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    Nodo* actual= raiz;
    int len= clave.size();
    bool puedeSer= actual!= nullptr;
    for (int i = 0; i < len && puedeSer; ++i) {
        int j= int(clave[i]);
        puedeSer= ((actual->siguientes)[j]!= nullptr);
        actual= (actual->siguientes)[j];
    }
    if (puedeSer){
        puedeSer= (actual->definicion)!= nullptr;
    }
    return puedeSer;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
    Nodo* actual= raiz;
    int len= clave.size();
    for (int i = 0; i < len; ++i) {
        int j= int(clave[i]);
        actual= (actual->siguientes)[j];
    }
    const T& res= *(actual->definicion);
    return res;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
    Nodo* actual= raiz;
    int len= clave.size();
    for (int i = 0; i < len; ++i) {
        int j= int(clave[i]);
        actual= (actual->siguientes)[j];
    }
    T& res= *(actual->definicion);
    return res;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
    Nodo* actual= raiz;
    int len= clave.size();
    Nodo* ultimo= raiz;
    int indice = 0;
    for (int i = 0; i < len; ++i) {
        int j= int(clave[i]);
        if (actual->hijos()> 1 || actual->definicion!= nullptr){
            ultimo= actual;
            indice= i;
        }
        actual= (actual->siguientes)[j];
    }
    delete actual->definicion;
    actual->definicion= nullptr;
    if ((actual->hijos())== 0){
        int j= int(clave[indice]);
        Nodo* aBorrar= ultimo->siguientes[j];
        ultimo->siguientes[j]= nullptr;
        indice++;
        for (indice; indice < len; ++indice) {
            j= int(clave[indice]);
            Nodo* aux= aBorrar->siguientes[j];
            delete aBorrar;
            aBorrar= aux;
        }
        delete aBorrar;
    }
    _size--;
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
    return (_size==0);
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& entrada){
    if (raiz== nullptr)
        raiz= new Nodo();
    Nodo* actual= raiz;
    string clave= entrada.first;
    int len= clave.size();
    for (int i = 0; i < len; ++i) {
        int j= int(clave[i]);
        if ((actual->siguientes)[j]== nullptr){
            Nodo* nuevo= new Nodo();
            (actual->siguientes)[j]=nuevo;
        }
        actual=(actual->siguientes)[j];
    }
    if (actual->definicion== nullptr){
        T* significado= new T;
        actual->definicion= significado;
        _size++;
    }
    *(actual->definicion)= entrada.second;
}

