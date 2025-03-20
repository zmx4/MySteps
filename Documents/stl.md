

# 容器

## 操作
- `empty()` 检验容器是否为空,若为空,返回true.
- `size()` 返回容器大小
- `push_back()` 将元素插入容器尾部
- `push_front()` 将元素插入容器头部
- `front()` 返回容器头部元素
- `back()` 返回容器尾部元素
- `begin()` 返回元素头部迭代器
- `end()` 返回元素尾部迭代器
- `accumulate()` 返回区间内元素的和

### 1)`vector`

支持操作:`empty()` `size()` `push_back()` `front()` `back()` `[]` 

### 2)`bitset`

bitset <<n>n> b(num)

`<n>`表示上限2**n

`(num)`将num转换为二进制存储在b中

`count()`用于统计数的二进制中1的个数