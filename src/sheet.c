#include <stdio.h>
#include <malloc.h>
#include "../headers/sheetH.h"

//Criar nova ficha

int InitSheet(Sheet *sheet){
    Sheet *aux;
    aux = sheet;

    aux->playerName = NULL;
    aux->investigatorName = NULL;
    aux->ocupation = NULL;
    aux->age = 0;
    aux->sex = 0;

    *sheet = *aux;
}

int CreateNewSheet(Sheet *sheet, char *playerName, char *investigatorName, char *ocupation, int age, int sex){
    InitSheet(sheet);

    sheet->playerName = playerName;
    sheet->investigatorName = investigatorName;
    sheet->ocupation = ocupation;
    sheet->age = age;
    sheet->sex = sex;
}

int ShowSheet(Sheet sheet){
    printf(
            "Player: %s\n"
            "Investigator: %s\n"
            "Ocupation: %s\n"
            "Age: %i\n"
            "Sex: %i\n",
            sheet.playerName, sheet.investigatorName, sheet.ocupation, sheet.age, sheet.sex
            );
    return 1;
}

//Sheet List
void CreateSheetList(SheetList *sL){
    sL->start = NULL;
    sL->end = NULL;
}

//Insere uma ficha na lista de fichas da mesa
int InsertSheetList(SheetList *sL, Sheet s){
    struct SheetNo *aux;
    aux = (struct SheetNo*)malloc(sizeof (struct SheetNo));
    if(aux == NULL) return 0;//CASO O AUXILIAR SEJA NULO, NAO EXISTE LISTA
    if(sL->start == NULL){
        //data
        aux->sheet = s;
        //
        //Uma lista circular, então no fim, volta ao começo
        sL->start = aux;
        sL->end = aux;
        aux->next = sL->start;
        aux->previous = sL->end;
        return 1;
    }
    //data
    aux->sheet = s;
    //
    aux->previous = sL->end;
    sL->end->next = aux;
    aux->next = sL->start;
    sL->start->previous = aux;
    sL->end = aux;
    return 1;
}

//Mostra as fichas da mesa
void ShowSheetList(SheetList sL, int direction){
    struct SheetNo *aux;
    aux = NULL;
    if(sL.start == NULL)printf("\nEMPTY SHEET LIST\n");
    else{
        if(direction == 0){
            aux = sL.start;
            do{
                printf("\n-------------FICHA DE INVESTIGADOR-------------\n");
                printf(
                        "\nPlayer: %s\n"
                        "Investigator: %s\n"
                        "Ocupation: %s\n"
                        "Age: %i\n"
                        "Sex: %i\n",
                        aux->sheet.playerName, aux->sheet.investigatorName, aux->sheet.ocupation, aux->sheet.age, aux->sheet.sex
                );
                printf("\n-----------------------------------------------\n");
                printf("\n+--------------------+\n");
                printf("\n| PLAYER: %s|\n", aux->sheet.playerName);
                printf("\n| INVESTIGATOR: %s|\n", aux->sheet.investigatorName);
                printf("\n| OCUPATION: %s|\n", aux->sheet.ocupation);
                printf("\n| AGE: %s|\n", aux->sheet.age);
                printf("\n| SEX: %s|\n", aux->sheet.sex);
                printf("\n+--------------------+\n");

                aux = aux->next;
            } while (aux != sL.start);
        }else{
            aux = sL.end;
            do{
                printf("\n-------------FICHA DE INVESTIGADOR-------------\n");
                printf(
                        "\nPlayer: %s\n"
                        "Investigator: %s\n"
                        "Ocupation: %s\n"
                        "Age: %i\n"
                        "Sex: %i\n",
                        aux->sheet.playerName, aux->sheet.investigatorName, aux->sheet.ocupation, aux->sheet.age, aux->sheet.sex
                );
                printf("\n-----------------------------------------------\n");
                printf("Antes");
                aux = aux->previous;
                printf("Depois");
            } while (aux != sL.end);
        }
    }
}

//
