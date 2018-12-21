#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExportar,SIGNAL(triggered()), this, SLOT(exportar()));
    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatistic()
{
    ui->lb_media->setText(QString::number(estatistica2.mediaConsumo(),'f',2));
    ui->lb_totalConsumo->setText(QString::number(estatistica2.totalConsumo(),'f',2));
    ui->lb_total->setText(QString::number(estatistica2.totalValor(),'f',2));
}

void MainWindow::inserirDadosNaTebela(Consumo consumo, int row)
{
    ui->tabela->setItem(row,0,new QTableWidgetItem(consumo.getData_ant()));
    ui->tabela->setItem(row,1,new QTableWidgetItem(QString::number(consumo.getLeitura_ant())));
    ui->tabela->setItem(row,2,new QTableWidgetItem(consumo.getData_atual()));
    ui->tabela->setItem(row,3,new QTableWidgetItem(QString::number(consumo.getLeitura_atual())));
    ui->tabela->setItem(row,4,new QTableWidgetItem(QString::number(consumo.getConsumo())));
    ui->tabela->setItem(row,5,new QTableWidgetItem(QString::number(consumo.getTarifa())));
    ui->tabela->setItem(row,6,new QTableWidgetItem(QString::number(consumo.getValor())));
}

void MainWindow::on_bt_inserir_clicked()
{

    if(ui->le_data_ant->text().size() != 0 && ui->le_leitura_ant->text().size() != 0 && ui->le_data_atual->text().size() != 0 && ui->le_leitura_atual->text().size() != 0 && ui->le_tarifa->text().size() != 0){
        Consumo consumo;

        consumo.setData_ant(ui->le_data_ant->text());
        consumo.setLeitura_ant(ui->le_leitura_ant->text().toFloat());
        consumo.setData_atual(ui->le_data_atual->text());
        consumo.setLeitura_atual(ui->le_leitura_atual->text().toFloat());
        consumo.setTarifa(ui->le_tarifa->text().toFloat());

        int qnt_row = ui->tabela->rowCount();

        ui->tabela->insertRow(qnt_row);

        inserirDadosNaTebela(consumo, qnt_row);

        ui->le_data_ant->clear();
        ui->le_leitura_ant->clear();
        ui->le_data_atual->clear();
        ui->le_leitura_atual->clear();
        ui->le_tarifa->clear();

        estatistica2.inserirDados(consumo);
        atualizarEstatistic();

    }
}

void MainWindow::on_bt_ordValor_clicked()
{
    ui->tabela->clearContents();

    estatistica2.ordenarPorValor();
    for(int i = 0; i<estatistica2.size(); i++){
        inserirDadosNaTebela(estatistica2[i], i);
    }
}

void MainWindow::on_bt_ordConsumo_clicked()
{
    ui->tabela->clearContents();
    estatistica2.ordenarPorConsumo();
    for(int i = 0; i<estatistica2.size();i++){
        inserirDadosNaTebela(estatistica2[i],i);
    }
}

void MainWindow::exportar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Historico de Consumo","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( gerenciadorDeArquivos::exportarDados(nomeArquivo,estatistica2) ){
        QMessageBox::information(this, "Salvar dados","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar dados","Não foi possível salvar os dados");
    }
}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Historico de Consumo","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    estatistica2.clear();

    if(gerenciadorDeArquivos::carregarDados(nomeArquivo,estatistica2)){

        ui->tabela->clearContents();
        for(int i=0;i<estatistica2.size();i++){

            if(i >= ui->tabela->rowCount())
                ui->tabela->insertRow(i);

            inserirDadosNaTebela(estatistica2[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar dados","Não foi possível carregar os dados");
    }
}
