//
// Created by rhayn on 11/7/2020.
//

#include "hashtable.h"
#include "stdlib.h"
#include "stdio.h"
#include <stddef.h>
#include <string.h>

struct HASHTABLE* newHashtable(){
    struct HASHTABLE* a = (struct HASHTABLE*)malloc(sizeof(struct TUPLE*) * 1009);
    struct TUPLE* tuple = NULL;
    for(int i = 0; i < 1009; i++){
       a->hashtable[i] = tuple;
    }
    return a;
}

extern int hashkeyID(int n){
    return n % 1009;
}

extern int hashkeyCourse(char c[5]){
    if('*' == c[0]){
        return -1000;
    } else {
        int n = c[0] + c[1] + c[2] + c[3] + c[4];
        return n % 1009;
    }
}

extern struct TUPLE* getTail(struct TUPLE* data){
    if(data->next != NULL){
        getTail(data->next);
    }
    else{
        return data;
    }
}

extern void insertIDFirst(struct TUPLE* data, struct HASHTABLE* a){
    int k = hashkeyID(data->StudentId);
    if(a->hashtable[k] == NULL){
        a->hashtable[k] = data;
        a->hashtable[k]->next = NULL;
    }
    else{
        getTail(data)->next = data;
    }
}

extern void insertCourseFirst(struct TUPLE* data, struct HASHTABLE* a){
    int k = hashkeyCourse(data->Course);
    if (a->hashtable[k] == NULL) {
        a->hashtable[k] = data;
    } else {
        getTail(a->hashtable[k])->next = data;
    }
}

extern void compareCIdG(struct TUPLE* tuple, char c[5], int sID, char g[2]){
    if((sID == tuple->StudentId || sID == 0) && (strcmp(g, tuple->Grade) == 0 || g[0] == 42) && (c[0] == 42 || strcmp(c, tuple->Course) == 0)){
        for(int i = 0; i < 5; i++){
            tuple->Course[i] = 0;
        }
        tuple->StudentId = -1000;
        for(int i = 0; i < 5; i++){
            tuple->Grade[i] = 0;
        }
    }
    if(tuple->next != NULL) {
        compareCIdG(tuple->next, c, sID, g);
    }
}

extern void compareSNAP(struct TUPLE* tuple, int sID, char n[30], char a[50], char p[8]){
    if((sID == 0 || sID == tuple->StudentId) && ((strcmp(n, tuple->Name) == 0) || n[0] == 42) && ((strcmp(a, tuple->Address) == 0) || a[0] == 42) && ((strcmp(p, tuple->Phone) == 0) || p[0] == 42)){
        tuple->StudentId = -1000;
        for(int i = 0; i < 30; i++){
            tuple->Name[i] = 0;
        }
        for(int i = 0; i < 50; i++){
            tuple->Address[i] = 0;
        }
        for(int i = 0; i < 8; i++){
            tuple->Phone[i] = 0;
        }
    }
    if(tuple->next != NULL){
        compareSNAP(tuple->next, sID, n, a, p);
    }
}

extern void compareCP(struct TUPLE* tuple, char c[5], char p[5]){
    if(((p[0] == 42 || strcmp(p, tuple->Prerec) == 0) && (c[0] == 42 || strcmp(c, tuple->Course) == 0))){
        for(int i = 0; i < 5; i++){
            tuple->Course[i] = 0;
        }
        for(int i = 0; i < 5; i++){
            tuple->Prerec[i] = 0;
        }
    }
    if(tuple->next != NULL){
        compareCP(tuple->next, c, p);
    }
}

extern void compareCDH(struct TUPLE* tuple, char d[2], char h[8]){
    if((d[0] == 42 || strcmp(d, tuple->Day) == 0) && (h[0] == 42 || strcmp(h, tuple->Hour) == 0)){
        for(int i = 0; i < 5; i++){
            tuple->Course[i] = 0;
        }
        for(int i = 0; i < 2; i++){
            tuple->Day[i] = 0;
        }
        for(int i = 0; i < 8; i++){
            tuple->Hour[i] = 0;
        }
    }
    if(tuple->next != NULL){
        compareCDH(tuple->next, d, h);
    }
}

