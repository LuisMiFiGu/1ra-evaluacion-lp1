/*REALIZE UN PROGRAMA QUE PERMITA SIMULAR UNA RULETA DE OPCIONES Y QUE EL USUARIO PUEDA ELEJIR ENTRE DOS OPCIONES
TRES OPCIONES, CUATRO O DIEZ. TODAS LAS OPCIONES DEBEN SER INGRESADAS Y VALIDADAS POR TECLADO, LAS OPCIONES PUEDEN SER PALABRAS,
NUMEROS O SIMBOLOS ESPECIALES. NO PUEDE USAR FUNCIONES, ESTRUCTURAS, ARREGLOS BIDIMENCIONALES, PUNTEROS O LISTAS.*/
/*UNA VEZ LISTO SUBALO A SU REPOSITORIO CON UNA DESCRIPCION*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Configurar la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    char repetirJuego = 's';

    // Ciclo principal para repetir todo el programa si el usuario lo desea
    while (repetirJuego == 's' || repetirJuego == 'S') {
        int cantidadOpciones = 0;

        // Validación para que la cantidad sea 2, 3, 4 o 10
        do {
            cout << "\n         === SIMULADOR DE RULETA DE OPCIONES ===" << endl;
            cout << "Ingrese la cantidad de opciones para la ruleta (2, 3, 4 o 10): ";
            cin >> cantidadOpciones;

            if (cantidadOpciones != 2 && cantidadOpciones != 3 && cantidadOpciones != 4 && cantidadOpciones != 10) {
                cout << "\n[ERROR] Cantidad no valida. Solo se permite elegir entre 2, 3, 4 o 10 opciones. Intente de nuevo.\n\n";
            }
        } while (cantidadOpciones != 2 && cantidadOpciones != 3 && cantidadOpciones != 4 && cantidadOpciones != 10);

        // Declaración del arreglo unidimensional de tamaño fijo máximo (10)
        string opciones[10];

        cout << "\n                  --- INGRESO DE OPCIONES ---" << endl;
        cout << "Nota: Las opciones pueden ser palabras, numeros o simbolos especiales.\n" << endl;

        for (int i = 0; i < cantidadOpciones; i++) {
            bool opcionValida = false;
            
            do {
                cout << "Ingrese la opcion " << (i + 1) << ": ";
                cin >> opciones[i];

                if (opciones[i] != "") {
                    opcionValida = true;
                } else {
                    cout << "La opcion no puede estar vacia. Intente de nuevo." << endl;
                }
            } while (!opcionValida);
        }

        // Mostrar las opciones ingresadas
        cout << "\n----------------------------------------" << endl;
        cout << "Opciones registradas en la ruleta:" << endl;
        for (int i = 0; i < cantidadOpciones; i++) {
            cout << "  [" << (i + 1) << "] " << opciones[i] << endl;
        }
        cout << "----------------------------------------" << endl;

        // Bucle interno para permitir girar la misma ruleta varias veces antes de cambiar opciones
        char repetirGiro = 's';
        while (repetirGiro == 's' || repetirGiro == 'S') {
            char girar;
            cout << "\nPresione la letra 'g' (o cualquier tecla y Enter) para girar la ruleta: ";
            cin >> girar;

            // Selección aleatoria del índice ganador
            int indiceGanador = rand() % cantidadOpciones;

            // Selección aleatoria de un color ANSI para el resultado (31 al 36)
            int colorAleatorio = 31 + (rand() % 6);

            // Mostrar el resultado con color aleatorio
            cout << "\n    ========================================" << endl;
            cout << "               GIRANDO LA RULETA...!" << endl;
            cout << "    ========================================" << endl;
            cout << "         El resultado ganador es: \033[1;" << colorAleatorio << "m** " << opciones[indiceGanador] << " **\033[0m" << endl;
            cout << "    ========================================" << endl;

            cout << "\n¿Desea volver a girar esta misma ruleta? (s/n): ";
            cin >> repetirGiro;
        }

        // Preguntar si desea iniciar todo de nuevo con nuevas opciones / nueva cantidad
        cout << "\n¿Desea configurar una nueva ruleta con nuevas opciones? (s/n): ";
        cin >> repetirJuego;
        cout << "\n";
    }

    cout << "Gracias por usar el simulador de ruleta! Hasta luego." << endl;

    return 0;
}
