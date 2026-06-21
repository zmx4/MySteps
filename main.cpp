#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 复用之前的结果结构体
struct DiskResult {
    std::vector<int> accessOrder; // 磁头访问的磁道顺序
    int totalSeekLength;          // 总寻道长度
    double avgSeekLength;         // 平均寻道长度
};

/**
 * @brief 执行 SCAN (电梯算法) 磁盘调度算法
 * @param requests 初始的磁道请求序列
 * @param currentHead 磁头当前所在的初始位置
 * @param direction 初始移动方向：1 表示向外(递增)，-1 表示向内(递减)
 * @return DiskResult 包含访问顺序、总寻道长度和平均寻道长度的结果结构体
 */
DiskResult runSCAN(std::vector<int> requests, int currentHead, int direction = 1) {
    DiskResult result;
    result.totalSeekLength = 0;
    int n = requests.size();

    if (n == 0) return result;

    // 1. 对请求序列进行排序，便于按顺序扫描
    std::sort(requests.begin(), requests.end());

    int head = currentHead;
    result.accessOrder.push_back(head); // 记录起始位置

    // 2. 找到当前磁头位置在排序后数组中的分割点
    // lower_bound 返回第一个 >= head 的迭代器
    auto it = std::lower_bound(requests.begin(), requests.end(), head);
    int splitIndex = std::distance(requests.begin(), it);

    // 3. 根据初始方向决定扫描顺序
    if (direction == 1) { 
        // 向外(递增)方向扫描
        for (int i = splitIndex; i < n; ++i) {
            result.totalSeekLength += std::abs(requests[i] - head);
            head = requests[i];
            result.accessOrder.push_back(head);
        }
        // 到达边界后反向，处理剩余（递减方向）的请求
        for (int i = splitIndex - 1; i >= 0; --i) {
            result.totalSeekLength += std::abs(requests[i] - head);
            head = requests[i];
            result.accessOrder.push_back(head);
        }
    } else { 
        // 向内(递减)方向扫描
        for (int i = splitIndex - 1; i >= 0; --i) {
            result.totalSeekLength += std::abs(requests[i] - head);
            head = requests[i];
            result.accessOrder.push_back(head);
        }
        // 到达边界后反向，处理剩余（递增方向）的请求
        for (int i = splitIndex; i < n; ++i) {
            result.totalSeekLength += std::abs(requests[i] - head);
            head = requests[i];
            result.accessOrder.push_back(head);
        }
    }

    // 计算平均寻道长度（注意：总步数是 n，因为要处理 n 个请求）
    result.avgSeekLength = static_cast<double>(result.totalSeekLength) / n;
    return result;
}

// 测试示例
int main() {
    std::vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int startHead = 53;

    // 假设初始方向为向外（递增）
    DiskResult res = runSCAN(requests, startHead, 1);

    std::cout << "SCAN 访问顺序: ";
    for (int track : res.accessOrder) {
        std::cout << track << " ";
    }
    std::cout << "\n总寻道长度: " << res.totalSeekLength << std::endl;
    std::cout << "平均寻道长度: " << res.avgSeekLength << std::endl;

    return 0;
}