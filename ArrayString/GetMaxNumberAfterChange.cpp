
// 我来解释一下？

// int changed[2]   = {0, 0};  
// 记录 0或者1组成的连续串最长是多少 此串变化过一次
// int noChange[2] = {0, 0};
// 记录 0或者1组成的连续串最长是多少 此串没有变化过

// change【1】 可以理解为 1的通过俘虏0的连续串得到的 so far的连续串长度

// 扫描每一个数 有几种操作

// 此数必定破坏原来对手的unchange过的串  也就是使之归零
// 此数可以变化为对手 这样 对手的change = 对手unchange +1
// 无论如何情况 都破坏了对手的unchange的串 必须归零 因为即使第二种情况 对手的
// unchange的串也不再是unchange了 

// 当然此数也做 这么两件事
// 使自己change的串长度加一
// 使自己未经change的串长度加一

// 如果可以把这部分逻辑从max函数中拿出来会清晰很多吧


// 两个max是如果不去change应该如何
// 后边的两个语句是如果x变成对手应该如何


// longway太牛了 其实这是dp

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int getMaxLength(vector<bool>& ary){
	int changed[2]   = {0, 0}; 
   	int noChange[2] = {0, 0};
   	int maxL = 0;

   for (bool x : ary)  {
        ++changed[x];
        ++noChange[x];
        changed[1-x] = 1 + noChange[1-x];  //此数可以变化为对手 这样 对手的change = 对手unchange +1
        noChange[1-x] = 0;                 // 此数必定破坏原来对手的unchange过的串  也就是使之归零

        maxL = max(maxL, changed[x]);
        maxL = max(maxL, changed[1-x]);
   }   

   return maxL;
}


int main(int argc, char const *argv[])
{
	vector<bool> v{1, 0,1};
	assert(3==getMaxLength(v));
	return 0;
}