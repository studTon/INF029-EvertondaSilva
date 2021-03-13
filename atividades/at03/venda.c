#include <stdio.h>
#include "estoque.h"

/*Função para adicionar produtos na compra do cliente*/
void adicionar_produto(void)
{
    /*Lista de produtos em estoque*/
    estoqueproduto[0].codigo = 1010;
    estoqueproduto[0].nome = "PAPEL HIGIENICO";
    estoqueproduto[0].qtde = 95;
    estoqueproduto[0].preco = 12.99;
    estoqueproduto[1].codigo = 1011;
    estoqueproduto[1].nome = "CREME DENTAL";
    estoqueproduto[1].qtde = 63;
    estoqueproduto[1].preco = 7.99;
    estoqueproduto[2].codigo = 2000;
    estoqueproduto[2].nome = "DESINFETANTE";
    estoqueproduto[2].qtde = 16;
    estoqueproduto[2].preco = 18.99;
    estoqueproduto[3].codigo = 2010;
    estoqueproduto[3].nome = "AGUA SANITARIA";
    estoqueproduto[3].qtde = 29;
    estoqueproduto[3].preco = 6.99;
    estoqueproduto[4].codigo = 2025;
    estoqueproduto[4].nome = "LIMPA VIDROS";
    estoqueproduto[4].qtde = 51;
    estoqueproduto[4].preco = 20.99;
    estoqueproduto[5].codigo = 2080;
    estoqueproduto[5].nome = "DETERGENTE";
    estoqueproduto[5].qtde = 42;
    estoqueproduto[5].preco = 2.99;
    estoqueproduto[6].codigo = 3010;
    estoqueproduto[6].nome = "FARINHA DE TRIGO";
    estoqueproduto[6].qtde = 33;
    estoqueproduto[7].codigo = 3062;
    estoqueproduto[7].nome = "ACUCAR CRISTAL";
    estoqueproduto[7].qtde = 141;
    estoqueproduto[7].preco = 1.99;
    estoqueproduto[8].codigo = 3099;
    estoqueproduto[8].nome = "CHOCOLATE EM PO";
    estoqueproduto[8].qtde = 12;
    estoqueproduto[8].preco = 26.99;
    estoqueproduto[9].codigo = 4125;
    estoqueproduto[9].nome = "FILE DE PEITO DE FRANGO";
    estoqueproduto[9].qtde = 78;
    estoqueproduto[9].preco = 11.99;
    /*Fim da lista*/


    /*Adicionar produtos para venda ao cliente*/
    printf("==========================\n\tCompra\n==========================\n");
    int input_codigo;
    int op = 1;
    float totalCompra = 0;
    float valor;
    int qtdeItens;
    char *nomeProduto;
    while (op != 0)
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &input_codigo);
        switch(input_codigo)
        {
            case 1010:{
                nomeProduto = estoqueproduto[0].nome;
                valor = estoqueproduto[0].preco;
            }break;
            case 1011:{
                nomeProduto = estoqueproduto[1].nome;
                valor = estoqueproduto[1].preco;
            }break;
            case 2000:{
                nomeProduto = estoqueproduto[2].nome;
                valor = estoqueproduto[2].preco;
            }break;
            case 2010:{
                nomeProduto = estoqueproduto[3].nome;
                valor = estoqueproduto[3].preco;
            }break;
            case 2025:{
                nomeProduto = estoqueproduto[4].nome;
                valor = estoqueproduto[4].preco;
            }break;
            case 2080:{
                nomeProduto = estoqueproduto[5].nome;
                valor = estoqueproduto[5].preco;
            }break;
            case 3010:{
                nomeProduto = estoqueproduto[6].nome;
                valor = estoqueproduto[6].preco;
            }break;
            case 3062:{
                nomeProduto = estoqueproduto[7].nome;
                valor = estoqueproduto[7].preco;
            }break;
            case 3099:{
                nomeProduto = estoqueproduto[8].nome;
                valor = estoqueproduto[8].preco;
            }break;
            case 4125:{
                nomeProduto = estoqueproduto[9].nome;
                valor = estoqueproduto[9].preco;
            }break;
            default:{
                valor = 0;
            }break;
        }
        printf("Quantidade de itens?\n::");
        scanf("%d", &qtdeItens);
        valor *= qtdeItens;
        printf("%s X %d == %.2f\n", nomeProduto, qtdeItens, valor);
        totalCompra += valor;
        printf("Adicionar outro produto?\n0 - NAO\n1 - SIM\n::");
        scanf("%d", &op);
    }
    
    printf("\nTOTAL A PAGAR: R$ %.2f\n", totalCompra);
      
}