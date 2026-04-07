# Sistema de Itinerário de Ônibus

O sistema foi desenvolvido em **C++** e utiliza a estrutura de dados de **Listas Duplamente Encadeadas** para gerenciar as paradas de ônibus.

## Estrutura do Projeto

O projeto está dividido de forma modular para facilitar a manutenção e leitura:

- `include/list.h`: Arquivo de cabeçalho contendo a definição da estrutura do Nó (Parada) e da Lista (Itinerario).
- `src/list.cpp`: Implementação da lógica de todas as operações da lista duplamente encadeada.
- `tests/tests.cpp`: Script isolado para realizar uma bateria de testes automatizados nas operações da lista.
- `main.cpp`: Ponto de entrada do programa, contendo o menu interativo para o usuário final.

---

## Como Compilar e Executar (Ubuntu/Linux)

Certifique-se de ter o compilador `g++` instalado na sua máquina. Caso não tenha, instale com:
`sudo apt update && sudo apt install build-essential`

### Para rodar o Sistema Principal (Menu Interativo):
Na raiz do projeto, execute os comandos:
1. **Compilar:** `g++ main.cpp src/list.cpp -o itinerario`
2. **Executar:** `./itinerario`

### Para rodar a Bateria de Testes:
Na raiz do projeto, execute os comandos:
1. **Compilar:** `g++ tests/tests.cpp src/list.cpp -o testes_itinerario`
2. **Executar:** `./testes_itinerario`

---

## Pontos de Análise e Justificativa

### 1. Qual variação de lista foi escolhida (simplesmente encadeada, duplamente encadeada ou circular)?
Foi escolhida a **Lista Duplamente Encadeada**.

### 2. Por que essa estrutura é mais adequada para esse problema do que as demais? Justifique com base nas operações implementadas.
A lista duplamente encadeada é a estrutura mais eficiente para este cenário devido à exigência específica da operação de **"Listar rota em ordem inversa"**. Em uma lista simplesmente encadeada, percorrer a rota de trás para frente seria ineficiente, exigindo o uso de recursão, pilhas auxiliares ou múltiplas travessias. 

Com a lista duplamente encadeada, cada nó (parada) possui um ponteiro para a parada anterior (`anterior`), permitindo a travessia reversa de forma direta e eficiente. Além disso, a manutenção de um ponteiro para o final da lista (`fim`) torna as operações de **"Inserir parada no fim"** e **"Remover última parada"** extremamente rápidas, sem a necessidade de percorrer toda a estrutura desde o início.

### 3. Haveria algum cenário real (ex: linha circular de ônibus) em que outra variação de lista seria mais vantajosa? Explique.
Sim, em rotas de ônibus conhecidas como **linhas circulares**. Nesses trajetos, o ônibus não possui um "ponto final" definitivo onde a viagem termina e o veículo faz a volta; o último ponto do trajeto conecta-se naturalmente ao primeiro, formando um loop contínuo. 

Para modelar essa realidade física, uma **Lista Circular** (podendo ser simples ou duplamente encadeada) seria muito mais vantajosa. Em uma lista circular, o ponteiro `proximo` do último nó aponta de volta para o primeiro nó da lista. Isso facilita a simulação do trajeto contínuo do ônibus, permitindo que o sistema avance pelas paradas infinitamente sem precisar de uma lógica manual para reiniciar o percurso ao chegar ao fim.
