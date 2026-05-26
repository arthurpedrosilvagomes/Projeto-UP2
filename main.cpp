#include <iostream>

float saldo = 0;

void cardapio() {

    int escolha_do_usuário;

    std::string salgados[4] = {"Coxinha", "Pastel", "minipizza", "Pão de Queijo"};
    float precos_salgados[4] = {3.20, 5.10};
    
    std::string doces[4] = {"Bolo", "Brigadeiro", "Surpresa de uva", "Paçoca"};
    float precos_doces[4] = {5, 4.32, 2.20, 1.20};

    std::string sucos[4] = {"Acerola", "Abacaxi", "Maracujá", "Laranja"};
    float precos_sucos[4] = {1.50, 2.50, 3, 2.60};

    while (escolha_do_usuário != 4) {    

        std::cout << "=== Cardápio ===\n"
                << "[1] Salgados\n"
                << "[2] Doces\n"
                << "[3] Sucos\n"
                << "[4] Voltar ao menu principal\n";
        
        std::cout << ">>> ";
        std::cin >> escolha_do_usuário;

        int escolher_lanche;

        switch (escolha_do_usuário) {
        case 1:
            for (int i = 0; i < 2; i++) {
                std::cout << '[' << i + 1 << ']' << salgados[i] << ": " << precos_salgados[i] << "\n";
            }

            std::cout << ">>>";
            std::cin >> escolher_lanche;

            if (1 <= escolher_lanche && escolher_lanche <= 2) {
                std::cout << "Lache Comprado com sucesso!\n";
            }

            else if (saldo < precos_salgados[escolher_lanche - 1]) {
                std::cout << "Você não tem saldo suficiente\n";
            }

            else {
                std::cout << "Este item não está para venda!\n";
            }
            
            break;
        
        case 2:
            for (int i = 0; i < 3; i++) {
                std::cout << '[' << i + 1 << ']' << doces[i] << ": " << precos_doces[i] << "\n";
            }
            break;
        
        case 3:
            for (int i = 0; i < 4; i++) {
                std::cout << '[' << i + 1 << ']' << sucos[i] << ": " << precos_sucos[i] << "\n";
            }
            break;
        
        default:
            break;
        }
    }
}

int main() {

    int escolha_do_usuario;

    while (escolha_do_usuario != 5) {
        std::cout << "=== Cantina ===\n"
                  << "[1] Cardápio\n"
                  << "[2] Saldo\n"
                  << "[3] PROMOÇÃO!\n"
                  << "[4] Pedidos\n"
                  << "[5] Sair\n";

        std::cout << ">>> ";
        std::cin >> escolha_do_usuario;

        switch (escolha_do_usuario) {
        case 1:
            cardapio();
            break;
            
        case 2:
            break;
            
        case 3:
            break;
            
        case 4:
            break;
        
        default:
            break;
        }
    }

    return 0;
}