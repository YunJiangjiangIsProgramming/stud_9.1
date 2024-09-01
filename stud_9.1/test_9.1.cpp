#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include <cstdint>
#include <unordered_map>
#include <random>
#include <ctime>
using namespace std;

//https://leetcode.cn/problems/longest-common-prefix
class Solution0 {
public:
    // 计算两个字符串的公共前缀长度
    string common(string s1, string s2)
    {
        int i = 0; // 用于统计公共前缀的长度
        while (i < min(s1.size(), s2.size()) && s1[i] == s2[i]) {
            ++i; // 如果当前字符相同，则增加索引
        }
        return s1.substr(0, i); // 返回公共前缀
    }
    // 计算字符串数组的最长公共前缀
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s = strs[0]; // 初始化最长公共前缀为第一个字符串
        for (int i = 1; i < strs.size(); ++i) { // 遍历字符串数组
            s = common(s, strs[i]); // 更新最长公共前缀为当前字符串和上一个公共前缀的公共前缀
        }
        return s; // 返回最长公共前缀
    }
};


//const int MAX_NUM = 100000000; // 最大数字范围（1亿）

 //生成1亿随机数据
std::vector<int> generateData(size_t size)
{
    std::vector<int> data(size);
    std::default_random_engine generator(static_cast<unsigned int>(time(0))); // 随机数生成器
    std::uniform_int_distribution<int> distribution(0, MAX_NUM - 1); // 生成范围在0到99999999之间的随机数

    for (size_t i = 0; i < size; ++i)
    {
        data[i] = distribution(generator); // 生成随机数并存入数据中
    }
    return data; // 返回生成的数据
}

// 找出只出现一次的数字
std::vector<int> findUniqueNumbers(const std::vector<int>& data)
{
    std::unordered_map<int, int> countMap; // 哈希表用于记录每个数字出现的次数

    // 统计每个数字的出现次数
    for (int num : data)
    {
        countMap[num]++; // 增加对应数字的计数
    }

    std::vector<int> uniqueNumbers; // 存储只出现一次的数字

    // 遍历哈希表，找出只出现一次的数字
    for (const auto& pair : countMap)
    {
        if (pair.second == 1) // 如果出现次数为1
        {
            uniqueNumbers.push_back(pair.first); // 添加到结果中
        }
    }

    return uniqueNumbers; // 返回只出现一次的数字
}

void findonlyonenum()
{

    const size_t dataSize = 100000000; // 数据大小（1亿）
    std::vector<int> data = generateData(dataSize); // 生成数据

    // 找出只出现一次的数字
    std::vector<int> uniqueNumbers = findUniqueNumbers(data);

    // 输出结果
    std::cout << "Unique numbers (appeared once):" << std::endl;
    for (int num : uniqueNumbers)
    {
        std::cout << num << std::endl; // 输出只出现一次的数字
    }
}


const int MAX_NUM = 10000000; // 最大数字范围
const int TOTAL_SIZE = 10000000; // 数据总大小
const int REPEAT_COUNT = 100000; // 每个重复数字的出现次数

// 生成随机数据，确保只有一个唯一数字
std::vector<int> generateData()
{
    std::vector<int> data;
    std::unordered_map<int, int> numCount;

    // 生成重复的数字
    for (int i = 0; i < TOTAL_SIZE - 1; ++i)
    {
        int num = rand() % MAX_NUM; // 生成随机数字
        data.push_back(num);
        numCount[num]++;
    }

    // 选择一个唯一的数字
    int uniqueNum;
    do {
        uniqueNum = rand() % MAX_NUM; // 确保唯一数字不与重复数字相同
    } while (numCount.find(uniqueNum) != numCount.end());

    data.push_back(uniqueNum); // 添加唯一数字

    return data;
}

// 找出只出现一次的数字
std::vector<int> findUniqueNumbers(const std::vector<int>& data)
{
    std::unordered_map<int, int> countMap;

    // 统计每个数字的出现次数
    for (int num : data)
    {
        countMap[num]++;
    }

    std::vector<int> uniqueNumbers;

    // 遍历哈希表，找出只出现一次的数字
    for (const auto& pair : countMap)
    {
        if (pair.second == 1)
        {
            uniqueNumbers.push_back(pair.first);
        }
    }

    return uniqueNumbers;
}

void  findonly1()
{
    srand(static_cast<unsigned int>(time(0))); // 设置随机种子
    std::vector<int> data = generateData(); // 生成数据
    std::vector<int> uniqueNumbers = findUniqueNumbers(data); // 找出唯一数字

    // 输出结果
    std::cout << "Unique number: " << uniqueNumbers[0] << std::endl;

}

// 简单的字符串哈希函数
unsigned int hashstr(const std::string& str) {
    unsigned int hash = 5381; // 种子值
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}




// 将IP地址字符串转换为32位无符号整数
uint32_t ip_to_uint32(const std::string& ip) {
    uint32_t ip_uint = 0;
    size_t parts = std::sscanf(ip.c_str(), "%u.%u.%u.%u", &ip_uint, &ip_uint, &ip_uint, &ip_uint);
    if (parts != 4) {
        std::cerr << "Invalid IP address format" << std::endl;
        return 0;
    }
    return ip_uint;
}

// 简单的IP地址哈希函数
uint32_t hash_ip(const std::string& ip) {
    uint32_t hash = ip_to_uint32(ip);
    hash ^= hash >> 16; // 混合高位和低位
    hash *= 0x45d9f3b; // 使用一个质数进行乘法散列
    hash ^= hash >> 12;
    hash *= 0x766dc419;
    hash ^= hash >> 16;
    return hash;
}

void testip()
{

    std::string ip = "8.8.8.8"; // 示例IP地址
    uint32_t hash_value = hash_ip(ip);
    std::cout << "Hash value of IP address " << ip << ": " << hash_value << std::endl;
}
int main()
{
    //findonlyonenum();
    //findonly1();
    testip();
    return 0;
}