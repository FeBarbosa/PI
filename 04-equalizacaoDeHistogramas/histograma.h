#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include <unordered_map>
#include <QImage>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

/**
    IDEIA: Usar um hashmap
        - Verificar quando se a chave já existe, então inseri-la ou incrementar o valor associado
*/

class histograma
{
public:
    histograma(int);

    int L;
    int N;

    std::vector<std::vector<double>> tabela;

    void calcularFrequencia(const QImage&);
    void normalizacao();
    void mostrar();
    void normalizacaoDaimagem(QImage&);
};

#endif // HISTOGRAMA_H
