#include <iostream>
using namespace std;

int main() {
    
    int filas=4,columnas=3;

    int** arr=new int*[filas];
    for(int i=0;i<filas;i++){
        arr[i]=new int[columnas];
    }

    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            arr[i][j]=i*3+j;
        }
    }

   
    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            cout<<arr[i][j]<<'\t';
        }
        cout<<endl;
    }

    for (int i=0;i<filas;i++){
        delete[]arr[i];
        }
        delete[]arr;
    return 0;
}