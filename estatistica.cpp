#include "estatistica.h"

Estatistica::Estatistica(QObject *parent) : QObject(parent)
{

}

void Estatistica::inserirDados(const Consumo a)
{
    estatistica.push_back(a);
}

float Estatistica::mediaConsumo()
{
    return std::accumulate(estatistica.begin(),estatistica.end(),0.0, [](float acc, Consumo a){return acc+=a.getConsumo();})/estatistica.size();
}

float Estatistica::totalConsumo()
{
    return std::accumulate(estatistica.begin(),estatistica.end(),0.0, [](float acc, Consumo a){return acc+=a.getConsumo();});
}

float Estatistica::totalValor()
{
    return std::accumulate(estatistica.begin(),estatistica.end(),0.0, [](float acc, Consumo a){return acc+=a.getValor();});
}

void Estatistica::ordenarPorConsumo()
{
    std::sort(estatistica.begin(), estatistica.end(), [](Consumo a, Consumo b){return a.getConsumo()>b.getConsumo();});
}

void Estatistica::ordenarPorValor()
{
    std::stable_sort(estatistica.begin(),estatistica.end(),[](Consumo a, Consumo b){return a.getValor()>b.getValor();});
}

int Estatistica::size()
{
    return estatistica.size();
}

void Estatistica::clear()
{
    estatistica.clear();
}

Consumo Estatistica::operator[](int i)
{
    return estatistica[i];
}
