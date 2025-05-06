#include <iostream>
using namespace std;


int main(){

    int planos=2,filas=3,columnas=4;
    int ***arr= new int**[planos];
        for(int i=0;i<planos;i++){
            arr[i]=new int*[filas];
            for (int j=0;j<filas;j++){
                arr[i][j]=new int[columnas];
            }
        }

    for (int i=0;i<planos;i++){
        for (int j=0;j<filas;j++){
            for (int k=0;k<columnas;k++){

                arr[i][j][k]=i*12+j*4+k;
            }
        }
    }

    
    for (int i=0;i<planos;i++){
        for (int j=0;j<filas;j++){
            for (int k=0;k<columnas;k++){

                cout<<arr[i][j][k]<<'\t';
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for (int i=0;i<planos;i++){
        for (int j=0;j<filas;j++){
                delete[]arr[i][j];
            }
            delete[]arr[i];
        }
        delete[]arr;
    












    return 0;
}