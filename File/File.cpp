// File.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Filer.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CFiler* pFiler = new CFiler();
	int iRet = pFiler->ParseFile(L"D:/temp/input.txt", L"I");
	pFiler->SaveFile(L"D:/temp/output.txt");
	delete pFiler;
	return 0;
}

