/*
 * Nombre del Proyecto: Analizador de Números
 * Modelo: B
 * Integrantes: [Luis Figueroa 33057755] y [Alexson Martinez 33864146]
 * Asignatura: Lenguaje de Programación II (Sección A)
 * Lapso: 2026-II
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Prototypes de funciones
int leerEnteroEnRango(long long minVal, long long maxVal, const char* mensaje);
bool esPrimo(int n);
long long factorial(int n);
int mcd(int a, int b);
long long mcm(int a, int b);
bool esPerfecto(int n);
long long invertirNumero(long long n);
long long decimalABinario(int n);
void mostrarEstadisticas(int c1, int c2, int c3, int c4, int c5, int c6);

/*
 * Función: leerEnteroEnRango
 * Qué hace: Lee un número entero por teclado, valida que no se ingresen letras y 
 *           que esté dentro del rango [minVal, maxVal]. Repite hasta que el dato sea válido.
 * Parámetros: 
 *   - long long minVal: Valor mínimo permitido.
 *   - long long maxVal: Valor máximo permitido.
 *   - const char* mensaje: Mensaje para solicitar el dato al usuario.
 * Retorna: Un entero validado tipo int (o long long según el caso).
 */
int leerEnteroEnRango(long long minVal, long long maxVal, const char* mensaje) {
    long long valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            if (valor >= minVal && valor <= maxVal) {
                return static_cast<int>(valor);
            } else {
                cout << "Error: Debe estar entre " << minVal << " y " << maxVal << ". Intente de nuevo.\n";
            }
        } else {
            cout << "Error: Entrada invalida (ingrese un numero entero valido).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/*
 * Función: esPrimo
 * Qué hace: Determina si un número entero entre 1 y 100 000 es primo.
 * Parámetros: int n (número a evaluar).
 * Retorna: bool (true si es primo, false en caso contrario).
 */
bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

/*
 * Función: factorial
 * Qué hace: Calcula el factorial de un número entre 0 y 20 mediante un ciclo.
 * Parámetros: int n (número a evaluar).
 * Retorna: long long (el factorial resultado).
 */
long long factorial(int n) {
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

/*
 * Función: mcd
 * Qué hace: Calcula el Máximo Común Divisor entre dos enteros usando el algoritmo de Euclides con ciclos.
 * Parámetros: int a, int b (los dos enteros positivos).
 * Retorna: int (el MCD).
 */
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/*
 * Función: mcm
 * Qué hace: Calcula el Mínimo Común Múltiplo utilizando la relación MCM(a,b) = (a * b) / MCD(a,b).
 * Parámetros: int a, int b (los dos enteros positivos).
 * Retorna: long long (el MCM calculado).
 */
long long mcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (static_cast<long long>(a) / mcd(a, b)) * b;
}

/*
 * Función: esPerfecto
 * Qué hace: Determina si un entero es un número perfecto sumando sus divisores propios.
 * Parámetros: int n (número a evaluar entre 1 y 100 000).
 * Retorna: bool (true si la suma de divisores es igual a n, false en caso contrario).
 */
bool esPerfecto(int n) {
    if (n <= 1) return false;
    int suma = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma == n;
}

/*
 * Función: invertirNumero
 * Qué hace: Invierte el orden de los dígitos de un número entero.
 * Parámetros: long long n (número de 0 a 999 999 999).
 * Retorna: long long (el número invertido).
 */
long long invertirNumero(long long n) {
    long long invertido = 0;
    while (n > 0) {
        invertido = (invertido * 10) + (n % 10);
        n /= 10;
    }
    return invertido;
}

/*
 * Función: decimalABinario
 * Qué hace: Convierte un entero entre 0 y 1023 a su representación en código binario (construida matemáticamente como un número).
 * Parámetros: int n (número en decimal).
 * Retorna: long long (representación numérico-binaria).
 */
long long decimalABinario(int n) {
    if (n == 0) return 0;
    long long binario = 0;
    long long posicion = 1;
    while (n > 0) {
        int residuo = n % 2;
        binario += residuo * posicion;
        posicion *= 10;
        n /= 2;
    }
    return binario;
}

/*
 * Función: mostrarEstadisticas
 * Qué hace: Imprime en pantalla las estadísticas de uso acumuladas en la sesión.
 * Parámetros: Contadores individuales de cada una de las 6 operaciones.
 * Retorna: void.
 */
void mostrarEstadisticas(int c1, int c2, int c3, int c4, int c5, int c6) {
    int total = c1 + c2 + c3 + c4 + c5 + c6;
    cout << "\n========================================\n";
    cout << "        ESTADISTICAS DE LA SESION       \n";
    cout << "========================================\n";
    cout << "1. Consultas de Primo:        " << c1 << "\n";
    cout << "2. Calculos de Factorial:     " << c2 << "\n";
    cout << "3. Calculos de MCD/MCM:       " << c3 << "\n";
    cout << "4. Consultas de Perfeccto:    " << c4 << "\n";
    cout << "5. Consultas de Capicua:      " << c5 << "\n";
    cout << "6. Conversiones a Binario:    " << c6 << "\n";
    cout << "----------------------------------------\n";
    cout << "TOTAL DE OPERACIONES REALIZADAS: " << total << "\n";
    cout << "========================================\n";
}

int main() {
    // Configuración de formato para decimales
    cout << fixed << setprecision(2);

    int opcion = 0;
    // Contadores para estadísticas de sesión
    int cantPrimo = 0, cantFact = 0, cantMcdMcm = 0;
    int cantPerf = 0, cantCapi = 0, cantBin = 0;

    do {
        cout << "\n=== ANALIZADOR DE NUMEROS ===\n";
        cout << "1. Es primo\n";
        cout << "2. Factorial\n";
        cout << "3. MCD y MCM\n";
        cout << "4. Es perfecto\n";
        cout << "5. Capicua\n";
        cout << "6. Binario\n";
        cout << "7. Estadisticas\n";
        cout << "8. Salir\n";
        
        opcion = leerEnteroEnRango(1, 8, "Opcion: ");

        switch (opcion) {
            case 1: {
                int num = leerEnteroEnRango(1, 100000, "Ingrese entero (1 a 100 000): ");
                if (esPrimo(num)) {
                    cout << "El numero " << num << " ES primo.\n";
                } else {
                    cout << "El numero " << num << " NO es primo.\n";
                }
                cantPrimo++;
                break;
            }
            case 2: {
                int num = leerEnteroEnRango(0, 20, "Ingrese entero (0 a 20): ");
                cout << num << "! = " << factorial(num) << "\n";
                cantFact++;
                break;
            }
            case 3: {
                int a = leerEnteroEnRango(1, 100000, "Ingrese primer entero (1 a 100 000): ");
                int b = leerEnteroEnRango(1, 100000, "Ingrese segundo entero (1 a 100 000): ");
                cout << "MCD(" << a << ", " << b << ") = " << mcd(a, b) << "\n";
                cout << "MCM(" << a << ", " << b << ") = " << mcm(a, b) << "\n";
                cantMcdMcm++;
                break;
            }
            case 4: {
                int num = leerEnteroEnRango(1, 100000, "Ingrese entero (1 a 100 000): ");
                if (esPerfecto(num)) {
                    cout << "El numero " << num << " ES perfecto.\n";
                } else {
                    cout << "El numero " << num << " NO es perfecto.\n";
                }
                cantPerf++;
                break;
            }
            case 5: {
                long long num = leerEnteroEnRango(0, 999999999, "Ingrese entero (0 a 999 999 999): ");
                long long inv = invertirNumero(num);
                cout << "Numero invertido: " << inv << "\n";
                if (num == inv) {
                    cout << "El numero " << num << " ES capicua.\n";
                } else {
                    cout << "El numero " << num << " NO es capicua.\n";
                }
                cantCapi++;
                break;
            }
            case 6: {
                int num = leerEnteroEnRango(0, 1023, "Numero decimal (0 a 1023): ");
                cout << num << " en binario es " << decimalABinario(num) << "\n";
                cantBin++;
                break;
            }
            case 7: {
                mostrarEstadisticas(cantPrimo, cantFact, cantMcdMcm, cantPerf, cantCapi, cantBin);
                break;
            }
            case 8: {
                cout << "\nSaliendo del programa...\n";
                mostrarEstadisticas(cantPrimo, cantFact, cantMcdMcm, cantPerf, cantCapi, cantBin);
                break;
            }
        }
    } while (opcion != 8);

    return 0;
}
