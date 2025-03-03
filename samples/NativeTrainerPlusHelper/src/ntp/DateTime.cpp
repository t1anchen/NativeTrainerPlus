#include "ntp/api.h"
#include "pch.h"
#include "ntp/DateTime.h"
#include <numeric>
#include <string>
#include <iomanip>
#include <sstream>
#include "ntp/arithmetic.h"


namespace NTP {

    DateTime& DateTime::operator+=(DateTime const& other)
    {
        int carry = 0;

        // second
        auto dv = floordiv(second_ + other.second_, 60);
        carry = dv.quot;
        second_ = dv.rem;

        // minute
        dv = floordiv(minute_ + other.minute_ + carry, 60);
        carry = dv.quot;
        minute_ = dv.rem;

        // hour
        dv = floordiv(hour_ + other.hour_ + carry, 24);
        carry = dv.quot;
        hour_ = dv.rem;
        int carry_orig = carry;

        dv = floordiv(day_ + other.day_ + carry, 32);
        carry = ((dv.quot == 0) && (dv.rem == 0)) ? carry : dv.quot;
        int day_new = (dv.rem == 0) ? ((dv.quot == 0) ? 31 : 1) : dv.rem;
        dv = floordiv(month_ + other.month_ + carry, 13);
        carry = ((dv.quot == 0) && (dv.rem == 0)) ? carry : dv.quot;
        int month_new = (dv.rem == 0) ? ((dv.quot == 0) ? 12 : 1) : dv.rem;
        dv = floordiv(year_ + other.year_ + carry, 9999);
        int year_new = dv.rem;

        // leapyear calibration
        //
        // [2025-03-03T12:05:06+08:00] following the modification logic from https://github.com/FIying-Scotsman/GTAV-EnhancedNativeTrainer/blob/master/EnhancedNativeTrainer/src/features/time.cpp#L428
        bool is_leap_year = false;
        if (year_new % 4 == 0)
            is_leap_year = true;
        int max_days_in_a_month = 31;
        switch (month_new) {
        case 2:
            max_days_in_a_month = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_days_in_a_month = 30;
            break;
        default:
            break;
        }
        if (is_leap_year && (month_new == 2)) {
            max_days_in_a_month = 29;
        }
        
        carry = carry_orig;

        // day
        dv = floordiv(day_ + other.day_ + carry, max_days_in_a_month+1);
        carry = ((dv.quot == 0) && (dv.rem == 0)) ? carry : dv.quot;
        day_ = (dv.rem == 0) ? ((dv.quot == 0) ? 31 : 1) : dv.rem;

        // month (2nd)
        dv = floordiv(month_ + other.month_ + carry, 13);
        carry = ((dv.quot == 0) && (dv.rem == 0)) ? carry : dv.quot;
        month_ = (dv.rem == 0) ? ((dv.quot == 0) ? 12 : 1) : dv.rem;

        // year (2nd)
        dv = floordiv(year_ + other.year_ + carry, 9999);
        year_ = dv.rem;

        return *this;
    }

    DateTime DateTime::operator+(DateTime const& other) {
        DateTime result{ *this };
        result += other;
        return result;
    }
    
    DateTime DateTime::operator-() const {
        DateTime result{ *this };
        if (result.year_ > 0)
            result.year_ = -result.year_;

        if (result.month_ > 0)
            result.month_ = -result.month_;

        if (result.day_ > 0)
            result.day_ = -result.day_;

        if (result.hour_ > 0)
            result.hour_ = -result.hour_;

        if (result.minute_ > 0)
            result.minute_ = -result.minute_;

        if (result.second_ > 0)
            result.second_ = -result.second_;
        return result;
    }
    DateTime DateTime::operator-(DateTime const& other) {
        DateTime operand = -other;
        return *this + operand;
    }
    std::string DateTime::to_string() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(4) << year_;
        oss << "-";
        oss << std::setfill('0') << std::setw(2) << month_;
        oss << "-";
        oss << std::setfill('0') << std::setw(2) << day_;
        oss << "T";
        oss << std::setfill('0') << std::setw(2) << hour_;
        oss << ":";
        oss << std::setfill('0') << std::setw(2) << minute_;
        oss << ":";
        oss << std::setfill('0') << std::setw(2) << second_;
        return oss.str();
    }
    std::ostream& operator<< (std::ostream& out, DateTime& dt) {
        out << dt.to_string();
        return out;
    }
}
