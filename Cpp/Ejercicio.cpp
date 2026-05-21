#include <iostream>
#include <string>

using namespace std;

// 1. CREACION DE LA CLASE
class Estudiante {
// Atributos privados para garantizar el encapsulamiento
private:
    string cedula;
    string nombre;
    string apellido;
    double nota1, nota2, nota3;
    double promedio;
    string estado;

public:
    // Constructor: Se ejecuta al crear un objeto. Sirve para inicializar las variables en vacio o cero.
    Estudiante() {
        cedula = "";
        nombre = "";
        apellido = "";
        nota1 = 0;
        nota2 = 0;
        nota3 = 0;
        promedio = 0;
        estado = "";
    }

    // Metodo para guardar la informacion personal del estudiante
    void setDatosPersonales(string ced, string nom, string ape) {
        cedula = ced;
        nombre = nom;
        apellido = ape;
    }

    // Metodo para guardar las 3 notas despues de ser validadas
    void setNotas(double n1, double n2, double n3) {
        nota1 = n1;
        nota2 = n2;
        nota3 = n3;
    }

    // Metodo que calcula el promedio y determina si el estudiante aprueba (>= 7) o reprueba
    void calcularPromedioYEstado() {
        promedio = (nota1 + nota2 + nota3) / 3;
        
        if (promedio >= 7.00) {
            estado = "Aprobado";
        } else {
            estado = "Reprobado";
        }
    }

    // Metodo Get: Sirve para obtener el estado actual del estudiante y poder contarlo luego
    string getEstado() {
        return estado;
    }

    // Metodo para imprimir en pantalla toda la informacion consolidada del objeto
    void mostrarInformacion() {
        cout << "---------------------------------------" << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "Notas: " << nota1 << ", " << nota2 << ", " << nota3 << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Estado: " << estado << endl;
    }
};

// 2. PROGRAMA PRINCIPAL
int main() {
    // Declaracion de un arreglo que contendra 5 objetos de la clase Estudiante
    Estudiante estudiantes[5]; 
    int aprobados = 0;
    int reprobados = 0;

    cout << "=== REGISTRO DE ESTUDIANTES ===" << endl;

    // Bucle iterativo para registrar la informacion de los 5 estudiantes
    for (int i = 0; i < 5; i++) {
        string ced, nom, ape;
        double n1, n2, n3;

        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "Ingrese Cedula: "; cin >> ced;
        cout << "Ingrese Nombre: "; cin >> nom;
        cout << "Ingrese Apellido: "; cin >> ape;

        estudiantes[i].setDatosPersonales(ced, nom, ape);

        // Ciclo do-while para validar estrictamente que la Nota 1 este en el rango de 0 a 10
        do {
            cout << "Ingrese Nota 1 (0-10): "; cin >> n1;
        } while (n1 < 0 || n1 > 10);

        // Ciclo do-while para validar estrictamente que la Nota 2 este en el rango de 0 a 10
        do {
            cout << "Ingrese Nota 2 (0-10): "; cin >> n2;
        } while (n2 < 0 || n2 > 10);

        // Ciclo do-while para validar estrictamente que la Nota 3 este en el rango de 0 a 10
        do {
            cout << "Ingrese Nota 3 (0-10): "; cin >> n3;
        } while (n3 < 0 || n3 > 10);

        // Se envian las notas al objeto y se calcula automaticamente su estado
        estudiantes[i].setNotas(n1, n2, n3);
        estudiantes[i].calcularPromedioYEstado();
    }

    cout << "\n=== LISTADO COMPLETO ===" << endl;
    
    // Bucle para mostrar el listado y contar cuantos aprobaron o reprobaron
    for (int i = 0; i < 5; i++) {
        estudiantes[i].mostrarInformacion();
        
        // Se extrae el estado del objeto para incrementar los contadores globales
        if (estudiantes[i].getEstado() == "Aprobado") {
            aprobados = aprobados + 1;
        } else {
            reprobados = reprobados + 1;
        }
    }

    cout << "---------------------------------------" << endl;
    cout << "Total Aprobados: " << aprobados << endl;
    cout << "Total Reprobados: " << reprobados << endl;

    return 0;
}