extern void compareCR(struct TUPLE* tuple, char r[15]){
    if(r[0] == 42 || strcmp(r, tuple->Room) == 0){
        for(int i = 0; i < 5; i++){
            tuple->Course[i] = 0;
        }
        for(int i = 0; i < 15; i++){
            tuple->Room[i] = 0;
        }
    }
    if(tuple->next != NULL){
        compareCR(tuple->next, r);
    }
}

extern void deleteCIdG(char c[5], char id[5], char g[2], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    int sID = atoi(id);
    if(courseKey != -1000){
        if(a->hashtable[courseKey] != NULL) {
            compareCIdG(a->hashtable[courseKey], c, sID, g);
        }
    }
    if(c[0] == 42){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                compareCIdG(a->hashtable[i], c, sID, g);
            }
        }
    }
}

extern void deleteSNAP(char id[5], char n[30], char a[50], char p[8], struct HASHTABLE* ht){
    int sID = atoi(id);
    int idKey = -1000;
    if(sID != 0){
        idKey = hashkeyID(sID);
    }
    if(idKey != -1000){
        if(ht->hashtable[idKey] != NULL) {
            compareSNAP(ht->hashtable[idKey], sID, n, a, p);
        }
    }
    if(sID == 0){
        for(int i = 0; i < 1009; i++){
            if(ht->hashtable[i] != NULL) {
                compareSNAP(ht->hashtable[i], sID, n, a, p);
            }
        }
    }
}

extern void deleteCP(char c[5], char p[5], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    if(courseKey != -1000){
        if(a->hashtable[courseKey] != NULL) {
            compareCP(a->hashtable[courseKey], c, p);
        }
    }
    else if(courseKey == -1000){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                compareCP(a->hashtable[i], c, p);
            }
        }
    }
}

extern void deleteCDH(char c[5], char d[2], char h[8], struct HASHTABLE* a){
    int courseKey = -1000;
    if(c[0] != 42){
        courseKey = hashkeyCourse(c);
    }
    if(courseKey != -1000){
        if(a->hashtable[courseKey] != NULL) {
            compareCDH(a->hashtable[courseKey], d, h);
        }
    }
    else if(courseKey == -1000){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                compareCDH(a->hashtable[i], d, h);
            }
        }
    }
}

extern void deleteCR(char c[5], char r[15], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    if(courseKey != -1000){
        if(a->hashtable[courseKey] != NULL) {
            compareCR(a->hashtable[courseKey], r);
        }
    }
    else if(courseKey == -1000){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                compareCR(a->hashtable[i], r);
            }
        }
    }
}

extern void getTupleCIdG(struct TUPLE* tuple, char c[6], int sID, char g[2]){
    if((sID == tuple->StudentId || sID == 0) && (strcmp(g, tuple->Grade) == 0 || g[0] == 42) && (c[0] == 42 || strcmp(c, tuple->Course) == 0)){
        printf("\n************");
        printf("\nCourse: %s", tuple->Course);
        printf("\nStudent ID: %d", tuple->StudentId);
        printf("\nGrade: %s", tuple->Grade);
        printf("\n************");
    }
    if(tuple->next != NULL) {
        getTupleCIdG(tuple->next, c, sID, g);
    }
}

extern void getTupleSNAP(struct TUPLE* tuple, int sID, char n[30], char a[50], char p[8]){
    if((sID == 0 || sID == tuple->StudentId) && ((strcmp(n, tuple->Name) == 0) || n[0] == 42) && ((strcmp(a, tuple->Address) == 0) || a[0] == 42) && ((strcmp(p, tuple->Phone) == 0) || p[0] == 42)){
        printf("\n************");
        printf("\nStudent ID: %d", tuple->StudentId);
        printf("\nName: %s", tuple->Name);
        printf("\nAddress: %s", tuple->Address);
        printf("\nPhone Number: %s", tuple->Phone);
        printf("\n************");
    }
    if(tuple->next != NULL){
        getTupleSNAP(tuple->next, sID, n, a, p);
    }
}

