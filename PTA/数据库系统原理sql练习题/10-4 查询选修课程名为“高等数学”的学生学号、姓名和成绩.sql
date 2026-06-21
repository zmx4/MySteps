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
SELECT 
    s.sno,
    s.sname,
    sc.score
FROM students s, sc, course c
WHERE s.sno = sc.sno 
  AND sc.cno = c.cno 
  AND c.cname = '高等数学';