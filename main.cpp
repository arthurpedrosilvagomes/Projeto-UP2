#include <iostream>
#include <vector>

float saldo = 0;

struct pedido {
    std::string lanche;
    float preco;
};

std::vector<pedido> lista_de_pedidos;

void cardapio() {
    std::string lanches[9] = {"Pão de queijo", "Coxinha", "Pastel", "MiniPizza", "Brigadeido", "Surpresa de Uva", "Bolo", "Suco de laranja", "Suco de uva"};
    float precos[9] = {1.20, 2.10, 2.50, 2.35, 1.50, 2, 3.50, 1.20, 1.20};

    int escolher_lanche;

    while (escolher_lanche != -1) {

        std::cout << "Saldo atual: " << saldo << "\n";

        for (int i = 0; i < 9; i++) {
            std::cout << "[" << i + 1 << "] " << lanches[i] << " - " << precos[i] << "\n";
        }

        std::cout << "\nSelecione um dos itens para comprar o lanche, ou digite '-1' para sair do cardápio\n"
                  << ">>> ";
        
        std::cin >> escolher_lanche;

        if (escolher_lanche == -1) {
            break;
        }

        if (!(1 <= escolher_lanche && escolher_lanche <= 9)) {
            std::cout << "O lanche que você busca não está aqui!\n";
        }

        else if (saldo < precos[escolher_lanche - 1]) {
            std::cout << "Você não tem saldo o suficiente!\n";
        }

        else {
            std::cout << "Pedido Feito!\n";
            pedido lanche_escolhido;
            lanche_escolhido.lanche = lanches[escolher_lanche - 1];
            lanche_escolhido.preco = precos[escolher_lanche - 1];
            lista_de_pedidos.push_back(lanche_escolhido);
        }
    }
}

void inserir_saldo() {

    int escolher_saldo;

    int opcoes_saldo[3] = {10, 25, 50};

    while (escolher_saldo != -1) {
        for (int i = 0; i < 3; i++) {
            std::cout << "[" << i + 1 << "]" << "Inserir: " << opcoes_saldo[i] << "\n";
        }

        std::cout << "\nSelecione um dos itens para inserir o saldo, ou digite '-1' para voltar ao menu\n"
                  << ">>> ";
        
        std::cin >> escolher_saldo;

        if (escolher_saldo == -1) {
            break;
        }

        if (!(1 <= escolher_saldo && escolher_saldo <= 3)) {
            std::cout << "Essa opção não existe, tente um dos numeros presentes!\n";
        }

        else {
            std::cout << "Inserção de R$" << opcoes_saldo[escolher_saldo - 1] << ",00 feita com sucesso\n";
            saldo += opcoes_saldo[escolher_saldo - 1];
        }
    }
}

void pedidos() {
    std::cout << "=== Pedidos ===\n";
    for (int i = 0; i < lista_de_pedidos.size(); i++) {
        std::cout << "[" << i + 1 << "] " << lista_de_pedidos[i].lanche << " ---> " << lista_de_pedidos[i].preco << "\n";
    }
    std::cout << "===============\n";

    int escolha_do_usuario;

    std::cout << "[1] Confirmar pedidos\n"
              << "[2] Eliminar pedido\n"
              << "[3] Retornar ao menu\n"
              << ">>> ";
    
    std::cin >> escolha_do_usuario;

    float custo_total = 0;

    switch (escolha_do_usuario) {
    case 1:
        for (int i = 0; i < lista_de_pedidos.size(); i++) {
            custo_total += lista_de_pedidos[i].preco;
        }

        if (saldo < custo_total) {
            std::cout << "Você não tem saldo o suficiente!\n";
        }
        else {
            std::cout << "Pedido feito com sucesso!\n";
            saldo -= custo_total;
            lista_de_pedidos.clear();
        }
        break;
    
    case 2:
        int eliminar_pedido;
        std::cout << "Insira um pedido para eliminar: ";
        std::cin >> eliminar_pedido;

        if (!(1 <= eliminar_pedido && eliminar_pedido <= lista_de_pedidos.size())) {
            std::cout << "Não foi possível encontrar esse pedido!\n";
        }
        else {
            std::cout << "Pedido Eliminado com sucesso!\n";
            lista_de_pedidos.erase(lista_de_pedidos.begin() + (eliminar_pedido - 1));
        }
        break;
    }
}

int main() {

    int escolha_do_usuario;

    while (escolha_do_usuario != 4) {
        std::cout << "=== Cantina ===\n"
                  << "[1] Cardápio\n"
                  << "[2] Inserir Saldo\n"
                  << "[3] Pedidos\n"
                  << "[4] Sair\n";

        std::cout << ">>> ";
        std::cin >> escolha_do_usuario;

        switch (escolha_do_usuario) {

            case 1:
                cardapio();
                break;
            
            case 2:
                inserir_saldo();
                break;
            
            case 3:
                pedidos();
                break;
        
            default:
                std::cout << "Escolha apenas um dos 5 numeros na tela\n";
        }
    }

    return 0;
}