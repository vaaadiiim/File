#include "stdafx.h"
#include "Filer.h"
#include <fstream>



CFiler::CFiler()
{
}


CFiler::~CFiler()
{
}


int CFiler::ParseLine(std::wstring* psLine, std::wstring sWordToDel)
{
	int iRet = 0;
	if (sWordToDel.empty() || psLine->empty())
		return iRet;
	int iWordPos = psLine->find(sWordToDel);
	while (iWordPos > -1)
	{
		psLine->erase(iWordPos, sWordToDel.length());
		iRet++;
		iWordPos = psLine->find(sWordToDel);
	}
	return iRet;
}

int CFiler::ParseFile(std::wstring sFilePath, std::wstring sWordToDel)
{
	if (sFilePath.empty())
		return -1;
	lsParsedFile.clear();
	ifstream finput(sFilePath);
	if (!finput.is_open())
		return -1;
	int iRet = 0;
	std::wstring sLine = L"";
	char c;
	while (finput.get(c))
	{
		if (c == '\r' || c == '\n')
		{
			iRet += ParseLine(&sLine, sWordToDel);
			lsParsedFile.push_back(sLine);
			sLine = L"";
		}
		else
			sLine += c;
	}
	lsParsedFile.push_back(sLine);
	sLine = L"";
	finput.close();
	lsParsedFile.sort();
	return iRet;
}
int CFiler::SaveFile(std::wstring sPathToSave)
{
	ofstream fout(sPathToSave);
	if(fout.is_open())
	{
		std::wstring sLine = L"";
		for (auto sLine : lsParsedFile)
		{
			int iLen = sLine.length();
			for (int i = 0; i < iLen; i++)
			{
				char c = static_cast<char>(sLine.at(i));
				fout.write(&c, 1);
			}
			fout.write("\r\n", 2);
		}
		fout.close();
		return 0;
	} else
		return -1;
}