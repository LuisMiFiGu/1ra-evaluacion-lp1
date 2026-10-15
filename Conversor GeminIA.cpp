/*REALIZE UN PROGRAMA QUE PERMITA REALIZAR CONVERSIONES ENTRE UNIDADES DE LONGITUD, MASA Y TIRMPO.
CONSIDERE LAS MAS USADAS, VALIDE LA ENTRADA POR TECLADO Y CONSIDERE LAS RESTRICCIONES DEL ULTIMO EJERCICIO.
EL USUARIO DBE SER CAPAZ SELECCIONAR LAS UNIDADES QUE DESEA CONVERTIR*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    char repetirJuego = 's';

    // Ciclo principal para repetir el programa si el usuario lo desea
    while (repetirJuego == 's' || repetirJuego == 'S') {
        int categoria = 0;

        // Validación de la categoría principal
        do {
            cout << "\n========================================" << endl;
            cout << "     CONVERSOR DE UNIDADES - MENU" << endl;
            cout << "========================================" << endl;
            cout << "1. Longitud (m, km, cm, mm, in, ft)" << endl;
            cout << "2. Masa (kg, g, lb, oz)" << endl;
            cout << "3. Tiempo (s, min, h, dias)" << endl;
            cout << "4. Salir" << endl;
            cout << "Seleccione una categoria (1-4): ";
            cin >> categoria;

            if (categoria < 1 || categoria > 4) {
                cout << "\n[ERROR] Opcion no valida. Elija un numero entre 1 y 4.\n\n";
            }
        } while (categoria < 1 || categoria > 4);

        if (categoria == 4) {
            cout << "\n¡Gracias por usar el conversor! Hasta luego." << endl;
            break;
        }

        int origen = 0;
        int destino = 0;
        double valor = 0.0;
        double resultado = 0.0;

        // ---------------------------------------------------------
        // CATEGORÍA 1: LONGITUD
        // ---------------------------------------------------------
        if (categoria == 1) {
            do {
                cout << "\n--- CONVERSION DE LONGITUD ---" << endl;
                cout << "Unidades disponibles:\n";
                cout << "1. Metros (m)\n2. Kilometros (km)\n3. Centimetros (cm)\n";
                cout << "4. Milimetros (mm)\n5. Pulgadas (in)\n6. Pies (ft)\n";
                cout << "Elija la unidad de ORIGEN (1-6): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-6): ";
                cin >> destino;

                if (origen < 1 || origen > 6 || destino < 1 || destino > 6) {
                    cout << "\n[ERROR] Unidades de longitud invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 6 || destino < 1 || destino > 6);

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            // Convertir la unidad de origen a una unidad base (Metros)
            double valorEnMetros = 0.0;
            if (origen == 1) valorEnMetros = valor;
            else if (origen == 2) valorEnMetros = valor * 1000.0;
            else if (origen == 3) valorEnMetros = valor / 100.0;
            else if (origen == 4) valorEnMetros = valor / 1000.0;
            else if (origen == 5) valorEnMetros = valor * 0.0254;
            else if (origen == 6) valorEnMetros = valor * 0.3048;

            // Convertir de Metros a la unidad de destino
            if (destino == 1) resultado = valorEnMetros;
            else if (destino == 2) resultado = valorEnMetros / 1000.0;
            else if (destino == 3) resultado = valorEnMetros * 100.0;
            else if (destino == 4) resultado = valorEnMetros * 1000.0;
            else if (destino == 5) resultado = valorEnMetros / 0.0254;
            else if (destino == 6) resultado = valorEnMetros / 0.3048;
        }
        // ---------------------------------------------------------
        // CATEGORÍA 2: MASA
        // ---------------------------------------------------------
        else if (categoria == 2) {
            do {
                cout << "\n--- CONVERSION DE MASA ---" << endl;
                cout << "Unidades disponibles:\n";
                cout << "1. Kilogramos (kg)\n2. Gramos (g)\n3. Libras (lb)\n4. Onzas (oz)\n";
                cout << "Elija la unidad de ORIGEN (1-4): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-4): ";
                cin >> destino;

                if (origen < 1 || origen > 4 || destino < 1 || destino > 4) {
                    cout << "\n[ERROR] Unidades de masa invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 4 || destino < 1 || destino > 4);

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            // Convertir la unidad de origen a una unidad base (Kilogramos)
            double valorEnKg = 0.0;
            if (origen == 1) valorEnKg = valor;
            else if (origen == 2) valorEnKg = valor / 1000.0;
            else if (origen == 3) valorEnKg = valor * 0.45359237;
            else if (origen == 4) valorEnKg = valor * 0.02834952;

            // Convertir de Kilogramos a la unidad de destino
            if (destino == 1) resultado = valorEnKg;
            else if (destino == 2) resultado = valorEnKg * 1000.0;
            else if (destino == 3) resultado = valorEnKg / 0.45359237;
            else if (destino == 4) resultado = valorEnKg / 0.02834952;
        }
        // ---------------------------------------------------------
        // CATEGORÍA 3: TIEMPO
        // ---------------------------------------------------------
        else if (categoria == 3) {
            do {
                cout << "\n--- CONVERSION DE TIEMPO ---" << endl;
                cout << "Unidades disponibles:\n";
                cout << "1. Segundos (s)\n2. Minutos (min)\n3. Horas (h)\n4. Dias (dias)\n";
                cout << "Elija la unidad de ORIGEN (1-4): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-4): ";
                cin >> destino;

                if (origen < 1 || origen > 4 || destino < 1 || destino > 4) {
                    cout << "\n[ERROR] Unidades de tiempo invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 4 || destino < 1 || destino > 4);

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            // Convertir la unidad de origen a una unidad base (Segundos)
            double valorEnSegundos = 0.0;
            if (origen == 1) valorEnSegundos = valor;
            else if (origen == 2) valorEnSegundos = valor * 60.0;
            else if (origen == 3) valorEnSegundos = valor * 3600.0;
            else if (origen == 4) valorEnSegundos = valor * 86400.0;

            // Convertir de Segundos a la unidad de destino
            if (destino == 1) resultado = valorEnSegundos;
            else if (destino == 2) resultado = valorEnSegundos / 60.0;
            else if (destino == 3) resultado = valorEnSegundos / 3600.0;
            else if (destino == 4) resultado = valorEnSegundos / 86400.0;
        }

        // Mostrar el resultado de la conversión
        cout << "\n========================================" << endl;
        cout << "           RESULTADO EXITOSO" << endl;
        cout << "========================================" << endl;
        cout << "       El valor convertido es: \033[32m" << resultado <<"\033[0m"<< endl;
        cout << "========================================" << endl;

        // Preguntar si desea realizar otra conversión
        cout << "\nDesea realizar otra conversion? (s/n): ";
        cin >> repetirJuego;
    }

    return 0;
}
