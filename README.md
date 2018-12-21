# Hist�rico de Consumo

### Resumo/Objetivos

Est� aplica��o tem como objeto fazer com que o usuario possa ter um hist�rico do seu consumo de energia e de quanto est� gastando com esse servi�o. Est� aplica��o � �til para que o usu�rio possa ter um controle financeiro melhor e que possa tomar decis�es baseadas no seu hist�rio mensal de gastos.

### Manual para uso da aplica��o desenvolvida em QT com finalidade de criar um hist�rico de consumo de energia 

A tela inicial da aplica��o (como mostra na figura abaixo) deve ser preenchida pelo usu�rio.

![](figuras/tela_inicial.JPG)

Esses dados podem ser encontrado em sua conta de energia. A figura abaixo, mostra os dados as serem preenchidos na aplica��o:

![](figuras/conta_de_energia.png)

Ap�s preenchido todos os dados, o usu�rio deve precionar o bot�o "Inserir Dados", para que a tebela seja preenchida e consequentemente calcular o seu consumo (KWh) e o valor aproximado de sua conta de energia.

OBS.: No valor aproximado, j� esta sendo somado os R$23,00 da contribui��o de servi�o de ilumina��o p�blica.

# Bot�es da p�gina inicial da Aplica��o

### Iserir Dados

Como j� mencionado acima, o bot�o Inserir Dados ap�s precionado, preenche a tabela com as informa��es do usu�rio.

### Ordenar por Valor

O bot�o "Ordenar por Valor" ap�s precionado ordena a tabela de dados de forma decrescente. Ou seja, do maior valor aproximado para o menor.

### Ordenar por Consumo

O bot�o "Ordenar por Consumo" ap�s precionado ordena a tabela de dados tamb�m de forma decrescente, por�m levando em considera��o o consumo. Ou seja, do maior Consumo para o menor.

Na figura abaixo temos um exemplo da fun��o Ordenar por Consumo:

![](figuras/ordenar_por_consumo.JPG)

# Aba de Estat�sticas

A aplica��o tamb�m conta com uma aba para mostrar as estat�sticas do turma.

![](figuras/tela_de_estatisticas.JPG)

Como pode ser visto na figura acima, a aba de estatisca conta com M�dia de Consumo (Calcula a m�dia dos consumos em KWh preenchidos na tabela), Total de Consumo (Soma todos os consumos em KWh preenchidos na tabela) e Total Pago (Soma de todos os valores aproximados preenchidos na tabela).

# Exportar e Carregar

Esta aplica��o tamb�m consta com as op��es de Exportar e Carregar arquivos. A op��o "Exportar" salva as informa��es que constam na tabela em um arquivo no formato txt e a op��o "Carregar" importa as informa��es que est�o em um arquivo salvo no seu Computador.

![](figuras/arquivo.png)
