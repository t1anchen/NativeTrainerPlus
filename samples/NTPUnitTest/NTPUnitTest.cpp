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
            NTP::DateTime dt(2025, 3, 2, 0, 12, 30);
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
            Assert::AreNotEqual(dt_a.minute(), actual.minute());
        }
        TEST_METHOD(add_nonleap)
        {
            NTP::DateTime dt_a(2025, 3, 31, 0, 0, 0);
            NTP::DateTime dt_b(0, 0, 1, 0, 0, 0);
            NTP::DateTime expected(2025, 4, 1, 0, 0, 0);
            NTP::DateTime actual = dt_a + dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());

            dt_a.set_datetime(2025, 3, 31, 23, 0, 0);
            dt_b.set_datetime(0, 0, 0, 1, 0, 0);
            expected.set_datetime(2025, 4, 1, 0, 0, 0);
            actual = dt_a + dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());
        }
        TEST_METHOD(add_feb_nonleap)
        {
            NTP::DateTime dt_a(2025, 2, 28, 0, 0, 0);
            NTP::DateTime dt_b(0, 0, 1, 0, 0, 0);
            NTP::DateTime expected(2025, 3, 1, 0, 0, 0);
            NTP::DateTime actual = dt_a + dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());
        }
        TEST_METHOD(add_feb_leap)
        {
            NTP::DateTime dt_a(2024, 2, 28, 0, 0, 0);
            NTP::DateTime dt_b(0, 0, 1, 0, 0, 0);
            NTP::DateTime expected(2024, 2, 29, 0, 0, 0);
            NTP::DateTime actual = dt_a + dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());
        }
        TEST_METHOD(add_feb_leap_second)
        {
            NTP::DateTime dt_a(2024, 2, 28, 23, 59, 59);
            NTP::DateTime dt_b(0, 0, 0, 0, 0, 1);
            NTP::DateTime expected(2024, 2, 29, 0, 0, 0);
            NTP::DateTime actual = dt_a + dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());
        }
        TEST_METHOD(add_newyear)
        {
            NTP::DateTime dt_a(2024, 12, 31, 23, 59, 59);
            NTP::DateTime dt_b(0, 0, 0, 0, 0, 1);
            NTP::DateTime expected(2025, 1, 1, 0, 0, 0);
            NTP::DateTime actual = dt_a + dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());
        }
        TEST_METHOD(sub)
        {
            NTP::DateTime dt_a{ 2025,1,1,0,0,0 };
            NTP::DateTime dt_b{ 0,0,0,0,0,1 };
            NTP::DateTime expected{ 2024,12,31,23,59,59 };
            NTP::DateTime actual = dt_a - dt_b;
            Assert::AreEqual(expected.to_string(), actual.to_string());
        }
    };
}
