#include <iostream>

int saldo = 0;

void cardapio() {
    std::string laches[] = {0};
    int precos[] = {0};
}

int main() {

    int escolha_do_usuario;

    while (true) {
        std::cout << "=== Cantina ===\n"
                  << "[1] Cardápio\n"
                  << "[2] Saldo\n"
                  << "[3] PROMOÇÃO!\n"
                  << "[4] Pedidos\n"
                  << "[5] Sair\n";

        std::cout << ">>> ";
        std::cin >> escolha_do_usuario;

        if (escolha_do_usuario == 5) {
            break;
        }

        switch (escolha_do_usuario) {

            case 1:
                break;
            
            case 2:
                break;
            
            case 3:
                break;
            
            case 4:
                break;
        
            default:
                std::cout << "Escolha apenas um dos 5 numeros na tela\n";
        }
    }

    return 0;
}