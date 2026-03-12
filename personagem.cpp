#include "Personagem.h"
#include <iostream>
#include <fstream> // Para gravar arquivos

Personagem::Personagem(string n, int v, int a, int m) {
    nome = n;
    vida = v;
    vidaMaxima = v;
    ataque = a;
    mana = m;
    inventario.push_back("Pocao de Cura");
}

void Personagem::atacar(Personagem &inimigo) {
    cout << "⚔️ " << nome << " desfere um golpe em " << inimigo.nome << "!" << endl;
    inimigo.vida -= ataque;
    if (inimigo.vida < 0) inimigo.vida = 0;

    // GRAVANDO NO LOG
    ofstream log("batalha.txt", ios::app);
    log << nome << " atacou " << inimigo.nome << " e deixou ele com " << inimigo.vida << " de HP.\n";
    log.close();
}

void Personagem::usarItem(int indice) {
    if (indice < inventario.size()) {
        cout << "🍷 Usando " << inventario[indice] << "..." << endl;
        vida += 40;
        if (vida > vidaMaxima) vida = vidaMaxima;
        inventario.erase(inventario.begin() + indice);
    }
}

void Personagem::mostrarStatus() {
    cout << "\n--- STATUS DE " << nome << " ---" << endl;
    cout << "HP: " << vida << "/" << vidaMaxima << " | MANA: " << mana << endl;
    cout << "MOCHILA: ";
    for(const auto& item : inventario) cout << "[" << item << "] ";
    cout << endl;
}

bool Personagem::estaVivo() {
    return vida > 0;
}