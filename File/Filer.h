#pragma once

#include <string>
#include <list>

using namespace std;

class CFiler
{
public:
	CFiler();
	~CFiler();

private:
	list<std::wstring> lsParsedFile;
	
public:
	int ParseLine(std::wstring* psLine, std::wstring sWordToDel);//ret: nuber of deleted words
	int ParseFile(std::wstring sFilePath, std::wstring sWordToDel);//ret: nuber of deleted words or -1 if file not opened
	int SaveFile(std::wstring sPathToSave);//ret: 0 - success; -1 - file not opened
};

