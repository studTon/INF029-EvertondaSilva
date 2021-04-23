// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de An�lise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laborat�rio de Programa��o
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orienta��es gerais -----
//  Descri��o: esse arquivo deve conter as quest�eses do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as quest�es do trabalho

//  ----- Dados do Aluno -----
//  Nome: Everton Souza da Silva
//  email: 20192160012@ifba.edu.br
//  Matr�cula: 20192160012
//  Semestre: 2021.1

//  Copyright � 2016 Renato Novais. All rights reserved.
// �ltima atualiza��o: 12/12/2017

// #################################################

int somar(int x, int y); //fun��o utilizada para testes
int fatorial(int x); //fun��o utilizada para testes
int q1(char *data);
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

/*Fun��es extras*/
//Q1 e Q2
int verificarData(int arranjoData[]);
int decomporDataDia(char data[]);
int decomporDataMes(char data[]);
int decomporDataAno(char data[]);
int anoBissexto(int arranjoData[]);
//Q2
int calcularDias(char *datainicial, char *datafinal);
int calcularMaiorData(char *datainicial, char *datafinal);