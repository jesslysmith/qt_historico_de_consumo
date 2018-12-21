#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "estatistica.h"
#include "consumo.h"

class gerenciadorDeArquivos
{
public:
    gerenciadorDeArquivos();
    static bool exportarDados(QString &arquivo, Estatistica &estatistica);
    static bool carregarDados(QString &arquivo, Estatistica &estatistica);
};

#endif // GERENCIADORDEARQUIVOS_H