extern void getTupleCP(struct TUPLE* tuple, char c[5], char p[5]){
    if(((p[0] == 42 || strcmp(p, tuple->Prerec) == 0) && (c[0] == 42 || strcmp(c, tuple->Course) == 0))){
        printf("\n************");
        printf("\nCourse: %s", tuple->Course);
        printf("\nPrerequisite: %s", tuple->Prerec);
        printf("\n************");
    }
    if(tuple->next != NULL){
        getTupleCP(tuple->next, c, p);
    }
}

extern void getTupleCDH(struct TUPLE* tuple, char c[5], char d[2], char h[8]){
    if((d[0] == 42 || strcmp(d, tuple->Day) == 0) && (h[0] == 42 || strcmp(h, tuple->Hour) == 0) && (c[0] == 42 || strcmp(c, tuple->Course) == 0)){
        printf("\n************");
        printf("\nCourse: %s", tuple->Course);
        printf("\nDay: %s", tuple->Day);
        printf("\nHour: %s", tuple->Hour);
        printf("\n************");
    }
    if(tuple->next != NULL){
        getTupleCDH(tuple->next, c, d, h);
    }
}

extern void getTupleCR(struct TUPLE* tuple, char c[5], char r[15]){
    if((r[0] == 42 || strcmp(r, tuple->Room) == 0) && (c[0] == 42 || strcmp(c, tuple->Course) == 0)){
        printf("\n************");
        printf("\nCourse: %s", tuple->Course);
        printf("\nRoom: %s", tuple->Room);
        printf("\n************");
    }
    if(tuple->next != NULL){
        getTupleCR(tuple->next, c, r);
    }
}

extern void lookupCIdG(char c[5], char id[5], char g[2], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    int sID = atoi(id);
    if(courseKey != -1000){
        getTupleCIdG(a->hashtable[courseKey], c, sID, g);
    }
    if(courseKey == -1000){
        for(int i = 0; i < 1009; i++) {
            if(a->hashtable[i] != NULL) {
                getTupleCIdG(a->hashtable[i], c, sID, g);
            }
        }
    }
}

extern void lookupSNAP(char id[6], char n[30], char a[50], char p[8], struct HASHTABLE* ht){
    int sID = atoi(id);
    int idKey = -1000;
    if(sID != 0){
        idKey = hashkeyID(sID);
    }
    if(idKey != -1000){
        getTupleSNAP(ht->hashtable[idKey], sID, n, a, p);
    }
    if(sID == 0){
        for(int i = 0; i < 1009; i++){
            if(ht->hashtable[i] != NULL) {
                getTupleSNAP(ht->hashtable[i], sID, n, a, p);
            }
        }
    }
}

extern void lookupCP(char c[5], char p[5], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    if(courseKey != -1000){
        getTupleCP(a->hashtable[courseKey], c, p);
    }
    else if(courseKey == -1000){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                getTupleCP(a->hashtable[i], c, p);
            }
        }
    }
}

extern void lookupCDH(char c[5], char d[2], char h[8], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    if(courseKey != -1000){
        getTupleCDH(a->hashtable[courseKey], c, d, h);
    }
    else if(courseKey == -1000){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                getTupleCDH(a->hashtable[i], c, d, h);
            }
        }
    }
}

extern void lookupCR(char c[5], char r[15], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    if(courseKey != -1000){
        getTupleCR(a->hashtable[courseKey], c, r);
    }
    else {
        for (int i = 0; i < 1009; i++) {
            if (a->hashtable[i] != NULL) {
                getTupleCR(a->hashtable[i], c, r);
            }
        }
    }
}

