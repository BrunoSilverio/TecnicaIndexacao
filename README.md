# Trabalho sobre Técnicas de Indexação
Projeto 2 de ERD-B

1º. Criar um arquivo binário, com pelo menos 50 registros, desordenados.

Os registros devem ter pelo menos 5 (cinco) campos, sendo:
- chave primária do tipo inteiro com 4 dígitos;
- campo nome/descrição – tipo string;
- campo passível de ser categorizado (4 ou 5 categorias) – tipo string;
- campo 4 – tipo real;
- campo 5 – qualquer tipo.
  
IMPORTANTE: não serve dados de alunos.

Esse arquivo pode ser criado em um programa independente.

2º. Programa objeto do trabalho:  criar índices e utilizar os métodos de busca.

 I - Índices exigidos:

  a) Considerando que o arquivo principal está desordenado, criar um índice denso ou exaustivo, contendo todas as chaves primárias e a posição relativa linear que o registro se encontra no arquivo. Utilizar qualquer método para a ordenação desse índice, pela chave primária;
  
  b) Tabela Invertida para a ordem alfabética do campo2 (string);
  
  c) Dois índices secundários – listas ligadas de cada uma das categorias. Um dos índices deve seguir a ordenação da chave primária e o outro pela ordem alfabética do campo2 (Tabela Invertida – item b);

IMPORTANTE: considerando que para o exercício o arquivo é pequeno, os índices podem estar gravados ou gerados todas as vezes que o programa for executado.

II – Execução do Programa:
  1) Menu:
  
    a. Consultar “um registro”:
    
    b. Alterar/Atualizar campo(s) de um registro (menos o campo chave primária):
    
    c. Eliminar um registro do arquivo:
    
    d. Inserir um registro no arquivo:

    e. Impressão:

