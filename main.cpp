#include <iostream>
#include <map>
#include <string.h>

#include "test_template.h"
#include "test_memcpy.h"


int main() {
    // map迭代中删除元素
    std::map<int, int> xmap;
    for(int i = 0; i < 5; ++i)
    {
        xmap.insert({i, i});
    }
    for(auto it = xmap.begin(); it != xmap.end();)
    {
        if(it->second%2)
        {
            std::cout<<"erase key:"<<it->first<<std::endl;
            it = xmap.erase(it);
        }
        else
        {
            std::cout<<"pass key:"<<it->first<<std::endl;
            ++it;
        }
    }

    // 模板enable_if
    std::cout << "Hello, World!" << std::endl;
    int a = 5, b = 6, c = 7;
    float d = 5.5f;
    std::cout<<std::boolalpha;
    std::cout<<a<<" is odd ? " << is_odd(a) << std::endl;
    std::cout<<b<<" is even ? " << is_even(b) << std::endl;
    std::cout<<c<<" is odd ? " << is_odd_test(c) << std::endl;
    //std::cout<<d<<" is odd ? " << is_odd2(d) << std::endl; // 编译报错， no match function

    TA<5, bool> ta;
    std::cout<<"ta.a = "<<ta.a<<std::endl;
    std::cout<<"size of TA:"<<sizeof(TA<5>)<<std::endl;
    std::cout<<"size of ta:"<<sizeof(ta)<<std::endl;
    std::cout<<"size of TTest:"<<sizeof(TTest)<<std::endl;

    // 内存拷贝
    void* src = malloc(20);
    memset(src, 0, 20);
    memset(src, 'a', 9);
    std::cout<<"src:"<<(char*)src<<std::endl;
    std::cout<<std::endl;

    // 调用原始版本
    {
        void* dst = malloc(10);
        memcpy(dst, src, 10);
        std::cout<<"dst1:"<<(char*)dst<<std::endl;
        free(dst);
    }
    {
        void* dst = (char*)src + 5;
        memcpy(dst, src, 10);
        std::cout<<"dst2:"<<(char*)dst<<std::endl;
        std::cout<<"src:"<<(char*)src<<std::endl;
    }
    {
        void* dst = src;
        memcpy(dst, (char*)src + 2, 10);
        std::cout<<"dst3:"<<(char*)dst<<std::endl;
        std::cout<<"src:"<<(char*)src<<std::endl;
    }
    std::cout<<"------"<<std::endl;
    // 调用自定义版本
    {
        void* dst = malloc(10);
        test_memcpy(dst, src, 10);
        std::cout<<"dst1:"<<(char*)dst<<std::endl;
        free(dst);
    }
    {
        void* dst = (char*)src + 5;
        test_memcpy(dst, src, 10);
        std::cout<<"dst2:"<<(char*)dst<<std::endl;
        std::cout<<"src:"<<(char*)src<<std::endl;
    }
    {
        void* dst = (char*)src;
        test_memcpy(dst, (char*)src + 2, 10);
        std::cout<<"dst3:"<<(char*)dst<<std::endl;
        std::cout<<"src:"<<(char*)src<<std::endl;
    }
    free(src);

    return 0;
}