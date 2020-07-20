// MOVE SEMANTICS.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
class ObjetoPesado
{
private:

    const int NumDatos = 1000000;
    int* _datos;

public:

    ObjetoPesado()
        : _datos(new int[NumDatos])
    {
    }

    ObjetoPesado(ObjetoPesado&& origen) //Move Constructor
        : _datos(nullptr)
    {
        std::swap(_datos, origen._datos);
    }

    ObjetoPesado(const ObjetoPesado& origen)
        : ObjetoPesado() // Llamada al constructor por defecto,
                         // soportado desde C++11
    {
        std::copy(origen._datos,
            origen._datos + NumDatos,
            _datos);
    }

    ~ObjetoPesado()
    {
        delete[] _datos;
    }
};

int main()
{
    clock_t start = clock();
    for (auto i = 0; i < 10000; i++)
    {
        ObjetoPesado origen;
        ObjetoPesado* copia = new ObjetoPesado(origen); // Constructor copia
        delete copia;
    }
    std::cout << "copia: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << std::endl;

    start = clock();
    for (auto i = 0; i < 10000; i++)
    {
        ObjetoPesado origen;
        ObjetoPesado* copia = new ObjetoPesado(std::move(origen)); // Constructor move
        delete copia;
    }
    std::cout << "move: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << std::endl;
}

