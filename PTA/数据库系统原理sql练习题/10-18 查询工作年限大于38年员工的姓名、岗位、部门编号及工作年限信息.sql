 CREATE TABLE `dept` (
  `deptno` decimal(2,0) NOT NULL,
  `dname` varchar(14) DEFAULT NULL,
  `loc` varchar(13) DEFAULT NULL,
  PRIMARY KEY (`deptno`)
) ;

CREATE TABLE `emp` (
  `empno` decimal(4,0) NOT NULL,
  `ename` varchar(10) DEFAULT NULL,
  `job` varchar(9) DEFAULT NULL,
  `mgr` decimal(4,0) DEFAULT NULL,
  `hiredate` date DEFAULT NULL,
  `sal` decimal(7,2) DEFAULT NULL,
  `comm` decimal(7,2) DEFAULT NULL,
  `deptno` decimal(2,0) DEFAULT NULL,
  PRIMARY KEY (`empno`)
) ;

CREATE TABLE `salgrade` (
  `grade` decimal(10,0) NOT NULL,
  `losal` decimal(10,0) DEFAULT NULL,
  `hisal` decimal(10,0) DEFAULT NULL,
  PRIMARY KEY (`grade`)
);

SELECT ename, job, deptno, TIMESTAMPDIFF(YEAR, hiredate, CURDATE()) AS 工作年限
FROM emp
WHERE TIMESTAMPDIFF(YEAR, hiredate, CURDATE()) > 38;