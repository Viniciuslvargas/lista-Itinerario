#include <iostream>
#include <string>
#include "../include/list.h"

using namespace std;

int main() {
    cout << "--- INICIANDO BATERIA DE TESTES ---\n\n";
    Itinerario* testeRota = new Itinerario;
    testeRota->totalParadas = 0;
    testeRota->inicio = NULL;
    testeRota->fim = NULL;
    
    inserirInicio(*testeRota, "Ponto A");
    inserirFim(*testeRota, "Ponto C");
    inserirPosicao(*testeRota, "Ponto B", 2);
    
    cout << "\nTeste de Listagem (Deve ser A -> B -> C):\n";
    listarIda(*testeRota);
    
    cout << "\nTeste de Listagem Inversa (Deve ser C -> B -> A):\n";
    listarVolta(*testeRota);
    
    cout << "\nTeste de Remocao:\n";
    removerUltima(*testeRota); 
    listarIda(*testeRota);     
    
    cout << "\n";
    contarParadas(*testeRota); 
    
    cout << "\n--- FIM DOS TESTES ---\n";
    
    liberarItinerario(*testeRota);
    delete testeRota;

    return 0;
}