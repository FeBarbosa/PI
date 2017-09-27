#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->imagem1 = QImage(NULL);
    this->imagem2 = QImage(NULL);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Carregar a primeira imagem ----------------------------------------------------------------------
void MainWindow::on_carregarImg1_clicked()
{
    QFileDialog lerImagem; // Objeto para leitura de arquivo

    lerImagem.exec();

    this->imagem1 = QImage(lerImagem.selectedFiles().first()); // carrega a imagem selecionada para a imagem1

    this->ui->imagemMostrada->setPixmap(QPixmap::fromImage(this->imagem1)); //Define a label imagemMostrada com a imagem carrega
}

//Carregar a segunda imagem (Operações aritméticas) -----------------------------------------------
void MainWindow::on_carregarImg2_clicked()
{
    QFileDialog lerImagem; // Objeto para leitura em arquivo

    lerImagem.exec();

    this->imagem2 = QImage(lerImagem.selectedFiles().first()); // carrega a imagem selecionada para a imagem2
}

// Na operação de soma não é necessário o uso da segunda imagem -----------------------------------

// Na operação de subtração não é necessário o uso da segunda imagem

// Na operação de espelhamento é necessário o uso da segunda imagem

void MainWindow::on_aplicar_clicked()
{
    if(this->ui->soma->isChecked() && !this->imagem2.isNull())
    {//Aplica operação de soma sobre as imagens
        aritmetica::operacao(this->imagem1, this->imagem2, 1);
    }
    else if(this->ui->subtracao->isChecked() && !this->imagem2.isNull())
    {//Aplica operação de subtração sobre as imagens
        aritmetica::operacao(this->imagem1, this->imagem2, -1);
    }
    else if(this->ui->espelhamento->isChecked())
    {
        if(this->ui->tipoEspelha->currentIndex() == 0)
            geometrica::espelhamento(this->imagem1, true);
        else
            geometrica::espelhamento(this->imagem1, false);
    }

    this->ui->imagemMostrada->setPixmap(QPixmap::fromImage(this->imagem1));
}

// ------------------------------------------------------------------------------------------------
void MainWindow::on_espelhamento_clicked()
{
    if(this->ui->espelhamento->isChecked())
    {
        //Desativa a comboBox tipoEspelha
        this->ui->tipoEspelha->setEnabled(true);
        //Ativa a comboBox tipoEspelha
        this->ui->carregarImg2->setEnabled(false);
    }
}

// ------------------------------------------------------------------------------------------------
void MainWindow::on_soma_clicked()
{
    if(this->ui->soma->isChecked())
    {
        //Desativa a comboBox tipoEspelha
        this->ui->tipoEspelha->setEnabled(false);
        //Ativa a comboBox tipoEspelha
        this->ui->carregarImg2->setEnabled(true);
    }
}

// ------------------------------------------------------------------------------------------------
void MainWindow::on_subtracao_clicked()
{
    if(this->ui->subtracao->isChecked())
    {
        //Desativa a comboBox tipoEspelha
        this->ui->tipoEspelha->setEnabled(false);
        //Ativa a comboBox tipoEspelha
        this->ui->carregarImg2->setEnabled(true);
    }
}
