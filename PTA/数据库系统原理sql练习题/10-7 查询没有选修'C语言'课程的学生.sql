CREATE TABLE `stu` (
  `sno` char(4) NOT NULL,
  `sname` char(8) NOT NULL,
  `sex` tinyint(1) DEFAULT NULL,
  `mno` char(2) DEFAULT NULL,
  `birdate` datetime DEFAULT NULL,
  `memo` text,
  PRIMARY KEY (`sno`)
);
CREATE TABLE `cou` (
  `cno` char(4) NOT NULL,
  `cname` varchar(30) NOT NULL,
  `credit` smallint(6) DEFAULT NULL,
  `ptime` char(5) DEFAULT NULL,
  `teacher` char(10) DEFAULT NULL,
  PRIMARY KEY (`cno`)
) ;
CREATE TABLE `sc` (
  `sno` char(4) NOT NULL,
  `cno` char(4) NOT NULL,
  `grade` decimal(6,1) DEFAULT NULL,
  PRIMARY KEY (`sno`,`cno`),
  CONSTRAINT `fk_sc_cno` FOREIGN KEY (`cno`) REFERENCES `cou` (`CNO`),
  CONSTRAINT `fk_sc_sno` FOREIGN KEY (`sno`) REFERENCES `stu` (`sno`)
);
select stu.sno, stu.sname
from stu
where not exists 
(
    select *
    from sc, cou
    where sc.cno = cou.cno and cou.cname = 'C语言' and sc.sno = stu.sno
)