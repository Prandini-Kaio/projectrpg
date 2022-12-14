#ifndef RPGHELPER_TABLEH_H
#define RPGHELPER_TABLEH_H
#include "./sheetH.h"
#include "./sectionH.h"

typedef struct{
    int id;
    char tableTitle[250];
    char masterName[250];
    SheetList sheetList;
    SectionList sectionList;
}Table;

struct TableNo{
    struct TableNo *previous;
    Table table;
    struct TableNo *next;
};

typedef struct {
    struct TableNo *start;
    struct TableNo *end;
} TableList;

int CreateTable(int id, char masterName[], char titleTable[],SheetList playersSheet);
Table SearchTable(int id, TableList *tableL);
void ShowTable(Table table);

int CreateTableList(TableList *tableL);
int InsertTableList(TableList *tableL, Table table);
int TableExists(int id, TableList *tableList);
void ShowTableList(TableList *tableList);

#endif //RPGHELPER_TABLEH_H