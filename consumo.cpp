#include "consumo.h"

float Consumo::getLeitura_ant() const
{
    return leitura_ant;
}

void Consumo::setLeitura_ant(float value)
{
    leitura_ant = value;
}

float Consumo::getLeitura_atual() const
{
    return leitura_atual;
}

void Consumo::setLeitura_atual(float value)
{
    leitura_atual = value;
}

float Consumo::getTarifa() const
{
    return tarifa;
}

void Consumo::setTarifa(float value)
{
    tarifa = value;
}

QString Consumo::getData_ant() const
{
    return data_ant;
}

void Consumo::setData_ant(const QString &value)
{
    data_ant = value;
}

QString Consumo::getData_atual() const
{
    return data_atual;
}

void Consumo::setData_atual(const QString &value)
{
    data_atual = value;
}


float Consumo::getConsumo() const
{
    float consumo;

    consumo = leitura_atual - leitura_ant;

    return consumo;
}

float Consumo::getValor() const
{
    float valor;

    valor = (getConsumo() * tarifa)+23;

    return valor;
}

Consumo::Consumo()
{

}

Consumo::Consumo(QString da_ant, QString lei_ant, QString da_atual, QString lei_atual, QString c, QString t, float v)
{
    data_ant = da_ant;
    leitura_ant = lei_ant.toFloat();
    data_atual = da_atual;
    leitura_atual = lei_atual.toFloat();
    consumo = c.toFloat();
    tarifa = t.toFloat();
    valor = v;
}
