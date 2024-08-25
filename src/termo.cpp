#include "../include/termo.h"

Termo::Termo(long long int peso, const std::string& nome) : peso(peso), nome(nome) {}

std::string Termo::getNome() const {
    return nome;
}

bool Termo::compararPorNome(const Termo& a, const Termo& b) {
    return a.nome < b.nome;
}

bool Termo::compararPorPeso(const Termo& a, const Termo& b) {
    return a.peso > b.peso;  // Ordem decrescente por peso
}

bool Termo::operator<(const Termo& outro) const {
    return nome < outro.nome;
}

std::ostream& operator<<(std::ostream& os, const Termo& termo) {
    os << termo.peso << "\t" << termo.nome;
    return os;
}
