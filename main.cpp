#include <iostream>
#include "arreglo_dinamico.h"
using namespace std;


int main(){
    ArregloDinamico str;
    str.insertar_final("Fabian");
    str.insertar_final("Alejandro");
    str.insertar_final("Esqueda");
    str.insertar_final("Rodriguez");
    str.insertar_final("Andy");
    str.insertar_final("Josue");
    str.insertar_final("Esqueda");
    str.insertar_final("Rodriguez");

    str.insertar_inicio("Esqueda Rodriguez");
    str.insertar_inicio("Alan Jareth");

    // string prueba;
    // getline(cin, prueba);
    // str.setString(prueba);
    // str.insertar_inicio(prueba); 

    cout<<"\nELEMENTOS AGREGADOS AL INICIO Y AL FINAL DEL ARREGLO\n\n";

    for (size_t i = 0; i < str.size(); i++){
        cout << str[i] << " ";
    } 
    cout<<"\n\n";

    return 0;
}