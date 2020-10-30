#include <iostream>
#include "arreglo_dinamico.h"
using namespace std;


int main(){
    ArregloDinamico<string> str;//La T en la clase va a recibir strings
    size_t posicion;
    //Prueba 1 -> Insertar 4 strings al inicio y al final
    str.insertar_inicio("Prueba Numero 1.1");
    str.insertar_inicio("Prueba Numero 1");
    str.insertar_inicio("Prueba Numero 0");
    str.insertar_final("Prueba Numero 2");
    str.insertar_final("Prueba Numero 2.1");

    //Insertar una cadena al inicio del arreglo
    // string st;
    // getline(cin, st);
    // cout<<endl;
    // str.setString(st);
    // str.insertar_inicio(st);

    str.insertar("Insertar en una pos. valida", 2);//Insertar 1500 en la posicion 2

    str.eliminar_inicio();
    str.eliminar_final();
    str.eliminar(1);//Eliminar en la posicion 1

    //Se inserta una cadena en la posicion que el usuario quiera
    // cout<<"Posicion a insertar: "; cin>>posicion;
    // fflush(stdin);
    // getline(cin, st);
    // cout<<endl;
    // str.setString(st);
    // str.insertar(st, posicion);

    cout<<endl;
    for (size_t i=0; i < str.size(); i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    return 0;
}