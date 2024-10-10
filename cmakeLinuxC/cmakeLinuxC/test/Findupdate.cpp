#include "Findupdate.h"

bool Findupdate::checkFile(string fileName, vector<string> &fileList)
{
    string filePath = fileName;
    DIR* dirp = opendir(filePath.c_str());
    if (dirp == nullptr) {
        std::cerr << "打开文件夹失败: " << filePath << std::endl;
        return false;
    }

    struct dirent* dp;
    int i = 0;
    while ((dp = readdir(dirp)) != nullptr) {
        string strFileName(dp->d_name);
        string newstrFileName;
        if (strFileName.find(".")!=-1 ) {
            if (strFileName.substr(strFileName.find_last_of(".")).compare(".stp")==0)
            {
                newstrFileName = strFileName.substr(0,strFileName.find_last_of("."))+"-0"+to_string(++i)+".stp";
                if (rename((filePath+strFileName).c_str(), (filePath+newstrFileName).c_str()) != 0) {
                    std::cerr << "文件名修改失败 " << strFileName << std::endl;
                }
                fileList.push_back(newstrFileName);
            }
        }
    }
    closedir(dirp);
	return true;
}

void Findupdate::test()
{
	string filePath = "/usr/test/testFile/";
    vector<string> fileList;
	bool bRet = checkFile(filePath, fileList);
    //打印修改后的文件列表
    for (auto it = fileList.begin(); it != fileList.end(); ++it) {
        std::cout << *it << std::endl;
    }

}