extern int getID(char n[30], struct TUPLE* tuple){
    if(strcmp(n, tuple->Name) == 0){
        return tuple->StudentId;
    }
    else if(tuple->next != NULL){
        getID(n, tuple->next);
    }
    else{
        return 0;
    }
}

extern char* getCourse(int sID, struct TUPLE* tuple){
    if(sID == tuple->StudentId){
        return tuple->Course;
    }
    else if(tuple->next != NULL){
        getCourse(sID, tuple->next);
    }
    else{
        return "*";
    }
}

extern int CDHMatch(char c[5], char d[2], char h[8], struct TUPLE* tuple){
    if(strcmp(d, tuple->Day) == 0 && strcmp(h, tuple->Hour) == 0 && strcmp(c, tuple->Course) == 0){
        return 1;
    }
    else if(tuple->next != NULL){
        CDHMatch(c, d, h, tuple->next);
    }
    else{
        return 0;
    }
}

extern void queryOne(char n[30], char c[6], struct HASHTABLE* a, struct HASHTABLE* b) {
    int ID = 0;
    for (int i = 0; i < 1009; i++) {
        if (a->hashtable[i] != NULL) {
           ID = getID(n, a->hashtable[i]);
           if(ID != 0){
               break;
           }
        }
    }
    char IDString[6];
    sprintf(IDString, "%d", ID);
    lookupCIdG(c, IDString, "*", b);
}

extern void queryTwo(char n[30], char d[2], char h[9], struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c, struct HASHTABLE* e){
    int ID = 0;
    for (int i = 0; i < 1009; i++) {
        if (a->hashtable[i] != NULL) {
            ID = getID(n, a->hashtable[i]);
            if(ID != 0){
                break;
            }
        }
    }

    for(int i = 0; i < 1009; i++) {
        if(b->hashtable[i] != NULL) {
             if(getCourse(ID, b->hashtable[i])[0] != 42){
                 int match = CDHMatch(getCourse(ID, b->hashtable[i]), d, h, c->hashtable[i]);
                 if(match == 1){
                     lookupCR(getCourse(ID, b->hashtable[i]), "*", e);
                     break;
                 }
             }
        }
    }
}

extern void copyCourse(struct TUPLE* a, struct HASHTABLE* b){
    struct TUPLE* tuple = createTupleCIdG(a->Course, a->StudentId, a->Grade);
    insertCourseFirst(tuple, b);
    if(a->next != NULL){
        copyCourse(a->next, b);
    }
}

extern void selectionCIdG(char c[6], struct HASHTABLE* a, struct HASHTABLE* b){
    int courseKey = hashkeyCourse(c);
    if(a->hashtable[courseKey] != NULL) {
        copyCourse(a->hashtable[courseKey], b);
    }
}

extern void storeIDFromTuple(struct TUPLE* a, struct HASHTABLE* b){
    int IDKey = hashkeyID(a->StudentId);
    struct TUPLE* tuple = createTupleID(a->StudentId);
    b->hashtable[IDKey] = tuple;
    if(a->next != NULL){
        storeIDFromTuple(a->next, b);
    }
}

extern void projectionIDfromCourse(char c[6], struct HASHTABLE* a, struct HASHTABLE* b){
    int courseKey = hashkeyCourse(c);
    storeIDFromTuple(a->hashtable[courseKey], b);
}

extern void printAllIDs(struct HASHTABLE* a){
    for(int i = 0; i < 1009; i++){
        if(a->hashtable[i] != NULL){
            printf("\n%d", a->hashtable[i]->StudentId);
        }
    }
}

extern void setDay(struct TUPLE* a, struct TUPLE* b, struct HASHTABLE* c){
    struct TUPLE* tuple = createTupleCRDH(a->Course, b->Room, a->Day, a->Hour);
    insertCourseFirst(tuple, c);
    if(a->next != NULL){
        setDay(a->next, b, c);
    }
}

