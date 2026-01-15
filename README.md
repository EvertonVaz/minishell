# Minishell

Repositório para a criação do projeto Minishell da 42 São Paulo. Este projeto é uma implementação de um shell Unix minimalista desenvolvido em C, com o objetivo de replicar o funcionamento básico do Bash.

## 🚀 Funcionalidades Concluídas

- [x] Variáveis de ambiente
- [x] Tokenização (Lexer)
- [x] Análise sintática (Parser)
- [x] Árvore de Sintaxe Abstrata (AST)
- [x] Pipes (`|`)
- [x] Redirecionamentos (`>`, `>>`, `<`, `<<`)
- [x] Heredoc
- [x] Expansão de variáveis (`$VAR`)
- [x] Tratamento de sinais (Ctrl+C, Ctrl+\, Ctrl+D)
- [x] Builtins (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- [x] Gerenciamento de status de execução (`$?`)

## 🏗️ Arquitetura do Projeto

O código está organizado em módulos lógicos dentro do diretório [src/](src/):

1.  **Lexer & Tokenização**: Transforma a string de entrada em uma lista de tokens.
    *   Arquivos principais: [src/lexer/tokens.c](src/lexer/tokens.c) e [src/lexer/ft_strtok.c](src/lexer/ft_strtok.c).
2.  **Parser & AST**: Valida a sintaxe e constrói uma Árvore de Sintaxe Abstrata (AST) para definir a ordem de execução.
    *   Arquivos principais: [src/parser/parser.c](src/parser/parser.c) e [src/ast_construtor/ast.c](src/ast_construtor/ast.c).
3.  **Execução**: Percorre a AST e executa os comandos, gerenciamento de processos e pipes.
    *   Arquivos principais: [src/exec/exec.c](src/exec/exec.c), [src/exec/handle_pipe.c](src/exec/handle_pipe.c) e [src/exec/handle_and_or.c](src/exec/handle_and_or.c).
4.  **Redirecionamentos**: Manipula descritores de arquivo.
    *   Lógica em [src/redirect/redirect.c](src/redirect/redirect.c) e [src/redirect/heredoc.c](src/redirect/heredoc.c).
5.  **Builtins**: Comandos internos implementados no diretório [src/builtin/](src/builtin/).
6.  **Sinais**: Tratamento de interrupções em [src/signal/handle_signals.c](src/signal/handle_signals.c).

## 🛠️ Componentes de Apoio

*   **[Libft](libs/libft/)**: Biblioteca de funções utilitárias básica.
*   **Main**: O loop principal (REPL) reside em [src/main.c](src/main.c), utilizando a biblioteca `readline`.

## 💻 Compilação

O projeto utiliza um [Makefile](Makefile) para automação:

```sh
make        # Compila o executável minishell
make bonus  # Compila com funcionalidades de bônus (wildcards/operadores lógicos)
```

## 🧪 Testes

Para testes, existe um ambiente dedicado em [minishell_tester/](minishell_tester/).
