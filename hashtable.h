//
// Created by erh on 11/7/2020.
//

#ifndef DATABASEPROJECT_HASHTABLE_H
#define DATABASEPROJECT_HASHTABLE_H

#include "tuple.h"


struct HASHTABLE{
    TUPLELIST hashtable[1009];
};

struct HASHTABLE* newHashtable();

extern int hashkeyID(int n);

extern int hashkeyCourse(char c[5]);

extern struct TUPLE* getTail(struct TUPLE* data);

extern void insertIDFirst(struct TUPLE* data, struct HASHTABLE* a);

extern void insertCourseFirst(struct TUPLE* data, struct HASHTABLE* a);

extern void compareCIdG(struct TUPLE* tuple, char c[5], int sID, char g[2]);

extern void compareSNAP(struct TUPLE* tuple, int sID, char n[30], char a[50], char p[8]);

extern void compareCP(struct TUPLE* tuple, char c[5], char p[5]);

extern void compareCDH(struct TUPLE* tuple, char d[2], char h[8]);

extern void compareCR(struct TUPLE* tuple, char r[15]);

extern void deleteCIdG(char c[5], char id[5], char g[2], struct HASHTABLE* a);

extern void deleteSNAP(char id[5], char n[30], char a[50], char p[8], struct HASHTABLE* ht);

extern void deleteCP(char c[5], char p[5], struct HASHTABLE* a);

extern void deleteCDH(char c[5], char d[2], char h[8], struct HASHTABLE* a);

extern void deleteCR(char c[5], char r[15], struct HASHTABLE* a);

extern void getTupleCIdG(struct TUPLE* tuple, char c[5], int sID, char g[2]);

extern void getTupleSNAP(struct TUPLE* tuple, int sID, char n[30], char a[50], char p[8]);

extern void getTupleCP(struct TUPLE* tuple, char c[5], char p[5]);

extern void getTupleCDH(struct TUPLE* tuple, char c[5], char d[2], char h[8]);

extern void getTupleCR(struct TUPLE* tuple, char c[5], char r[15]);

extern void lookupCIdG(char c[5], char id[5], char g[2], struct HASHTABLE* a);

extern void lookupSNAP(char id[5], char n[30], char a[50], char p[8], struct HASHTABLE* ht);

extern void lookupCP(char c[5], char p[5], struct HASHTABLE* a);

extern void lookupCDH(char c[5], char d[2], char h[8], struct HASHTABLE* a);

extern void lookupCR(char c[5], char r[15], struct HASHTABLE* a);

extern int getID(char n[30], struct TUPLE* tuple);

extern char* getCourse(int sID, struct TUPLE* tuple);

extern int CDHMatch(char c[5], char d[2], char h[8], struct TUPLE* tuple);

extern void queryOne(char n[30], char c[5], struct HASHTABLE* a, struct HASHTABLE* b);

extern void queryTwo(char n[30], char d[2], char h[9], struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c, struct HASHTABLE* e);

extern void copyCourse(struct TUPLE* a, struct HASHTABLE* b);

extern void selectionCIdG(char c[6], struct HASHTABLE* a, struct HASHTABLE* b);

extern void storeIDFromTuple(struct TUPLE* a, struct HASHTABLE* b);

extern void projectionIDfromCourse(char c[6], struct HASHTABLE* a, struct HASHTABLE* b);

extern void printAllIDs(struct HASHTABLE* a);

extern void setDay(struct TUPLE* a, struct TUPLE* b, struct HASHTABLE* c);

extern void joinCrCdh(struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c);

extern void getTupleCRDH(struct TUPLE* tuple, char c[6], char r[16], char d[2], char h[9]);

extern void lookupCRDH(char c[6], char r[16],  char d[2], char h[9], struct HASHTABLE* a);

extern void copyRoomTuple(char r[16], struct TUPLE* a, struct HASHTABLE* b);

extern void selectionCRDH(char r[16], struct HASHTABLE* a, struct HASHTABLE* b);

extern void printProjectionRH(struct TUPLE* a);

extern void allRAOs(struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c, struct HASHTABLE* d, char r[16]);

extern void queryOneREPL(struct HASHTABLE* a, struct HASHTABLE* b);

extern void queryTwoREPL(struct HASHTABLE* a, struct HASHTABLE* b, struct HASHTABLE* c, struct HASHTABLE* d);

#endif //DATABASEPROJECT_HASHTABLE_H
