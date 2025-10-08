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
        cc=3; cf=3;
       m={{3,2,1},{2,10,7},{6,5,4}};
       
    }
    void matrizCargada2(){
        m.clear();
        cc=3; cf=2;
       m={{2,2,7},{6, 5, 4}};
       
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
    
    void mostrar7(){
        for (int c=0;c<cc;c++){//col
            for (int f=(cf-1);f>=0;f--){//fil
                cout<<m[f][c]<<" , ";
            }
            cout<<endl;
        }
    }
    
    void mostrar_5(){
        for (int f=(cf-1);f>=0;f--){//fila
            for (int c=(cc-1);c>=0;c--){//col
                cout<<m[f][c]<<" , ";
            }
            cout<<endl;
        }
    }
    
    void mostrar_tri_2_7(){
        for (int f=(cf-1);f>=0;f--){//fila
            for (int c=f;c<cc;c++){//col
                cout<<m[f][c]<<" , ";
            }
            cout<<endl;
        }
    }
    
    
     void mostrar_tri_3_5(){
        for (int c=(cc-1);c>=0;c--){//col
            for (int f=(cf-c-1);f>=0;f--){//fil
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
    
    void segmentarFila(int fila){
        int aux;
        for(int c1=0;c1<cc;c1++){
          for(int c2=c1+1;c2<cc;c2++){
             // int m1=m[fila][c1]; ocupar estas variables
             // int m2=m[fila][c2];
              if(
                  (m[fila][c1] %2==1 && m[fila][c2]%2==0) ||
             ( m[fila][c1] %2==1 && m[fila][c2] %2==1 && m[fila][c1] >m[fila][c2]) ||
              (m[fila][c1] %2==0 && m[fila][c2] %2==0 && m[fila][c1] <m[fila][c2])){
                  aux=m[fila][c1];
                  m[fila][c1]=m[fila][c2];
                  m[fila][c2]=aux;  //realizar un void pafra intercambiar elementos
                  
              } 
          }  
        }
    }
    
    void segmentarFilasParesImpares(){
        for(int f=0;f<cf;f++){
            segmentarFila(f);
        }
    }
   void interCambiar0filaconultimafila(){
       int aux;
       for(int c=0;c<cc;c++){
           aux=m[0][c];
           m[0][c]=m[cf-1][c];
           m[cf-1][c]=aux;
       }
   } 
   void interFilas(int fila1,int fila2){
       int aux;
       for(int c=0;c<cc;c++){
           aux=m[fila1][c];
           m[fila1][c]=m[fila2][c];
           m[fila2][c]=aux;
       }
   }
   
    int cantPares(int fila){
       int cp=0;
       for(int c=0;c<cc;c++){
          if(m[fila][c]%2==0){
              cp++;
          }
       }
       return cp;
   }  
   
   
   
   void segmentarFilas(int fila){
       int e1,e2,aux;
       for(int c1=0;c1<cc;c1++){
          for(int c2=c1+1;c2<cc;c2++){
            e1=m[fila][c1];
            e2=m[fila][c2];
            if(e1%2==1 && e2%2==0 ||
               e1%2==1 && e2%2==1 && (e1>e2) ||
               e1%2==0 && e2%2==0 && (e1>e2)  ){
                   aux=e1;
                   m[fila][c1]=m[fila][c2];
                   m[fila][c2]=aux;
               }
         }  
       }
   }
   
   void segmentarFilasPareseImpares(){
       for(int f=0;f<cf;f++){
           segmentarFilas(f);
       }
   }
   /////////////////////////////
   void intercambiarFilas(int f1,int f2){
       int aux;
       for(int c=0;c<cc;c++){
           aux=m[f1][c];
           m[f1][c]=m[f2][c];
           m[f2][c]=aux;
       }
   }
   
   bool esPrimo(int nro){
       int c=0;
       for(int i=1; i<=nro;i++){
           if(nro%i==0){
               c++;
           }
       }
       return c==2;
   }
   
   int cantPrimosXfila(int fila){
       int cp=0;
        for(int c=0;c<cc;c++){
          if(esPrimo(m[fila][c])){
              cp++;
          }
        }
        return cp;
   }
   
   
   
   void ordenarFilasXcantPrimos(){
       for(int f1=0; f1<cf;f1++){
           for(int f2=f1+1; f2<cf;f2++){
             if(cantPrimosXfila(f1)>cantPrimosXfila(f2)){
                intercambiarFilas(f1,f2) ;
             
             }  
         }
       }
   }
   
   int frecuencia(int ele){
       int ce=0;
       for(int f=0;f<cf;f++){
           for(int c=0;c<cc;c++){
               if(m[f][c]==ele){
                   ce++;
               }
           }
       }
       return ce;
   }
   
   int cantElementosUnicos(){
       int ceu=0;
       for(int f=0;f<cf;f++){
           for(int c=0;c<cc;c++){
                if(frecuencia(m[f][c])==1){
                    ceu++;
                }
           }
       }
       return ceu;
   }
   
   
   bool existeEle(int ele){
    for(int f=0;f<cf;f++){
           for(int c=0;c<cc;c++){
               if(m[f][c]==ele){
                   return true;
               }
           }
       }   
       return false;
   }
   
   
   bool matrizIncluidaEnOtra(Matriz m2){
       for(int f=0;f<cf;f++){
           for(int c=0;c<cc;c++){
               if(!m2.existeEle(m[f][c])){
                   return false;
               }
           }
       }
       return true;
   }
   
   void intercambiar(int f1,int c1,int f2,int c2){
       int aux=m[f1][c1];
       m[f1][c1]=m[f2][c2];
       m[f2][c2]=aux;
   }
   
   void intercambioColumnas(int c1,int c2){
       for(int f=0;f<cf;f++){
         intercambiar(f,c1,f,c2);  
       }
   }
  
   void ordenarColEnBaseAunaFila(int fila){
       for(int c1=0;c1<cc;c1++){
          for(int c2=c1+1;c2<cc;c2++){
           if(m[fila][c1]>m[fila][c2]){
               intercambioColumnas(c1,c2);
           }
         } 
       }
   }
   
   void ordenarElemPorFrec(){
       int fre1,fre2;
       int puntero;
       for(int c1=(cc-1);c1>=0;c1--){
           for(int f1=0;f1<cf;f1++){//ele 1
              
              for(int c2=c1 ;c2>=0;c2--){//ele2
                  if(c1==c2){
                     puntero= f1;
                  }else{
                      puntero = 0;
                  }
                  for(int f2=puntero;f2<cf;f2++){
                      fre1=frecuencia(m[f1][c1]);
                      fre2=frecuencia(m[f2][c2]);
                      if(fre2>fre1||
                         (fre1==fre2 && m[f2][c2]<m[f1][c1])){
                             intercambiar(f1,c1,f2,c2);
                         }
                  }
              } 
               
           }
       }
   }
   
   
   void segmentarParesImpares(){
       int e1,e2,puntero;
       for(int c1=0 ;c1<cc;c1++){
           for(int f1=(cf-1);f1>=0;f1--){
              
              for(int c2=c1 ;c2<cc;c2++){
                  if(c1==c2){
                      puntero=f1;
                  }   else{
                      puntero=cf-1;
                  }
                  for(int f2=puntero;f2>=0;f2--){
                      e1=m[f1][c1];
                      e2=m[f2][c2];
                      if(e1%2==1 && e2%2==0 ||
                         e1%2==1 && e2%2==1 && e1>e2 ||
                         e1%2==0 && e2%2==0 && e1>e2){
                             intercambiar(f1,c1,f2,c2);
                             //mostrar1();
                             //cout<<endl;
                         }
                  }
              }
           }
       }
   }
   
   bool esFibo(int nro){
       int a=-1;int b=1;
       int f=0;
       while(f<=nro){
           f=a+b;
           a=b;
           b=f;
           if(f==nro){
               return true;
           }
       }
       return false;
   }
   
   void intercalarFiboNoFibo(){
       int e1,e2, puntero;
       bool bandera=true;
       for(int c1=0;c1<cc;c1++){
           for(int f1=(cf-1);f1>=0;f1--){
               if(bandera){//fibos
                   for(int c2=c1;c2<cc;c2++){
                       if(c1==c2){
                           puntero=f1;
                       }else{
                           puntero=cf-1;
                       }
                       for(int f2=puntero;f2>=0;f2--){
                           e1=m[f1][c1];
                           e2=m[f2][c2];
                           if(!esFibo(e1)&&esFibo(e2) ||
                              !esFibo(e1)&&!esFibo(e2)&& e1>e2 || 
                              esFibo(e1)&&esFibo(e2)&& e1>e2 ){
                                  intercambiar(f1,c1,f2,c2);
                              }
                       }
                   }
               }else{//no fibo
                   for(int c2=c1;c2<cc;c2++){
                       if(c1==c2){
                           puntero=f1;
                       }else{
                           puntero=cf-1;
                       }
                       for(int f2=puntero;f2>=0;f2--){
                           e2=m[f1][c1];
                           e1=m[f2][c2];
                           if(!esFibo(e1)&&esFibo(e2) ||
                              !esFibo(e1)&&!esFibo(e2)&& e1<e2 || 
                              esFibo(e1)&&esFibo(e2)&& e1<e2 ){
                                  intercambiar(f1,c1,f2,c2);
                              }
                       }
                   }
               }
               bandera=!bandera;
               
           }
       }
   }
   
   
};



int main() {
    Matriz m,m2,mr;
    
    //m.cargar(3,3);
    m.matrizCargada();
    m2.matrizCargada2();
    m.mostrar1();
    cout<<endl;
   // m.ordenarColEnBaseAunaFila(0);
  // m.ordenarElemPorFrec();
 // m.segmentarParesImpares();
 m.intercalarFiboNoFibo();
    m.mostrar1();
    m.multiplicarMatriz(m2,mr);
  //  cout<<m.matrizIncluidaEnOtra(m2);
   // m.segmentarFilasParesImpares();
 //  m.interCambiar0filaconultimafila();
// m.segmentarFilasPareseImpares();
//m.ordenarFilasXcantPrimos();
//cout<<"Se repite: "<<m.frecuencia(1);
    // m.mostrar1();
    //m.mostrar_tri_3_5();
    //m.mostrarVibora();
    //cout<<"Elemento mayor : "<<m.elementoMayor();
   // cout<<"Elemento mas repetido: "<<m.elementoMasRepetido();
    //cout<<"Elemento : 1 se repite: "<<m.frecuenciaEle(1);
    //cout<<"Elementos unicos: "<<m.cantElementosUnicos();
   /* m.mostrar1();
   cout<<endl;
    m.mostrar2();
   cout<<endl;
    m.mostrar5();*/
    return 0;
}