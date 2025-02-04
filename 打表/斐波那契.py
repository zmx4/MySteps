import math

def fibonacci(n):
    # 确保输入为非负整数
    if n < 0:
        return "输入必须是非负整数"
    elif n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        sqrt_5 = math.sqrt(5)
        phi = (1 + sqrt_5) / 2   # 黄金分割比
        psi = (1 - sqrt_5) / 2   # 黄金分割比的共轭
        
        # 使用比内公式计算斐波那契数
        fib_n = (phi**n - psi**n) / sqrt_5
        
        # 四舍五入取整，因为计算过程中可能产生小数部分
        return round(fib_n)

# 测试代码
if __name__ == "__main__":
    for i in range(5,100):
        res = fibonacci(i-1)*fibonacci(i+1) - fibonacci(i)*fibonacci(i)
        print(res)