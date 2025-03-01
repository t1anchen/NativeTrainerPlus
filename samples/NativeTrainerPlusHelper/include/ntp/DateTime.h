#pragma once
#include <string>

namespace NTP {
    class DateTime
    {
    public:
        DateTime(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0) : year_(year), month_(month), day_(day), hour_(hour), minute_(minute), second_(second) {};
        ~DateTime() {};
        DateTime operator+(DateTime const& other);
        std::string to_string() const;
        friend std::ostream& operator<< (std::ostream& out, DateTime& dt);
        int year() const { return year_; };
        void set_year(const int other) {
            if (1 <= other && other <= 9999) {
                year_ = other;
            }
        }
        int month() const { return month_; };
        void set_month(const int other) {
            if (1 <= other && other <= 12) {
                month_ = other;
            }
        }
        int day() const { return day_; };
        void set_day(const int other) {
            if (1 <= other && other <= 31) {
                day_ = other;
            }
        }
        inline void set_date(const int year, const int month, const int day) {
            set_year(year);
            set_month(month);
            set_day(day);
        }
        int hour() const { return hour_; };
        void set_hour(const int other) {
            if (0 <= other && other <= 23) {
                hour_ = other;
            }
        }
        int minute() const { return minute_; };
        void set_minute(const int other) {
            if (0 <= other && other <= 59) {
                minute_ = other;
            }
        }
        int second() const { return second_; };
        void set_second(const int other) {
            if (0 <= other && other <= 59) {
                second_ = other;
            }
        }
        inline void set_time(const int hour, const int minute, const int second) {
            set_hour(hour);
            set_minute(minute);
            set_second(second);
        }
    private:
        int year_;
        int month_;
        int day_;
        int hour_;
        int minute_;
        int second_;
    };

}