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
			std::string expected("2025-03-02T00:12:30");
			std::string actual(dt.to_string());
			Assert::AreEqual(expected, actual);

		}
		TEST_METHOD(add)
		{
			NTP::DateTime dt_a(2025, 3, 2, 12, 34, 56);
			NTP::DateTime dt_b(0, 0, 0, 0, 0, 4);
			NTP::DateTime expected(2025, 3, 2, 12, 35, 00);
			NTP::DateTime actual = dt_a + dt_b;
			Assert::AreEqual(expected.to_string(), actual.to_string());
		}
	};
}
