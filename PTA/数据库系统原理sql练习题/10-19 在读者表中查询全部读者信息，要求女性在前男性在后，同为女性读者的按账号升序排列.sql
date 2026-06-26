create table 读者(账号 char(4) ,姓名 char(5),性别 char(1) ,等级 char(4),出生日期 date,余额 float)
SELECT *
FROM 读者
ORDER BY CASE 性别
           WHEN '女' THEN 1
           WHEN '男' THEN 2
         END,
         账号 ASC;