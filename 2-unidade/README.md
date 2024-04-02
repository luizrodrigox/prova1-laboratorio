Este código implementa um sistema simples de gerenciamento de contatos utilizando uma tabela hash para armazenar os contatos. A seguir, está uma breve explicação de cada parte do código:

  Estruturas de Dados:
        Contato: Estrutura que representa um contato com campos para nome, telefone, email e um ponteiro para o próximo contato na lista encadeada.
        ListaContatos: Estrutura que contém um array de ponteiros para contatos, servindo como a tabela hash.

  Funções Auxiliares:
        calcular_hash: Função que calcula o valor hash para uma determinada chave (neste caso, o nome do contato).
        inicializar_lista: Inicializa a lista de contatos com todos os ponteiros apontando para NULL.
        inserir_contato: Insere um novo contato na tabela hash.
        remover_contato: Remove um contato da tabela hash.
        buscar_contato: Busca um contato na tabela hash pelo nome.
        imprimir_contatos: Imprime todos os contatos presentes na tabela hash.

  Função main:
        Inicializa uma lista de contatos vazia.
        Lê os contatos de um arquivo chamado "todosOsContatos.txt" e insere-os na lista.
        Exibe um menu com opções para inserir, remover, buscar e imprimir contatos.
        O loop continua até que o usuário escolha a opção de sair (opção 0).

Dificuldades enfrentadas na Implementação:

   Dificuldade potencial, pode-se garantir que a função de hash distribua os elementos de forma uniforme na tabela. 
   Se a distribuição não for uniforme, pode ocorrer um número excessivo de colisões, o que afeta o desempenho da tabela hash.
   Além disso, o tratamento adequado de memória é crucial para evitar vazamentos de memória, especialmente ao lidar com alocações dinâmicas.
