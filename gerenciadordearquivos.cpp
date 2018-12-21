#include "gerenciadordearquivos.h"

gerenciadorDeArquivos::gerenciadorDeArquivos()
{

}

bool gerenciadorDeArquivos::exportarDados(QString &arquivo, Estatistica &estatistica)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<estatistica.size();i++){
        out << estatistica[i].getData_ant()<<","<<estatistica[i].getLeitura_ant()<<","<<estatistica[i].getData_atual()<<","<<estatistica[i].getLeitura_atual()<<","<<estatistica[i].getConsumo()<<","<<estatistica[i].getTarifa()<<","<<estatistica[i].getValor()<<"\n";
    }

    file.close();
    return true;
}

bool gerenciadorDeArquivos::carregarDados(QString &arquivo, Estatistica &estatistica)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Consumo a(dados[0],dados[1],dados[2],dados[3],dados[4],dados[5],dados[6].toFloat());
        estatistica.inserirDados(a);

    }
    return true;
}
