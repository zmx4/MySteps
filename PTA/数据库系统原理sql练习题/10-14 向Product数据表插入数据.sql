CREATE TABLE Product
(product_id      CHAR(4)      NOT NULL, --商品编号
 product_name    VARCHAR(100) NOT NULL, --商品名称
 product_type    VARCHAR(32)  NOT NULL, --商品种类
 sale_price      INTEGER ,              --销售价格
 purchase_price  INTEGER ,              --进货价格
 regist_date     DATE ,                 --登记日期
 PRIMARY KEY (product_id)); 
insert into Product
values('0003','菜刀','厨房用具','50','20','2019-09-20');