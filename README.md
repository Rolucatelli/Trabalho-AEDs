# Trabalho-AEDs
### Professor: Felipe Rey
### Curso: Ciência da Computação
### Semestre: 2º
### Alunos:
1. Aluno 1: Rodrigo Luis Gasparino Lucatelli
    - `Matrícula: 2023.1.08.019`
1. Aluno 2: João Felipe Martins Santana
    - `Matrícula: 2023.1.08.007`
1. Aluno 3: José Olavo Monteiro Travassos Pereira da Silva
    - `Matrícula: 2023.1.08.009`

### Linguagem: C
### Compilador: GCC
### Ambiente de Desenvolvimento: VSCode
### Sistema Operacional: Windows 10

O objetivo desse trabalho é fazer um programa que verifique um arquivo xml e retorne se ele é válido ou não. Para isso, utilizamos uma pilha para armazenar as tags de abertura e fechamento do arquivo xml. Caso a tag de fechamento não seja igual a tag de abertura, o arquivo não é válido. Caso a tag de fechamento seja igual a tag de abertura, a pilha é desempilhada e o programa continua a verificar o arquivo xml. Caso a pilha esteja vazia e ainda existam tags de fechamento, o arquivo não é válido. Caso a pilha não esteja vazia e não existam mais tags de fechamento, o arquivo não é válido. Caso a pilha esteja vazia e não existam mais tags de fechamento, o arquivo é válido.
