#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_carregar_clicked();

    void on_limpar_clicked();

    void on_aplicar_clicked();
    void ampliar();
    void reduzir();
private:
    Ui::MainWindow *ui;
    QImage imagem;
};

#endif // MAINWINDOW_H
