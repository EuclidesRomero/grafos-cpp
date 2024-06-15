#include<iostream>
using namespace std;
const int orden = 5;
void ingresarMatriz(int [orden][orden], int i, int j);
void imprimirMatriz(int [orden][orden]);
bool checkCircuito(int [orden][orden], int);


int main() {
	int opcion;
	bool sw = false;
	int matriz[orden][orden];
	int i = 0,  j = 0;
	
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
        	cout<<"la matriz resultante es: "<<endl;
        	imprimirMatriz(matriz);
        	break;  		
		}
		
    } while(opcion != 4);
}


void ingresarMatriz(int matriz[orden][orden], int i, int j) {
	if(i >= orden) {
		return;
	}
	if(j < orden) {
		cout<<"Ingrese el valor de matriz[" << i << "][" << j << "]";
		cin >> matriz[i][j];
		ingresarMatriz(matriz, i, j +1 );
	}
	else {
		ingresarMatriz(matriz, i + 1, 0);
	}
	
}

void imprimirMatriz(int matriz[orden][orden]) {
	cout<<"La matriz resultante es:";
	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			cout<<matriz[i][j];
		}
		cout<< endl;
	}
}
