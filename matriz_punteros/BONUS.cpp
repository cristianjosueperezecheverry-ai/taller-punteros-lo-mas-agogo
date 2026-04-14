#include <iostream>
#include <vector>
#include <functional>

using namespace std;


double aplicarPipeline(double valor, const vector<function<double(double)>>& funciones) {
    double res = valor;
    for (const auto& f : funciones) {
        res = f(res); // El resultado de una es la entrada de la siguiente
    }
    return res;
}

int main() {
    double valorInicial = 5.0;

   
    vector<function<double(double)>> pipeline = {
        [](double x) { return x * 2; },   // Doble: 5 -> 10
        [](double x) { return x + 3; },   // Suma 3: 10 -> 13
        [](double x) { return x * x; }    // Cuadrado: 13 -> 169
    };

    double resultado = aplicarPipeline(valorInicial, pipeline);

    cout << "Valor inicial: " << valorInicial << endl;
    cout << "Resultado tras pipeline: " << resultado << endl;

    return 0;
}
