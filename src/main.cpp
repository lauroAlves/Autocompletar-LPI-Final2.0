#include "../include/autocompletar.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo> <quantidade>" << std::endl;
        return 1;
    }

    std::string arquivo = argv[1];
    int k = std::stoi(argv[2]);

    try {
        Autocompletar autocompletar(arquivo);

        std::string prefixo;
        while (true) {
            std::cout << "Digite o prefixo (ou 'sair' para encerrar): ";
            std::getline(std::cin, prefixo);
            if (prefixo == "sair") break;

            autocompletar.buscarTermos(prefixo, k);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
