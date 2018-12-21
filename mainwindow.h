#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>

#include "gerenciadordearquivos.h"
#include "consumo.h"
#include "estatistica.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Estatistica estatistica2;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatistic();

private slots:
    void on_bt_inserir_clicked();

    void on_bt_ordValor_clicked();

    void on_bt_ordConsumo_clicked();

    void exportar();
    void carregar();

private:
    Ui::MainWindow *ui;
    void inserirDadosNaTebela(Consumo consumo, int row);


};
#endif // MAINWINDOW_H
