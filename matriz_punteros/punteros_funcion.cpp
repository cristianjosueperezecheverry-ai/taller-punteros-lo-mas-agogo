#include <iostream>
#include <vector>

using namespace std;

// 1. Definimos las funciones matemáticas básicas
double cuadrado(double x) { return x * x; }
double doble(double x) { return x * 2; }
double inverso(double x) { 
    if (x == 0) return 0; // Evitar división por cero
    return 1.0 / x; 
}


void aplicarOperacion(double* arr, int n, double (*op)(double)) {
    for (int i = 0; i < n; i++) {
        arr[i] = op(arr[i]); // Llamamos a la función que nos pasaron
    }
}

int main() {
    int n;
    cout << "Tamaño del arreglo: ";
    cin >> n;

    
    double* datos = new double[n];
    for(int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> datos[i];
    }

    cout << "\nElija operacion: 1. Cuadrado, 2. Doble, 3. Inverso: ";
    int opcion;
    cin >> opcion;

   
    double (*seleccionada)(double) = nullptr;

    if (opcion == 1) seleccionada = cuadrado;
    else if (opcion == 2) seleccionada = doble;
    else if (opcion == 3) seleccionada = inverso;

    if (seleccionada != nullptr) {
        aplicarOperacion(datos, n, seleccionada);
        
        cout << "Resultado: ";
        for(int i = 0; i < n; i++) cout << datos[i] << " ";
        cout << endl;
    }

    delete[] datos; // Siempre liberar memoria
    return 0;
}
