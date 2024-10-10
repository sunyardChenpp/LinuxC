#pragma once


#include <iostream>
#include <cstdio>
#include <dirent.h>
#include <vector>
using namespace std;

//在一个几何文件目录下，存在相同扩展名".stp"的多个文件，对这样的文件名，请修改文件名称，在文件
//名称后增加排序标识"-01"，"-02"，"-03"...
// Input： 目录名称
// Output：文件列表清单
class Findupdate
{
public:
	// Input： 目录名称 ，Output：文件列表清单 ，公用一个string 变量fileName
	bool checkFile(string fileName,vector<string> &fileList);
	void test();
};