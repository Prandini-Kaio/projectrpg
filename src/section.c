#include <malloc.h>
#include "../headers/sectionH.h"
#include "stdio.h"

int CreateSectionList(SectionList *sectionList){
    sectionList->start = NULL;
    time_t t= time(NULL);
    sectionList->openSecDate = localtime(&t);
    sectionList->end = NULL;
}

int InsertSectionInList(SectionList *sectionList){
    struct SectionNo *aux;
    aux = (struct SectionNo *)malloc(sizeof(struct SectionNo));
    if(sectionList->start == NULL){
        //Dados
        aux->section = CreateSection(sectionList);
        //
        sectionList->start = aux;
        sectionList->end = aux;
        aux->next = sectionList->start;
        aux->previous = sectionList->end;
        return 1;
    }

    //Dados
    aux->section = CreateSection(sectionList);
    //
    aux->previous = sectionList->end;
    sectionList->end->next = aux;
    aux->next = sectionList->start;
    sectionList->start->previous = aux;
    sectionList->end = aux;
    return 1;
}

Section CreateSection(SectionList *sectionList){
    Section section;

    time_t t = time(NULL);
    section.lastOpenDate = localtime(&t);
    //Se o start for nulo
    if(sectionList->start == NULL) section.numberOfSection = 0;
    else section.numberOfSection += sectionList->end->section.numberOfSection;

    return section;
}

