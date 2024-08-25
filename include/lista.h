#ifndef LISTA_H
#define LISTA_H

#include <vector>
#include <iostream>

template <typename T>
class Lista {
protected:
    std::vector<T> lista;

public:
    void inserir(const T& item) {
        lista.push_back(item);
    }

    int tamanho() const {
        return lista.size();
    }

    void imprimir() const {
        for (const auto& item : lista) {
            std::cout << item << std::endl;
        }
    }

    T& operator[](int index) {
        return lista.at(index);
    }
};

#endif // LISTA_H
