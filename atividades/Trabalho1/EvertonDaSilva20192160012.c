// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de An�lise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laborat�rio de Programa��o
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orienta��es gerais -----
//  Descri��o: esse arquivo deve conter as quest�es do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as quest�es do trabalho

//  ----- Dados do Aluno -----
//  Nome: Everton Souza da Silva
//  email: 20192160012@ifba.edu.br
//  Matr�cula: 20192160012
//  Semestre: 2021.1

//  Copyright � 2016 Renato Novais. All rights reserved.
// �ltima atualiza��o: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "EvertonDaSilva20192160012.h"
/*
## fun��o utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## fun��o utilizada para testes  ##

 fatorial = fatorial de um n�mero
@objetivo
    calcular o fatorial de um n�mero
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //fun��o utilizada para testes
    int fat = 1;
    if(x == 0 || x == 1)
        fat = 1;
    else
    {   
        fat = x;
        while(x > 1)
        {
            x--;
            fat *= x;
        }
    }
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = m�s, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inv�lida
    1 -> se data v�lida
 @restri��es
    N�o utilizar fun��es pr�prias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    int datavalida;
    int bomInput = 0;
    int tamData = 0;
    
    int contaCorretos = 0;
    while(data[tamData] != '/')
    {
        if(data[tamData] >= '0' && data[tamData] <= '9')
        {
            contaCorretos++;
        }
        tamData++;
    }

    if(contaCorretos >= 1 && contaCorretos <= 2)
    {
        bomInput++;
    }
    
    tamData++;
    contaCorretos = 0;
    while(data[tamData] != '/')
    {
        if(data[tamData] >= '0' && data[tamData] <= '9')
        {
            contaCorretos++;
        }
        tamData++;
    }
    if(contaCorretos >= 1 && contaCorretos <= 2)
    {
        bomInput++;
    }

    tamData++;
    contaCorretos = 0;
    while(data[tamData] != '\0' || tamData < 10)
    {
        if(data[tamData] >= '0' && data[tamData] <= '9')
        {
            contaCorretos++;
        }
        tamData++;
    }
    if(contaCorretos >= 2 && contaCorretos <= 4)
    {
        bomInput++;
    }
    
    contaCorretos = 0;
    tamData = 0;
    while( data[tamData] != '\0' || tamData < 10)
    {
        if (data[tamData] == '/' && (tamData >= 1 && tamData <= 5))
        {
            contaCorretos++;
        }
        tamData++;
    }

    if( contaCorretos == 2 )
    {
        bomInput++;
    }
    
    
    if(bomInput == 4)
    {
        int dataInt[3];
        
        dataInt[0] = decomporDataDia(data);
        dataInt[1] = decomporDataMes(data);
        dataInt[2] = decomporDataAno(data);
        
        datavalida = verificarData(dataInt);
    }    
    else
    {
        datavalida = 0; 
    }

    return datavalida;
}

int decomporDataDia(char data[])
{
    char dataDia[3];
    int dataInt;

    int iContador = 0;
    int jContador = 0;

    while( data[iContador] != '/' )
    {
        dataDia[jContador] = data[iContador];
        iContador++;
        jContador++;
    }
    dataDia[jContador] = '\0';
    if( jContador == 2 )
    {
        dataInt = (dataDia[0] - '0') * 10;
        dataInt += dataDia[1] - '0';    
    }
    else
        dataInt = dataDia[0] - '0';

    return dataInt;
}
int decomporDataMes(char data[])
{
    int dataInt;
    char dataMes[3];
    
    int iContador = 0;
    while(data[iContador] != '/') iContador++;
    iContador++;
    int jContador = 0;
    while( data[iContador] != '/')
    {
        dataMes[jContador] = data[iContador];
        iContador++;
        jContador++;
    }
    dataMes[jContador] = '\0';
    if( jContador == 2 )
    {
        dataInt = (dataMes[0] - '0') * 10;
        dataInt += dataMes[1] - '0';    
    }
    else
        dataInt = dataMes[0] - '0';
    
    return dataInt;
}

int decomporDataAno(char data[])
{
    char dataAno[5];
    int dataInt;
    int iContador = 0;
    int contaBarras = 0;
    while(contaBarras < 2)
    {
        if(data[iContador] == '/')
            contaBarras++;
        iContador++;
    }
    int jContador = 0;
    while( jContador < 4 || dataAno[jContador] != '\0')
    {
        dataAno[jContador] = data[iContador];
        iContador++;
        jContador++;
    }
    dataAno[jContador] = '\0';

    if( jContador == 3 )
    {
        dataInt = atoi(dataAno);
    }
    else   
    {
        dataInt = atoi(dataAno) + 2000;
    }
   
    return dataInt;
}

int verificarData(int arranjoData[]) /*Formato [0] == dia| [1] == m�s| [2] == ano*/
{
    
    int bissexto = 0;
    if((arranjoData[2] % 400 == 0) || ((arranjoData[2] % 4 == 0) && (arranjoData[2] % 100 != 0)))
    {
        bissexto = 1;
    }
    
    if
    (arranjoData[1] == 1||arranjoData[1] == 3||arranjoData[1] == 5||arranjoData[1] == 7||
     arranjoData[1] == 8||arranjoData[1] == 10||arranjoData[1] == 12)
    {
        if(arranjoData[0] >= 1 && arranjoData[0] <= 31)
            return 1;
        else
            return 0;
    }
    if
    (arranjoData[1] == 4||arranjoData[1] == 6||arranjoData[1] == 9||arranjoData[1] == 11)
    {
        if(arranjoData[0] >= 1 && arranjoData[0] <= 30)
            return 1;
        else
            return 0;
    }


    if(bissexto == 1)
    {
        if(arranjoData[1] == 2 && (arranjoData[0] >= 1 && arranjoData[0] <= 29))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    if(bissexto == 0)
    {
        if(arranjoData[1] == 2 && (arranjoData[0] >= 1 && arranjoData[0] <= 28))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

/*
 Q2 = diferen�a entre duas datas
 @objetivo
    Calcular a diferen�a em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Al�m disso, a fun��o tem tr�s par�metros qtdDias, qtdMeses e qtdAnos. Esses tr�s par�metros devem ser utilizados para guardar os resultados dos c�lculos. Na chamada da fun��o deve passar o valor -1 para os tr�s
 @saida
    1 -> c�lculo de diferen�a realizado com sucesso
    2 -> datainicial inv�lida
    3 -> datafinal inv�lida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas tr�s vari�veis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;

    /*mantenha o c�digo abaixo, para salvar os dados em 
    nos par�metros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se � uma pesquisa Case Sensitive ou n�o. Se isCaseSensitive = 1, a pesquisa deve considerar diferen�as entre mai�sculos e min�sculos.
        Se isCaseSensitive != 1, a pesquisa n�o deve  considerar diferen�as entre mai�sculos e min�sculos.
 @saida
    Um n�mero n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    //printf("local %s\n", setlocale(LC_ALL, ""));
    setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "");
    setlocale(LC_NUMERIC, "");
    //printf("%s\n", texto);
    //char l = '�'
    //printf("%c", l);
    int qtdOcorrencias = 0;
    
    if(isCaseSensitive == 1)
    {
        int iContador = 0;
        while( texto[iContador] != '\0')
        {
            /*####################################Vogais acentuadas###################################*/
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'a';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'A';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'e';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'E';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'i'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'I'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'o'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'O'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'u'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'U'; 
            }
            if(texto[iContador] == '�')
            {
                texto[iContador] = 'c';
            }
            if(texto[iContador] == '�')
            {
                texto[iContador] = 'C';
            }
            /*###########################################################################################*/
            
            if(texto[iContador] == c)
            {
                qtdOcorrencias++;
            }
            iContador++;
        }
    }
    else
    {
        int iContador = 0;
        while( texto[iContador] != '\0')
        {
            /*####################################Vogais acentuadas###################################*/
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'a';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'A';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'e';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'E';
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'i'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'I'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'o'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'O'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'u'; 
            }
            if(texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�'||texto[iContador] == '�')
            {
                texto[iContador] = 'U'; 
            }
            if(texto[iContador] == '�')
            {
                texto[iContador] = 'c';
            }
            if(texto[iContador] == '�')
            {
                texto[iContador] = 'C';
            }
            /*###########################################################################################*/
            
            if(c >= 'A' && c <= 'Z')
            {
                if(texto[iContador] == c || texto[iContador] == c + 32)
                {
                    qtdOcorrencias++;
                }
            }
            
            if(c >= 'a' && c <= 'z')
            {
                if(texto[iContador] == c || texto[iContador] == c - 32)
                {
                    qtdOcorrencias++;
                }
            }
            iContador++;
        }
    }
    //printf("qtd %d\n", qtdOcorrencias);
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorr�ncias de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que ir� guardar as posi��es de in�cio e fim de cada ocorr�ncia da palavra (strBusca) no texto base (texto).
 @saida
    Um n�mero n >= 0 correspondente a quantidade de ocorr�ncias encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e sa�da correspondente. Por exemplo, se tiver uma �nica ocorr�ncia, a posi��o 0 do vetor deve ser preenchido com o �ndice de in�cio do texto, e na posi��o 1, deve ser preenchido com o �ndice de fim da ocorrencias. Se tiver duas ocorr�ncias, a segunda ocorr�ncia ser� amazenado nas posi��es 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como h� uma ocorr�ncia da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o �ndice da posi��o no texto deve come�ar ser contado a partir de 1.
        O retorno da fun��o, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte n�mero
 @objetivo
    Inverter n�mero inteiro
 @entrada
    uma int num.
 @saida
    N�mero invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q5 = ocorr�ncia de um n�mero em outro
 @objetivo
    Verificar quantidade de vezes da ocorr�ncia de um n�mero em outro
 @entrada
    Um n�mero base (numerobase) e um n�mero de busca (numerobusca).
 @saida
    Quantidade de vezes que n�mero de busca ocorre em n�mero base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}
