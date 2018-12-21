#ifndef ESTATISTICA_H
#define ESTATISTICA_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "consumo.h"

class Estatistica : public QObject
{
    Q_OBJECT
private:
    QVector<Consumo> estatistica;
public:
    explicit Estatistica(QObject *parent = nullptr);
    void inserirDados(const Consumo a);
    float mediaConsumo();
    float totalConsumo();
    float totalValor();
    void ordenarPorConsumo();
    void ordenarPorValor();

    int size();
    void clear();

    Consumo operator[](int i);

signals:

public slots:
};

#endif // ESTATISTICA_H
