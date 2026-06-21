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

select students.sname
from students,sc
where students.sno = sc.sno and sc.cno = '0000008' and students.sname in (select students.sname
from students,sc
where students.sno = sc.sno and sc.cno = '0000007');