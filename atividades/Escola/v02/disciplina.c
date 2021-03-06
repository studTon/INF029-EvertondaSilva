#include <stdio.h>
#include "disciplina.h"
#include "professor.h"

/*Variáveis para auxiliar a contagem de disciplinas*/
int chaveValidarDisciplina;
int DisciplinasCadastradas = 0;
int disciplinasExcluidas = 0;
/*Registro das disciplinas*/
cadastroDisc disciplina[QTD_DE_DISC];

void menuDisc()
{
    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*       INFO DISCIPLINA      *\n");
        printf("******************************\n");
        /*menu disciplina*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Inserir disciplina\n");
        printf("2 - Excluir disciplina\n");
        printf("3 - Listar disciplinas\n::");

        scanf("%c", &escolha);
        while(getchar() != '\n');/*Pular o char new line No input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                inserirDisc();
            }break;
            case '2':
            {
                excluirDisc();
            }break;
            case '3':
            {
                listarDisciplinas();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
}

void inserirDisc()
{
    chaveValidarDisciplina = 0;
    printf("***Inserir disciplina***\n");
    //Gerar código
    gerarCodigoDaDisc(DisciplinasCadastradas);
    //Nome da disciplina
    NomeDaDisciplina();
    //Semestre da disciplina
    semestreDaDisciplina();
    //Nome do professor na disciplinar
    professorDaDisciplina();
    /*Validações dos campos inseridos*/
    validarNomeDisc(disciplina[DisciplinasCadastradas].NomeDisciplina);
    validarSemestre(disciplina[DisciplinasCadastradas].semestre);
    validarProfNaDisc(disciplina[DisciplinasCadastradas].professorDisciplina);
    
    /*Contar os cadastros com sucesso*/
    if(chaveValidarDisciplina == 4)
        DisciplinasCadastradas++;
}
/*######Funções para inserir os campos do cadastro da disciplina######*/
void NomeDaDisciplina()
{
    printf("Digite o Nome da disciplina: ");
    fgets(disciplina[DisciplinasCadastradas].NomeDisciplina, TAM_NoME_DISC, stdin);
}

void semestreDaDisciplina()
{
    printf("Digite o semestre da disciplina: ");
    scanf("%c", &disciplina[DisciplinasCadastradas].semestre);
    while(getchar() != '\n');
}

void professorDaDisciplina()
{
    printf("Digite o Nome do professor que ensina a disciplina: ");
    scanf("%[^\n]%*c", disciplina[DisciplinasCadastradas].professorDisciplina);
}
/*###################################################################*/
void gerarCodigoDaDisc(int inputIndiceDisc)
{
    inputIndiceDisc++;//+1 para inicializar a numeração do cadastro
    if(inputIndiceDisc <= QTD_DE_DISC)
    {
        if(disciplinasExcluidas > 0)
            inputIndiceDisc += disciplinasExcluidas;
         //Decomposição do inteiro para char
        char caracterCentena = (inputIndiceDisc / 100) + '0';
        char caracterDezena = ((inputIndiceDisc % 100) / 10) + '0';
        char caracterUnidade = (inputIndiceDisc % 10) + '0';
        //Formar a string do código
        int iContador = 0;
        while(iContador < TAM_CODIGO_DISC)
        {
            if(iContador == 0)
            {
                disciplina[DisciplinasCadastradas].codigo[iContador] = caracterCentena;
            }
            if(iContador == 1)
            {
                disciplina[DisciplinasCadastradas].codigo[iContador] = caracterDezena;
            }
            if(iContador == 2)
            {
                disciplina[DisciplinasCadastradas].codigo[iContador] = caracterUnidade;
            }
            iContador++;
        }
        if(iContador == 3)
            disciplina[DisciplinasCadastradas].codigo[iContador] = '\0';

        //Conclusão
        printf("***Codigo da disciplina: %s***\n", disciplina[DisciplinasCadastradas].codigo);   
    }
    else
    {
        printf("IMPOSSIVEL CADASTRAR MAIS DISCIPLINAS\n");
    }
    
}
void validarNomeDisc(char inputDisciplina[])
{
    int iContador = 0;
    int contadorCaracteresReais = 0;
    while(inputDisciplina[iContador] != '\0')
    {
		if((inputDisciplina[iContador] >= 'a'&&inputDisciplina[iContador] <= 'z')||(inputDisciplina[iContador] >= 'A'&&inputDisciplina[iContador] <= 'Z')||inputDisciplina[iContador] == ' ')
        {
            contadorCaracteresReais++;
        }
        iContador++;
	}
    if(contadorCaracteresReais == iContador - 1)
    {
        printf("NoME DA DISCIPLINA VALIDO\n");
        chaveValidarDisciplina++;
    }
    else
    {
        printf("NoME INVALIDO PARA A DISCIPLINA\n");
    }
}
void validarSemestre(char inputSemestre)
{
    if(inputSemestre >= '1' && inputSemestre <= '8')
    {
        printf("SEMESTRE VALIDO\n");
        chaveValidarDisciplina++;
    }
    else
    {
        printf("SEMESTRE INVALIDO\n");
    }
}

