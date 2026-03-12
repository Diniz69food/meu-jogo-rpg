#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>

using namespace std;

class Personagem {
private:
    int vidaMaxima;
public:
    string nome;
    int vida;
    int ataque;
    int mana;
    vector<string> inventario;

    Personagem(string n, int v, int a, int m);
    void atacar(Personagem &inimigo);
    void usarItem(int indice);
    void mostrarStatus();
    bool estaVivo();
    void adicionarItem(string item);
};

#endif