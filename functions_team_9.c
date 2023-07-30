#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define L 10

void limpaInput()
{
    while (getchar() != '\n')
        ;
}

// "Inicia" o negrito
void bold()
{
    printf("\033[1;30m");
}

// Retira o negrito
void endbold()
{
    printf("\033[0m");
}

void introd()
{
    printf("\n**Bem Vindo!**\n");
    printf("*Neste programa o utilizador terá à sua disposição as diferentes funcionalidades,\nque serão aplicadas aos valores inseridos pelo utilizador:\n\n");
    printf("-> Cálculo da raíz quadrada de todos os elementos no vetor.\n");
    printf("-> Construção de uma matriz 10 por 10, em que cada linha é composta pelo vetor lido\n   e por permutações dos seus valores.\n");
    printf("-> Devolução dos valores em posições múltiplas de três do vetor.\n");
    printf("-> Devolução do vetor ordenado por ordem decrescente.\n");
    printf("-> Cálculo da multiplicação de todos os elementos no vetor por três.\n");
    printf("-> Identificação do máximo de todos os elementos do vetor.\n\n");
    bold();
    printf("*********************************************************************************************\n");
    printf("** ATENÇÃO! Os valores inseridos pelo utilizador, devem estar compreendidos entre 10 e 16. **\n");
    printf("*********************************************************************************************\n\n");
    endbold();

    do
    {
        printf("Prima enter para iniciar o procedimento.");
    } while (getchar() != '\n');
}

void RaizQuadrada(int *nums, int l)
{
    float raizes[L];

    printf("Estas são as Raízes Quadradas dos valores introduzidos pelo utilizador:\n");
    for (int i = 0; i < l; i++)
    {
        raizes[i] = nums[i];         //guarda valor no array
        raizes[i] = sqrt(raizes[i]); //faz a raiz quadrada do valor guardado no array
        printf("%.2f ", raizes[i]);  //imprime raiz quadrada do numero
    }
    printf("\n\n");
}

void MatrizPermutacoes(int *nums, int l)
{
    int i;

    printf("Matriz onde a primeira linha é composta pelos valores inseridos\ne as restantes por permutações dos mesmos:\n\n");
    for (i = 0; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n"); //Termina a primeira linha

    for (i = 1; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[0]); //Termina a segunda linha

    for (i = 2; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("%d %d\n", nums[0], nums[1]); //Termina a terceira linha

    for (i = 3; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("%d %d %d\n", nums[0], nums[1], nums[2]); //Termina a quarta linha

    for (i = 4; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]); //Termina a quinta linha

    for (i = 5; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("%d %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3], nums[4]); //Termina a sexta linha

    printf("%d %d %d %d ", nums[6], nums[7], nums[8], nums[9]);
    for (i = 0; i < l - 4; i++)
    {
        printf("%d ", nums[i]); //Termina a setima linha
    }
    printf("\n");

    printf("%d %d %d ", nums[7], nums[8], nums[9]);
    for (i = 0; i < l - 3; i++)
    {
        printf("%d ", nums[i]); //Termina a oitava linha
    }
    printf("\n");

    printf("%d %d ", nums[8], nums[9]);
    for (i = 0; i < l - 2; i++)
    {
        printf("%d ", nums[i]); //Termina a nona linha
    }
    printf("\n");

    printf("%d ", nums[9]); //Inicio da décima linha
    for (i = 0; i < l - 1; i++)
    {
        printf("%d ", nums[i]); //Chega ao fim da décima linha
    }
    printf("\n\n");
}

void MultiplosTres(int *nums, int l)
{
    printf("Estes são os valores em posições múltiplas de três do vetor:\n");
    for (int i = 0; i < l; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d\n", nums[i]);
        }
    }
    printf("\n\n");
}

void MostraOrdemDecrescente(int *nums, int l)
{
    int valor;

    printf("Estes são os valores, apresentados por ordem decrescente:\n");
    for (int i = 0; i < l; i++)
    {
        for (int e = i + 1; e < l; e++)
        {
            if (nums[i] < nums[e])
            {
                valor = nums[e];
                nums[e] = nums[i];
                nums[i] = valor;
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n\n");
}

void MultiplicarElementosPor3(int *nums, int l)
{
    int mult[L];

    printf("Estes são os valores, quando multiplicados por três:\n");
    for (int i = 0; i < l; i++)
    {
        mult[i] = nums[i];            //guarda valor no array
        mult[i] = mult[i] * 3;        //multiplica por 3 os valores guardados no array
        printf("%d ", mult[i]); //imprime numeros multiplicados por 3
    }
    printf("\n\n");
}

void Maximo(int *nums, int l)
{
    int tmpMax, max = 0;

    for (int i = 0; i < l; i++) // Vai percorrer todos os elementos do array.
    {
        tmpMax = nums[i];
        if (tmpMax > max) //Vai verificar qual é o maior de todos os números e guardar na variável max.
        {
            max = tmpMax;
        }
    }
    printf("O valor máximo dos números introduzidos é %d.\n\n",max);
}

void menuPrincipal()
{
    int op;
    int a;
    int nums[L];

    for (int i = 0; i < 10; i++)
    {
        
        printf("Por favor introduza 10 números inteiros entre 10 e 16:\n");
        if (scanf("%d", &a) != 1) //Para evitar aceitar letras, verifica se foi introduzido um número inteiro
        {
            limpaInput(); //Para consumir o lixo
            printf("Por favor introduza um valor válido.\n");
            i--;
        }
        else
        {
            if ((a >= 10) && (a <= 16))
            {
                nums[i] = a;
                system("clear");
            }
            else
            {
                printf("Por favor introduza um valor válido.\n");
                i--; //como se este não tivesse sido feito.
            }
        }
    }
    system("clear");
    do
    {
        printf("\t*____________Menu Príncipal____________*\n");
        printf("O que pretende fazer? Escolha uma das seguintes opções:\n\n");
        printf("1- Cálcular a raíz quadrada de todos os elementos inseridos.\n");
        printf("2- Construir uma matriz 10 por 10, em que cada linha é composta pelos valores recebidos e as restantes por permutações.\n");
        printf("3- Ver os valores em posições múltiplas de três do vetor.\n");
        printf("4- Ordenar os elementos do vetor por ordem decrescente.\n");
        printf("5- Cálcular a multiplicação de todos os elementos inseridos por 3.\n");
        printf("6- Identificar o máximo de todos os elementos.\n\n");
        printf("0- Sair.\n\n");
        printf("---> ");
        if (scanf("%d", &op) != 1) //Para evitar aceitar letras, verifica se foi introduzido um número inteiro
        {
            limpaInput(); //Para consumir o lixo
            continue;
        }

        switch (op)
        {
        case 1:
            system("clear");
            RaizQuadrada(nums, L);
            break;
        case 2:
            system("clear");
            MatrizPermutacoes(nums, L);
            break;
        case 3:
            system("clear");
            MultiplosTres(nums, L);
            break;
        case 4:
            system("clear");
            MostraOrdemDecrescente(nums, L);
            break;
        case 5:
            system("clear");
            MultiplicarElementosPor3(nums, L);
            break;
        case 6:
            system("clear");
            Maximo(nums, L);
            break;
        case 0: 
            printf("Obrigado e volte sempre.\n");
            //Termina o programa
            break;
        default:
            printf("Opção inválida! Por favor, insira um valor correto.\n\n\n");
            break;
        }
    } while (op != 0);
}