-- Count Records in Software Table
DECLARE
    C NUMBER := 0;
    CURSOR C1 IS SELECT * FROM SOFTWARE;
BEGIN
    FOR I IN C1 LOOP
        C := C1%ROWCOUNT;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Total number of records in the Software table: ' || C);
END;
/


-- Fetch Programmer Names Based on Skills
SET SERVEROUTPUT ON;
DECLARE
    TYPE ProgrammerRec IS RECORD (
        ProgrammerName VARCHAR2(50)
    );
    Language PROGRAMMER.PROF1%TYPE := '&Language';
    CURSOR C2 (Language IN VARCHAR2) IS
        SELECT NAME
        FROM PROGRAMMER
        WHERE PROF1 = Language OR PROF2 = Language;
BEGIN
    FOR ProgrammerRow IN C2(Language) LOOP
        DBMS_OUTPUT.PUT_LINE('Programmer: ' || ProgrammerRow.NAME);
    END LOOP;
END;
/


-- Fetch Studies by Course
SET SERVEROUTPUT ON;
DECLARE
    TYPE StudentRec IS RECORD (
        StudentName VARCHAR2(50)
    );
    CourseName STUDIES.COURSE%TYPE := '&CourseName';
    CURSOR C3 (CourseName IN VARCHAR2) IS
        SELECT NAME
        FROM STUDIES
        WHERE COURSE = CourseName;
    StudentRow StudentRec;
BEGIN
    OPEN C3(CourseName);
    LOOP
        FETCH C3 INTO StudentRow;
        EXIT WHEN C3%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Student: ' || StudentRow.StudentName);
    END LOOP;
    CLOSE C3;
END;
/

--  Count Students Enrolled by Course
SET SERVEROUTPUT ON;
DECLARE
    TYPE CourseRec IS RECORD (
        CourseName VARCHAR2(50),
        StudentCount NUMBER
    );
    CURSOR C4 IS
        SELECT COURSE, COUNT(*) AS StudentCount
        FROM STUDIES
        GROUP BY COURSE;
    CourseRow CourseRec;
BEGIN
    OPEN C4;
    LOOP
        FETCH C4 INTO CourseRow;
        EXIT WHEN C4%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Course: ' || CourseRow.CourseName || ', Total Students: ' || CourseRow.StudentCount);
    END LOOP;
    CLOSE C4;
END;
/


-- Fetch Software Titles Based on Language
SET SERVEROUTPUT ON;
DECLARE
    Language SOFTWARE.DEV_IN%TYPE := '&Language';
    CURSOR C5 (Language IN VARCHAR2) IS
        SELECT NAME
        FROM SOFTWARE
        WHERE DEV_IN = Language;
    SoftwareRow C5%ROWTYPE;
BEGIN
    OPEN C5(Language);
    LOOP
        FETCH C5 INTO SoftwareRow;
        EXIT WHEN C5%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Software: ' || SoftwareRow.NAME);
    END LOOP;
    CLOSE C5;
END;
/
