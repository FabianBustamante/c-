#include <iostream>
using namespace std;

int main() {
    // Declaración de la matriz tridimensional m[2][3][4]
    // 2 planos, cada uno con 3 filas y 4 columnas
    int m[2][3][4];

    // Inicialización de la matriz con valores
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                m[i][j][k] = i*12 + j*4 + k;
                // Equivalente: *(*(*(m+i)+j)+k) = i*12 + j*4 + k;
            }
        }
    }

    // 1. Imprimir toda la matriz tridimensional usando índices
    cout << "MATRIZ COMPLETA m[2][3][4] USANDO ÍNDICES:" << endl;
    for(int i = 0; i < 2; i++) {
        cout << "Plano " << i << ":" << endl;
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                cout << m[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 1b. Imprimir toda la matriz usando un puntero a la matriz
    int (*p)[3][4] = m;  // Puntero a la matriz completa

    cout << "MATRIZ COMPLETA USANDO PUNTERO p:" << endl;
    for(int i = 0; i < 2; i++) {
        cout << "Plano " << i << ":" << endl;
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                cout << p[i][j][k] << "\t";
                // Equivalente: cout << *(*(*(p+i)+j)+k) << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 2. Puntero a un plano específico (segundo plano)
    int (*plano_ptr)[4] = m[1];  // Apunta al segundo plano

    cout << "IMPRIMIENDO SOLO EL PLANO 1 USANDO PUNTERO:" << endl;
    for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 4; k++) {
            cout << plano_ptr[j][k] << "\t";
            // Equivalente: cout << *(*(plano_ptr+j)+k) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // 3. Puntero a una fila específica (segunda fila del primer plano)
    int *fila_ptr = m[0][1];  // Apunta a la segunda fila del primer plano

    cout << "IMPRIMIENDO SOLO LA FILA 1 DEL PLANO 0 USANDO PUNTERO:" << endl;
    for(int k = 0; k < 4; k++) {
        cout << fila_ptr[k] << "\t";
        // Equivalente: cout << *(fila_ptr+k) << "\t";
    }
    cout << endl;

    // 4. Acceso a elementos individuales con ambas notaciones
    cout << "\nACCESO A ELEMENTOS INDIVIDUALES:" << endl;

    // Elemento en el centro de la matriz (plano 1, fila 1, columna 2)
    int i = 1, j = 1, k = 2;
    cout << "Elemento usando índices: " << m[i][j][k] << endl;
    // Equivalente: cout << "Elemento usando punteros: " << *(*(*(m+i)+j)+k) << endl;

    return 0;
}