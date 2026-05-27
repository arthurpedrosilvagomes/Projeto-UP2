#include <iostream>

int saldo = 50;

void cardapio() {
    std::string laches[9] = {"Pão de queijo", "Coxinha", "Pastel", "MiniPizza", "Brigadeido", "Surpresa de Uva", "Bolo", "Suco de laranja", "Suco de uva"};
    float precos[9] = {1.20, 2.10, 2.50, 2.35, 1.50, 2, 3.50, 1.20, 1.20};

    int escolher_lache;

    while (escolher_lache != -1) {
        for (int i = 0; i < 9; i++) {
            std::cout << "[" << i + 1 << "] " << laches[i] << " - " << precos[i] << "\n";
        }

        std::cout << "\nSelecione um dos itens para comprar o lanche, ou digite '-1' para sair do cardápio\n"
                  << ">>> ";
        
        std::cin >> escolher_lache;

        if (escolher_lache == -1) {
            return;
        }

        if (!(1 <= escolher_lache && escolher_lache <= 9)) {
            std::cout << "O lanche que você busca não está aqui!\n";
        }

        else if (saldo < precos[escolher_lache - 1]) {
            std::cout << "Você não tem saldo o suficiente!\n";
        }

        else {
            std::cout << "Compra feita com sucesso!\n";
            saldo = saldo - precos[escolher_lache - 1];
        }
    }
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
                cardapio();
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