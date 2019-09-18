// MyLog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <io.h>
#include <fstream>
#include <time.h>
#include <sstream>
using namespace std;
string getCurrentTime();
int main()
{
	int f=_access("mylog.log", 0);
	fstream fs;
	if (f ==-1)
	{
		fs = fstream("mylog.log",ios::trunc | ios::in | ios::out);
	}
	else
	{
		fs = fstream("mylog.log", ios::app | ios::in | ios::out);
	}
	string curTime= getCurrentTime();
	cout << curTime;
	char data[1024] = {};
	cin >> data;
	fs << curTime;
	fs << data;
	fs << "\n";
	fs.close();
	cout << "记录完成\n";
	cin.get();
	return 0;
}
string getCurrentTime()
{
	time_t t = time(NULL);
	tm ts = {};
	localtime_s(&ts,&t);

	stringstream ss;
	ss << 1900+ts.tm_year;
	ss << "-";
	ss << ts.tm_mon+1;
	ss << "-";
	ss << ts.tm_mday;
	ss << " ";
	ss << ts.tm_hour;
	ss << ":";
	ss << ts.tm_min;
	ss << ":";
	ss << ts.tm_sec;
	ss << "\n";
	
	return  ss.str().data();
}

