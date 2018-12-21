#ifndef CONSUMO_H
#define CONSUMO_H

#include <QObject>

class Consumo
{
private:
    QString data_ant;
    float leitura_ant;
    QString data_atual;
    float leitura_atual;
    float tarifa;
    float consumo;
    float valor;


public:
    explicit Consumo();
    Consumo(QString da_ant, QString lei_ant, QString da_atual, QString lei_atual, QString c, QString t, float v);

    float getLeitura_ant() const;
    void setLeitura_ant(float value);

    float getLeitura_atual() const;
    void setLeitura_atual(float value);

    float getTarifa() const;
    void setTarifa(float value);

    QString getData_ant() const;
    void setData_ant(const QString &value);

    QString getData_atual() const;
    void setData_atual(const QString &value);

    float getConsumo() const;

    float getValor() const;
};

#endif // CONSUMO_H
