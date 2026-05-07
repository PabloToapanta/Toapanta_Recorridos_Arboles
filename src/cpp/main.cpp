#include <iostream>
#include <queue>
#include <string>
using namespace std;

// =====================
// ESTRUCTURAS DE DATOS
// =====================
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// Estructura adicional para el Ejercicio 5 (Módulos del Sistema Web)
struct NodoString {
    string dato;
    NodoString* izquierda;
    NodoString* derecha;

    NodoString(string valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// ===============
// FUNCIONES BASE
// ===============
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;
    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";

        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

// ======================
// FUNCIONES DE UTILIDAD
// ======================
Nodo* buildBaseTree() {
    // Reutiliza la lógica proporcionada originalmente para construir el árbol base
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha = new Nodo(7);
    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(20);
    return raiz;
}

int countNodes(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + countNodes(raiz->izquierda) + countNodes(raiz->derecha);
}

int countLeaves(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) return 1;
    return countLeaves(raiz->izquierda) + countLeaves(raiz->derecha);
}

// =========================
// RESOLUCIÓN DE EJERCICIOS
// =========================
void exerciseOne() {
    cout << "\n--- Ejercicio 1: Recorridos Manuales vs Codigo ---" << endl;
    
    // Representación visual del árbol original
    cout << "Representacion del Arbol Original:" << endl;
    cout << "        10" << endl;
    cout << "       /  \\" << endl;
    cout << "      5    15" << endl;
    cout << "     / \\   / \\" << endl;
    cout << "    2   7 12 20" << endl;

    cout << "\nEsperado Manual Preorden : 10 5 2 7 15 12 20" << endl;
    cout << "Esperado Manual Inorden  : 2 5 7 10 12 15 20" << endl;
    cout << "Esperado Manual Postorden: 2 7 5 12 20 15 10" << endl;
    cout << "Esperado Manual BFS      : 10 5 15 2 7 12 20" << endl;
    
    Nodo* raiz = buildBaseTree();
    cout << "\nResultados del Codigo:" << endl;
    cout << "Preorden: "; preorden(raiz); cout << endl;
    cout << "Inorden: "; inorden(raiz); cout << endl;
    cout << "Postorden: "; postorden(raiz); cout << endl;
    cout << "BFS: "; bfs(raiz); cout << endl;
}

void exerciseTwo() {
    cout << "\n--- Ejercicio 2: Agregar Nodos (1, 3, 18, 25) ---" << endl;
    Nodo* raiz = buildBaseTree();
    
    // Lógica para agregar nuevos nodos (MANTENER LA LÓGICA EXISTENTE)
    raiz->izquierda->izquierda->izquierda = new Nodo(1);   // Izquierda del 2
    raiz->izquierda->izquierda->derecha = new Nodo(3);     // Derecha del 2
    raiz->derecha->derecha->izquierda = new Nodo(18);      // Izquierda del 20
    raiz->derecha->derecha->derecha = new Nodo(25);        // Derecha del 20

    // Representación visual modificada incluyendo los nuevos nodos (solicitado)
    cout << "Representacion del Arbol Modificado:" << endl;
    cout << "              10" << endl;
    cout << "             /  \\" << endl;
    cout << "            5    15" << endl;
    cout << "           / \\   / \\" << endl;
    cout << "          2   7 12 20" << endl;
    cout << "         / \\       / \\" << endl;
    cout << "        1   3     18  25" << endl;

    cout << "\nResultados del Codigo con Arbol Modificado:" << endl;
    cout << "Preorden: "; preorden(raiz); cout << endl;
    cout << "Inorden: "; inorden(raiz); cout << endl;
    cout << "Postorden: "; postorden(raiz); cout << endl;
    cout << "BFS: "; bfs(raiz); cout << endl;
}

void exerciseThree() {
    cout << "\n--- Ejercicio 3: Contar total de Nodos ---" << endl;
    
    // Representación visual del árbol original
    cout << "Representacion del Arbol Original:" << endl;
    cout << "        10" << endl;
    cout << "       /  \\" << endl;
    cout << "      5    15" << endl;
    cout << "     / \\   / \\" << endl;
    cout << "    2   7 12 20" << endl;

    Nodo* raiz = buildBaseTree();
    int total = countNodes(raiz);
    cout << "\nLa cantidad total de nodos en el arbol original es: " << total << " (Esperado: 7)" << endl;
}

void exerciseFour() {
    cout << "\n--- Ejercicio 4: Contar las Hojas ---" << endl;
    
    // Representación visual del árbol original
    cout << "Representacion del Arbol Original:" << endl;
    cout << "        10" << endl;
    cout << "       /  \\" << endl;
    cout << "      5    15" << endl;
    cout << "     / \\   / \\" << endl;
    cout << "    2   7 12 20" << endl;

    Nodo* raiz = buildBaseTree();
    int leaves = countLeaves(raiz);
    cout << "\nLa cantidad de nodos hoja en el arbol original es: " << leaves << " (Esperado: 4)" << endl;
}

void exerciseFive() {
    cout << "\n--- Ejercicio 5: Sistema Web ---" << endl;
    
    // Representación visual de los módulos del Sistema Web (solicitado)
    cout << "Representacion de Modulos (Caso Real):" << endl;
    cout << "            Sistema Web" << endl;
    cout << "           /           \\" << endl;
    cout << "     Usuarios        Inventario" << endl;
    cout << "      /    \\          /      \\" << endl;
    cout << " Registrar Buscar  Productos Reportes" << endl;

    NodoString* raiz = new NodoString("Sistema Web");
    raiz->izquierda = new NodoString("Usuarios");
    raiz->derecha = new NodoString("Inventario");
    raiz->izquierda->izquierda = new NodoString("Registrar");
    raiz->izquierda->derecha = new NodoString("Buscar");
    raiz->derecha->izquierda = new NodoString("Productos");
    raiz->derecha->derecha = new NodoString("Reportes");

    cout << "\nEstructura del Sistema Web construida en memoria." << endl;
    cout << "\nRespuestas a las preguntas de recorrido:" << endl;
    cout << "1. Mostrar el menu principal: PREORDEN." << endl;
    cout << "   (Visita la raiz primero para mostrar el titulo y luego despliega sus submenus secuencialmente)." << endl;
    cout << "2. Procesar primero los modulos internos: POSTORDEN." << endl;
    cout << "   (Asegura que los procesos hijos se procesen, carguen o liberen antes que el contenedor padre)." << endl;
    cout << "3. Mostrar modulos nivel por nivel: BFS (Anchura)." << endl;
    cout << "   (Ideal para dibujar el esquema del sitio exactamente por niveles jerarquicos)." << endl;
}

// =============
// FUNCION MAIN 
// =============
int main() {
    int option;
    do {
        cout << "\n========== MENU DE ARBOLES BINARIOS ==========" << endl;
        cout << "1. Ejercicio 1 (Recorridos Base)" << endl;
        cout << "2. Ejercicio 2 (Agregar Nodos)" << endl;
        cout << "3. Ejercicio 3 (Contar Nodos)" << endl;
        cout << "4. Ejercicio 4 (Contar Hojas)" << endl;
        cout << "5. Ejercicio 5 (Proyecto Final - Sistema Web)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> option)) {
            // Manejo básico de entrada no numérica
            cin.clear();
            cin.ignore(1000, '\n');
            option = -1;
        }

        switch (option) {
            case 1: exerciseOne(); break;
            case 2: exerciseTwo(); break;
            case 3: exerciseThree(); break;
            case 4: exerciseFour(); break;
            case 5: exerciseFive(); break;
            case 0: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (option != 0);

    return 0;
}