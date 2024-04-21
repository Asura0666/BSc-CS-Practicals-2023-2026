
CREATE TABLE Student (
  id int primary key,
  name varchar(20),
  phone_no numeric(10,5)
);

SELECT *  FROM Student;

ALTER TABLE Student ADD COLUMN age int ;

SELECT * FROM Student;

DROP TABLE Student;