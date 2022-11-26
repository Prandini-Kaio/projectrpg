#ifndef RPGHELPER_SECTIONH_H
#define RPGHELPER_SECTIONH_H
#include "time.h"

typedef struct {
    int numberOfSection;
    struct tm *lastOpenDate;
}Section;

struct SectionNo{
    struct SectionNo *next;
    Section section;
    struct SectionNo *previous;
};

typedef struct {
    struct SectionNo *start;
    struct tm *openSecDate;
    struct SectionNo *end;
}SectionList;

int CreateSectionList(SectionList *sectionList);
int InsertSectionInList(SectionList *sectionList);

Section CreateSection(SectionList *sectionList);

#endif //RPGHELPER_SECTIONH_H
