create table student(
sno char(8) primary key,
sname varchar(10) not null,
gender char(2) check(gender='男' or gender='女'),
birthdate date,
major varchar(20) default '软件工程'
);
select sname, birthdate
from student
where gender = '女' and major = '计算机科学';