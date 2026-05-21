import java.util.Scanner;

public class SistemaEstudiantes {
    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        // Declaracion de un arreglo que contendra 5 objetos de la clase Estudiante
        Estudiante[] estudiantes = new Estudiante[5]; 
        int aprobados = 0;
        int reprobados = 0;

        System.out.println("=== REGISTRO DE ESTUDIANTES ===");

        // Bucle iterativo para registrar la informacion de los 5 estudiantes
        for (int i = 0; i < 5; i++) {
            System.out.println("\nEstudiante " + (i + 1) + ":");
            System.out.print("Ingrese Cedula: ");
            String ced = leer.next();
            System.out.print("Ingrese Nombre: ");
            String nom = leer.next();
            System.out.print("Ingrese Apellido: ");
            String ape = leer.next();

            // Usamos el constructor para instanciar el objeto con sus datos personales
            estudiantes[i] = new Estudiante(ced, nom, ape);

            double n1, n2, n3;
            
            // Ciclo do-while para validar estrictamente que la Nota 1 este en el rango de 0 a 10
            do {
                System.out.print("Ingrese Nota 1 (0-10): ");
                n1 = leer.nextDouble();
            } while (n1 < 0 || n1 > 10);

            // Ciclo do-while para validar estrictamente que la Nota 2 este en el rango de 0 a 10
            do {
                System.out.print("Ingrese Nota 2 (0-10): ");
                n2 = leer.nextDouble();
            } while (n2 < 0 || n2 > 10);

            // Ciclo do-while para validar estrictamente que la Nota 3 este en el rango de 0 a 10
            do {
                System.out.print("Ingrese Nota 3 (0-10): ");
                n3 = leer.nextDouble();
            } while (n3 < 0 || n3 > 10);

            // Se envian las notas al objeto y se calcula automaticamente su promedio y estado
            estudiantes[i].setNotas(n1, n2, n3);
            estudiantes[i].calcularPromedioYEstado();
        }

        System.out.println("\n=== LISTADO COMPLETO ===");
        
        // Bucle para mostrar la informacion de todos los estudiantes y contar los resultados
        for (int i = 0; i < 5; i++) {
            estudiantes[i].mostrarInformacion();
            
            // Se extrae el estado del objeto para incrementar los contadores globales
            if (estudiantes[i].getEstado().equals("Aprobado")) {
                aprobados = aprobados + 1;
            } else {
                reprobados = reprobados + 1;
            }
        }

        System.out.println("---------------------------------------");
        System.out.println("Total Aprobados: " + aprobados);
        System.out.println("Total Reprobados: " + reprobados);

        leer.close();
    }
}

// CREACION DE LA CLASE ESTUDIANTE
class Estudiante {
    // Atributos privados para garantizar el encapsulamiento de datos
    private String cedula;
    private String nombre;
    private String apellido;
    private double nota1, nota2, nota3;
    private double promedio;
    private String estado;

    // Constructor: Inicializa el objeto recibiendo los datos personales
    public Estudiante(String ced, String nom, String ape) {
        cedula = ced;
        nombre = nom;
        apellido = ape;
    }

    // Metodo Set: Permite guardar las notas en los atributos privados
    public void setNotas(double n1, double n2, double n3) {
        nota1 = n1;
        nota2 = n2;
        nota3 = n3;
    }

    // Metodo que realiza la operacion matematica del promedio y define el estado academico
    public void calcularPromedioYEstado() {
        promedio = (nota1 + nota2 + nota3) / 3;
        
        if (promedio >= 7.00) {
            estado = "Aprobado";
        } else {
            estado = "Reprobado";
        }
    }

    // Metodo Get: Permite extraer el valor del estado desde el programa principal
    public String getEstado() {
        return estado;
    }

    // Metodo para imprimir en pantalla toda la informacion consolidada del objeto
    public void mostrarInformacion() {
        System.out.println("---------------------------------------");
        System.out.println("Cedula: " + cedula);
        System.out.println("Nombre: " + nombre + " " + apellido);
        System.out.println("Notas: " + nota1 + ", " + nota2 + ", " + nota3);
        System.out.println("Promedio: " + promedio);
        System.out.println("Estado: " + estado);
    }
}