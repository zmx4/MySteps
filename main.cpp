#include <iostream>
#include <set>
#include <algorithm>
#include <chrono>

int main()
{
	// 创建一个包含大量元素的set
	std::set<int> largeSet;
	for (int i = 0; i < 1000000; i++)
	{
		largeSet.insert(i);
	}

	// 使用set::find测量时间
	auto start1 = std::chrono::high_resolution_clock::now();
	auto it1 = largeSet.find(999999);
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration1 = end1 - start1;

	// 使用std::find测量时间
	auto start2 = std::chrono::high_resolution_clock::now();
	auto it2 = std::find(largeSet.begin(), largeSet.end(), 999999);
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration2 = end2 - start2;

	std::cout << "set::find用时: " << duration1.count() << " 毫秒\n";
	std::cout << "std::find用时: " << duration2.count() << " 毫秒\n";

	return 0;
}