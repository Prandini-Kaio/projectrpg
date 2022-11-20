#ifndef RPGHELPER_SHEETH_H
#define RPGHELPER_SHEETH_H

typedef struct {
    char *playerName;
    char *investigatorName;
    char *ocupation;
    //Atributos
    //Pericias
    int age;
    int sex;
    //Equips
}Sheet;

struct SheetNo{
    struct SheetNo *previous;
    Sheet sheet;
    struct SheetNo *next;
};

typedef struct {
    struct SheetNo *start;
    struct SheetNo *end;
} SheetList;

//Lista De Fichas
void CreateSheetList(SheetList *sL);
int InsertSheetList(SheetList *sL, Sheet s);
void ShowSheetList(SheetList sL, int direction);

int InitSheet(Sheet *sheet);
int CreateNewSheet(Sheet *sheet, char *playerName, char *investigatorName, char *ocupation, int age, int sex);
int ShowSheet(Sheet sheet);

#endif //RPGHELPER_SHEETH_H
