#pragma once
namespace NTP {
    class DateTime
    {
    public:
        DateTime operator+(DateTime const& other);
        int year() { return year_; };
        int month() { return month_; };
        int day() { return day_; };
        int hour() { return hour_; };
        int minute() { return minute_; };
        int second() { return second_; };
    private:
        int year_;
        int month_;
        int day_;
        int hour_;
        int minute_;
        int second_;
    };
}


