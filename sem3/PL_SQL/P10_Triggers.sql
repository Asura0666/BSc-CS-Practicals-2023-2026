-- 1. Create table student87
CREATE TABLE student87(
  student_id INTEGER,
  s_name VARCHAR2(10),
  score INTEGER
);

-- 2. Insert values into student87
INSERT INTO student87 VALUES (1, 'sam', 800);
INSERT INTO student87 VALUES (2, 'ram', 699);
INSERT INTO student87 VALUES (3, 'tom', 250);
INSERT INTO student87 VALUES (4, 'om', 350);
INSERT INTO student87 VALUES (5, 'jay', 750);

-- View student87 data
SELECT * FROM student87;

-- 3. Create table affect
CREATE TABLE affect(
  a_id INTEGER,
  a_name VARCHAR2(10),
  score INTEGER
);

-- 4. Trigger before_insert on student87 to insert into affect
CREATE OR REPLACE TRIGGER before_insert
BEFORE INSERT ON student87
FOR EACH ROW
BEGIN
  INSERT INTO affect(a_id, a_name, score)
  VALUES(:new.student_id, :new.s_name, :new.score);
END;
/

-- Insert into student87 which triggers before_insert
INSERT INTO student87 VALUES (6, 'sai', 550);

-- 5. Trigger before_delete on student87 to insert into affect
CREATE OR REPLACE TRIGGER before_delete
BEFORE DELETE ON student87
FOR EACH ROW
BEGIN
  INSERT INTO affect(a_id, a_name, score)
  VALUES(:old.student_id, :old.s_name, :old.score);
END;
/

-- Delete from student87 which triggers before_delete
DELETE FROM student87 WHERE student_id = 3;

-- 6. Trigger before_update on student87 to insert into affect
CREATE OR REPLACE TRIGGER before_update
BEFORE UPDATE ON student87
FOR EACH ROW
BEGIN
  INSERT INTO affect(a_id, a_name, score)
  VALUES(:old.student_id, :old.s_name, :old.score);
END;
/

-- Update student87 which triggers before_update
UPDATE student87 SET score = 900 WHERE student_id = 5;

-- 7. Trigger after_insert on student87 to insert into affect
CREATE OR REPLACE TRIGGER after_insert
AFTER INSERT ON student87
FOR EACH ROW
BEGIN
  INSERT INTO affect(a_id, a_name, score)
  VALUES(:new.student_id, :new.s_name, :new.score);
END;
/

-- Insert into student87 which triggers after_insert
INSERT INTO student87 VALUES (7, 'raj', 500);

-- 8. Trigger after_delete on student87 to insert into affect
CREATE OR REPLACE TRIGGER after_delete
AFTER DELETE ON student87
FOR EACH ROW
BEGIN
  INSERT INTO affect(a_id, a_name, score)
  VALUES(:old.student_id, :old.s_name, :old.score);
END;
/

-- Delete from student87 which triggers after_delete
DELETE FROM student87 WHERE student_id = 1;

-- 9. Trigger after_update on student87 to insert into affect
CREATE OR REPLACE TRIGGER after_update
AFTER UPDATE ON student87
FOR EACH ROW
BEGIN
  INSERT INTO affect(a_id, a_name, score)
  VALUES(:old.student_id, :old.s_name, :old.score);
END;
/

-- Update student87 which triggers after_update
UPDATE student87 SET score = 1900 WHERE student_id = 7;

-- 10. Disable the after_update trigger and update student87
ALTER TRIGGER after_update DISABLE;
UPDATE student87 SET score = 800 WHERE student_id = 2;

-- View the data from student87 and affect
SELECT * FROM student87;
SELECT * FROM affect;

-- 11. Enable the after_update trigger and update student87
ALTER TRIGGER after_update ENABLE;
UPDATE student87 SET s_name = 'rahul' WHERE student_id = 7;

-- 12. Drop the after_update trigger
DROP TRIGGER after_update;
--OR
TRIGGER after_update DROPPED;