#include <iostream>
#include <string>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    unsigned long long r = 1;  // 初始余数为1（代表第一个光棍数"1"）
    int count = 1;             // 初始位数1
    string s = "";             // 商字符串
    bool flag = false;         // 标记是否已开始记录非零商

    while (r != 0) {
        if (r < n) {
            // 余数小于除数时需要借位
            if (flag) {
                // 已开始记录非零商，添加0
                s += '0';
            }
            // 借位：相当于在余数后添加1
            r = r * 10 + 1;
            count++;  // 位数增加
        } else {
            
            unsigned long long digit = r / n;
            s += ('0' + digit);  // 添加当前商位
            flag = true;         // 标记已开始记录非零商
            r = r % n;           // 更新余数
            
            // 余数为0，除法完成
            if (r == 0) {
                break;
            }
            
            // 借位继续
            r = r * 10 + 1;
            count++;
        }
    }

    cout << s << " " << count;
    return 0;
}