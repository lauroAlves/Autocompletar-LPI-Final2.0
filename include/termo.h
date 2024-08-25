#ifndef TERMO_H
#define TERMO_H

#include <string>
#include <ostream>

class Termo {
public:
    long long int peso; // Alterado para long long int
    std::string nome;

    Termo(long long int peso = 0, const std::string& nome = "");

    std::string getNome() const;

    static bool compararPorNome(const Termo& a, const Termo& b);
    static bool compararPorPeso(const Termo& a, const Termo& b);

    bool operator<(const Termo& outro) const;

    friend std::ostream& operator<<(std::ostream& os, const Termo& termo);
};

#endif // TERMO_H
