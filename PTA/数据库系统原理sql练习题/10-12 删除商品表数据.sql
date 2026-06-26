CREATE TABLE sh_goods (
  id INT  PRIMARY KEY,                         --商品id
  category_id INT  NOT NULL DEFAULT 0 ,        -- 商品分类id
  name VARCHAR(120) NOT NULL,                  --商品名称
  keyword VARCHAR(255) NOT NULL,               -- 关键词编号
  content TEXT NOT NULL ,                      --商品详情
  price DECIMAL(10, 2)  NOT NULL DEFAULT 0 ,   --价格
  stock INT  NOT NULL DEFAULT 0,               -- 库存
  score DECIMAL(3, 2)  NOT NULL DEFAULT 0 ,    -- 用户评分
  comment_count INT  NOT NULL DEFAULT 0        -- 评论数量
) ;
delete from sh_goods where keyword = '003';