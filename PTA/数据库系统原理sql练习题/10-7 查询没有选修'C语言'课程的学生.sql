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
SELECT s.sno AS 学号, s.sname AS 姓名
FROM stu s
WHERE NOT EXISTS (
    SELECT 1
    FROM sc
    JOIN cou ON sc.cno = cou.cno
    WHERE sc.sno = s.sno
      AND cou.cname = 'C语言'
)
ORDER BY s.sno ASC;