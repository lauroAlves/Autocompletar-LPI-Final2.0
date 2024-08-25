#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>

template <typename T>
class ListaOrdenada {
public:
    void inserir(const T& item);
    void ordenar(const std::function<bool(const T&, const T&)>& comparar);
    std::vector<T> buscar(const std::string& prefixo) const;
    size_t size() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const; // Versão const do operador []

private:
    std::vector<T> lista;
};

// Incluindo a implementação inline para evitar problemas de instância de template
#include "../src/listaordenada.cpp"

#endif // LISTAORDENADA_H
