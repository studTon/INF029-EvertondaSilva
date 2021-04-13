#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "utilitarios.h"
/*Registro*/
typedef struct
{
    char matricula[TAM_MATRICULA_PROF];
    char nome[TAM_NOME];
    char sexo;
    char dataNasc[TAM_DATA_NASC];
    char cpf[TAM_CPF];
}cadastroProfessor;

/*Registro*/
extern cadastroProfessor professor[QTD_DE_PROFS];

/*Vari�veis para auxiliar a contagem dos alunos*/
extern int chaveDeValidarProf;
extern int cadastrosComSucessoProf;
extern int cadastrosProfExcluidos;

/*Fun��es principais*/
void menuProf(void);
void inserirProf(void);
void excluirProf(void);
int excluirProfNaLista(int indiceProf);
void listarProf(void);
/*Fun��es para inserir os dados do professor*/
void inserirNomeProf(void);
void inserirSexoProf(void);
void inserirDataProf(void);
void inserirCpfProf(void);
/*Fun��es de Valida��o*/
void gerarMatriculaProf(int inputIndiceProf);
void validarNomeProf(char inputNome[]);
void validarCPFProf(char cpf[]);
void validarSexoProf(char sexo);
void validarNascProf(char data[]);
/**********************/
#endif