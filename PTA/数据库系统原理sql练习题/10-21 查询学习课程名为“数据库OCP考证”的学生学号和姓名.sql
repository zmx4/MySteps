CREATE TABLE students (
 sno char(7) ,
  sname char(8) NOT NULL,
  class char(10),
  ssex char(2),
  bday date ,
  bplace char(10) ,
  IDNum char(18) ,
  sdept char(16),
  phone char(11),
  PRIMARY KEY (sno)
) ;

CREATE TABLE sc (
 sno char(7) ,
 cno char(7) ,
 score decimal(4,1),
 point decimal(2,1),
 PRIMARY KEY (sno,cno)
) ;

CREATE TABLE course (
 cno char(7) ,
 cname varchar(20) NOT NULL,
 cpno char(7),
 ccredit int NOT NULL,
 PRIMARY KEY (cno)
) ;
select sno,sname
from students
where sno in (select sno
    from sc, course
    where sc.cno = course.cno and course.cname = '数据库OCP考证');