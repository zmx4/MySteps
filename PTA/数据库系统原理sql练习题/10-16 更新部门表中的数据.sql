CREATE TABLE dept (  
DId CHAR(2) NOT NULL,           -- 部门编号  
DName VARCHAR(20) NOT NULL,     -- 部门名称  
DAddr VARCHAR(20) NULL,         -- 地址  
DTele VARCHAR(16) NULL,         -- 电话  
DEmail VARCHAR(50) NULL,        -- 邮箱  
PRIMARY KEY (DId)              
);
update dept set DEmail = 'el@163.com' where DId='EL';