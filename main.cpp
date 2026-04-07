#include <iostream>
#include <string>
#include "include/list.h"

using namespace std;

int main() {
    Itinerario* rota = new Itinerario;
    rota->totalParadas = 0;
    rota->inicio = NULL;
    rota->fim = NULL;

    int opcao;
    string nome;
    int posicao;

    do {
        cout << "\n--- SISTEMA DE ITINERARIO DE ONIBUS ---\n";
        cout << "1. Inserir parada no inicio\n";
        cout << "2. Inserir parada no fim\n";
        cout << "3. Inserir parada por posicao\n";
        cout << "4. Remover primeira parada\n";
        cout << "5. Remover ultima parada\n";
        cout << "6. Buscar parada por nome\n";
        cout << "7. Listar rota completa (ida)\n";
        cout << "8. Listar rota em ordem inversa\n";
        cout << "9. Contar paradas\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue; 
        }
        cin.ignore(); 

        switch (opcao) {
            case 1:
                cout << "Nome da parada: ";
                getline(cin, nome);
                inserirInicio(*rota, nome);
                break;
            case 2:
                cout << "Nome da parada: ";
                getline(cin, nome);
                inserirFim(*rota, nome);
                break;
            case 3:
                cout << "Nome da parada: ";
                getline(cin, nome);
                cout << "Posicao desejada (1 para inicio): ";
                cin >> posicao;
                cin.ignore();
                inserirPosicao(*rota, nome, posicao);
                break;
            case 4:
                removerPrimeira(*rota);
                break;
            case 5:
                removerUltima(*rota);
                break;
            case 6:
                cout << "Digite o nome ou parte do nome da parada: ";
                getline(cin, nome);
                buscarParada(*rota, nome);
                break;
            case 7:
                listarIda(*rota);
                break;
            case 8:
                listarVolta(*rota);
                break;
            case 9:
                contarParadas(*rota);
                break;
            case 0:
                cout << "Encerrando o sistema...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 0);

    liberarItinerario(*rota);
    delete rota;

    return 0;
}