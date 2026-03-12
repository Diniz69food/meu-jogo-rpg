#include <iostream>
#include <fstream>
#include <limits> // Necessário para a limpeza de erros
#include "Personagem.h"

int main() {
    Personagem heroi("Arthur, o Cavaleiro", 120, 25, 50);
    Personagem monstro("Dragao de PDS", 200, 15, 100);

    ofstream log("batalha.txt");
    log << "--- INICIO DA BATALHA ---\n";
    log.close();

    cout << "--- BEM-VINDO AO RPG DA UFMG ---" << endl;

    while (heroi.estaVivo() && monstro.estaVivo()) {
        heroi.mostrarStatus();
        monstro.mostrarStatus();

        cout << "\nSUA VEZ: (1) Atacar | (2) Usar Pocao | (3) Fugir: ";
        int acao;
        
        // --- TRAVA DE SEGURANÇA ---
        if (!(cin >> acao)) { // Se o usuário digitar algo que não é número
            cout << "⚠️ Erro: Digite apenas os numeros 1, 2 ou 3!" << endl;
            cin.clear(); // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o lixo digitado
            continue; // Volta para o início do turno
        }
        // ---------------------------

        if (acao == 1) {
            heroi.atacar(monstro);
        } else if (acao == 2) {
            heroi.usarItem(0);
        } else if (acao == 3) {
            cout << "🏃 Voce tentou fugir, mas o monstro bloqueou o caminho!" << endl;
        } else {
            cout << "Escolha invalida! Voce perdeu o turno se atrapalhando." << endl;
        }

        if (!monstro.estaVivo()) {
            cout << "\n🏆 O " << monstro.nome << " foi derrotado! Parabens!" << endl;
            break;
        }

        cout << "\n--- TURNO DO INIMIGO ---" << endl;
        monstro.atacar(heroi);

        if (!heroi.estaVivo()) {
            cout << "\n💀 Voce caiu em batalha... Fim de jogo." << endl;
        }
    }

    cout << "\n[DICA]: O log da luta foi salvo em 'batalha.txt'!" << endl;
    return 0;
}
