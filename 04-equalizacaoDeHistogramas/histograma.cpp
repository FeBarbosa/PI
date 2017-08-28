#include "histograma.h"

histograma::histograma(int N):L(0), N(N){}

/**
    INFORMAÇÔES
        - Cinza;
        - Frequência;
        - Probabilidade;
        - Frequência Acumulada;
        - NOrmalizada.
*/

using parDeInteiros = std::pair<int, int>;

//Função de comparaçao para ordenar os valores pela frequência
bool comparacaoParaOrdenacao(std::vector<double> a, std::vector<double> b)
{
        return (a[0] < b[0]);
}

// Calcular histograma a apartir de uma imagem ----------------------------------------------------
void histograma::calcularFrequencia(const QImage& img)
{
    QColor cor;
    int cinzaAtual;

    std::map<int, int> aux;

    for(int i = 0; i < img.width(); i ++)
        for(int j = 0; j < img.height(); j++)
        {   
            cor = img.pixel(i, j);
            cinzaAtual = (cor.red() + cor.blue() + cor.green())/3;

            if(cinzaAtual > L)
                L = cinzaAtual;

            auto encontraCinza = aux.find(cinzaAtual);

            if(encontraCinza == aux.end()) //Se o tom de cinza não existir no set, o insira com frequência 1
            {
                aux.insert({cinzaAtual, 1});
            }
            else
            {
                encontraCinza->second++;
            }

        }

    for(auto it = aux.begin(); it != aux.end(); ++it)
    {
        this->tabela.push_back({(double)it->first, (double)it->second, 0.0, 0.0, 0.0});
    }

    std::sort(this->tabela.begin(), this->tabela.end(), comparacaoParaOrdenacao);
}

void histograma::normalizacao()
{
      for(int i = 0; i < (int)this->tabela.size(); i++)
      {
          this->tabela[i][2] = this->tabela[i][1]/N;

          if(i == 0)
              this->tabela[i][3] = this->tabela[i][2];
          else
              this->tabela[i][3] = this->tabela[i][2] + this->tabela[i-1][3];

          this->tabela[i][4] = (this->tabela[i][3])*L;
      }
}

void histograma::normalizacaoDaimagem(QImage& img)
{
    QColor cor;
    double aux;

    for(int i = 0; i < img.width(); i++)
    {
        for(int j = 0; j < img.height(); j++)
        {
            cor = img.pixel(i, j);
            aux = (cor.red() + cor.green() + cor.blue())/3;
            for(int k = 0; k < (int)this->tabela.size(); k++)
            {
                if(aux ==  this->tabela[k][0])
                {
                    aux = round(this->tabela[k][4]);
                    img.setPixel(i, j, QColor(aux,aux,aux).rgb());
                    break;
                }

            }

        }
    }
}


void histograma::mostrar()
{
    for(auto it1 = this->tabela.begin(); it1 != this->tabela.end(); ++it1)
    {
        for(auto it2 = it1->begin(); it2 != it1->end(); ++it2)
        {
            std::cout << *it2 << " ";
        }

        std::cout << std::endl;
    }
}
