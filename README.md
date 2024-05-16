# Multiplicação de matrizes

Define três matrizes A, B e C, onde:

- A é uma matriz de dimensões M por K.
- B é uma matriz de dimensões K por N.
- C é a matriz resultante (A x B), de dimensões M por N.

Define uma estrutura ``ThreadArgs`` para passar argumentos para cada thread. Neste caso, a estrutura contém as coordenadas do elemento na matriz C que a thread deve calcular.

Define a função ``multiplyElement``, que é executada por cada thread. Esta função é responsável por calcular o produto de um único elemento de A por um único elemento correspondente de B e armazená-lo na posição correta da matriz C.

Na função principal, gera valores aleatórios nas matrizes A e B e as mostra.

Inicializa um relógio para medir o tempo de execução do código.

Cria um número de threads igual ao número total de elementos na matriz C. Cada thread é responsável por calcular um único elemento da matriz C.

As threads são criadas com base na função ``multiplyElement``, e cada thread recebe uma estrutura ``ThreadArgs`` contendo as coordenadas do elemento que ela deve calcular.

As threads são então unidas de volta ao thread principal usando ``pthread_join()``.

Finaliza o relógio e calcula o tempo total de execução.

Exibe a matriz resultante C, que contém o produto das matrizes A e B.
