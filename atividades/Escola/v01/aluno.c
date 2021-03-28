#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#define CARACTER_DIA 3
#define CARACTER_MES 3
#define CARACTER_ANO 5
cadastroAluno aluno[100];
//menu Aluno
void menuAluno()
{
    /*Detecção de SO para SO a tela*/
    #if defined(WIN32)
        #define SO 1
    #endif
    if(SO == 1)
        system("cls");//Windows
    /**********************/

    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*         INFO ALUNO         *\n");
        printf("******************************\n");
        printf("\nEscolha uma opção a seguir:\n0 - Voltar\n1 - Cadastrar\n2 - Listar\n::");
        scanf("%c", &escolha);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                cadastrarAluno();
            }break;
            case '2':
            {
                //Listar alunos cadastrados
            }break;
        }
        /*Detecção de SO para SO limpar a tela*/
        if(SO == 1)
            system("cls");//Windows
        /**********************/
    }
    
}
//Geração de matrícula

int turma = 1;
void gerarMatricula(int inputIndiceAluno)
{
    int iContador = inputIndiceAluno;
    inputIndiceAluno++;
    if(inputIndiceAluno > 50)
    {
        turma++;
        inputIndiceAluno - 50;
    }
    //Decomposição do índice do aluno
    /*É necessário somar o char '0' a todos os valores inteiros na 
     *conversão de inteiro para char.*/
    char centenaAluno = (inputIndiceAluno / 100) + '0';
    char dezenaAluno = ((inputIndiceAluno % 100) / 10) + '0';
    char unidadeAluno = (inputIndiceAluno % 10) + '0';
    printf("centena: %c\ndezena: %c\nunidade: %c\n", centenaAluno, dezenaAluno, unidadeAluno);
    //Ano e semestre
    char ano[5] = "2021\0";
    char semestre = '1';
    //Decomposição da turma
    char dezenaTurma = (turma / 10) + '0';
    char unidadeTurma = (turma % 10) + '0';
    //Criação da string que representa a matrícula
    int contador = 0;
    while(contador < 13)
    {
        if(contador >= 0 && contador <= 3)
        {
            aluno[iContador].matricula[contador] = ano[contador];
        }
        if(contador == 4 || contador == 6 ||contador == 9)
        {
            aluno[iContador].matricula[contador] = '.';
        }
        if(contador == 5)
        {
            aluno[iContador].matricula[contador] = semestre;
        }
        if(contador == 7)
        {
            aluno[iContador].matricula[contador] = dezenaTurma;
        }
        else
	    {
            if(contador == 8)
                {
                    aluno[iContador].matricula[contador] = unidadeTurma;
                }
	    }    
        if(contador == 10)
        {
            aluno[iContador].matricula[contador] = centenaAluno;
        }
        else
        {
            if(contador == 11)
            {
                aluno[iContador].matricula[contador] = dezenaAluno;
            }
            else
            {
                if(contador == 12)
                {
                    aluno[iContador].matricula[contador] = unidadeAluno;
                }
            }
        }
    	contador++;
    }
    if(contador == 13)
        aluno[iContador].matricula[contador] = '\0';

    printf("MATRICULA GERADA: %s\n", aluno[iContador].matricula);

}
//Verificações da entrada de dados do cadastro
void validarNome(char inputNome[])
{   
    
    int tamanhoInputNome = 0;
    while(inputNome[tamanhoInputNome + 1] != '\0') tamanhoInputNome++;
    int tamanhoNomeReal = 0;
    int contador = 0;
    while(inputNome[contador] != '\0')
    {
        if(
        (inputNome[contador] >= 'a' && inputNome[contador] <= 'z')||
        (inputNome[contador] >= 'A' && inputNome[contador] <= 'Z')||
        (inputNome[contador] == ' '))
            tamanhoNomeReal++;
        contador++;
    }
    if(tamanhoInputNome == tamanhoNomeReal)
        printf("NOME VALIDO\n");
    else
        printf("ERRO: Nome invalido\n");
}
void validarCPF(char cpf[])
{
    /*Análise dos campo CPF*/
    int tamDoInput = 0;
    int contadorCaracterPonto = 0;
    int contadorCaracterHifen = 0;
    int contadorNumeros = 0;
    while(cpf[tamDoInput] != '\0')
    {
        if(cpf[tamDoInput] >= '0' && cpf[tamDoInput] <= '9' &&
        (tamDoInput != 3 && tamDoInput != 7 && tamDoInput != 11))
        {
            contadorNumeros++;
        }
        if(cpf[tamDoInput] == '.' && (tamDoInput == 3 || tamDoInput == 7))
        {
            contadorCaracterPonto++;
        }
        if(cpf[tamDoInput] == '-' && tamDoInput == 11)
        {
            contadorCaracterHifen++;
        }
        tamDoInput++;
    }
    int somaContadores = contadorCaracterHifen + contadorCaracterPonto + contadorNumeros;
    /*Conclusão*/
    if(somaContadores == 14)
    {
        printf("CPF VALIDO\n");
    }
    else
    {
        printf("ERRO: CPF invalido\n");
        //contaErros++;
    }
    
}
void validarSexo(char sexo)
{
    if(sexo == 'm'||sexo == 'M'||sexo == 'f'||sexo == 'F'||sexo == 'o'||sexo == 'o')
    {
        printf("SEXO VALIDO\n");
    }
    else
    {
        printf("ERRO: Sexo invalido\n");
    }
}
void validarNasc(char data[])
{
    int errosData = 0;
    /*Decomposição da data*/
    int tamDoInput = 0;
    int contaCaracterBarra = 0;
    int contaDiaNumero = 0;
    int contaMesNumero = 0;
    int contaAnoNumero = 0;
    while(data[tamDoInput] != '\0')
    {
        if(tamDoInput != 2 && tamDoInput != 5)
        {
            if(tamDoInput < 2)
            {
                if(data[tamDoInput] >= '0' && data[tamDoInput] <= '9')
                    contaDiaNumero++;
            }
            if(tamDoInput > 2 && tamDoInput < 5)
            {
                if(data[tamDoInput] >= '0' && data[tamDoInput] <= '9')
                    contaMesNumero++;
            }
            if(tamDoInput > 5 && tamDoInput < 10)
            {
                if(data[tamDoInput] >= '0' && data[tamDoInput] <= '9')
                    contaAnoNumero++;
            }
        }
        if (tamDoInput == 2 || tamDoInput == 5 && data[tamDoInput] == '/')
        {
            contaCaracterBarra++;
        }
        tamDoInput++;
    }

    if(contaDiaNumero != 2||contaMesNumero != 2||contaAnoNumero != 4||contaCaracterBarra != 2)
        errosData++;
    else
    {
        /*Aquisição das partes da data*/
            char diaChar[CARACTER_DIA];
            char mesChar[CARACTER_MES];
            char anoChar[CARACTER_ANO];

            //dia
            int iContador = 0;
            int jContador = 0;
            while (jContador < CARACTER_DIA - 1)
            {
                diaChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            diaChar[jContador] = '\0';
            //mês
            jContador = 0;
            iContador++;
            while (jContador < CARACTER_MES - 1)
            {
                mesChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            mesChar[jContador] = '\0';
            //ano
            jContador = 0;
            iContador++;
            while (jContador < CARACTER_ANO - 1)
            {
                anoChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            anoChar[jContador] = '\0';

        /*Conversão para inteiros*/
        //Conversão da string dia
        int indiceDoAlgarismo = 0;
        int diaData = 0;
        while (indiceDoAlgarismo < CARACTER_DIA - 1)
        {   
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    diaData += (diaChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 1:{
                    diaData += (diaChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }
        
        //Conversão da string mês
        int mesData = 0;
        indiceDoAlgarismo = 0;
        while(indiceDoAlgarismo < CARACTER_MES - 1)
        {
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    mesData += (mesChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 1:{
                    mesData += (mesChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }
        
        //Conversão da string ano
        int anoData = 0;
        indiceDoAlgarismo = 0;
        while(indiceDoAlgarismo < CARACTER_ANO - 1)
        {
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 1000;
                }break;
                case 1:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 100;
                }break;
                case 2:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 3:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }

        /*Verificação de ano bissexto*/
        int bissexto = 0; //0 - Comum | 1 - Bissexto
        if(anoData % 400 == 0)
            bissexto = 1;
        else
            if(anoData % 4 == 0 && (anoData % 100 != 0))
            {
                bissexto = 1;
            }

        /*Verificação da data conforme calendário*/
        if(bissexto == 1)
        {   
            //Meses
            if(mesData < 1 || mesData > 12)
                errosData++;
            //Dias                
            if(mesData == 1||mesData == 3||mesData == 5||mesData == 7||
            mesData == 8||mesData == 10||mesData == 12)
                if(diaData < 1 || diaData > 31)
                    errosData++;
            if(mesData == 4||mesData == 6||mesData == 9||mesData == 11)
                if(diaData < 1 || diaData > 30)
                    errosData++;
            if(mesData == 2 && (diaData < 1 || diaData > 29))
                errosData++;
        }
        else
        {
            //Meses
            if(mesData < 1 || mesData > 12)
                errosData++;
            //Dias
            if(mesData == 1||mesData == 3||mesData == 5||mesData == 7||
            mesData == 8||mesData == 10||mesData == 12)
                if(diaData < 1 || diaData > 31)
                    errosData++;
            if(mesData == 4||mesData == 6||mesData == 9||mesData == 11)
                if(diaData < 1 || diaData > 30)
                    errosData++;
            if(mesData == 2 && (diaData < 1 || diaData > 28))
                errosData++;
        }
    }
    

    /*Conclusão da validação*/
    if (errosData == 0)
    {
        printf("DATA VALIDA\n");
    }
    else
    {
        printf("ERRO: Data invalida\n");
    }
}
//Cadastrar aluno
void cadastrarAluno()
{
    int iContador = 0;
    printf("***Cadastrar aluno***\n");
    if(iContador > 50)
        iContador = 0;
    //Matrícula
    /*Gerar matrícula*/        
    gerarMatricula(iContador);
    //Nome
    printf("Digite o nome do(a) estudante: ");
    fgets(aluno[iContador].nome, sizeof(aluno[iContador].nome), stdin);
    /****Remover o new line*/
    int tamanhoDoInput = 0;
    while(aluno[iContador].nome[tamanhoDoInput] != '\0') tamanhoDoInput++;
    if(aluno[iContador].nome[tamanhoDoInput] == '\n')
        aluno[iContador].nome[tamanhoDoInput] = '\0';
    //Sexo
    printf("Digite o sexo do(a) estudante(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%c%*c", &aluno[iContador].sexo);
    
    //Data de nascimento
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    scanf("%11[^\n]%*c", &aluno[iContador].dataNasc);
    //CPF
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    scanf("%[^\n]%*c", &aluno[iContador].cpf);
    /*Validações*/
    validarNome(aluno[iContador].nome);
    validarSexo(aluno[iContador].sexo);
    validarNasc(aluno[iContador].dataNasc);
    validarCPF(aluno[iContador].cpf);
    /*Detecção de SO para pausar*/
    if(SO == 1)
        system("pause");//Windows
    /**********************/
}