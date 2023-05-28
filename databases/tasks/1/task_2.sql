-- Marios Papazogloy ice21390179

drop database if exists new_personnel;
create database new_personnel;
use new_personnel;

create table dept (
 DEPTNO int not null,
 DNAME varchar(14),
 LOC varchar(14),
 primary key(DEPTNO)
);

create table emp (
	EMPNO int not null, 
    ENAME varchar(10),
    JOB varchar(25),
	HIREDATE date, 
    MGR int, 
    SAL float, 
    COMM int,
	DEPTNO int,
    primary key (EMPNO),
    foreign key(DEPTNO) references dept(DEPTNO)
);

create table proj (
   PROJ_CODE int not null,
   DESCRIPTION varchar(12),
   primary key(PROJ_CODE)
);

create table assign (
  EMPNO int not null,
  PROJ_CODE int not null,
  A_TIME int not null,
  primary key(EMPNO, PROJ_CODE),
  foreign key(EMPNO) references emp(EMPNO),
  foreign key(PROJ_CODE) references proj(PROJ_CODE)
);

insert into dept values
	(10, 'Accounting', 'Athens'),
	(20, 'Sales', 'London'),
    (30, 'Research', 'Athens'),
    (40, 'Payroll', 'London')
	;
    
insert into emp values 
	(10, 'CODD', 'Analyst', '1989-01-01', 15, 3000, null, 10),
    (15, 'ELMASRI', 'Analyst', '1995-05-02', 15, 1200, 150, 10),
    (10, 'NAVATHE', 'Salesman', '1977-07-07', 20, 2000, null, 20),
    (10, 'DATE', 'Programmer','2004-05-04', 15, 1800, 200, 10)
    ;

insert into proj values
   (100, 'Payroll'),
   (200, 'Personnel'),
   (300, 'Sales')   
   ;
   
insert into assign values
   (10, 100, 40),
   (10, 200, 60),
   (15, 100, 100),
   (20, 200, 100),
   (30, 100, 100)
   ;


select * from emp;

/*


select 
	ENAME, SAL, COMM
from 
	emp, assign 
where 
	emp.EMPNO = assign.EMPNO
;

*/ 
