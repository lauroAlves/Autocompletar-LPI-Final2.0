#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "listaordenada.h"
#include "termo.h"
#include <string>

class Autocompletar {
public:
    Autocompletar(const std::string& arquivo);
    void carregarDados();
    void buscarTermos(const std::string& prefixo, int k) const;

private:
    ListaOrdenada<Termo> termos;
    std::string arquivo;

    int buscaBinaria(const std::string& prefixo) const;
};

#endif // AUTOCOMPLETE_H
