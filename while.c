#include <stdio.h> // Biblioteca padrão de entrada/saída (printf, scanf)
#include <time.h>  // Biblioteca para usar a função time() (semente para números aleatórios)

// Código adaptado a partir do tutorial disponível em:
// https://www.cprogressivo.net/2013/03/Como-criar-um-jogo-em-C-adivinhe-o-numero-que-o-computador-sorteou.html

int gerarNumeroAleatorio(); // Declaração da função que gera um número aleatório
void dicas(int palpite, int numero_aleatorio, int contador); // Declaração da função que dá dicas ao jogador

int main() 
{
    int continuar = 1; // Controla se o jogador quer continuar jogando (1 = sim, 0 = não)

    while (continuar != 0) { // Loop principal: Roda enquanto o jogador quiser continuar
        int numero_aleatorio = gerarNumeroAleatorio(); // Gera o número que o jogador deve adivinhar
        int palpite;         // Armazena o palpite (chute) do usuário
        int tentativas = 0;  // Conta quantas tentativas o usuário fez

        printf("Sorteando numero entre 1 e 1000...\n");
        printf("Comecou! Tente adivinhar o numero!\n\n");

        // Laço principal de tentativas usando while
        while (palpite != numero_aleatorio) { // Continua até o jogador acertar
            tentativas++; // Incrementa o número de tentativas
            printf("Tentativa %d: ", tentativas);
            scanf("%d", &palpite); // Lê o palpite do jogador
            dicas(palpite, numero_aleatorio, tentativas); // Chama função que informa dicas
        }

        // Pergunta se o usuário quer jogar de novo
        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &continuar); // Se digitar 0, sai do loop
    }
}

int gerarNumeroAleatorio() // Função que gera o número aleatório
{
    srand((unsigned)time(NULL));  // Inicializa o gerador com o tempo atual (evita repetição)

    return (1 + rand() % 1000);   // Retorna um número entre 1 e 1000
}

void dicas(int palpite, int numero_aleatorio, int contador) // Função que dá dicas ao jogador
{
    if (palpite > numero_aleatorio)
        printf("O numero sorteado e menor que %d\n\n", palpite); // Palpite foi alto demais
    else if (palpite < numero_aleatorio)
        printf("O numero sorteado e maior que %d\n\n", palpite); // Palpite foi baixo demais
    else
        printf("Parabens! Voce acertou o numero em %d tentativas!\n\n", contador); // Acertou!
            
}