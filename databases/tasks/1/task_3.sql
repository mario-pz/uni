-- Marios Papazogloy ice21390179


-- Δημιουργία βάσης new_personnel και τα στοιχεία της
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
    (20, 'NAVATHE', 'Salesman', '1977-07-07', 20, 2000, null, 20),
    (30, 'DATE', 'Programmer','2004-05-04', 15, 1800, 200, 10)
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
   
-- Άσκηση 1
select distinct ENAME, COMM from emp, dept 
	where emp.DEPTNO = dept.DEPTNO order by COMM;


-- Άσκηση 2
select distinct ENAME, JOB, SAL from emp order by SAL asc;
select distinct ENAME, JOB, SAL from emp order by SAL desc;

-- Άσκηση 3
select avg(SAL) from emp having count(*) > 1;

-- Άσκηση 4
select DEPTNO, avg(DATE_FORMAT(current_date(), "%Y") - DATE_FORMAT(HIREDATE, "%Y")) "ΠΡΟΗΠΗΡΕΣΙΑ" from emp group by DEPTNO;

-- Άσκηση 5
select PROJ_CODE, ENAME, JOB from emp,assign where emp.EMPNO = assign.EMPNO order by JOB;

-- Άσκηση 6

select DEPT.DNAME, EMP1.ENAME as 'MANAGER', EMP2.ENAME as 'EMPLOYEE'
from EMP EMP1
join EMP EMP2 on EMP2.MGR = EMP1.EMPNO
inner join DEPT on DEPT.DEPTNO = EMP1.DEPTNO
order by DEPT.DNAME, EMP2.ENAME;

-- Άσκηση 7
select distinct ENAME, JOB, LOC from emp, dept 
	where emp.DEPTNO = dept.DEPTNO;

-- Άσκηση 8
select distinct ENAME, DESCRIPTION from emp, proj, assign 
	where emp.EMPNO = assign.EMPNO and assign.PROJ_CODE = proj.PROJ_CODE and proj.PROJ_CODE = 100;