import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// =====================
// ESTRUCTURAS DE DATOS
// =====================
class Nodo {
    int dato;
    Nodo izquierda;
    Nodo derecha;

    public Nodo(int dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    // Estructura adicional para el Ejercicio 5
    static class NodoString {
        String dato;
        NodoString izquierda;
        NodoString derecha;

        public NodoString(String dato) {
            this.dato = dato;
            this.izquierda = null;
            this.derecha = null;
        }
    }

    // ===============
    // FUNCIONES BASE
    // ===============
    public static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    public static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecha);
    }

    public static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.print(raiz.dato + " ");
    }

    public static void bfs(Nodo raiz) {
        if (raiz == null) return;

        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);

        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");

            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    // ======================
    // FUNCIONES DE UTILIDAD
    // ======================
    public static Nodo buildBaseTree() {
        // Reutiliza la lógica proporcionada originalmente para construir el árbol base
        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);
        return raiz;
    }

    public static int countNodes(Nodo raiz) {
        if (raiz == null) return 0;
        return 1 + countNodes(raiz.izquierda) + countNodes(raiz.derecha);
    }

    public static int countLeaves(Nodo raiz) {
        if (raiz == null) return 0;
        if (raiz.izquierda == null && raiz.derecha == null) return 1;
        return countLeaves(raiz.izquierda) + countLeaves(raiz.derecha);
    }

    // =========================
    // RESOLUCIÓN DE EJERCICIOS
    // =========================
    public static void exerciseOne() {
        System.out.println("\n--- Ejercicio 1: Recorridos Manuales vs Codigo ---");
        
        // Representación visual del árbol original
        System.out.println("Representacion del Arbol Original:");
        System.out.println("        10");
        System.out.println("       /  \\");
        System.out.println("      5    15");
        System.out.println("     / \\   / \\");
        System.out.println("    2   7 12 20");

        System.out.println("\nEsperado Manual Preorden : 10 5 2 7 15 12 20");
        System.out.println("Esperado Manual Inorden  : 2 5 7 10 12 15 20");
        System.out.println("Esperado Manual Postorden: 2 7 5 12 20 15 10");
        System.out.println("Esperado Manual BFS      : 10 5 15 2 7 12 20");
        
        Nodo raiz = buildBaseTree();
        System.out.println("\nResultados del Codigo:");
        System.out.print("Preorden: "); preorden(raiz); System.out.println();
        System.out.print("Inorden: "); inorden(raiz); System.out.println();
        System.out.print("Postorden: "); postorden(raiz); System.out.println();
        System.out.print("BFS: "); bfs(raiz); System.out.println();
    }

    public static void exerciseTwo() {
        System.out.println("\n--- Ejercicio 2: Agregar Nodos (1, 3, 18, 25) ---");
        Nodo raiz = buildBaseTree();
        
        // Lógica para agregar nuevos nodos (MANTENER LA LÓGICA EXISTENTE)
        raiz.izquierda.izquierda.izquierda = new Nodo(1);   // Izquierda del 2
        raiz.izquierda.izquierda.derecha = new Nodo(3);     // Derecha del 2
        raiz.derecha.derecha.izquierda = new Nodo(18);      // Izquierda del 20
        raiz.derecha.derecha.derecha = new Nodo(25);        // Derecha del 20

        // Representación visual modificada incluyendo los nuevos nodos (solicitado)
        System.out.println("Representacion del Arbol Modificado:");
        System.out.println("              10");
        System.out.println("             /  \\");
        System.out.println("            5    15");
        System.out.println("           / \\   / \\");
        System.out.println("          2   7 12 20");
        System.out.println("         / \\       / \\");
        System.out.println("        1   3     18  25");

        System.out.println("\nResultados del Codigo con Arbol Modificado:");
        System.out.print("Preorden: "); preorden(raiz); System.out.println();
        System.out.print("Inorden: "); inorden(raiz); System.out.println();
        System.out.print("Postorden: "); postorden(raiz); System.out.println();
        System.out.print("BFS: "); bfs(raiz); System.out.println();
    }

    public static void exerciseThree() {
        System.out.println("\n--- Ejercicio 3: Contar total de Nodos ---");
        
        // Representación visual del árbol original
        System.out.println("Representacion del Arbol Original:");
        System.out.println("        10");
        System.out.println("       /  \\");
        System.out.println("      5    15");
        System.out.println("     / \\   / \\");
        System.out.println("    2   7 12 20");

        Nodo raiz = buildBaseTree();
        int total = countNodes(raiz);
        System.out.println("\nLa cantidad total de nodos en el arbol original es: " + total + " (Esperado: 7)");
    }

    public static void exerciseFour() {
        System.out.println("\n--- Ejercicio 4: Contar las Hojas ---");
        
        // Representación visual del árbol original
        System.out.println("Representacion del Arbol Original:");
        System.out.println("        10");
        System.out.println("       /  \\");
        System.out.println("      5    15");
        System.out.println("     / \\   / \\");
        System.out.println("    2   7 12 20");

        Nodo raiz = buildBaseTree();
        int leaves = countLeaves(raiz);
        System.out.println("\nLa cantidad de nodos hoja en el arbol original es: " + leaves + " (Esperado: 4)");
    }

    public static void exerciseFive() {
        System.out.println("\n--- Ejercicio 5: Sistema Web ---");
        
        // Representación visual de los módulos del Sistema Web (solicitado)
        System.out.println("Representacion de Modulos (Caso Real):");
        System.out.println("            Sistema Web");
        System.out.println("           /           \\");
        System.out.println("     Usuarios        Inventario");
        System.out.println("      /    \\          /      \\");
        System.out.println(" Registrar Buscar  Productos Reportes");

        NodoString raiz = new NodoString("Sistema Web");
        raiz.izquierda = new NodoString("Usuarios");
        raiz.derecha = new NodoString("Inventario");
        raiz.izquierda.izquierda = new NodoString("Registrar");
        raiz.izquierda.derecha = new NodoString("Buscar");
        raiz.derecha.izquierda = new NodoString("Productos");
        raiz.derecha.derecha = new NodoString("Reportes");

        System.out.println("\nEstructura del Sistema Web construida en memoria.");
        System.out.println("\nRespuestas a las preguntas de recorrido:");
        System.out.println("1. Mostrar el menu principal: PREORDEN.");
        System.out.println("   (Visita la raiz primero para mostrar el titulo y luego despliega sus submenus secuencialmente).");
        System.out.println("2. Procesar primero los modulos internos: POSTORDEN.");
        System.out.println("   (Asegura que los procesos hijos se procesen, carguen o liberen antes que el contenedor padre).");
        System.out.println("3. Mostrar modulos nivel por nivel: BFS (Anchura).");
        System.out.println("   (Ideal para dibujar el esquema del sitio exactamente por niveles jerarquicos).");
    }

    // =============
    // FUNCION MAIN
    // =============
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int option;

        do {
            System.out.println("\n========== MENU DE ARBOLES BINARIOS ==========");
            System.out.println("1. Ejercicio 1 (Recorridos Base)");
            System.out.println("2. Ejercicio 2 (Agregar Nodos)");
            System.out.println("3. Ejercicio 3 (Contar Nodos)");
            System.out.println("4. Ejercicio 4 (Contar Hojas)");
            System.out.println("5. Ejercicio 5 (Proyecto Final - Sistema Web)");
            System.out.println("0. Salir");
            System.out.print("Seleccione una opcion: ");
            
            // Básico manejo de entrada
            if (scanner.hasNextInt()) {
                option = scanner.nextInt();
            } else {
                scanner.next(); // Limpiar entrada inválida
                option = -1;
            }

            switch (option) {
                case 1: exerciseOne(); break;
                case 2: exerciseTwo(); break;
                case 3: exerciseThree(); break;
                case 4: exerciseFour(); break;
                case 5: exerciseFive(); break;
                case 0: System.out.println("Saliendo del programa..."); break;
                default: System.out.println("Opcion no valida. Intente de nuevo.");
            }
        } while (option != 0);
    }
}