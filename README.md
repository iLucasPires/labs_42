<p align="center">
  <img src="https://pbs.twimg.com/profile_images/1143875559195316224/uZCilKE3_400x400.jpg" width="200" height="200" alt="42 logo">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Status-Incomplete-red.svg" alt="Status">
</p>

# Labs 4º Edição

**Note:** This repository is in portuguese, because it was made for a brazilian school, [42 São Paulo](https://www.42sp.org.br/).

## Índice

- [Desafio](#desafio)
- [Algoritmo de Huffman em C](#algoritmo-de-huffman-em-c)
- [Funcionamento](#funcionamento)
- [Benefícios](#benefícios)
- [Utilização](#utilização)
- [Instalação](#instalação)
- [Como usar](#como-usar)
- [Sobre o projeto](#sobre-o-projeto)

## Desafio

O desafio consiste no desenvolvimento de uma aplicação de análise e compressão de dados. Essa aplicação utilizará o algoritmo de compressão Huffman e poderá receber múltiplos dados onde, uma vez que comprimido deve ser descomprimido e coletar informações pertinentes para a análise do processo e dado.

Para isso, você criará dois programas: `encoder` e `decoder`. O encoder receberá o dado a ser comprimido e exibirá suas informações vindas do decoder. Já, o decoder descomprimirá o dado e irá enviá-lo ao encoder com suas informações, onde será exibido. Os programas devem se comunicar utilizando _shared memory operations_.

A linguagem C será utilizada para o desenvolvimento e não há bibliotecas externas permitidas.

- [x] criar um programa que receba um arquivo de texto e compacte-o utilizando o algoritmo de Huffman.
- [x] compartilhar informações entre os programas utilizando _shared memory operations_.
- [x] criar um programa que descompacte um arquivo compactado pelo encoder.
- [ ] exibir informações sobre o processo de compressão e descompressão.
- [ ] rebeber múltiplos arquivos de texto.
- [ ] melhorar a eficiência do algoritmo de Huffman.

## Funcionamento

O algoritmo de Huffman funciona através da criação de uma árvore binária com base nas frequências de ocorrência dos símbolos da mensagem a ser compactada. Cada símbolo é representado por um nó na árvore, e os caminhos até cada símbolo são utilizados como códigos de compressão. Os símbolos com maior frequência de ocorrência ficam mais próximos da raiz da árvore, enquanto os símbolos com menor frequência ficam mais distantes. Dessa forma, os códigos dos símbolos mais frequentes tendem a ser mais curtos, o que resulta em uma compressão mais eficiente.

## Benefícios

Aumento da eficiência de armazenamento de dados: a compactação de dados permite que mais informações sejam armazenadas em menos espaço, o que é especialmente útil para aplicações que lidam com grandes volumes de dados.

Redução de tempo de transmissão de dados: ao enviar dados compactados, menos tempo é gasto na transmissão, o que é benéfico para aplicações que lidam com dados em tempo real ou em larga escala.
Segurança de dados: a compactação de dados também pode ser usada como uma técnica de criptografia para proteger informações confidenciais.

## Utilização

Este algoritmo de Huffman pode ser utilizado em várias aplicações, tais como:

Compactação de arquivos: para reduzir o tamanho de arquivos de imagem, vídeo, música, entre outros.
Transmissão de dados: para aumentar a velocidade de transmissão de dados em redes.
Armazenamento de dados: para aumentar a eficiência do armazenamento em dispositivos de armazenamento.
Espero que essa informação adicional ajude a esclarecer o propósito e aplicações do projeto de algoritmo de Huffman em C. Se você tiver alguma outra dúvida, estou sempre aqui para ajudar.

## Instalação

1. Clone este repositório para sua máquina:

2. Entre na pasta 42Labs:

   ```bash
   cd 42Labs
   ```

3. Compile o código com o comando:

   ```bash
   make
   ```

## Como usar

Para usar o programa de compactação, use o seguinte comando:

- Encoder:

   O encoder recebe um arquivo de texto como argumento e compacta o arquivo.

   ```bash
   ./encoder <file>
   ```

- Decoder:

   O decoder só funciona se o encoder tiver sido executado antes, pois ele precisa do arquivo compactado gerado pelo encoder.

   ```bash
   ./decoder
   ```

## Sobre o projeto

### Este projeto foi construído em sete etapas

- **Fase 1 - Estudo:**
Neste passo, é realizada uma pesquisa para compreender o objetivo do projeto, os desafios enfrentados e as habilidades necessárias para completar a tarefa.

  - [Algoritmo de Huffman em C](https://www.youtube.com/playlist?list=PLqJK4Oyr5WShtxF1Ch3Vq4b1Dzzb-WxbP)
  - [huffman coding](https://www.programiz.com/dsa/huffman-coding)
  - [Shared Memory](https://www.youtube.com/watch?v=WgVSq-sgHOc&t=367s)

- **Fase 2 - Construção das principais estruturas de dados:**
   Nesta etapa, são criadas as estruturas fundamentais para o algoritmo, como a árvore Huffman e o mapa de símbolos.

- **Fase 3 - Entendendo Encode / Decode:**
   Nesta fase, as funções para codificar e decodificar os dados são implementadas. Nesta fase, as funções para codificar e decodificar os dados são implementadas. A codificação é feita através da utilização dos caminhos na árvore Huffman para representar cada símbolo, enquanto a decodificação consiste em percorrer a árvore para descobrir qual símbolo representa cada caminho.

- **Fase 4 - Compactando / Descompactando:**
   Neste passo, os dados são efetivamente compactados e descompactados. Neste passo, os dados são efetivamente compactados e descompactados. A compactação é feita através da substituição dos símbolos da mensagem original pelos códigos correspondentes na árvore Huffman, enquanto a descompactação é feita através da utilização do mapa de símbolos para recuperar os símbolos originais a partir dos códigos.

- **Fase 5 - Compartilhando memória:**
Nesta etapa, o algoritmo é otimizado para compartilhar memória entre as diferentes estruturas de dados. Nesta etapa, o algoritmo é otimizado para compartilhar memória entre as diferentes estruturas de dados, a fim de reduzir o consumo de memória e tornar o algoritmo mais eficiente.

- **Fase 6 - Aplicando Fase 3 e 4 no novo programa:**
Neste passo, as funções de codificação e decodificação são aplicadas em um novo programa. Neste passo, as funções de codificação e decodificação são aplicadas em um novo programa que irá utilizar o algoritmo de Huffman para compactar e descompactar dados.
