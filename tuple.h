//
// Created by erh on 11/7/2020.
//

#ifndef DATABASEPROJECT_TUPLE_H
#define DATABASEPROJECT_TUPLE_H

typedef struct TUPLE *TUPLELIST;
struct TUPLE {
    int StudentId;
    char Name[31];
    char Address[51];
    char Phone[9];
    char Course[6];
    char Prerec[6];
    char Day[2];
    char Hour[9];
    char Room[16];
    char Grade[3];
    TUPLELIST next;
};

struct TUPLE* createTupleCIdG(char c[5], int id, char g[2]);

struct TUPLE* createTupleSNAP(int id, char n[30], char a[50], char p[8]);

struct TUPLE* createTupleCP(char c[5], char p[5]);

struct TUPLE* createTupleCDH(char c[5], char d[2], char h[8]);

struct TUPLE* createTupleCR(char c[5], char r[15]);

struct TUPLE* createTupleID(int id);

struct TUPLE* createTupleCRDH(char c[6], char r[16], char d[2], char h[8]);





#endif //DATABASEPROJECT_TUPLE_H
