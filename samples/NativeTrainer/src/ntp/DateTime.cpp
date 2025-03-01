#include "ntp/DateTime.h"
#include <numeric>

namespace NTP {
    
    DateTime DateTime::operator+(DateTime const& other)
    {
        int carry = 0;
        DateTime result;

        // second
        auto dv = std::div(second_ + other.second_, 60);
        carry = dv.quot;
        result.second_ = dv.rem;

        // minute
        dv = std::div(minute_ + other.minute_ + carry, 60);
        carry = dv.quot;
        result.minute_ = dv.rem;

        // hour
        dv = std::div(hour_ + other.hour_ + carry, 60);
        carry = dv.quot;
        result.hour_ = dv.rem;
        return result;
    }
}