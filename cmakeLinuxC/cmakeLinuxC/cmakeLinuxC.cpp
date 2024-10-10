// cmakeLinuxC.cpp: 定义应用程序的入口点。
//

#include "cmakeLinuxC.h"
#include "./test/Findupdate.h"
#include "./test/Solution.h"
using namespace std;

int main()
{
	cout << "你好 CMake,请开发Linux环境下的C++项目" << endl;
	//第一题代码测试
	cout << "第一题代码测试:" << endl;
	Findupdate findupdate;
	findupdate.test();

	//第二题代码测试
	cout << "\n第二题代码测试:" << endl;
	Solution solution;
	solution.test();
	return 0;
}
