#include "../headers/sectionH.h"
#include "stdio.h"



int NewSection(SectionList *sectionList){
    Section section;
    section.numberOfSection += sectionList->end->section.numberOfSection;
    section.lastOpenDate = time(0);

    InsertNewSection(sectionList, section);
    return 0;
}

int CreateSectionList(SectionList *sectionList){
    sectionList->start = NULL;
    time_t t = time(NULL);
    sectionList->openSecDate = localtime(&t);
    sectionList->end = NULL;
    return 1;
}

int InsertNewSection(SectionList *secList, Section sec){
    struct SectionNo *aux;
    aux = NULL;
    if(secList->start == NULL){
        //data
        aux->section = sec;
        time_t t = time(NULL);
        aux->section.lastOpenDate = localtime(&t);
        //
        //Uma lista circular, então no fim, volta ao começo
        secList->start = aux;
        secList->end = aux;
        aux->next = secList->start;
        aux->previous = secList->end;
        return 1;
    }
    //data
    aux->section = sec;
    // Aumentar o numero da seção
    aux->section.numberOfSection += aux->previous->section.numberOfSection;
    //
    aux->previous = secList->end;
    secList->end->next = aux;
    aux->next = secList->start;
    secList->start->previous = aux;
    secList->end = aux;
    return 1;
}