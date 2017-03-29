#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage imagem; //Imagem

private slots:
    void on_carregarImg_clicked();

    void on_limparTela_clicked();

    void on_obterHistograma_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
