#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;
const int orden = 5;

void ingresarMatriz(int matriz[orden][orden], int i, int j);
void imprimirMatriz(int matriz[orden][orden]);
bool checkCircuito(int matriz[orden][orden], int verticeInicio);
bool validarEntrada();

int main() {
    int opcion;
    bool sw = false;
    int matriz[orden][orden] = { 0 };
    int i = 0, j = 0;

    do {
        cout << "\nMenu:\n";
        cout << "1. Ingresar matriz \n";
        cout << "2. Imprimir matriz \n";
        cout << "3. Verificar si existe un circuito desde un vertice\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

		if (!validarEntrada()) {
			continue;
		}

        switch (opcion) {
        case 1:
            ingresarMatriz(matriz, i, j);
            sw = true;
            break;
        case 2:
			if (!sw) {
				cout << "No se ha ingresado ninguna matriz" << endl;
				break;
			}
			cout << "la matriz resultante es: " << endl;
			imprimirMatriz(matriz);
			break;
        case 3:
			int vertice;
			if (!sw) {
				cout << "No se ha ingresado ninguna matriz" << endl;
			}
			else {
				do {
					cout << "Ingrese el vertice desde 0 hasta " << orden - 1 << ": ";
					cin >> vertice;
				} while (!validarEntrada() || vertice < 0 && vertice >= orden);

				if (checkCircuito(matriz, vertice)) {
					cout << "Existe un circuito desde el vertice " << vertice << endl;
				}
				else {
					cout << "No existe un circuito desde el vertice " << vertice << endl;
				}
			}
			break;

        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 4);

    return 0;
}

void ingresarMatriz(int matriz[orden][orden], int i, int j) {
	if (i >= orden) {
		return;
	}
	if (j < orden) {
		int valor;
		do {
			cout << "Ingrese el valor (1 o 0) para la posicion [" << i << "][" << j << "] de la matriz: ";
			cin >> valor;

		} while (!validarEntrada() || valor != 0 && valor != 1);

		matriz[i][j] = valor;
		ingresarMatriz(matriz, i, j + 1);
	}
	else {
		ingresarMatriz(matriz, i + 1, 0);
	}

}

void imprimirMatriz(int matriz[orden][orden]) {
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkCircuito(int matriz[orden][orden], int vertice) {
	vector<bool> visitado(orden, false);
	stack<int> pila;
	pila.push(vertice);

	while (!pila.empty()) {
		int VerticeActual = pila.top();
		pila.pop();

		if (visitado[VerticeActual]) {
			if (VerticeActual == vertice) {
				return true;
			}
			continue;
		}

		visitado[VerticeActual] = true;

		for (int i = 0; i < orden; i++) {
			if (matriz[VerticeActual][i] == 1) {
				pila.push(i);
			}
		}
	}

	return false;
}

bool validarEntrada() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Opcion no valida" << endl;
		return false;
	}
	return true;
}

