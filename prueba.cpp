#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int orden = 5;

void ingresarMatriz(int matriz[orden][orden], int i, int j);
void imprimirMatriz(int matriz[orden][orden]);
bool checkCircuito(int matriz[orden][orden], int verticeInicio);

int main() {
    int opcion;
    bool sw = false;
    int matriz[orden][orden] = {0}; // Inicializar matriz a 0
    int i = 0, j = 0;

    do {
        cout << "\nMenu:\n";
        cout << "1. Ingresar matriz \n";
        cout << "2. Imprimir matriz \n";
        cout << "3. Verificar si existe un circuito desde un vertice\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarMatriz(matriz, i, j);
                sw = true;
                break;
            case 2:
                cout << "La matriz resultante es: " << endl;
                imprimirMatriz(matriz);
                break;
            case 3:
                if (sw) {
                    int vertice;
                    cout << "Ingrese el vertice desde 0 hasta " << orden - 1 << ": ";
                    cin >> vertice;
                    bool respuesta = checkCircuito(matriz, vertice);
                    if (respuesta) {
                        cout << "Existe un circuito desde el vertice " << vertice << endl;
                    } else {
                        cout << "No existe un circuito desde el vertice " << vertice << endl;
                    }
                } else {
                    cout << "Ingrese la matriz primero" << endl;
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
        cout << "Ingrese el valor de matriz[" << i << "][" << j << "]: ";
        cin >> matriz[i][j];
        ingresarMatriz(matriz, i, j + 1);
    } else {
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

bool checkCircuito(int matriz[orden][orden], int verticeInicio) {
    vector<bool> visitado(orden, false);
    vector<bool> enStack(orden, false);
    stack<int> pila;
    
    pila.push(verticeInicio);
    visitado[verticeInicio] = true;
    enStack[verticeInicio] = true;
    
    while (!pila.empty() ) {
        int verticeActual = pila.top();
        bool encontrado = false;
        
        for (int i = 0; i < orden; ++i) {
		       	
            if (matriz[verticeActual][i] == 1) { 
            
                if (!visitado[i]) {
                    pila.push(i);
                    visitado[i] = true;
                    enStack[i] = true;
                    encontrado = true;
                    break;
                } else if (enStack[i]) {
                    return true;
                }
            }
        }
        if(encontrado == false){
        pila.pop();
        enStack[verticeActual] = false;
		}
        
    }

    return false;
}

