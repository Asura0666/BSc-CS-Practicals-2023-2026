-- BASIC CALCULATOR USING CASE STATEMENT
DECLARE
  operator CHAR(2);
  num1 NUMBER;
  num2 NUMBER;
  result NUMBER;
BEGIN
  operator := '&operator ';
  
  DBMS_OUTPUT.PUT_LINE('Enter the first number:');
  num1 := &num1;
  
  DBMS_OUTPUT.PUT_LINE('Enter the second number:');
  num2 := &num2;
  
  CASE operator
    WHEN '+' THEN
      result := num1 + num2;
    WHEN '-' THEN
      result := num1 - num2;
    WHEN '/' THEN
      IF num2 != 0 THEN
        result := num1 / num2;
      ELSE
        DBMS_OUTPUT.PUT_LINE('Error: Division by zero');
        RETURN;
      END IF;
    WHEN '*' THEN
      result := num1 * num2;
    ELSE
      DBMS_OUTPUT.PUT_LINE('Error: Invalid operator');
      RETURN;
  END CASE;
  
  DBMS_OUTPUT.PUT_LINE('Result: ' || result);
END;
/

-- ILLUSTRATING CASE WHEN STATEMENT
DECLARE
  grade CHAR(1) := 'B';
  description VARCHAR2(20);

BEGIN
  CASE grade
    WHEN 'A' THEN
      description := 'Excellent';
    WHEN 'B' THEN
      description := 'Good';
    WHEN 'C' THEN
      description := 'Fair';
    WHEN 'D' THEN
      description := 'Poor';
    ELSE
      description := 'Invalid Grade';
  END CASE;

  DBMS_OUTPUT.PUT_LINE('Grade: ' || grade || ', Description: ' || description);
END;
/

-- PRINT NUMBERS 1 TO 10 USING EXIT WHEN LOOP
DECLARE
  i NUMBER := 1;

BEGIN
  LOOP
    DBMS_OUTPUT.PUT_LINE(i);
    i := i + 1;
    EXIT WHEN i > 10;
  END LOOP;
END;
/

-- PRINT EVEN NUMBERS UPTO 10 USING EXIT WHEN LOOP
DECLARE
  i NUMBER := 2;

BEGIN
  LOOP
    DBMS_OUTPUT.PUT_LINE(i);
    i := i + 2;
    EXIT WHEN i > 10;
  END LOOP;
END;
/

-- PRINT ODD NUMBERS UPTO 10 USING WHILE LOOP
DECLARE
  i NUMBER := 1;

BEGIN
  WHILE i <= 10 LOOP
    IF MOD(i, 2) != 0 THEN
      DBMS_OUTPUT.PUT_LINE(i);
    END IF;
    i := i + 1;
  END LOOP;
END;
/

-- CALCULATE FACTORIAL OF A NUMBER USING FOR LOOP
DECLARE
  num NUMBER := 5;
  factorial NUMBER := 1;

BEGIN
  FOR i IN 1..num LOOP
    factorial := factorial * i;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Factorial of ' || num || ' is ' || factorial);
END;
/

-- PRINT NUMBERS IN REVERSE ORDER USING FOR LOOP
BEGIN
  FOR i IN REVERSE 1..10 LOOP
    DBMS_OUTPUT.PUT_LINE(i);
  END LOOP;
END;
/
