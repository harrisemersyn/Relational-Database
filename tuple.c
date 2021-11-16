//
// Created by erh on 11/7/2020.
//

#include "tuple.h"
#include "stdlib.h"
#include <stddef.h>
#include "string.h"
#include "stdio.h"

struct TUPLE* createTupleCIdG(char c[5], int id, char g[2]){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    for(int i = 0; i < 5; i++){
        newTuple->Course[i] = c[i];
    }
    newTuple->Course[5] = '\0';
    newTuple->StudentId = id;
    for(int i = 0; i < 2; i++){
        newTuple->Grade[i] = g[i];
    }
    newTuple->Grade[2] = '\0';
    newTuple->next =  NULL;
    return newTuple;
}

struct TUPLE* createTupleSNAP(int id, char n[30], char a[50], char p[8]){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    newTuple->StudentId = id;
    for(int i = 0; i < 30; i++){
        newTuple->Name[i] = n[i];
    }
    newTuple->Name[30] = '\0';
    for(int i = 0; i < 50; i++){
        newTuple->Address[i] = a[i];
    }
    newTuple->Address[50] = '\0';
    for(int i = 0; i < 8; i++){
        newTuple->Phone[i] = p[i];
    }
    newTuple->Phone[8] = '\0';
    newTuple->next =  NULL;
    return newTuple;
}

struct TUPLE* createTupleCP(char c[5], char p[5]){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    for(int i = 0; i < 5; i++){
        newTuple->Course[i] = c[i];
    }
    newTuple->Course[5] = '\0';
    for(int i = 0; i < 5; i++){
        newTuple->Prerec[i] = p[i];
    }
    newTuple->Prerec[5] = '\0';
    newTuple->next =  NULL;
    return newTuple;
}

struct TUPLE* createTupleCDH(char c[5], char d[2], char h[8]){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    for(int i = 0; i < 5; i++){
        newTuple->Course[i] = c[i];
    }
    newTuple->Course[5] = '\0';
    for(int i = 0; i < 2; i++){
        newTuple->Day[i] = d[i];
    }
    newTuple->Day[1] = '\0';
    for(int i = 0; i < 8; i++){
        newTuple->Hour[i] = h[i];
    }
    newTuple->Hour[8] = '\0';
    newTuple->next =  NULL;
    return newTuple;
}

struct TUPLE* createTupleCR(char c[5], char r[15]){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    for(int i = 0; i < 5; i++){
        newTuple->Course[i] = c[i];
    }
    newTuple->Course[5] = '\0';
    for(int i = 0; i < 15; i++){
        newTuple->Room[i] = r[i];
    }
    newTuple->Room[15] = '\0';
    newTuple->next =  NULL;
    return newTuple;
}

struct TUPLE* createTupleID(int id){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    newTuple->StudentId = id;
    newTuple->next =  NULL;
    return newTuple;
}

struct TUPLE* createTupleCRDH(char c[6], char r[16], char d[2], char h[9]){
    struct TUPLE* newTuple = (struct TUPLE*)malloc(sizeof(struct TUPLE));
    for(int i = 0; i < 5; i++){
        newTuple->Course[i] = c[i];
    }
    newTuple->Course[5] = '\0';
    for(int i = 0; i < 15; i++){
        newTuple->Room[i] = r[i];
    }
    newTuple->Room[15] = '\0';
    for(int i = 0; i < 2; i++){
        newTuple->Day[i] = d[i];
    }
    newTuple->Day[1] = '\0';
    for(int i = 0; i < 8; i++){
        newTuple->Hour[i] = h[i];
    }
    newTuple->Hour[8] = '\0';
    newTuple->next =  NULL;
    return newTuple;
}
