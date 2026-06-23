
CREATE TABLE fruits
(
f_id    char(10)         NOT NULL,
s_id    INT            NOT NULL,
f_name  char(255)      NOT NULL,
f_price decimal(8,2)      NOT NULL,
PRIMARY KEY(f_id) 
);

select f_name, f_price
from fruits
where f_price between 2.00 and 10.20
order by f_price desc, f_name;