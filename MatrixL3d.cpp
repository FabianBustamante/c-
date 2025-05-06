#include <iostream>
using namespace std;

class CMatrix3D {
public:
    CMatrix3D(int _dx, int _dy, int _dz);
    ~CMatrix3D();
    
    int fi(int x, int y, int z); // Función de indexado lineal

    int get(int x, int y, int z);
    void set(int x, int y, int z, int v);
    int& gs(int x, int y, int z);
    int& operator()(int x, int y, int z);

    void print(); // Imprime capa por capa (valor por z)

private:
    int* vec;
    int dx, dy, dz;
};

CMatrix3D::CMatrix3D(int _dx, int _dy, int _dz) {
    dx = _dx; dy = _dy; dz = _dz;
    vec = new int[dx * dy * dz](); // Inicializado en 0
}

CMatrix3D::~CMatrix3D() {
    delete[] vec;
}

int CMatrix3D::fi(int x, int y, int z) {
    return z * dx * dy + y * dx + x;
}

int CMatrix3D::get(int x, int y, int z) {
    return vec[fi(x, y, z)];
}

void CMatrix3D::set(int x, int y, int z, int v) {
    vec[fi(x, y, z)] = v;
}

int& CMatrix3D::gs(int x, int y, int z) {
    return vec[fi(x, y, z)];
}

int& CMatrix3D::operator()(int x, int y, int z) {
    return vec[fi(x, y, z)];
}

void CMatrix3D::print() {
    for (int z = 0; z < dz; ++z) {
        cout << "Capa Z = " << z << ":\n";
        for (int y = 0; y < dy; ++y) {
            for (int x = 0; x < dx; ++x) {
                cout << vec[fi(x, y, z)] << " ";
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
    CMatrix3D m(3, 3, 2); // Matriz 3x3x2
    m.print();

    m.set(1, 1, 0, 10);
    m.set(2, 0, 1, 20);
    m.gs(0, 0, 1) = 99;
    m(2, 2, 0) = m(0, 0, 1);

    m.print();

    return 0;
}
