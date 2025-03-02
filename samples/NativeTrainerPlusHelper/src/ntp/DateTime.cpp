#include "ntp/DateTime.h"
#include <numeric>
#include <string>
#include <iomanip>
#include <sstream>

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
        dv = std::div(hour_ + other.hour_ + carry, 24);
        carry = dv.quot;
        result.hour_ = dv.rem;
        return result;
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
