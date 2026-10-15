/*REALIZE UN PROGRAMA QUE PERMITA REALIZAR CONVERSIONES ENTRE UNIDADES DE LONGITUD, MASA Y TIRMPO.
CONSIDERE LAS MAS USADAS, VALIDE LA ENTRADA POR TECLADO Y CONSIDERE LAS RESTRICCIONES DEL ULTIMO EJERCICIO.
EL USUARIO DBE SER CAPAZ SELECCIONAR LAS UNIDADES QUE DESEA CONVERTIR. EL PROGRAMA DEBE MOSTRAR LAS UNIDADES DE ORIGEN
Y DESTINO AL IMPRIMIR LA SALIDA, INCLUYE LAS UNIDADES DEL SISTEMA INTERNACIONAL Y LAS MAS CONOCIDAS DE TEMPEERATURA*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    char repetirJuego = 's';

    // Ciclo principal para repetir el conversor
    while (repetirJuego == 's' || repetirJuego == 'S') {
        int categoria = 0;

        // Validación del menú principal de categorías
        do {
            cout << "\n========================================" << endl;
            cout << "     CONVERSOR DE UNIDADES - MENU" << endl;
            cout << "========================================" << endl;
            cout << "1. Longitud (m, km, cm, mm, in, ft)" << endl;
            cout << "2. Masa (kg, g, lb, oz)" << endl;
            cout << "3. Tiempo (s, min, h, dias)" << endl;
            cout << "4. Temperatura (Celsius, Fahrenheit, Kelvin)" << endl;
            cout << "5. Salir" << endl;
            cout << "Seleccione una categoria (1-5): ";
            cin >> categoria;

            if (categoria < 1 || categoria > 5) {
                cout << "\n[ERROR] Opcion no valida. Elija un numero entre 1 y 5.\n\n";
            }
        } while (categoria < 1 || categoria > 5);

        if (categoria == 5) {
            cout << "\n¡Gracias por usar el conversor! Hasta luego." << endl;
            break;
        }

        int origen = 0;
        int destino = 0;
        double valor = 0.0;
        double resultado = 0.0;
        string nombreOrigen = "";
        string nombreDestino = "";

        // ---------------------------------------------------------
        // CATEGORÍA 1: LONGITUD
        // ---------------------------------------------------------
        if (categoria == 1) {
            do {
                cout << "\n--- CONVERSION DE LONGITUD ---" << endl;
                cout << "1. Metros (m - SI)\n2. Kilometros (km)\n3. Centimetros (cm)\n";
                cout << "4. Milimetros (mm)\n5. Pulgadas (in)\n6. Pies (ft)\n";
                cout << "Elija la unidad de ORIGEN (1-6): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-6): ";
                cin >> destino;

                if (origen < 1 || origen > 6 || destino < 1 || destino > 6) {
                    cout << "\n[ERROR] Unidades de longitud invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 6 || destino < 1 || destino > 6);

            // Asignar nombres para la salida
            if (origen == 1) nombreOrigen = "Metros (m)";
            else if (origen == 2) nombreOrigen = "Kilometros (km)";
            else if (origen == 3) nombreOrigen = "Centimetros (cm)";
            else if (origen == 4) nombreOrigen = "Milimetros (mm)";
            else if (origen == 5) nombreOrigen = "Pulgadas (in)";
            else if (origen == 6) nombreOrigen = "Pies (ft)";

            if (destino == 1) nombreDestino = "Metros (m)";
            else if (destino == 2) nombreDestino = "Kilometros (km)";
            else if (destino == 3) nombreDestino = "Centimetros (cm)";
            else if (destino == 4) nombreDestino = "Milimetros (mm)";
            else if (destino == 5) nombreDestino = "Pulgadas (in)";
            else if (destino == 6) nombreDestino = "Pies (ft)";

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            double valorEnMetros = 0.0;
            if (origen == 1) valorEnMetros = valor;
            else if (origen == 2) valorEnMetros = valor * 1000.0;
            else if (origen == 3) valorEnMetros = valor / 100.0;
            else if (origen == 4) valorEnMetros = valor / 1000.0;
            else if (origen == 5) valorEnMetros = valor * 0.0254;
            else if (origen == 6) valorEnMetros = valor * 0.3048;

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
                cout << "1. Kilogramos (kg - SI)\n2. Gramos (g)\n3. Libras (lb)\n4. Onzas (oz)\n";
                cout << "Elija la unidad de ORIGEN (1-4): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-4): ";
                cin >> destino;

                if (origen < 1 || origen > 4 || destino < 1 || destino > 4) {
                    cout << "\n[ERROR] Unidades de masa invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 4 || destino < 1 || destino > 4);

            if (origen == 1) nombreOrigen = "Kilogramos (kg)";
            else if (origen == 2) nombreOrigen = "Gramos (g)";
            else if (origen == 3) nombreOrigen = "Libras (lb)";
            else if (origen == 4) nombreOrigen = "Onzas (oz)";

            if (destino == 1) nombreDestino = "Kilogramos (kg)";
            else if (destino == 2) nombreDestino = "Gramos (g)";
            else if (destino == 3) nombreDestino = "Libras (lb)";
            else if (destino == 4) nombreDestino = "Onzas (oz)";

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            double valorEnKg = 0.0;
            if (origen == 1) valorEnKg = valor;
            else if (origen == 2) valorEnKg = valor / 1000.0;
            else if (origen == 3) valorEnKg = valor * 0.45359237;
            else if (origen == 4) valorEnKg = valor * 0.02834952;

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
                cout << "1. Segundos (s - SI)\n2. Minutos (min)\n3. Horas (h)\n4. Dias (dias)\n";
                cout << "Elija la unidad de ORIGEN (1-4): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-4): ";
                cin >> destino;

                if (origen < 1 || origen > 4 || destino < 1 || destino > 4) {
                    cout << "\n[ERROR] Unidades de tiempo invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 4 || destino < 1 || destino > 4);

            if (origen == 1) nombreOrigen = "Segundos (s)";
            else if (origen == 2) nombreOrigen = "Minutos (min)";
            else if (origen == 3) nombreOrigen = "Horas (h)";
            else if (origen == 4) nombreOrigen = "Dias";

            if (destino == 1) nombreDestino = "Segundos (s)";
            else if (destino == 2) nombreDestino = "Minutos (min)";
            else if (destino == 3) nombreDestino = "Horas (h)";
            else if (destino == 4) nombreDestino = "Dias";

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            double valorEnSegundos = 0.0;
            if (origen == 1) valorEnSegundos = valor;
            else if (origen == 2) valorEnSegundos = valor * 60.0;
            else if (origen == 3) valorEnSegundos = valor * 3600.0;
            else if (origen == 4) valorEnSegundos = valor * 86400.0;

            if (destino == 1) resultado = valorEnSegundos;
            else if (destino == 2) resultado = valorEnSegundos / 60.0;
            else if (destino == 3) resultado = valorEnSegundos / 3600.0;
            else if (destino == 4) resultado = valorEnSegundos / 86400.0;
        }
        // ---------------------------------------------------------
        // CATEGORÍA 4: TEMPERATURA
        // ---------------------------------------------------------
        else if (categoria == 4) {
            do {
                cout << "\n--- CONVERSION DE TEMPERATURA ---" << endl;
                cout << "1. Celsius (°C)\n2. Fahrenheit (°F)\n3. Kelvin (K - SI)\n";
                cout << "Elija la unidad de ORIGEN (1-3): ";
                cin >> origen;
                cout << "Elija la unidad de DESTINO (1-3): ";
                cin >> destino;

                if (origen < 1 || origen > 3 || destino < 1 || destino > 3) {
                    cout << "\n[ERROR] Unidades de temperatura invalidas. Intente de nuevo.\n";
                }
            } while (origen < 1 || origen > 3 || destino < 1 || destino > 3);

            if (origen == 1) nombreOrigen = "Celsius (°C)";
            else if (origen == 2) nombreOrigen = "Fahrenheit (°F)";
            else if (origen == 3) nombreOrigen = "Kelvin (K)";

            if (destino == 1) nombreDestino = "Celsius (°C)";
            else if (destino == 2) nombreDestino = "Fahrenheit (°F)";
            else if (destino == 3) nombreDestino = "Kelvin (K)";

            cout << "Ingrese el valor a convertir: ";
            cin >> valor;

            // Convertir primero a Celsius como base
            double valorEnCelsius = 0.0;
            if (origen == 1) valorEnCelsius = valor;
            else if (origen == 2) valorEnCelsius = (valor - 32.0) * 5.0 / 9.0;
            else if (origen == 3) valorEnCelsius = valor - 273.15;

            // Convertir de Celsius a la unidad de destino
            if (destino == 1) resultado = valorEnCelsius;
            else if (destino == 2) resultado = (valorEnCelsius * 9.0 / 5.0) + 32.0;
            else if (destino == 3) resultado = valorEnCelsius + 273.15;
        }

        // Mostrar el resultado detallado indicando claramente el origen y el destino
        cout << "\n========================================" << endl;
        cout << "           RESULTADO EXITOSO" << endl;
        cout << "========================================" << endl;
        cout << valor << " " << nombreOrigen << " equivalen a:" << endl;
        cout << "\033[1;36m>> " << resultado << " " << nombreDestino << "\033[0m" << endl;
        cout << "========================================" << endl;

        // Preguntar si desea realizar otra conversión
        cout << "\n¿Desea realizar otra conversion? (s/n): ";
        cin >> repetirJuego;
    }

    return 0;
}
