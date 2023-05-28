-- Marios Papazogloy ice21390179

drop database if exists NEW_PERSONNEL;
create database NEW_PERSONNEL;

use NEW_PERSONNEL;

create table dept (
 DEPTNO INT NOT NULL,
 DNAME varchar(14),
 LOC varchar(14)
);

create table emp (
	EMPNO int not null, 
    ENAME varchar(10),
    JOB varchar(25),
	HIREDATE date, 
    MGR int, 
    SAL float, 
    COMM int,
	DEPTNO int
);

create table proj (
   PROJ_CODE int not null,
   DESCRIPTION varchar(12)
);

create table assign (
  EMPNO int not null,
  PROJ_CODE int not null,
  A_TIME int not null
);


insert into dept values
	(10, 'Accounting', 'Athens'),
	(20, 'Sales', 'London'),
    (30, 'Research', 'Athens'),
    (40, 'Payroll', 'London')
	;

-- select * from dept;
/*
     ______________________________
	|'10' |'Accounting' |'Athens'  |
	|'20' |'Sales'      |'London'  |
	|'30' |'Research'   |'Athens'  |
	|'40' |'Payroll'    |'London'  |
*/

insert into emp values 
	(10, 'CODD', 'Analyst', '1989-01-01', 15, 3000, null, 10),
    (15, 'ELMASRI', 'Analyst', '1995-05-02', 15, 1200, 150, 10),
    (10, 'NAVATHE', 'Salesman', '1977-07-07', 20, 2000, null, 20),
    (10, 'DATE', 'Programmer','2004-05-04', 15, 1800, 200, 10)
    ;

-- describe emp;
-- select * from emp;
/*
 EMPNO ENAME JOB HIREDATE MGR SAL COMM DEPTNO 
________________________________________________________
'10','CODD','Analyst','2022-05-14','15','3000',NULL,'10'
'15','ELMASRI','Analyst','2022-05-14','15','1200','150','10'
'10','NAVATHE','Salesman','2022-05-14','20','2000',NULL,'20'
'10','DATE','Programmer','2022-05-14','15','1800','200','10'
*/
    
insert into proj values
   (100, 'Payroll'),
   (200, 'Personnel'),
   (300, 'Sales')   
   ;


-- select * from proj;
/*
	PROJ_CODE | DESCRIPTION
     ______________________
	| '100'   |'Payroll'   |
	| '200'   |'Personnel' |
	| '300'   |'Sales'     |
*/

insert into assign values
   (10, 100, 40),
   (10, 200, 60),
   (15, 100, 100),
   (20, 200, 100),
   (30, 100, 100)
   ;

-- select * from assign;

/*
	 EMPNO | PROJ_CODE | A_TIME
     _________________________
	| '10' |  '100' |  '40'  |
	| '10' |  '200' |  '60'  |
	| '15' |  '100' |  '100' |
	| '20' |  '200' |  '100' |
	| '30' |  '100' |  '100' |
*/
