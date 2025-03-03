def max_parts(total):
    # 生成7的幂直到超过总金额
    powers_of_7 = []
    power = 1
    while power <= total:
        powers_of_7.append(power)
        power *= 7
    
    # 从大到小排序
    powers_of_7.reverse()
    
    result = 0  # 总份数
    for value in powers_of_7:
        # 每种面值最多使用5个
        count = min(5, total // value)
        total -= count * value
        result += count
    
    # 检查是否能正好分配完
    if total == 0:
        return result
    else:
        return -1  # 无法正好分配

total = 1000000
print(max_parts(total))