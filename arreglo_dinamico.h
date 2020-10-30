#ifndef ARREGLO_DINAMICO_H
#define ARREGLO_DINAMICO_H

#include <iostream>
using namespace std;

template <class T>//La T representa un tipo de dato generico
class ArregloDinamico{

    public:
    ArregloDinamico(); //Constructor
    ~ArregloDinamico(); //Destructor

    void insertar_final(const T &s);//Aqui inserta elememtos en la posicion que marque el contador
    void insertar_inicio(const T &s);//Inserta elementos siempre en la posicion 0
    void insertar(const T &s, size_t pos);//Insertar en una posicion valida donde existe informacion
    size_t size();//Para retornar los elementos en el arreglo

    void setString(const T &st);
    T getString();

    //Sobrecargar el operador de los [] para mostrar los datos
    string operator [] (size_t pos){
        return arreglo[pos];
    }

    private:
        T *arreglo;//Es un arreglo de tipo T
        string st;
        size_t tam;
        size_t cont;
        const static int MAX = 8; 
        void expandir();//Crecer el arreglo
};

template <class T>
ArregloDinamico<T>::ArregloDinamico(){
    arreglo = new T [MAX];//Crea el arreglo dinamico reservando la memoria
    cont = 0;
    tam = MAX; //tam = 8;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico(){
    delete [] arreglo;
}

template <class T>
void ArregloDinamico<T>::insertar_final(const T &s){
    if(cont == tam){//Nuestro arreglo esta lleno
        //expandir la capacidad para seguir almacenando info
        expandir();
    }

    arreglo[cont] = s;//El arreglo inicia en la posicion cont 
                      //y guarda en esa posicion lo que se le pase como parametro
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T &s){
    if(cont == tam){//Nuestro arreglo esta lleno
        //expandir la capacidad para seguir almacenando info
        expandir();
    }

    for (size_t i = cont; i>0; i--){//Va a iniciar desde el final del arreglo
                                    //Y se van a mover los elementos hacia la derecha

            arreglo[i] = arreglo[i-1];//Mover nuestro elemento a la siguiente posicion
    }

    arreglo[0] = s;//En la posicion 0 se va a agregar el elemento que recibe como parametro
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar(const T &s, size_t pos){
    if (pos >= cont){
        cout<<"La posicion no es valida";
        return; 
    }
    
    if (cont == tam){//Si el arreglo esta lleno, se expande
        expandir();
    }

    for (size_t i = cont; i > pos; i--){
        arreglo[i] = arreglo[i-1];//Va a recorrer una posicion a la derecha los elementos
    }

    arreglo[pos] = s;//En la posicion pos se va a insertar el elemento que le mandamos
    cont ++;
    
}

template <class T>
size_t ArregloDinamico<T>::size(){
    return cont;
}

template <class T>
void ArregloDinamico<T>::expandir(){
    string *nuevo = new T [tam+MAX];//Se va a expandir el tamaÃ±o del arreglo

    for (size_t i = 0; i < cont; i++){
        nuevo[i] = arreglo[i];//Copia los elementos hacia el nuevo arreglo
    }

    delete[] arreglo;
    arreglo = nuevo;//Copiar las direcciones de memoria del primer arreglo hacia el nuevo, porque son punteros
    tam += MAX;//El tamaÃ±o ahora es el tamaÃ±o + 8, que vale la variable MAX  
}

template<class T>
void ArregloDinamico<T>::setString(const T &s){
    this->st=st;
}
template<class T>
T ArregloDinamico<T>::getString(){
    return st;
}

#endif //ARREGLO_DINAMICO_H