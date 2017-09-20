#include "stdafx.h"
#include "CppUnitTest.h"
#include "Filer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(TestLineParser)
	{
	public:
		
		TEST_METHOD(TestParseLine1)
		{
			CFiler filer;
			std::wstring sParsing = L"werbwrbwrbwrb abcd uuuuuuuuuu";
			std::wstring sWord = L"abcd";
			int iRet = filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(iRet == 1, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine2)
		{
			CFiler filer;
			std::wstring sParsing = L"werbwrbwrbwrb abcd uuuuuuuuuu";
			std::wstring sWord = L"1111";
			int iRet = filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(iRet == 0, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine3)
		{
			CFiler filer;
			std::wstring sParsing = L"werbwrbwrbwrb abcd uuuuuuuuuu";
			std::wstring sWord = L"";
			int iRet = filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(iRet == 0, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine4)
		{
			CFiler filer;
			std::wstring sParsing = L"werbwrbwrbwrb abcd uuuuuuuuuu";
			std::wstring sWord = L"abcd";
			filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(sParsing == L"werbwrbwrbwrb  uuuuuuuuuu", L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine5)
		{
			CFiler filer;
			std::wstring sParsing = L"werbwrbwrbwrb abcd uuuuuuuuuu";
			std::wstring sWord = L"abcd";
			filer.ParseLine(&sParsing, sWord);
			Assert::IsFalse(sParsing == L"werbwrbwrbwrb uuuuuuuuuu", L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine6)
		{
			CFiler filer;
			std::wstring sParsing = L"";
			std::wstring sWord = L"abcd";
			int iRet = filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(iRet == 0, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine7)
		{
			CFiler filer;
			std::wstring sParsing = L"abcdabcd";
			std::wstring sWord = L"abcd";
			int iRet = filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(iRet == 2, L"message", LINE_INFO());
		}
		TEST_METHOD(TestParseLine8)
		{
			CFiler filer;
			std::wstring sParsing = L"abcdabcd";
			std::wstring sWord = L"abcd";
			filer.ParseLine(&sParsing, sWord);
			Assert::IsTrue(sParsing == L"", L"message", LINE_INFO());
		}
	};
}