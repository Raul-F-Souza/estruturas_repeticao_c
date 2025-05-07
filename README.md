# Jogo "Adivinhe o Número" em C

Este projeto é um jogo simples escrito em linguagem C, onde o usuário precisa adivinhar um número aleatório entre 1 e 1000.  
Ele foi criado com fins didáticos para demonstrar o uso de **estruturas de repetição** em C (`while`, `do...while`, `for`).

## Funcionalidades

- Geração de número aleatório entre 1 e 1000
- Modo interativo com dicas para o jogador
- Contador de tentativas
- Versões com:
  - `while`
  - `do...while`
  - `for`

## Como compilar e executar

### Requisitos

- [GCC](https://gcc.gnu.org/) instalado no sistema
- Terminal (cmd, PowerShell, Bash, etc.)

### Compilação

```bash
gcc while.c -o jogo.exe
```

### Execução

```bash
./jogo.exe
```

> Substitua `while.c` pelo nome do arquivo desejado, como `for.c` ou `do_while.c`

## 🧠 Conceitos abordados

- Estruturas de repetição em C (`while`, `for`, `do...while`)
- Uso de funções (`main`, `gerarNumeroAleatorio`, `dicas`)
- Entrada e saída com `scanf` e `printf`
- Geração de números aleatórios com `rand()` e `srand()`

## 📂 Estrutura do Projeto

```
├── while.c         # Versão com while
├── for.c           # Versão com for
├── do_while.c      # Versão com do...while
└── README.md       # Documentação do projeto
```

## 🧷 Fonte do código base

Este projeto foi adaptado a partir do seguinte tutorial:

> [Como criar um jogo em C - C Progressivo](https://www.cprogressivo.net/2013/03/Como-criar-um-jogo-em-C-adivinhe-o-numero-que-o-computador-sorteou.html)
