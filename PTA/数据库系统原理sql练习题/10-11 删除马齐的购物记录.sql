
CREATE TABLE customer(

cid CHAR(4) PRIMARY KEY,

cname VARCHAR(20) NOT NULL,

sex CHAR(1) DEFAULT '女',

phone CHAR(11) UNIQUE

);

CREATE TABLE recorder(

id INT PRIMARY KEY  AUTO_INCREMENT,

cid CHAR(4),

gid CHAR(4),

quantity INT NOT NULL,

sale_date DATETIME,

CONSTRAINT recorder_cid_fk FOREIGN KEY (cid) REFERENCES customer(cid)

);

delete from recorder 
where cid in (select cid from customer where cname = '马齐');