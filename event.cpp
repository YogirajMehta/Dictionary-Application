/*
Name-Yogiraj Mehta
email-ymehta4@myseneca.ca
id-162867238
date-04-10-2025
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "event.h"
#include "settings.h"
#include <iomanip>

namespace seneca {
    Event::Event(const char* name, const std::chrono::nanoseconds& duration)
        : m_name{ name }, m_duration{ duration } {
    }

    std::ostream& operator<<(std::ostream& os, const Event& event) {
        static size_t counter = 0;
        counter++;

       
        int durationWidth = 11;  
        auto duration = event.m_duration.count();

        if (g_settings.m_time_units == "microseconds") {
            durationWidth = 8;
            duration /= 1000;
        }
        else if (g_settings.m_time_units == "milliseconds") {
            durationWidth = 5;
            duration /= 1000000;
        }
        else if (g_settings.m_time_units == "seconds") {
            durationWidth = 2;
            duration /= 1000000000;
        }

        os << std::right
            << std::setw(2)
            << counter << ": "
            << std::setw(40)
            << event.m_name << " -> "
            << std::setw(durationWidth)
            << duration << " "
            << g_settings.m_time_units;

        return os;
    }
}