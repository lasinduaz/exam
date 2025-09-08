  CREATE TABLE EmpLog (
    EmpId      INT,
    Log_date   DATE,
    New_salary FLOAT,
    Action     VARCHAR(20)
);

SELECT * FROM EmpLog

DROP TABLE EmpLog
DROP TABLE emp
DROP TRIGGER log_del_emp
DROP TRIGGER log_salary_increase
DROp TRIGGER log_new_emp

  --Activity 2:
CREATE TRIGGER log_salary_increase
ON emp
AFTER UPDATE
AS
BEGIN
    DECLARE @EMPID INT, @SALARY FLOAT;

    -- Assign values from the inserted pseudo-table
    SELECT @EMPID = e.EmpId, @SALARY = e.salary
    FROM inserted e;

    -- Insert log entry
    INSERT INTO EmpLog (EmpId, Log_date, New_salary, Action)
    VALUES (@EMPID, GETDATE(), @SALARY, 'NEW SALARY');
END;

update emp
set salary = salary + 5000
where empID = 100


--Activity 3:
CREATE TRIGGER log_del_emp
on emp
AFTER DELETE
AS
BEGIN
    DECLARE @EMPID INT, @SALARY INT;

    SELECT @EMPID = e.EmpId, @SALARY = e.salary FROM deleted e;

    --enter log table
    INSERT INTO EmpLog (EmpId, Log_date, New_salary, Action)
    VALUES (@EMPID, GETDATE(), @SALARY, 'User Deleted ');
END;


delete from emp where empID=101

--Activity 3:
CREATE TRIGGER log_new_emp
on emp
AFTER INSERT
AS
BEGIN
    DECLARE @EMPID INT , @SALARY INT;

    select @EMPID= e.EmpId,  @SALARY = e.salary FROM inserted e;
        --enter log table
    INSERT INTO EmpLog (EmpId, Log_date, New_salary, Action)
    VALUES (@EMPID, GETDATE(), @SALARY, 'User Add ');
    
END;

insert into emp values(121,'Kamal','Perera',100000)