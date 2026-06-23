-- 创建选课表  
CREATE TABLE sc (  
SCId INT NOT NULL, -- 选课序号，主键  
CId CHAR(4) NOT NULL, -- 课程编号 
SId CHAR(9) NOT NULL, -- 学号  
SCTerm CHAR(12) NULL, -- 开课学年/学期  
SCScore1 FLOAT NULL ,-- 平时成绩  
SCScore2 FLOAT NULL, -- 期中成绩  
SCScore3 FLOAT NULL, -- 期末成绩  
SCScore FLOAT NULL ,-- 总评成绩  
PRIMARY KEY (SCId)
);
SELECT AVG(SCScore3) AS avg_score
FROM sc
WHERE CId = '1';