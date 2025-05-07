#include <stdio.h> // Biblioteca padrão de entrada/saída (printf, scanf)
#include <time.h>  // Biblioteca para usar a função time() (semente para números aleatórios)

// Código adaptado a partir do tutorial disponível em:
// https://www.cprogressivo.net/2013/03/Como-criar-um-jogo-em-C-adivinhe-o-numero-que-o-computador-sorteou.html

int gerarNumeroAleatorio(); // Declaração da função que gera um número aleatório
void dicas(int palpite, int numero_aleatorio, int contador); // Declaração da função que dá dicas ao jogador

int main() 
{
    int continuar = 1,     // Controla se o usuário quer jogar novamente (números diferentes de zero = sim, 0 = não)
        numero_aleatorio,  // Armazena o número sorteado aleatoriamente
        contador,          // Conta quantas tentativas o usuário fez
        palpite;           // Armazena o palpite (chute) do usuário

    do // Loop externo: roda o jogo até o usuário decidir parar
    {
        printf("Sorteando numero entre 1 e 1000...\n");
        numero_aleatorio = gerarNumeroAleatorio();  // Gera um número aleatório e armazena em 'numero_aleatorio'

        printf("Comecou! Tente adivinhar o numero!\n\n");
        contador = 0;      // Zera o contador de tentativas a cada nova rodada

        do // Loop interno: roda até o usuário acertar
        {
            contador++; // Incrementa o número de tentativas
            printf("Tentativa %d: ", contador); // Escreve para o usuário digitar o palpite o palpite do usuário
            scanf("%d", &palpite); // Lê o palpite do usuário

            dicas(palpite, numero_aleatorio, contador); // Chama a função que dá dicas com base no palpite
        }
        while (palpite != numero_aleatorio); // Continua até o número ser adivinhado corretamente

        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &continuar); // Se digitar 0, sai do loop
    }
    while (continuar); // Repete o jogo se o valor for diferente de 0

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