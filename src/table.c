#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "../headers/tableH.h"

TableList tableList;
Table currentTable;

int idd = 0;
int currentTableID;

//Cria uma nova mesa e retorna ela
int CreateTable(int id, char masterName[250], char titleTable[200],SheetList sheetList){
    Table table;

    table.id = id + idd;
    strcpy(&table.masterName, masterName);
    strcpy(&table.tableTitle, titleTable);
    table.sheetList = sheetList;

    InsertTableList(&tableList, table);
    idd++;
    return 0;
}

//Mostra as informações da mesa
void ShowTable(Table table){
    Table *aux;
    aux = &table;
    printf("\n    -----------------------------------\n");
    printf("    \n"
           "        Mestre: %s\n"
           "        ID: %d\n",
           &aux->masterName, aux->id);
    printf("\n    -----------------------------------\n");
    aux = aux;
}

//Insere uma ficha na lista de fichas da mesa
int InsertTableList(TableList *tl, Table table){
    struct TableNo *aux;
    aux = (struct TableNo*)malloc(sizeof (struct TableNo));
    if(aux == NULL) return 0;//CASO O AUXILIAR SEJA NULO, NAO EXISTE LISTA
    if(tl->start == NULL){
        //data
        aux->table = table;
        //
        //Uma lista circular, então no fim, volta ao começo
        tl->start = aux;
        tl->end = aux;
        aux->next = tl->start;
        aux->previous = tl->end;
        return 1;
    }
    //data
    aux->table = table;
    //
    aux->previous = tl->end;
    tl->end->next = aux;
    aux->next = tl->start;
    tl->start->previous = aux;
    tl->end = aux;
    return 1;
}

Table SearchTable(int id){
    struct TableNo *aux;
    TableList tableL = GetTableList();
    aux = tableL.start;
    do{
        if(aux->table.id == id) return aux->table;
        aux = aux->next;
    } while (aux != tableL.start);
}

int SetCurrentTable(int id){
    int exists = TableExists(id);
    if(exists == 1) {
        currentTable = SearchTable(id);
    }
    else printf("ID NOT EXISTS");
}

Table GetCurrentTable(){
    return currentTable;
}

//Table List
int CreateTableList(TableList *tl){
    tl->start = NULL;
    tl->end = NULL;
}

//Mostra as fichas da mesa

void ShowTableList(){
    struct TableNo *aux;
    aux = tableList.start;
    do{
        ShowTable(aux->table);
        aux = aux->next;
    } while (aux != tableList.start);
}

int TableExists(int id){
    struct TableNo *aux;
    TableList tableList = GetTableList();
    aux = tableList.start;
    do {
        if(aux->table.id == id) return 1;
        aux = aux->next;
    } while (aux != tableList.start);
    return 0;
}

TableList GetTableList(){
    if(tableList.start == NULL) printf("EMPTY TABLE");
    return tableList;
}
