#include "pch.h"
#include "CppUnitTest.h"
#include "ntp/DateTime.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NTPUnitTest
{
	TEST_CLASS(NTPDateTime)
	{
	public:
		
		TEST_METHOD(to_string)
		{
			NTP::DateTime dt(2025,3,2,0,12,30);
			std::string expected("2025");
			std::string actual(dt.to_string());
			Assert::AreEqual(expected, actual);

		}
	};
}
