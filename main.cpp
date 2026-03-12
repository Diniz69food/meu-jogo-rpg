#include <iostream>
#include "Personagem.h"

int main() {
    Personagem heroi("Arthur, o Cavaleiro", 120, 25, 50);
    Personagem monstro("Dragao de PDS", 200, 15, 100);

    // Limpa o arquivo de log antigo
    ofstream log("batalha.txt");
    log << "--- INICIO DA BATALHA ---\n";
    log.close();

    cout << "--- BEM-VINDO AO RPG DA UFMG ---" << endl;

    while (heroi.estaVivo() && monstro.estaVivo()) {
        heroi.mostrarStatus();
        monstro.mostrarStatus();

        cout << "\nSUA VEZ: (1) Atacar | (2) Usar Pocao | (3) Fugir: ";
        int acao;
        cin >> acao;

        if (acao == 1) {
            heroi.atacar(monstro);
        } else if (acao == 2) {
            heroi.usarItem(0);
        } else {
            cout << "Voce tentou fugir, mas falhou!" << endl;
        }

        if (!monstro.estaVivo()) {
            cout << "\nO " << monstro.nome << " foi derrotado! Parabens!" << endl;
            break;
        }

        // Turno do Inimigo
        cout << "\n--- TURNO DO INIMIGO ---" << endl;
        monstro.atacar(heroi);

        if (!heroi.estaVivo()) {
            cout << "\nVoce caiu em batalha... O semestre acabou para voce." << endl;
        }
    }

    cout << "\n[DICA]: O resumo da luta foi salvo em 'batalha.txt'!" << endl;
    return 0;
}
