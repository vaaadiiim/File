#include "stdafx.h"
#include "CppUnitTest.h"
#include "Filer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestFiler)
	{
	public:

		TEST_METHOD(TestParseFile1)
		{
			CFiler filer;
			int iRet = filer.ParseFile(L"", L"abcd");
			Assert::IsTrue(iRet == -1, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseFile2)
		{
			CFiler filer;
			int iRet = filer.ParseFile(L"abcd", L"abcd");
			Assert::IsTrue(iRet == -1, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseFile3)
		{
			CFiler filer;
			int iRet = filer.ParseFile(L"D:/Temp/input.txt", L"I");
			Assert::IsTrue(iRet == 4, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseFile4)
		{
			CFiler filer;
			int iRet = filer.ParseFile(L"D:/Temp/input.txt", L"tttt");
			Assert::IsTrue(iRet == 0, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseFile5)
		{
			CFiler filer;
			int iRet = filer.ParseFile(L"D:/Temp/input.txt", L"");
			Assert::IsTrue(iRet == 0, L"message", LINE_INFO());
		}
		TEST_METHOD(TestSaveFile1)
		{
			CFiler filer;
			filer.ParseFile(L"D:/Temp/input.txt", L"abcd");
			int iRet = filer.SaveFile(L"D:/Temp/output.txt");
			Assert::IsTrue(iRet == 0, L"message", LINE_INFO());
		}
		TEST_METHOD(TestSaveFile2)
		{
			CFiler filer;
			filer.ParseFile(L"D:/Temp/input.txt", L"abcd");
			int iRet = filer.SaveFile(L"D:/abcd/output.txt");
			Assert::IsTrue(iRet == -1, L"message", LINE_INFO());
		}
		TEST_METHOD(TestSaveFile3)
		{
			CFiler filer;
			std::list<std::wstring> vsParsedFile;
			filer.ParseFile(L"D:/Temp/input.txt", L"abcd");
			int iRet = filer.SaveFile(L"");
			Assert::IsTrue(iRet == -1, L"message", LINE_INFO());
		}
	};
}