#include "mainwindow.h"
#include "ui_mainwindow.h"

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
void MainWindow::on_CarregarImg_clicked()
{
    QFileDialog dialog;

    dialog.exec();

    imagemOriginal = QImage(dialog.selectedFiles().first()); // Carrega a Imagem para a variável imagemOriginal

    this->imagem = imagemOriginal;

    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem));
}

// LIMPAR LABEL DA IMAGEM -------------------------------------------------------------------------
void MainWindow::on_LimparTela_clicked()
{
    this->imagem = QImage(ui->imagem->width(), ui->imagem->height(), QImage::Format_RGB32);
    this->imagem.fill(QColor(255, 255, 255));
    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem));
}
