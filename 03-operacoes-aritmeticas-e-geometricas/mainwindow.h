#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <iostream>
#include "geometrica.h"
#include "aritmetica.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage imagem1;
    QImage imagem2;

private slots:

    void on_carregarImg1_clicked();

    void on_carregarImg2_clicked();

    void on_aplicar_clicked();//Aplica o operação escolhida a(s) imagem(ns)

    void on_espelhamento_clicked();

    void on_soma_clicked();

    void on_subtracao_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
