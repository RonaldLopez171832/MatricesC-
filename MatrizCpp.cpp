#include <iostream>
#include <vector>
using namespace std;
#include <random>
#include <chrono>
#include <cmath> 

class Matriz {
   private:
    vector<vector<int>> m;  // usamos 
    public:
    // Método para cargar elementos desde teclado
    void cargar() {
        int cf,cc, valor;
        cout << "Ingresar # filas: ";
        cin >> cf;
        cout << "Ingresar # columnas: ";
        cin >> cc;
        m.clear();  // limpiamos por si ya tenía datos
        
        for (int f = 0; f < cf; f++){ 
            vector<int> fila;
            for (int c = 0; c <cc; c++) {
             cout << "Ingrese el elemento: [" << f << "]["<<c<<"]: ";
            cin >> valor;
            fila.push_back(valor);
            }
            m.push_back(fila);
    }
        
    }
    void cargarOrdenado() {
        vector<int> fila = {1, 2, 3}; 
        m.push_back(fila);
        fila = {4, 5, 6}; 
        m.push_back(fila);
        fila = {7, 8, 9}; 
        m.push_back(fila);
    }
    
    void mostrar() {
        for (int f = 0; f < m.size(); f++) {
             for (int c = 0; c < m[f].size(); c++) {
                 cout << m[f][c]<<" , ";
             }
             cout << endl;
          }
    }
    
    
     void mostrar8() {
         int cf=m.size()-1;
         int cc=m[0].size()-1;
        for (int c = cc; c >= 0; c--) {
             for (int f = cf; f>=0; f--) {
                 cout << m[f][c]<<" , ";
             }
             cout << endl;
          }
    }
    void mostrar3() {
         int cf=m.size()-1;
         int cc=m[0].size()-1;
        for (int f = 0; f <= cf; f++) {
             for (int c = cf; c>=0; c--) {
                 cout << m[f][c]<<" , ";
             }
             cout << endl;
          }
    }
    
    void mostrar12() {
        int cf=m.size()-1;
        int cc=m[0].size()-1;
        
        for (int f = 0; f <= cf; f++) {
            if(f%2==0){
               for (int c = 0; c<=cf; c++) {
                 cout << m[f][c]<<" , ";
             }  
            }else{
               for (int c = cf; c>=0; c--) {
                 cout << m[f][c]<<" , ";
             }  
            }
            
             cout << endl;
          }
    }
    
     void mostrarDiagonalP() {
        for (int f = 0; f < m.size(); f++) {
                 cout << m[f][f]<<" , ";
          }
    }
     void mostrarDiagonalS() {
        for (int f = 0; f < m.size(); f++) {
                 cout << m[f][m.size()-1-f]<<" , ";
          }
    }
    
};
// Programa principal para probar la clase
int main() {
   /* Vector v;
    v.cargarRandom(10,1,8);
    v.mostrar();
    v.intercalarPrimoNoPrimo();
    v.mostrar();*/
    Matriz m;
    m.cargarOrdenado();
    m.mostrar();
     cout << endl;
    m.mostrar8();
    cout << endl;
     m.mostrar12();
   /* cout<<endl;
    m.mostrarDiagonalP();
    cout<<endl;
    m.mostrarDiagonalS();*/
   // Vector v;
   // v.cargar();
   //v.cargarRandom(12,10,69);
   // cout << "Vector ingresado: ";
    //v.mostrar();
    //Vector v1,v2,v3;
    //v.cantidadElementosRepetidos(v1,v2);
    //v.cantidadElementosRango(v1,v2,v3,10);
    //v.mostrar();
    //v1.mostrar();
   // v2.mostrar();
//    v3.mostrar();
    
    
    /*Vector v1,v2,v3;
    v.cantidadElementosRango(v1,v2,v3,10);
    v.mostrar();
    v1.mostrar();
    v2.mostrar();
    v3.mostrar();*/
    //v.segmentarPrimoNoPrimo();
    //v.mostrar();
    //v.segmentarParImpar();
    //v.mostrar();
    //cout<<"Existen : "<<v.cantPrimos()<<" primos."<<endl;
    //cout<<"Existen : "<<v.cantFibos()<<" fibo(s)."<<endl;
    //cout<<"Pos del primer Primo : "<<v.primerPosPrimo();
    //v.primos();
    //v.ordenarAsc();
    //v.mostrar();
    //v.ordenarDesc();
    //v.mostrar();
    //v.mostrarPosPares();
    //v.ordenarSegAsc(3,8);
   // v.ordenarPosParesAsc();
    //v.mostrar();
    //v.mostrarPosImpares();
   // cout << "La suma de los elementos es: " << v.sumarElementos() << endl;
    return 0;
}