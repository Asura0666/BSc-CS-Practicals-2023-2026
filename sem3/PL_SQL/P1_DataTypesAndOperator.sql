
--Difference between CHAR AND VARCHAR data types
DECLARE 
  F_Name char(15);
  L_Name varchar2(15);
BEGIN 
  F_Name := 'SACHIN';
  L_Name := 'TENDULKAR';
  
  dbms_output.put_line('||' || F_Name || '||');
  dbms_output.put_line('||' || L_Name || '||');
END;
/

--Addition of 2 Numbers
DECLARE
  NUM1 INT;
  NUM2 INT;
  ADD_RESULT INT;
BEGIN
  NUM1 := 5; 
  NUM2 := 6;
  ADD_RESULT := NUM2 + NUM1;
  DBMS_OUTPUT.PUT_LINE('ADDITION: ' || ADD_RESULT); 
END;
/

--PRODUCT OF 2 number
DECLARE
  NUM1 INT;
  NUM2 INT;
  PRODUCT_RESULT INT;
BEGIN
  NUM1 := 5; 
  NUM2 := 6;
  PRODUCT_RESULT := NUM2 * NUM1;
  DBMS_OUTPUT.PUT_LINE('PRODUCT_RESULT: ' || PRODUCT_RESULT); 
END;
/

--Find reamainder
DECLARE
  NUM1 NUMBER := 10; 
  NUM2 NUMBER := 3;  
  REMAINDER_RESULT NUMBER;
BEGIN
  IF NUM2 = 0 THEN
    DBMS_OUTPUT.PUT_LINE('ERROR: DIVISION BY ZERO IS NOT ALLOWED.');
  ELSE
    REMAINDER_RESULT := NUM1 MOD NUM2;
    DBMS_OUTPUT.PUT_LINE('REMAINDER: ' || REMAINDER_RESULT);
  END IF;
END;
/

--Swap number using temp and without temp
DECLARE
  NUM1 INT := 5;
  NUM2 INT := 10;
  TEMP INT;
BEGIN
  -- Before Swap
  DBMS_OUTPUT.PUT_LINE('BEFORE SWAP:');
  DBMS_OUTPUT.PUT_LINE('NUM1: ' || NUM1 || ', NUM2: ' || NUM2);

  -- Swap using a temporary variable
  TEMP := NUM1;
  NUM1 := NUM2;
  NUM2 := TEMP;

  -- After Swap
  DBMS_OUTPUT.PUT_LINE('AFTER SWAP (USING TEMP VARIABLE):');
  DBMS_OUTPUT.PUT_LINE('NUM1: ' || NUM1 || ', NUM2: ' || NUM2);
END;
/

DECLARE
  NUM1 INT := 5;
  NUM2 INT := 10;
BEGIN
  -- Before Swap
  DBMS_OUTPUT.PUT_LINE('BEFORE SWAP:');
  DBMS_OUTPUT.PUT_LINE('NUM1: ' || NUM1 || ', NUM2: ' || NUM2);

  -- Swap without a temporary variable
  NUM1 := NUM1 + NUM2;
  NUM2 := NUM1 - NUM2;
  NUM1 := NUM1 - NUM2;

  -- After Swap
  DBMS_OUTPUT.PUT_LINE('AFTER SWAP (WITHOUT TEMP VARIABLE):');
  DBMS_OUTPUT.PUT_LINE('NUM1: ' || NUM1 || ', NUM2: ' || NUM2);
END;
/
