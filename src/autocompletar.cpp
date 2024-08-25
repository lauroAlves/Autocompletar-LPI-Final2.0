#include "../include/autocompletar.h"
#include "../include/termo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

Autocompletar::Autocompletar(const std::string& arquivo) : arquivo(arquivo) {
    carregarDados();
}

void Autocompletar::carregarDados() {
    std::ifstream file(arquivo);
    std::string linha;
    while (std::getline(file, linha)) {
        std::istringstream iss(linha);
        long long int peso;
        std::string nome;
        if (iss >> peso && std::getline(iss, nome)) {
            nome = nome.substr(1); // Remove o espaço após o tab
            termos.inserir(Termo(peso, nome));
        }
    }
    termos.ordenar(Termo::compararPorNome);
}

void Autocompletar::buscarTermos(const std::string& prefixo, int k) const {
    std::vector<Termo> resultados = termos.buscar(prefixo);
    std::sort(resultados.begin(), resultados.end(), Termo::compararPorPeso);
    
    for (int i = 0; i < std::min(k, static_cast<int>(resultados.size())); ++i) {
        std::cout << resultados[i] << std::endl;
    }
}

int Autocompletar::buscaBinaria(const std::string& prefixo) const {
    // Implementação da busca binária para prefixo
    int inicio = 0;
    int fim = termos.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        const std::string& nome = termos[meio].getNome();

        if (nome.find(prefixo) == 0) {
            return meio;
        }
        if (nome < prefixo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
