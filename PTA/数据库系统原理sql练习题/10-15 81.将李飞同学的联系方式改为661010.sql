CREATE TABLE `student`  (
  `SId` char(9),
  `GId` char(2),
  `SName` char(8),
  `SSexy` char(2),
  `SBdate` date,
  `STele` char(11)
);
update student set STele = '661010' where SName = '李飞';