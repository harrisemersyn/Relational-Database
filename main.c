#include <stdio.h>
#include "hashtable.h"
#include "tuple.h"

int main() {
    //8.1
    struct HASHTABLE* a  = newHashtable();
    struct TUPLE* oa = createTupleCIdG("CS101", 12345, "A");
    struct TUPLE* ta = createTupleCIdG("CS101", 67890, "B");
    struct TUPLE* tha = createTupleCIdG("EE200", 12345, "C");
    struct TUPLE* fa = createTupleCIdG("EE200", 22222, "B+");
    struct TUPLE* fia = createTupleCIdG("PH100", 33333, "A-");
    struct TUPLE* sa = createTupleCIdG("PH100", 67890, "C+");
    insertCourseFirst(oa, a);
    insertCourseFirst(ta, a);
    insertCourseFirst(tha, a);
    insertCourseFirst(fa, a);
    insertCourseFirst(fia, a);
    insertCourseFirst(sa, a);

    //8.2 a
    struct HASHTABLE* b = newHashtable();
    struct TUPLE* ob = createTupleSNAP(12345, "C.Brown", "12 Apple St.", "555-1234");
    struct TUPLE* tb = createTupleSNAP(67890, "L.VanPelt", "34 Pear Ave.", "555-5678");
    struct TUPLE* thb = createTupleSNAP(22222, "P.Patty", "56 Grape Blvd", "555-9999");
    insertIDFirst(ob, b);
    insertIDFirst(tb, b);
    insertIDFirst(thb, b);

    //8.2 b
    struct HASHTABLE* c = newHashtable();
    struct TUPLE* oc = createTupleCP("CS101", "CS100");
    struct TUPLE* tc = createTupleCP("EE200", "EE005");
    struct TUPLE* thc = createTupleCP("EE200", "CS100");
    struct TUPLE* fc = createTupleCP("CS120", "CS101");
    struct TUPLE* fic = createTupleCP("CS121", "CS120");
    struct TUPLE* sc = createTupleCP("CS205", "CS101");
    struct TUPLE* sec = createTupleCP("CS206", "CS121");
    struct TUPLE* ec = createTupleCP("CS206", "CS205");
    insertCourseFirst(oc, c);
    insertCourseFirst(tc, c);
    insertCourseFirst(thc, c);
    insertCourseFirst(fc, c);
    insertCourseFirst(fic, c);
    insertCourseFirst(sc, c);
    insertCourseFirst(sec, c);
    insertCourseFirst(ec, c);

    //8.2 c
    struct HASHTABLE* d = newHashtable();
    struct TUPLE* od = createTupleCDH("CS101", "M", "9AM");
    struct TUPLE* td = createTupleCDH("CS101", "W", "9AM");
    struct TUPLE* thd = createTupleCDH("CS101", "F", "9AM");
    struct TUPLE* fd = createTupleCDH("EE200", "T", "10AM");
    struct TUPLE* fid = createTupleCDH("EE200", "W", "1PM");
    struct TUPLE* sd = createTupleCDH("EE200", "H", "10AM");
    insertCourseFirst(od, d);
    insertCourseFirst(td, d);
    insertCourseFirst(thd, d);
    insertCourseFirst(fd, d);
    insertCourseFirst(fid, d);
    insertCourseFirst(sd, d);

    //8.2 d
    struct HASHTABLE* e = newHashtable();
    struct TUPLE* oe = createTupleCR("CS101", "Turing Aud.");
    struct TUPLE* te = createTupleCR("EE200", "25 Ohm Hall");
    struct TUPLE* the = createTupleCR("PH100", "Newton Lab.");
    insertCourseFirst(oe, e);
    insertCourseFirst(te, e);
    insertCourseFirst(the, e);

    printf("\n************");
    printf("\nQuery 1: Grade given student name and course:");
    printf("\n************");
    queryOneREPL(b, a);

    printf("\n************");
    printf("\nQuery 2: Course, Date, and Time given a student name:");
    printf("\n************");
    queryTwoREPL(b, a, d, e);

    printf("\n************");
    printf("\nSelection - New Hashtable made up of only CS101 tuples, then lookup on CS101, *, *:");
    printf("\n************");
    struct HASHTABLE* f  = newHashtable();
    selectionCIdG("CS101", a, f);
    lookupCIdG("CS101", "*", "*", f);

    printf("\n************");
    printf("\nProjection - New Hashtable made up of student ID only tuples from course CS101:");
    printf("\n************");
    struct HASHTABLE* g  = newHashtable();
    projectionIDfromCourse("CS101", a, g);
    printf("\nPrinting all tuples in new hashtable:");
    printAllIDs(g);

    printf("\n************");
    printf("\nJoin - joining tables CR and CDH:");
    printf("\n************");
    struct HASHTABLE* h = newHashtable();
    joinCrCdh(d, e, h);
    printf("Looking up CS101, *, *, * on new table CRDH:");
    lookupCRDH("CS101", "*", "*", "*", h);

    printf("\n************");
    printf("\nAll - Joining CR and CDH from figure 8.14, selecting all classes in turing auditorium, and projecting for days and times, then printing the new hashtable:");
    printf("\n************");
    struct HASHTABLE* CR = newHashtable();
    struct TUPLE* CRo = createTupleCR("CS101", "Turing Aud.");
    struct TUPLE* CRt = createTupleCR("EE200", "25 Ohm Hall");
    insertCourseFirst(CRo, CR);
    insertCourseFirst(CRt, CR);
    struct HASHTABLE* CDH = newHashtable();
    struct TUPLE* CDHo = createTupleCDH("CS101", "M", "9AM");
    struct TUPLE* CDHt = createTupleCDH("CS101", "W", "9AM");
    struct TUPLE* CDHtr = createTupleCDH("CS101", "F", "9AM");
    struct TUPLE* CDHf = createTupleCDH("EE200", "T", "10AM");
    struct TUPLE* CDHfi = createTupleCDH("EE200", "W", "1PM");
    struct TUPLE* CDHs = createTupleCDH("EE200", "H", "10AM");
    insertCourseFirst(CDHo, CDH);
    insertCourseFirst(CDHt, CDH);
    insertCourseFirst(CDHtr, CDH);
    insertCourseFirst(CDHf, CDH);
    insertCourseFirst(CDHfi, CDH);
    insertCourseFirst(CDHs, CDH);
    struct HASHTABLE* CRDH = newHashtable();
    struct HASHTABLE* SELECT = newHashtable();
    allRAOs(CDH, CR, CRDH, SELECT, "Turing Aud.");

    printf("\n************");
    printf("\n8.2 Functions:");
    printf("\n************");

    printf("\nLooking up CS101, 12345, * on table CIdG:");
    lookupCIdG("CS101", "12345", "*", a);

    printf("\nLooking up CS205, CS120 on table CP:");
    lookupCP("CS205", "CS120", c);

    printf("\nLooking up CS101, * on table CP after delete:");
    deleteCR("CS101", "*", e);
    lookupCR("CS101", "*", e);

    struct TUPLE* figureD = createTupleCP("CS205", "CS120");
    printf("\nInserting figure d, and then looking up:");
    insertCourseFirst(figureD, c);
    lookupCP("CS205", "CS120", c);

    struct TUPLE* figureE = createTupleCP("CS205", "CS101");
    printf("\nInserting figure e, and then looking up:");
    insertCourseFirst(figureE, c);
    lookupCP("CS205", "CS101", c);
}