void validarProfNaDisc(char NomeProfessor[])
{   
    int professorEscolhido;
    int indiceProfessor = 0;
    int achou = 0;//0 - Não achou professor| 1 - Achou professor
    while(indiceProfessor <= DisciplinasCadastradas)
    {
        int iContador = 0;
        int caracteresIguais = 0;
        while(NomeProfessor[iContador] != '\0')
        {
            if(NomeProfessor[iContador] == professor[indiceProfessor].Nome[iContador])
            {
                caracteresIguais++;
            }
            iContador++;
        }
        if(caracteresIguais == iContador)
        {   
            achou = 1;
            professorEscolhido = indiceProfessor;
            break;
        }
        indiceProfessor++;
    }
    if(achou == 1)
    {
        printf("NoME DE PROFESSOR VALIDO: %s\n", professor[professorEscolhido].Nome);
        chaveValidarDisciplina++;
    }
    else
    {
        printf("NoME DE PROFESSOR INVALIDO\n");
    }
}

void excluirDisc()
{
    printf("****************************\n");
    char NomeDisciplinaExcluir[TAM_NoME_DISC];
    printf("Digite o Nome da disciplina que deseja excluir: ");
    fgets(NomeDisciplinaExcluir, TAM_NoME_DISC, stdin);
    int jContador;
    int indiceDaDisciplina = 0;
    int caracteresIguais;
    int achou = 0;//0 - Não achou|1 - Achou
    while(indiceDaDisciplina < DisciplinasCadastradas)
    {
        caracteresIguais = 0;
        jContador = 0;
        while(NomeDisciplinaExcluir[jContador] == disciplina[indiceDaDisciplina].NomeDisciplina[jContador])
        {
            jContador++;
            caracteresIguais++;
        }
        if(caracteresIguais == jContador)
        {
            achou = 1;
            printf("DISCIPLINA ENCONTRADA\n");
            DisciplinasCadastradas += excluirDiscNaLista(indiceDaDisciplina);
            disciplinasExcluidas += achou;
            break;
        }
        indiceDaDisciplina++;
    }
    if(achou == 0)
    {
        printf("DISCIPLINA NAO ENCONTRADA: Certifique-se do numero da disciplina\n");
    }

}
int excluirDiscNaLista(int indiceDisc)
{
    while(indiceDisc <= DisciplinasCadastradas)
    {
        //Nome disciplina
        int iContador = 0;
        while(disciplina[indiceDisc].NomeDisciplina[iContador] != '\0')
        {
            disciplina[indiceDisc].NomeDisciplina[iContador] = 0;
            iContador++;
        }
        //Código da disciplina
        iContador = 0;
        while(disciplina[indiceDisc].codigo[iContador] != '\0')
        {
            disciplina[indiceDisc].codigo[iContador] = 0;
            iContador++;
        }
        disciplina[indiceDisc].semestre = 0;//Semestre
        iContador = 0;
        //Nome de professor associado
        while(disciplina[indiceDisc].professorDisciplina[iContador] != '\0')
        {
            disciplina[indiceDisc].professorDisciplina[iContador] = 0;
            iContador++;
        } 
        indiceDisc++;
    }
    
    return -1;
}
void listarDisciplinas()
{
    printf("\nLista de disciplinas cadastradas\n*******************************\n\n");
    int indiceDisciplina = 0;
    while(indiceDisciplina < DisciplinasCadastradas)
    {
        printf("CODIGO: %s\n", disciplina[indiceDisciplina].codigo);
        printf("NoME DA DISCIPLINA: %s\n", disciplina[indiceDisciplina].NomeDisciplina);
        printf("SEMESTRE: %c\n", disciplina[indiceDisciplina].semestre);
        printf("PROFESSOR DA DISCIPLINA: %s\n", disciplina[indiceDisciplina].professorDisciplina);
        printf("*******************************\n");
        indiceDisciplina++;
    }
    printf("Listagem completa...\n\n");
}
