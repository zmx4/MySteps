/*
create table teacher(
   tno char(15) primary key,
   tname varchar(10) not null,
   gender char(2),
   deptname varchar(50) ,  -- 所属系部
   title varchar(20)       -- 职称
);
*/
select tname from teacher where tname not like '刘%';