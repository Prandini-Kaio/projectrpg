#include <malloc.h>
#include "stdio.h"
#include "unistd.h"
#include "../../headers/tableH.h"
#include "../../headers/menusH.h"

int inTable;

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
            EntryTableMenu();
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
    TableList tableL = GetTableList();
    struct TableNo *aux;
    if(tableL.start == NULL) printf("SEM MESAS\n\n");
    aux = tableL.start;

    printf("\n===============================================\n");
    do{
        printf("\n-----------------------------------------------\n");
        printf("ID: %d\n"
               "    MESA: %s\n"
               "    MESTRE: %s", aux->table.id, &aux->table.tableTitle, &aux->table.masterName);
        aux = aux->next;
    } while (aux != tableL.start);
    printf("\n===============================================\n");
    printf("Qual o id da mesa que deseja entrar?\n");
    scanf("%d", &id);
    SetCurrentTable(id);
    inTable = 1;
    InTable();
//    printf("Aperte qualquer tecla para continuar\n");
//    getchar();
//    scanf("%*c");
}

void InTable(){
    Table curTable = GetCurrentTable();
    int op;
    printf("\n=================================================\n");
    printf("Bem vindo - %s", curTable.masterName);
    printf("\nO que deseja fazer?\n"
           "1 - Iniciar secao\n2 - Voltar");
    printf("\n=================================================\n");
    scanf("%d", &op);
    if(op == 1){
        InSection();
    }
}

void InSection(){
    Table curTable = GetCurrentTable();
    Section section;
    InsertNewSection(&curTable.sectionList, section);

    do{
        printf("\n--------------------%s--------------------\n", curTable.tableTitle);
        //printf("DATA: %s\n", gmtime(data1));
        printf("Data De Abertura: %s\n", asctime(curTable.sectionList.openSecDate));
        printf("Ultima Data De Abertura: %s\n", asctime(curTable.sectionList.end->section.lastOpenDate));
        scanf("%*c");
    }while (inTable);
}