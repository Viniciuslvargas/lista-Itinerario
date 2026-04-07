#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

struct Parada {
    string nome;
    Parada* proximo;
    Parada* anterior;
};

struct Itinerario {
    int totalParadas;
    Parada* inicio;
    Parada* fim;
};

void inserirInicio(Itinerario &lista, string nome);
void inserirFim(Itinerario &lista, string nome);
void inserirPosicao(Itinerario &lista, string nome, int posicao);
void removerPrimeira(Itinerario &lista);
void removerUltima(Itinerario &lista);
void buscarParada(const Itinerario &lista, string termoBusca);
void listarIda(const Itinerario &lista);
void listarVolta(const Itinerario &lista);
void contarParadas(const Itinerario &lista);
void liberarItinerario(Itinerario &lista);

#endif