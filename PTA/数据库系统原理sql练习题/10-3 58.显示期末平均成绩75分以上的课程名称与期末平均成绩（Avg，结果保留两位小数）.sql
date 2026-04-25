/*
CREATE TABLE `course`  (
  `CId` char(4),
  `PCId` char(4),
  `DId` char(2),
  `CName` char(20),
  `CCredit` int(11),
  `CHour` int(11),
  `CAttr` char(6),
  `CNum` int(11)
);
CREATE TABLE `sc`  (
  `SCId` int(11),
  `CId` char(4),
  `SId` char(9),
  `SCTerm` char(12),
  `SCScore1` float,
  `SCScore2` float,
  `SCScore3` float,
  `SCScore` float
);
*/
SELECT 
    course.CName, 
    ROUND(AVG(sc.SCScore3), 2) AS Avg
FROM 
    course 
JOIN 
    sc 
ON 
    course.CId = sc.CId
GROUP BY 
    course.CId, 
    course.CName
HAVING 
    AVG(sc.SCScore3) > 75;
