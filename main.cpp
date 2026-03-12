#include <iostream>
#include <string>

using namespace std;

// Classe que representa os lutadores do jogo
class Personagem {
public:
    string nome;
    int vida;
    int ataque;
    int pacoes;

    Personagem(string n, int v, int a) {
        nome = n;
        vida = v;
        ataque = a;
        pacoes = 1; 
    }

    void atacar(Personagem &inimigo) {
        cout << " -> " << nome << " atacou " << inimigo.nome << "!" << endl;
        inimigo.vida -= ataque;
        if (inimigo.vida < 0) inimigo.vida = 0;
    }

    void usarPocao() {
        if (pacoes > 0) {
            vida += 30;
            pacoes--;
            cout << " -> " << nome << " bebeu uma porcao! +30 de vida imediato." << endl;
        } else {
            cout << " -> Voces nao tem mais porcoes!" << endl;
        }
    }
};

int main() {
    Personagem heroi("Arthur", 100, 20);
    Personagem monstro("Goblin", 50, 15);

    cout << "=== MOTOR DE RPG SIMPLIFICADO ===" << endl;

    while (heroi.vida > 0 && monstro.vida > 0) {
        int escolha;
        cout << "\nStatus: " << heroi.nome << " [" << heroi.vida << " HP] | " 
             << monstro.nome << " [" << monstro.vida << " HP]" << endl;
        
        cout << "Escolha: (1) Atacar (2) Usar Porcao: ";
        cin >> escolha;

        if (escolha == 1) heroi.atacar(monstro);
        else heroi.usarPocao();

        if (monstro.vida <= 0) {
            cout << "\n[VITORIA] O monstro foi derrotado!" << endl;
            break; 
        }

        // Vez do Monstro
        monstro.atacar(heroi);

        if (heroi.vida <= 0) cout << "\n[DERROTA] Voce caiu em combate!" << endl;
    }

    return 0;
}