# Trabalho 1 – Classificação e Pesquisa de Dados

**Dupla:** Rhuan Lucas Barbosa Fernandes e Davi Santos Ferrarez

**Link para o GitHub:** [Repositório](https://github.com/RhuanLucass/cpd-trabalho01)

## 1. Introdução

### Bubble sort
O Bubble sort tem complexidade O(n²) e não é recomendado para grandes conjuntos de dados. Este algoritmo compara cada elemento com o próximo e os troca se estiverem fora de ordem. O loop continua até que todos os elementos estejam ordenados.

### Selection sort
Não é um algoritmo estável e possui complexidade O(n²) no melhor e pior caso. Consiste em encontrar o menor elemento e posicioná-lo na primeira posição, repetindo essa rotina para o restante do array.

### Insertion sort
O Insertion sort possui complexidade O(n²) e é eficiente para pequenos conjuntos. Ele compara o elemento atual com os antecessores, colocando-o em seu local adequado.

### Quicksort
Eficiente e baseado em divisão e conquista, mas não é estável. Complexidade O(n log n) no melhor e caso médio, O(n²) no pior. Usa um pivô para particionar o array.

### Merge sort
Complexidade O(n log n), eficiente para grandes entradas. Divide o vetor ao meio, recursivamente, e junta os subvetores ordenados.

### Heapsort
Instável, mas sempre O(n log n). Usa um heap binário para ordenar os elementos, mantido no próprio vetor.

## 2. Tabela

Foram utilizados 4 vetores de 25 mil elementos devido a limitações computacionais para totalizar a entrada sugerida de 100 mil.

| Vetores (Tam = 100000) | Bubble sort | Selection sort | Insertion sort | Quick sort | Merge sort | Heap sort |
| ----------------------- | ----------- | -------------- | -------------- | ---------- | ---------- | --------- |
| Aleatório               | 7.328 s     | 2.930 s        | 1.668 s        | 0.023 s    | 0.035 s    | 0.021 s   |
| Crescente               | 3.150 s     | 2.928 s        | 0.001 s        | 3.166 s    | 0.023 s    | 0.014 s   |
| Decrescente             | 6.043 s     | 2.972 s        | 3.292 s        | 3.157 s    | 0.016 s    | 0.014 s   |

## 3. Conclusão

O Bubble sort teve o pior desempenho no vetor aleatório devido ao grande número de comparações. Já o Heapsort foi o mais eficiente devido à sua estrutura de árvore binária.

No vetor crescente, o Insertion sort teve melhor desempenho, pois os elementos já estão ordenados. O pior foi o Quicksort devido à rotina de particionamento.

No vetor decrescente, o pior desempenho foi do Bubble sort e o melhor foi do Heapsort, novamente devido à sua estrutura de árvore binária.