extern void joinCrCdh(struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c){
    for(int i = 0; i < 1009; i++){
        if(a->hashtable[i] != NULL && b->hashtable[i] != NULL){
           setDay(a->hashtable[i], b->hashtable[i], c);
        }
    }
}

extern void getTupleCRDH(struct TUPLE* tuple, char c[6], char r[16], char d[2], char h[9]){
    if((d[0] == 42 || strcmp(d, tuple->Day) == 0) && (h[0] == 42 || strcmp(h, tuple->Hour) == 0) && (c[0] == 42 || strcmp(c, tuple->Course) == 0) && (r[0] == 42 || strcmp(r, tuple->Room) == 0)){
        printf("\n************");
        printf("\nCourse: %s", tuple->Course);
        printf("\nRoom: %s", tuple->Room);
        printf("\nDay: %s", tuple->Day);
        printf("\nHour: %s", tuple->Hour);
        printf("\n************");
    }
    if(tuple->next != NULL){
        getTupleCRDH(tuple->next, c, r, d, h);
    }
}

extern void lookupCRDH(char c[6], char r[16],  char d[2], char h[9], struct HASHTABLE* a){
    int courseKey = hashkeyCourse(c);
    if(courseKey != -1000){
        getTupleCRDH(a->hashtable[courseKey], c, r, d, h);
    }
    else if(courseKey == -1000){
        for(int i = 0; i < 1009; i++){
            if(a->hashtable[i] != NULL) {
                getTupleCRDH(a->hashtable[i], c, r, d, h);
            }
        }
    }
}

extern void copyRoomTuple(char r[16], struct TUPLE* a, struct HASHTABLE* b){
    if(strcmp(r, a->Room) == 0){
        struct TUPLE* tuple = createTupleCRDH(a->Course, a->Room, a->Day, a->Hour);
        insertCourseFirst(tuple, b);
    }
    if(a->next != NULL){
        copyRoomTuple(r, a->next, b);
    }
}

extern void selectionCRDH(char r[16], struct HASHTABLE* a, struct HASHTABLE* b){
    for(int i = 0; i < 1009; i++){
        if(a->hashtable[i] != NULL){
            copyRoomTuple(r, a->hashtable[i], b);
        }
    }
}

extern void printProjectionRH(struct TUPLE* a){
    printf("\n************");
    printf("\nDay: %s", a->Day);
    printf("\nHour: %s", a->Hour);
    printf("\n************");
    if(a->next != NULL){
        printProjectionRH(a->next);
    }
}

extern void allRAOs(struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c, struct HASHTABLE* d, char r[16]){
    joinCrCdh(a, b, c);
    selectionCRDH(r, c, d);
    for(int i = 0; i < 1009; i++){
        if(d->hashtable[i] != NULL){
            printProjectionRH(d->hashtable[i]);
        }
    }
}

extern void queryOneREPL(struct HASHTABLE* a, struct HASHTABLE* b){
    printf("\nEnter a student name and a course name, seperated by a space. Type  'quit here' to quit:");
    char name[31];
    char course[6];
    scanf("%s %s", &name, &course);
    if(strcmp(name, "quit") == 0 || strcmp(course, "quit") == 0){
        return;
    }
    queryOne(name, course, a, b);
    queryOneREPL(a, b);
}

extern void queryTwoREPL(struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c, struct HASHTABLE* d){
    printf("\nEnter a student name without any spaces between characters. Type  'quit quit quit' to quit:");
    char name[31];
    char day[5];
    char hour[9];
    scanf("%s %s %s", &name, &day, &hour);
    if(strcmp(name, "quit") == 0 || strcmp(day, "quit") == 0, strcmp(hour, "quit") == 0){
        return;
    }
    queryTwo(name, day, hour, a, b, c, d);
    queryTwoREPL(a, b, c, d);
}