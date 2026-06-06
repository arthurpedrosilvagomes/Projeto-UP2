#include <iostream>
#include <vector>

float saldo = 0;

struct item {
    std::string lanche;
    float preco;
};

std::vector<item> carrinho;

void adicionar_item_cardapio() {
    item novo;

    std::cout << "Nome do lanche: ";
    std::cin.ignore();
    getline(std::cin, novo.lanche);

    std::cout << "Preco: ";
    std::cin >> novo.preco;

    cardapio.push_back(novo);

    std::cout << "Item adicionado com sucesso!\n";
}

void remover_item_cardapio() {

    for(int i = 0; i < cardapio.size(); i++) {
        std::cout << "[" << i + 1 << "] "
                  << cardapio[i].lanche
                  << " - R$" << cardapio[i].preco << "\n";
    }

    int opcao;
    std::cout << "Qual item deseja remover? ";
    std::cin >> opcao;

    if(opcao >= 1 && opcao <= cardapio.size()) {
        cardapio.erase(cardapio.begin() + (opcao - 1));
        std::cout << "Item removido!\n";
    }
}

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

void confirmar_item() {
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

void eliminar_item() {
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
                  << "[2] Eliminar \n"
                  << "[3] Retornar ao menu\n"
                  << ">>> ";
        
        std::cin >> escolha_do_usuario;

        switch (escolha_do_usuario) {

            case 1:
                confirmar_item();
                break;
            
            case 2:
                eliminar_item();
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
                break;
        }
    }
}

/* Funções para interface do servidor */

void interface_servidor() {
    
    int escolha_servidor;

    while (escolha_servidor != 2) {
        std::cout << "=== ADMINISTRAÇÃO ===\n"
                << "[1] Adicionar Item\n"
                << "[2] Remover Item\n"
                << "[3] Sair\n"
                << ">>> ";
        
        std::cin >> escolha_servidor;

        switch (escolha_servidor) {

        case 1:
            adicionar_item_cardapio();
            break;
        case 2:
            remover_item_cardapio();
            break;
        case 3:
            break;
        
        default:
            std::cout << "Insira apenas um dos valores apresentados!\n";
            break;
        }
    }
}

int main() {

    int escolha_usuario;

    while (escolha_usuario != 3) {
        std::cout << "=== ENTRAR COMO ===\n"
                  << "[1] Servidor\n"
                  << "[2] Cliente\n"
                  << "[3] Sair\n"
                  << ">>> ";
        
        std::cin >> escolha_usuario;

        switch (escolha_usuario) {
        
        case 1:
            interface_servidor();
            break;
        
        case 2:
            interface_cliente();
            break;

        default:
            std::cout << "Insira apenas os valores apresentados!";
            break;
        }
    }

    return 0;
}
