// SumaArreglosParalelo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Karla Alejandra Fonseca Márquez A01795313

#include <iostream>
#include <omp.h>
#include <ctime> // Para inicializar el generador de números aleatorios

//#define N 1000
//#define chunk 100
//#define mostrar 10

void imprimeArreglo(float* d, int mostrar);

int main()
{
    std::cout << "Sumando arreglos en paralelo\n";

    // Variables para configurar los parámetros
    int N, chunk, mostrar;

    // Pedir datos al usuario
    std::cout << "Ingrese el tamaño del arreglo (N): ";
    std::cin >> N;

    std::cout << "Ingrese el tamaño del chunk: ";
    std::cin >> chunk;

    std::cout << "Ingrese la cantidad de valores a mostrar: ";
    std::cin >> mostrar;

    // Crear dinámicamente los arreglos
    float* a = new float[N];
    float* b = new float[N];
    float* c = new float[N];

    // Inicializar generador de números aleatorios
    std::srand(std::time(nullptr));

    // Llenar los arreglos con valores aleatorios
    for (int i = 0; i < N; i++)
    {
        a[i] = static_cast<float>(std::rand() % 100); // Números entre 0 y 99
        b[i] = static_cast<float>(std::rand() % 100);
    }

#pragma omp parallel for shared(a, b, c, chunk) schedule(static, chunk)

    for (int i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a, mostrar);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b, mostrar);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c, mostrar);
}


void imprimeArreglo(float* d, int mostrar)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
