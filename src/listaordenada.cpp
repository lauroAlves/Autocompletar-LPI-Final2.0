#include "../include/listaordenada.h"
#include <algorithm>
#include <string>

template <typename T>
void ListaOrdenada<T>::inserir(const T& item) {
    lista.push_back(item);
}

template <typename T>
void ListaOrdenada<T>::ordenar(const std::function<bool(const T&, const T&)>& comparar) {
    std::sort(lista.begin(), lista.end(), comparar);
}

template <typename T>
std::vector<T> ListaOrdenada<T>::buscar(const std::string& prefixo) const {
    std::vector<T> resultados;
    for (const auto& item : lista) {
        if (item.getNome().find(prefixo) == 0) {
            resultados.push_back(item);
        }
    }
    return resultados;
}

template <typename T>
size_t ListaOrdenada<T>::size() const {
    return lista.size();
}

template <typename T>
T& ListaOrdenada<T>::operator[](size_t index) {
    return lista[index];
}

template <typename T>
const T& ListaOrdenada<T>::operator[](size_t index) const {
    return lista[index];
}

// Remover a instância explícita do template se você estiver incluindo a implementação no cabeçalho
