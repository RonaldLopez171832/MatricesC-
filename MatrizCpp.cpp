// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Matriz{ //nombre de la clase
    private:
    vector<vector<int>> m;
    int cc,cf;
    public:
    
    void matrizCargada(){
        m.clear();
        cc=4; cf=4;
        vector<int> fila={1,2,3,4};
        m.push_back(fila);
        fila={5,6,7,8};
        m.push_back(fila);
        fila={6,2,2,2};
        m.push_back(fila);
        fila={1,1,1,1};
        m.push_back(fila);
    }
    void cargar(int cantf,int cantc){
        cc=cantc; cf=cantf;
        int elemento;
        m.clear();//limpiar o borrar la variable m
        for (int f=0;f<cantf;f++ ){
          vector<int> fila;
          for (int c=0;c<cantc;c++ ){
             cout<<"elemento ["<<f<<"]"<<"["<<c<<"] : ";
             cin>>elemento;
             fila.push_back(elemento);
          } 
          m.push_back(fila);
        }
    }
    void mostrar1(){
        for (int f=0;f<cf;f++){
            for (int c=0;c<cc;c++){
                cout<<m[f][c]<<" , ";
            }
            cout<<endl;
        }
    }
     void mostrar2(){
        for (int c=0;c<cc;c++){
            for (int f=0;f<cf;f++){
                cout<<m[f][c]<<" , ";
            }
            cout<<endl;
        }
    }
    
    void mostrar5(){
        for (int f=(cf-1);f>=0;f--){
            for (int c=(cc-1);c>=0;c--){
                cout<<m[f][c]<<" , ";
            }
            cout<<endl;
        }
    }
    
    void mostrarVibora(){
        for(int f =0;f<cf;f++){
            if(f%2==0){
              for (int c=0;c<cc;c++){
                cout<<m[f][c]<<" , ";
              }  
            }else{
               for (int c=(cc-1);c>=0;c--){
                cout<<m[f][c]<<" , ";
              }    
            }
            cout<<endl;
        }
    }
    
    int frecuenciaEle(int ele){
        int ce=0;
        for (int f=0;f<cf;f++){
            for (int c=0;c<cc;c++){
                if(m[f][c]==ele){
                    ce++;
                }
            }
        }
        return ce;
    }
    
    int elementoMasRepetido(){
        int ele=m[0][0];
        int cant=frecuenciaEle(m[0][0]);
        int ce=0;
         for (int f=0;f<cf;f++){
            for (int c=0;c<cc;c++){
                ce=frecuenciaEle(m[f][c]);
                if(ce>cant){
                    ele=m[f][c];
                    cant=ce;
                }
            }
        }
        return ele;
    }
    int elementoMayor(){
        int ele=m[0][0];
        for (int f=0;f<cf;f++){
            for (int c=0;c<cc;c++){
                if(m[f][c]>ele){
                    ele=m[f][c];
                }
            }
        }
        return ele;
    }
    int elementoMenor(){
        int ele=m[0][0];
        for (int f=0;f<cf;f++){
            for (int c=0;c<cc;c++){
                if(m[f][c]<ele){
                    ele=m[f][c];
                }
            }
        }
        return ele;
    }
};



int main() {
    Matriz m;
    
    //m.cargar(3,3);
    m.matrizCargada();
    m.mostrarVibora();
    cout<<"Elemento mayor : "<<m.elementoMayor();
   // cout<<"Elemento mas repetido: "<<m.elementoMasRepetido();
    //cout<<"Elemento : 1 se repite: "<<m.frecuenciaEle(1);
   /* m.mostrar1();
   cout<<endl;
    m.mostrar2();
   cout<<endl;
    m.mostrar5();*/
    return 0;
}