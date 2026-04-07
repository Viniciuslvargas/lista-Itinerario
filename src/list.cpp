#include "../include/list.h"
#include <iostream>
#include <string>

using namespace std;

void liberarItinerario(Itinerario &lista) {
    Parada* atual = lista.inicio;
    while (atual != NULL) {
        Parada* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
    lista.totalParadas = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}

void inserirInicio(Itinerario &lista, string nome) {
    Parada* novaParada = new Parada;
    novaParada->nome = nome;
    novaParada->anterior = NULL;
    novaParada->proximo = lista.inicio;

    if (lista.inicio != NULL) {
        lista.inicio->anterior = novaParada;
    } else {
        lista.fim = novaParada;
    }

    lista.inicio = novaParada;
    lista.totalParadas++;
    cout << "Parada '" << novaParada->nome << "' inserida no inicio.\n";
}

void inserirFim(Itinerario &lista, string nome) {
    Parada* novaParada = new Parada;
    novaParada->nome = nome;
    novaParada->proximo = NULL;
    novaParada->anterior = lista.fim;

    if (lista.fim != NULL) {
        lista.fim->proximo = novaParada;
    } else {
        lista.inicio = novaParada;
    }

    lista.fim = novaParada;
    lista.totalParadas++;
    cout << "Parada '" << novaParada->nome << "' inserida no fim.\n";
}

void inserirPosicao(Itinerario &lista, string nome, int posicao) {
    if (posicao <= 1) {
        inserirInicio(lista, nome);
        return;
    }
    if (posicao > lista.totalParadas) {
        inserirFim(lista, nome);
        return;
    }

    Parada* novaParada = new Parada;
    novaParada->nome = nome;

    Parada* atual = lista.inicio;
    for (int i = 1; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novaParada->proximo = atual->proximo;
    novaParada->anterior = atual;
    atual->proximo->anterior = novaParada;
    atual->proximo = novaParada;
    
    lista.totalParadas++;
    cout << "Parada '" << novaParada->nome << "' inserida na posicao " << posicao << ".\n";
}

void removerPrimeira(Itinerario &lista) {
    if (lista.inicio == NULL) {
        cout << "O itinerario ja esta vazio.\n";
        return;
    }

    Parada* temp = lista.inicio;
    cout << "Parada '" << temp->nome << "' removida do inicio.\n";

    if (lista.inicio == lista.fim) {
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL;
    }

    delete temp;
    lista.totalParadas--;
}

void removerUltima(Itinerario &lista) {
    if (lista.fim == NULL) {
        cout << "O itinerario ja esta vazio.\n";
        return;
    }

    Parada* temp = lista.fim;
    cout << "Parada '" << temp->nome << "' removida do fim.\n";

    if (lista.inicio == lista.fim) {
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.fim = lista.fim->anterior;
        lista.fim->proximo = NULL;
    }

    delete temp;
    lista.totalParadas--;
}

void buscarParada(const Itinerario &lista, string termoBusca) {
    if (lista.inicio == NULL) {
        cout << "O itinerario esta vazio.\n";
        return;
    }

    Parada* atual = lista.inicio;
    bool encontrada = false;
    int pos = 1;

    cout << "Resultados da busca por '" << termoBusca << "':\n";
    while (atual != NULL) {
        if (atual->nome.find(termoBusca) != string::npos) {
            cout << "- Posicao " << pos << ": " << atual->nome << "\n";
            encontrada = true;
        }
        atual = atual->proximo;
        pos++;
    }

    if (!encontrada) {
        cout << "Nenhuma parada encontrada contendo esse termo.\n";
    }
}

void listarIda(const Itinerario &lista) {
    if (lista.inicio == NULL) {
        cout << "O itinerario esta vazio.\n";
        return;
    }

    Parada* atual = lista.inicio;
    cout << "Rota (Ida): ";
    while (atual != NULL) {
        cout << "[" << atual->nome << "]";
        if (atual->proximo != NULL) cout << " -> ";
        atual = atual->proximo;
    }
    cout << "\n";
}

void listarVolta(const Itinerario &lista) {
    if (lista.fim == NULL) {
        cout << "O itinerario esta vazio.\n";
        return;
    }

    Parada* atual = lista.fim;
    cout << "Rota (Inversa): ";
    while (atual != NULL) {
        cout << "[" << atual->nome << "]";
        if (atual->anterior != NULL) cout << " -> ";
        atual = atual->anterior;
    }
    cout << "\n";
}

void contarParadas(const Itinerario &lista) {
    cout << "Total de paradas cadastradas: " << lista.totalParadas << "\n";
}