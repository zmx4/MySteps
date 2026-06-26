Create table my_student(
StudentID   char(12) primary key,
StudentName char(8) not null,
Sex  char(2) not null check(sex in('男','女')),
Birth  datetime not null
);
insert into my_student values('212254203161','李芳芳','女','1999-10-1');