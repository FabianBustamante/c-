#include <iostream>
using namespace std;

int main() {
    // Declaración de la matriz estática m[4][3]
    int m[4][3];

    // Inicialización de la matriz con algunos valores de ejemplo
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            m[i][j] = i * 3 + j;  // Solo un ejemplo de valores
        }
    }

    // Mostrar la matriz
    cout << "Matriz m[4][3]:" << endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
    cout<<*(*(m+2)+1)<<endl;

    int (*p)[3] = m;
    
  cout<<m[0][0]<<endl;
  cout<<p[0][0]<<endl;

  // Mostrar la matriz
  cout << "Matriz p[4][3]:" << endl;
  for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 3; j++) {
          cout << p[i][j] << "\t";
      }
      cout << endl;
  }
  cout<<endl;
    return 0;
}