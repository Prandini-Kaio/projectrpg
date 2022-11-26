#include <stdio.h>
#include <stdbool.h>

#include "headers/tableH.h"
#include "src/sqlTest.c"

//Variables
bool inProgram = true;
int inTable = 0;

void InitialMenu();
void TablesMenu();
void CreateTableMenu();
void EntryTableMenu();
void InTable();
void InSection();

TableList tableList;
Table currentTable;

int main() {

    do {
        InitialMenu();
    } while (inProgram);

    return 0;
}

void InitialMenu(){
    int op;
    printf("\n-----------------------------------------\n");
    printf("Bem vindo, o que deseja fazer?\n"
           "1 - Mesas");
    printf("\n-----------------------------------------\n");
    scanf("%d", &op);

    switch (op) {
        case 1://Mesas
            TablesMenu();
            break;
        case 2:
            printf("AA");
            break;
        default:
            printf("Default");
            break;
    }
}

void TablesMenu(){
    int op;
    printf("\n------------------MESA------------------\n");
    printf("\n"
           "1 - Criar Mesa 2 - Entrar em uma mesa");
    printf("\n----------------------------------------\n");
    scanf("%d", &op);

    switch (op) {
        case 1://Mesas
            CreateTableMenu();
            break;
        case 2:
            printf("Entrar em uma mesa");
            EntryTableMenu(&tableList);
            break;
        default:
            printf("Default");
            break;
    }
}

void CreateTableMenu(){
    char mestre[250];
    char title[250];

    printf("\n------------------CRIAR MESA------------------\n");
    printf("Mestre da mesa:\n");
    getchar();
    scanf ( "%[^\n]", mestre);
    getchar();
    printf("Titulo da mesa:\n");
    scanf ( "%[^\n]", title);
    printf("\n----------------------------------------------\n");
    SheetList sl;
    CreateTable(0, mestre, title,sl);
}

void EntryTableMenu(){
    int id;

    ShowTableList(&tableList);
    printf("Qual o id da mesa que deseja entrar?\n");
    scanf("%d", &id);
    currentTable = SearchTable(id, &tableList);
    inTable = 1;
    InTable();
}

void InTable(){
    int op;
    printf("\n=================================================\n");
    printf("\nO que deseja fazer?\n"
           "1 - Iniciar secao\n2 - Voltar");
    printf("\n=================================================\n");
    scanf("%d", &op);
    if(op == 1){
        InSection();
    }
}

void InSection(){
    do{
        printf("\n--------------------%s--------------------\n", currentTable.tableTitle);
        //printf("DATA: %s\n", gmtime(data1));
        printf("Data De Abertura: %s\n", asctime(currentTable.sectionList.openSecDate));
        fflush(stdout);
        printf("Ultima Data De Abertura: %s\n", asctime(currentTable.sectionList.end->section.lastOpenDate));
        scanf("%*c");
    }while (inTable);
}




