create table physician (
  eid integer primary key,
  name varchar(25) NOT NULL,
  position varchar(40) NOT NULL,
); 

insert into physician values(1,'John Dorian','Staff Internist');
insert into physician values(2,'Elliot Reid','Attending Physician');
insert into physician values(3,'Christopher Turk','Surgical Attending Physician');
insert into physician values(4,'Percival Cox','Senior Attending Physician');
insert into physician values(5,'Bob Kelso','Head Chief of Medicine');
insert into physician values(6,'Todd Quinlan','Surgical Attending Physician');
insert into physician values(7,'John Wen','Surgical Attending Physician');
insert into physician values(8,'Keith Dudemeister','MD Resident');
insert into physician values(9,'Molly Clock','Attending Psychiatrist');

create table department (
  did integer primary key,
  name varchar(20) not null,
  head integer not null
    constraint fk_department_physician references physician
);

insert into Department values(1,'General Medicine',4);
insert into Department values(2,'Surgery',7);
insert into Department values(3,'Psychiatry',9);
insert into department values(4,'Pediatric',3)

create table works_in (
  physician integer 
    constraint fk_works_in_physician references physician,
  department integer NOT NULL
    constraint fk_works_in_department references department,
  primary key(physician, department)
);

insert into works_in values(1,1);
insert into works_in values(2,1);
insert into works_in values(3,1);
insert into works_in values(3,2);
insert into works_in values(4,1);
insert into works_in values(5,1);
insert into works_in values(6,2);
insert into works_in values(7,1);
insert into works_in values(7,2);
insert into works_in values(8,1);
insert into works_in values(9,3)

create table patient (
  pid integer primary key,
  name varchar(25) not null,
  address varchar(30)  not null,
  phone char(10) not null,
  insuranceID integer,
);

insert into patient values(100000001,'John Smith','42 Foobar Lane','0775550256',68476213);
insert into patient values(100000002,'Grace Ritchie','37 Snafu Drive','0765550512',36546321);
insert into patient values(100000003,'Random J. Patient','101 Omgbbq Street','0715551204',65465421);
insert into patient values(100000004,'Dennis Doe','1100 Foobaz Avenue','0785552048',68421879);

create table appointment (
  appointmentId integer primary key,
  patient integer not null
    constraint fk_appointment_patient references patient,
  physician integer not null
    constraint fk_appointment_physician references physician,
  startTime datetime not null,
  endTime datetime not null,
  room char(4) not null
);

insert into appointment values(13216584,100000001,1,'2014-01-24 10:00','2014-01-24 11:00','A201');
insert into appointment values(26548913,100000002,2,'2014-04-24 10:00','2014-04-24 11:00','B101');
insert into appointment values(36549879,100000001,1,'2014-04-25 10:00','2014-04-25 11:00','A201');
insert into appointment values(46846589,100000004,4,'2014-03-25 10:00','2014-04-25 11:00','B085');
insert into appointment values(59871321,100000004,4,'2015-04-26 10:00','2015-04-26 11:00','C100');
insert into appointment values(69879231,100000003,2,'2015-04-26 11:00','2015-04-26 12:00','C101');
insert into appointment values(76983231,100000001,3,'2015-04-26 12:00','2015-04-26 13:00','C100');
insert into appointment values(86213939,100000004,9,'2015-04-27 10:00','2015-04-21 11:00','A105');
insert into appointment values(93216548,100000002,2,'2015-04-27 10:00','2015-04-27 11:00','B100');

create table drugs (
  code integer primary key,
  name varchar(25) not null,
  brand varchar(20) not null,
);

insert into drugs values(1,'Procrastin-X','X');
insert into drugs values(2,'Thesisin','Harcourts Labs');
insert into drugs values(3,'Awakin','Bar Laboratories');
insert into drugs values(4,'Crescavitin','Baz Industries');
insert into drugs values(5,'Melioraurin','SM Pharmaceuticals');

create table prescribes (
  physician integer
    constraint fk_prescribes_physician references physician,
  patient integer 
    constraint fk_prescribes_patient references patient,
  drug integer
    constraint fk_prescribes_drug references drugs,
  date datetime not null,
  appointment integer
    constraint fk_prescribes_appointment references appointment,
  dose integer,
  primary key(physician, patient, drug, date)
);

insert into prescribes values(1,100000001,1,'2008-04-24 10:47',13216584,5);
insert into prescribes values(9,100000004,2,'2008-04-27 10:53',86213939,10);
insert into prescribes values(9,100000004,2,'2008-04-30 16:53',NULL,5)


select * from physician
select * from department
select * from drugs
select * from appointment
select * from patient
select * from works_in
select * from prescribes
select * from drugs

--Activity 1:
    SELECT name FROM physician WHERE name LIKE 'John%';
    SELECT name FROM physician WHERE eid NOT IN 
    (
        SELECT head FROM department
    )
   
    select drug, count(*) AS COUNT 
    FROM prescribes
    GROUP By drug;  

    SELECT TOP 1 d.name AS 'Number of Times'
    FROM drugs d
    JOIN prescribes p ON d.code = p.drug
    GROUP BY d.name
    ORDER BY COUNT(*) DESC;

    CREATE FUNCTION dbo.displayphysicians(@depID INT)
    RETURNS int
    AS
    BEGIN
        DECLARE @count  INT;
        SELECT @count = COUNT(*)
        FROM works_in
        WHERE department = @depID;
        RETURN  @COUNT;
    END;
    
SELECT dbo.displayphysicians(3) AS NumberOfDoctors;

CREATE FUNCTION dbo.displaydates(@physician_id INT , @date DATE)
RETURNS INT
AS 
BEGIN
        DECLARE @count  INT;
        SELECT @count = COUNT(*)
        FROM appointment
        WHERE physician = @physician_id
        and cast (startTime as date) = @date;
        RETURN @count;
END;

SELECT dbo.displaydates(1, '2014-01-24 10:00') AS NumberOfAppointments;
--Activity 3: Working with Stored-Procedures

CREATE PROCEDURE displaynumberomedgivenbydoc
    @physicianID INT,
    @patientID INT
AS
BEGIN 
    DECLARE @drugCount INT;

    SELECT @drugCount = COUNT(*)
    FROM prescribes
    WHERE physician = @physicianID AND patient = @patientID;

    PRINT 'NUMBER OF DRUGS prescribed: ' + CAST(@drugCount AS VARCHAR);
END;
EXEC displaynumberomedgivenbydoc @physicianID = 101, @patientID = 2002; 


CREATE TRIGGER  
