#include <iostream>
#include <vector>

float saldo = 0;

struct item {
    std::string lanche;
    float preco;
};

std::vector<item> carrinho;

// Os valores aqui são apenas testes para demonstração
std::vector<item> cardapio {{"Brigadeiro", 1.2}, {"Bolo", 3.5}, {"Surpresa de Uva", 1.1}};

/* Funções para interface do cliente */

void adicionar_carrinho(std::string lanche, float preco) {
    item item_escolhido = {lanche, preco};
    carrinho.push_back(item_escolhido);
}

void mostrar_cardapio() {

    int escolher_lanche;

    while (true) {

        std::cout << "Saldo atual: " << saldo << "\n";

        std::cout << "=== CARDAPIO ===\n";
        for (int i = 0; i < cardapio.size(); i++) {
            std::cout << "[" << i + 1 << "] " << cardapio[i].lanche << " - " << cardapio[i].preco << "\n";
        }

        std::cout << "\nSelecione um dos itens para comprar o lanche, ou digite '0' para sair do cardápio\n"
                  << ">>> ";
        
        std::cin >> escolher_lanche;

        if (escolher_lanche == 0) {
            return;
        }

        if (!(1 <= escolher_lanche && escolher_lanche <= cardapio.size())) {
            std::cout << "O lanche que você busca não está aqui!\n";
        }
        else {
            std::cout << "item adicionado ao carrinho!\n";
            adicionar_carrinho(cardapio[escolher_lanche - 1].lanche, cardapio[escolher_lanche - 1].preco);
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

void confirmar_pedido() {
    float custo_total;
    for (int i = 0; i < carrinho.size(); i++) {
        custo_total += carrinho[i].preco;
    }

    if (saldo < custo_total) {
        std::cout << "Você não tem saldo o suficiente!\n";
    }
    else {
        std::cout << "item feito com sucesso!\n";
        saldo -= custo_total;
        carrinho.clear();
    }
}

void eliminar_pedido() {
    int eliminar_item;
    std::cout << "Insira um item para eliminar: ";
    std::cin >> eliminar_item;

    if (!(1 <= eliminar_item && eliminar_item <= carrinho.size())) {
        std::cout << "Não foi possível encontrar esse item!\n";
    }
    else {
        std::cout << "item Eliminado com sucesso!\n";
        carrinho.erase(carrinho.begin() + (eliminar_item - 1));
    }
}

void mostrar_carrinho() {
    std::cout << "=== CARRINHO ===\n";
    for (int i = 0; i < carrinho.size(); i++) {
        std::cout << "[" << i + 1 << "] " << carrinho[i].lanche << " ---> " << carrinho[i].preco << "\n";
    }
    std::cout << "===============\n";

    int escolha_do_usuario;

    while (escolha_do_usuario != 3) {

        std::cout << "[1] Confirmar pedido(s)\n"
                  << "[2] Eliminar pedido\n"
                  << "[3] Retornar ao menu\n"
                  << ">>> ";
        
        std::cin >> escolha_do_usuario;

        switch (escolha_do_usuario) {

            case 1:
                confirmar_pedido();
                break;
            
            case 2:
                eliminar_pedido();
                break;
            
            default:
                std::cout << "Selecione apenas as opções na tela\n";
                break;
        }
    }
}

void interface_cliente() {
    
    int escolha_do_usuario;

    while (escolha_do_usuario != 4) {
        std::cout << "=== Cantina ===\n"
                  << "[1] Cardápio\n"
                  << "[2] Inserir Saldo\n"
                  << "[3] Carrinho\n"
                  << "[4] Sair\n";

        std::cout << ">>> ";
        std::cin >> escolha_do_usuario;

        switch (escolha_do_usuario) {

            case 1:
                mostrar_cardapio();
                break;
            
            case 2:
                inserir_saldo();
                break;
            
            case 3:
                mostrar_carrinho();
                break;
        
            default:
                std::cout << "Escolha apenas um dos 4 numeros na tela\n";
        }
    }

}
// Bom dia pessoal

int main() {

    interface_cliente();

    return 0;
}
