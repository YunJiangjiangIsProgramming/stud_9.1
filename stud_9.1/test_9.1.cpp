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
    // ���������ַ����Ĺ���ǰ׺����
    string common(string s1, string s2)
    {
        int i = 0; // ����ͳ�ƹ���ǰ׺�ĳ���
        while (i < min(s1.size(), s2.size()) && s1[i] == s2[i]) {
            ++i; // �����ǰ�ַ���ͬ������������
        }
        return s1.substr(0, i); // ���ع���ǰ׺
    }
    // �����ַ�������������ǰ׺
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s = strs[0]; // ��ʼ�������ǰ׺Ϊ��һ���ַ���
        for (int i = 1; i < strs.size(); ++i) { // �����ַ�������
            s = common(s, strs[i]); // ���������ǰ׺Ϊ��ǰ�ַ�������һ������ǰ׺�Ĺ���ǰ׺
        }
        return s; // ���������ǰ׺
    }
};


//const int MAX_NUM = 100000000; // ������ַ�Χ��1�ڣ�

 //����1���������
std::vector<int> generateData(size_t size)
{
    std::vector<int> data(size);
    std::default_random_engine generator(static_cast<unsigned int>(time(0))); // �����������
    std::uniform_int_distribution<int> distribution(0, MAX_NUM - 1); // ���ɷ�Χ��0��99999999֮��������

    for (size_t i = 0; i < size; ++i)
    {
        data[i] = distribution(generator); // ���������������������
    }
    return data; // �������ɵ�����
}

// �ҳ�ֻ����һ�ε�����
std::vector<int> findUniqueNumbers(const std::vector<int>& data)
{
    std::unordered_map<int, int> countMap; // ��ϣ�����ڼ�¼ÿ�����ֳ��ֵĴ���

    // ͳ��ÿ�����ֵĳ��ִ���
    for (int num : data)
    {
        countMap[num]++; // ���Ӷ�Ӧ���ֵļ���
    }

    std::vector<int> uniqueNumbers; // �洢ֻ����һ�ε�����

    // ������ϣ���ҳ�ֻ����һ�ε�����
    for (const auto& pair : countMap)
    {
        if (pair.second == 1) // ������ִ���Ϊ1
        {
            uniqueNumbers.push_back(pair.first); // ��ӵ������
        }
    }

    return uniqueNumbers; // ����ֻ����һ�ε�����
}

void findonlyonenum()
{

    const size_t dataSize = 100000000; // ���ݴ�С��1�ڣ�
    std::vector<int> data = generateData(dataSize); // ��������

    // �ҳ�ֻ����һ�ε�����
    std::vector<int> uniqueNumbers = findUniqueNumbers(data);

    // ������
    std::cout << "Unique numbers (appeared once):" << std::endl;
    for (int num : uniqueNumbers)
    {
        std::cout << num << std::endl; // ���ֻ����һ�ε�����
    }
}


const int MAX_NUM = 10000000; // ������ַ�Χ
const int TOTAL_SIZE = 10000000; // �����ܴ�С
const int REPEAT_COUNT = 100000; // ÿ���ظ����ֵĳ��ִ���

// ����������ݣ�ȷ��ֻ��һ��Ψһ����
std::vector<int> generateData()
{
    std::vector<int> data;
    std::unordered_map<int, int> numCount;

    // �����ظ�������
    for (int i = 0; i < TOTAL_SIZE - 1; ++i)
    {
        int num = rand() % MAX_NUM; // �����������
        data.push_back(num);
        numCount[num]++;
    }

    // ѡ��һ��Ψһ������
    int uniqueNum;
    do {
        uniqueNum = rand() % MAX_NUM; // ȷ��Ψһ���ֲ����ظ�������ͬ
    } while (numCount.find(uniqueNum) != numCount.end());

    data.push_back(uniqueNum); // ���Ψһ����

    return data;
}

// �ҳ�ֻ����һ�ε�����
std::vector<int> findUniqueNumbers(const std::vector<int>& data)
{
    std::unordered_map<int, int> countMap;

    // ͳ��ÿ�����ֵĳ��ִ���
    for (int num : data)
    {
        countMap[num]++;
    }

    std::vector<int> uniqueNumbers;

    // ������ϣ���ҳ�ֻ����һ�ε�����
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
    srand(static_cast<unsigned int>(time(0))); // �����������
    std::vector<int> data = generateData(); // ��������
    std::vector<int> uniqueNumbers = findUniqueNumbers(data); // �ҳ�Ψһ����

    // ������
    std::cout << "Unique number: " << uniqueNumbers[0] << std::endl;

}

// �򵥵��ַ�����ϣ����
unsigned int hashstr(const std::string& str) {
    unsigned int hash = 5381; // ����ֵ
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}




// ��IP��ַ�ַ���ת��Ϊ32λ�޷�������
uint32_t ip_to_uint32(const std::string& ip) {
    uint32_t ip_uint = 0;
    size_t parts = std::sscanf(ip.c_str(), "%u.%u.%u.%u", &ip_uint, &ip_uint, &ip_uint, &ip_uint);
    if (parts != 4) {
        std::cerr << "Invalid IP address format" << std::endl;
        return 0;
    }
    return ip_uint;
}

// �򵥵�IP��ַ��ϣ����
uint32_t hash_ip(const std::string& ip) {
    uint32_t hash = ip_to_uint32(ip);
    hash ^= hash >> 16; // ��ϸ�λ�͵�λ
    hash *= 0x45d9f3b; // ʹ��һ���������г˷�ɢ��
    hash ^= hash >> 12;
    hash *= 0x766dc419;
    hash ^= hash >> 16;
    return hash;
}

void testip()
{

    std::string ip = "8.8.8.8"; // ʾ��IP��ַ
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