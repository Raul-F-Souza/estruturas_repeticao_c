#include <stdio.h> // Biblioteca padrão de entrada/saída (printf, scanf)
#include <time.h>  // Biblioteca para usar a função time() (semente para números aleatórios)

// Código adaptado a partir do tutorial disponível em:
// https://www.cprogressivo.net/2013/03/Como-criar-um-jogo-em-C-adivinhe-o-numero-que-o-computador-sorteou.html

int gerarNumeroAleatorio(); // Declaração da função que gera um número aleatório
void dicas(int palpite, int numero_aleatorio, int contador); // Declaração da função que dá dicas ao jogador

int main() {
    int continuar = 1; // Controla se o usuário quer jogar novamente (números diferentes de zero = sim, 0 = não)

    while (continuar != 0) { // Loop principal do jogo, repete enquanto o usuário quiser continuar
        int numero_aleatorio = gerarNumeroAleatorio(), // Gera um número aleatório e armazena em 'numero_aleatorio'
        limitador = 10, // Define o número máximo de tentativas
        palpite, // Armazena o palpite (chute) do usuário
        acertou = 0; // Indica se o jogador acertou (0 = não, 1 = sim)

        printf("Sorteando numero entre 1 e 1000...\n");
        printf("Voce tem 10 tentativas para adivinhar o numero!\n\n");

        // Laço com for limitado a 10 tentativas
        for (int tentativas = 1; tentativas <= limitador; tentativas++) {
            printf("Tentativa %d: ", tentativas);
            scanf("%d", &palpite); // Lê o palpite do jogador
            dicas(palpite, numero_aleatorio, tentativas);

            if (palpite == numero_aleatorio) {  // Se o jogador acertar:
                acertou = 1;     // Marca como verdadeiro
                break;           // Sai do loop
            }
        }

        if (!acertou) // Se acertou == 0
            printf("Suas tentativas acabaram. O numero era %d\n\n", numero_aleatorio);

        // Pergunta se o usuário quer jogar de novo
        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &continuar);  // Se digitar 0, sai do loop
    }

    return 0;
}

int gerarNumeroAleatorio() // Função que gera o número aleatório
{
    srand((unsigned)time(NULL));  // Inicializa o gerador com o tempo atual (evita repetição)

    return (1 + rand() % 1000);   // Retorna um número entre 1 e 1000
}

void dicas(int palpite, int numero_aleatorio, int contador) // Função que dá dicas ao jogador
{
    if (palpite > numero_aleatorio) // Ao comparar o palpite com o número retorna:
        printf("O numero sorteado e menor que %d\n\n", palpite); // Palpite foi alto demais
    else if (palpite < numero_aleatorio)
        printf("O numero sorteado e maior que %d\n\n", palpite); // Palpite foi baixo demais
    else
        printf("Parabens! Voce acertou o numero em %d tentativas!\n\n", contador); // Acertou!
            
}