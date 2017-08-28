#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "histograma.h"

QImage imagemOriginal; // Guarda a imagem de entrada

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// CARREGAMENTO DA IMAGEM -------------------------------------------------------------------------
void MainWindow::on_carregarImg_clicked()
{
    QFileDialog dialog;

    dialog.exec();

    imagemOriginal = QImage(dialog.selectedFiles().first()); //carrega a imagem selecionada para a variável imagemOriginal

    this->imagem = imagemOriginal;

    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem));
}

// LIMPAR LABEL DA IMAGEM -------------------------------------------------------------------------
void MainWindow::on_limparTela_clicked()
{
    this->imagem = QImage(ui->imagem->width(), ui->imagem->height(), QImage::Format_RGB32); //Define a imagem com o tamanho da label de carregamento
    this->imagem.fill(QColor(255, 255, 255)); // Preenche a imagem com a cor branca
    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem)); //Define a tela com a imagem criada
}

void MainWindow::on_obterHistograma_clicked()
{
    histograma a = histograma(this->imagem.width()*this->imagem.height());

    a.calcularFrequencia(this->imagem);
    a.normalizacao();
    a.mostrar();
    a.normalizacaoDaimagem(this->imagem);
    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem));
}
