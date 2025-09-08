CREATE TABLE emp (
    empID INTEGER PRIMARY KEY,
    fName VARCHAR(20),
    lName VARCHAR(20),
    salary FLOAT
);
select * from emp
INSERT INTO emp (empID, fName, lName, salary) 
VALUES (100, 'Mali', 'Kevin', 100000);

INSERT INTO emp (empID, fName, lName, salary) 
VALUES (101, 'Vivi', 'De Silva', 120000);

INSERT INTO emp (empID, fName, lName, salary) 
VALUES (103, 'Nadun', 'Ranmuthu', 110000);

INSERT INTO emp (empID, fName, lName, salary) 
VALUES (107, 'Dev', 'Steven', 140000);

INSERT INTO emp (empID, fName, lName, salary) 
VALUES (110, 'Kithmi', 'Perera', 150000);

SELECT * FROM emp

--Activity 2: 
CREATE PROCEDURE displayEmployeeDetails
AS
BEGIN
    SELECT * FROM emp;
END;
GO

EXEC displayEmployeeDetails;
GO


--Activity 3:

CREATE PROCEDURE displaySalaryGreaterThan100000
AS
BEGIN
    SELECT * FROM emp WHERE salary > 100000;
END;
GO

EXEC displaySalaryGreaterThan100000;
GO

--Activity 4;
CREATE PROCEDURE displaygivenemp
(
    @empID INT
)
AS
BEGIN
    SELECT * FROM emp
    WHERE empID =@empID
END;

DROP PROCEDURE displaygivenemp
EXEC  displaygivenemp  101;

---Activity 6:
CREATE PROCEDURE displaySalary 
    @empID INT,            -- Input parameter
    @salary FLOAT OUTPUT   -- Output parameter
AS
BEGIN
    -- Assign the salary to the output parameter based on empID
    SELECT @salary = salary
    FROM emp
    WHERE empID = @empID;
END;


DROP PROCEDURE displaySalary
DECLARE @s FLOAT
EXEC displaySalary @empID = 101, @salary = @s OUTPUT;
print 'Salary  ' + CAST(@s AS VARCHAR)

--Activity 7:
CREATE PROCEDURE addEnteries 
(
    @empID INT
)
AS
BEGIN
    -- Check if empID already exists
    IF EXISTS (SELECT 1 FROM emp WHERE empID = @empID)
    BEGIN
        PRINT 'In table';
    END
    ELSE 
    BEGIN
        INSERT INTO emp (empID, fName, lName, salary) 
        VALUES (199, 'Dunil', 'G', 5);  -- Remove leading zero in salary
    END
END;
EXEC addEnteries @empID = 199

--Activity 9:
CREATE PROCEDURE addnewEmp
{
}
AS
BEGIN

END


---Activity 10
CREATE FUNCTION getSalary (@Salary FLOAT)
RETURNS INT
AS
BEGIN
    DECLARE @count INT;

    SELECT @count = COUNT(*)
    FROM emp
    WHERE salary > @Salary;

    RETURN @count;
END;

EXEC getSalary @Salary = 5000
DROP FUNCTION getSalary()



--Activity 12
CREATE FUNCTION getSalarymorethan130000()
RETURNS INT
AS
BEGIN
    DECLARE @count INT;

    SELECT @count = COUNT(*)
    FROM emp
    WHERE salary > 130000;

    RETURN @count;
END;
Drop FUNCTION getSalarymorethan13000
SELECT dbo.getSalarymorethan130000() AS TotalAbove130k;


--Activity 13:
CREATE FUNCTION getAVG()
RETURNS FLOAT
AS 
BEGIN
    DECLARE @avgSalary FLOAT;

    SELECT @avgSalary = AVG(salary) FROM emp;

    RETURN @avgSalary;
END;

Drop FUNCTION getAVG

SELECT dbo.getAVG();
