#ifndef RPGHELPER_SECTIONH_H
#define RPGHELPER_SECTIONH_H
#include "time.h"

typedef struct {
    int numberOfSection;
    time_t firstOpenDate;
    time_t lastOpenDate;
}Section;

struct SectionNo{
    struct SectionNo *next;
    Section section;
    struct SectionNo *previous;
};

typedef struct {
    struct SectionNo *start;
    struct SectionNo *end;
}SectionList;

int NewSection(SectionList *secList);

int CreateSectionList(SectionList *sectionList);
int InsertNewSection(SectionList *secList, Section sec);

#endif //RPGHELPER_SECTIONH_H
