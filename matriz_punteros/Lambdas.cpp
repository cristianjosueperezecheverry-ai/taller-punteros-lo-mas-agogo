#include <iostream>
#include <functional> // Necesario para std::function

using namespace std;


double procesarArreglo(double* arr, int n, 
                       function<double(double)> transform, 
                       function<double(double, double)> accumulate) {
    
    double resultado = transform(arr[0]); 
    for (int i = 1; i < n; i++) {
        // Combinamos el resultado acumulado con el siguiente elemento transformado
        resultado = accumulate(resultado, transform(arr[i]));
    }
    return resultado;
}

int main() {
    int n = 3;
    double* datos = new double[n]{1.0, 2.0, 3.0};

   
    auto cuadrado = [](double x) { return x * x; };
    auto suma = [](double a, double b) { return a + b; };

   
    double total = procesarArreglo(datos, n, cuadrado, suma);

    cout << "Resultado final (Suma de cuadrados): " << total << endl;

    delete[] datos;
    return 0;
}
