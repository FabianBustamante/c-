#include <iostream>
using namespace std;

class CMatrixP3D {
public:
    CMatrixP3D(int _dx, int _dy, int _dz);
    ~CMatrixP3D();
    
    int get(int x, int y, int z);
    void set(int x, int y, int z, int v);
    int& gs(int x, int y, int z);
    int& operator()(int x, int y, int z);
    void print();

private:
    int*** m;
    int dx, dy, dz;
};

CMatrixP3D::CMatrixP3D(int _dx, int _dy, int _dz) {
    dx = _dx; dy = _dy; dz = _dz;

    // Crear puntero triple
    m = new int**[dz];
    for (int z = 0; z < dz; ++z) {
        m[z] = new int*[dy];
        for (int y = 0; y < dy; ++y) {
            m[z][y] = new int[dx]();
        }
    }
}

CMatrixP3D::~CMatrixP3D() {
    for (int z = 0; z < dz; ++z) {
        for (int y = 0; y < dy; ++y)
            delete[] m[z][y];
        delete[] m[z];
    }
    delete[] m;
}

int CMatrixP3D::get(int x, int y, int z) {
    return m[z][y][x];
}

void CMatrixP3D::set(int x, int y, int z, int v) {
    m[z][y][x] = v;
}

int& CMatrixP3D::gs(int x, int y, int z) {
    return m[z][y][x];
}

int& CMatrixP3D::operator()(int x, int y, int z) {
    return *(*(*(m + z) + y) + x);
}

void CMatrixP3D::print() {
    for (int z = 0; z < dz; ++z) {
        cout << "Capa Z = " << z << ":\n";
        for (int y = 0; y < dy; ++y) {
            for (int x = 0; x < dx; ++x) {
                cout << m[z][y][x] << " ";
            }
            cout << "\n";
        }
        cout << "--------\n";
    }
}

// -----------------------------
// MAIN DE PRUEBA
// -----------------------------

int main() {
    CMatrixP3D m(3, 3, 2); // Matriz 3x3x2
    m.print();

    m.set(1, 1, 0, 10);
    m.set(2, 0, 1, 20);
    m.gs(0, 0, 1) = 99;
    m(2, 2, 0) = m(0, 0, 1);

    m.print();

    return 0;
}
