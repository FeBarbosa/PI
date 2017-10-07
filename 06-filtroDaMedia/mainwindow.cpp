#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_carregar_clicked()
{
    QFileDialog dialog;
    scene = new QGraphicsScene();

    dialog.exec();

    this->imagemOriginal = QImage(dialog.selectedFiles().first()); // Carrega a imagem para a variável imagemOriginal
    this->imagem = this->imagemOriginal; //faz uma copia da imagemOriginal para a variavel imagem
    QPixmap pixmap = QPixmap::fromImage(this->imagem);
    scene->addPixmap(pixmap);

    ui->imagem->setScene(scene);
}

void MainWindow::on_aplicar_clicked()
{
    media::filtroMedia(this->imagem); //aplica o filtro da media na imagem com uma mascara de 3x3 (vizinhança 3x3)

    QPixmap pixmap = QPixmap::fromImage(this->imagem);
    this->scene->clear();
    this->scene->addPixmap(pixmap);

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_limpar_clicked()
{
    this->scene->clear();

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_cinza_clicked()
{
    media::cinza(this->imagem); //conversao da imagem para niveis de cinza

    QPixmap pixmap = QPixmap::fromImage(this->imagem);
    this->scene->clear();
    this->scene->addPixmap(pixmap);

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_imgOriginal_clicked()
{
    this->imagem = this->imagemOriginal; // restaurar a imagem para a imagemOriginal

    QPixmap pixmap = QPixmap::fromImage(this->imagemOriginal);
    this->scene->clear();
    this->scene->addPixmap(pixmap);

    ui->imagem->setScene(this->scene);
}
