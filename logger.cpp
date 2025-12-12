#include "logger.h"
using namespace std;

namespace seneca {

    Logger::Logger() : m_events{ nullptr }, m_size{ 0 }, m_capacity{ 10 } {
        m_events = new Event[m_capacity];
    }

    Logger::~Logger() {
        delete[] m_events;
    }

    Logger::Logger(Logger&& other) noexcept
        : m_events(other.m_events), m_size(other.m_size), m_capacity(other.m_capacity) {
        other.m_capacity = 0;
        other.m_size = 0;
        other.m_events = nullptr;
        
        
    }

    Logger& Logger::operator=(Logger&& other) noexcept {
        if (this != &other) {
            delete[] m_events;

            m_capacity = other.m_capacity;
            m_size = other.m_size;
            m_events = other.m_events;
            
            other.m_size = 0;
            other.m_capacity = 0;
            other.m_events = nullptr;
                       
        }
        return *this;
    }

    void Logger::addEvent(const Event& event) {
        if (m_size == m_capacity) {
            changes();
        }

        m_events[m_size] = event;
        m_size++;
    }

    std::ostream& operator<<(std::ostream& ostr, const Logger& other) {
        for (size_t i = 0; i < other.m_size; i++) {
            ostr << other.m_events[i] << '\n';
        }
        return ostr;
    }

    void Logger::changes() {
        m_capacity *= 2;
        Event* newEvents = new Event[m_capacity];

        for (size_t i = 0; i < m_size; i++) {
            newEvents[i] = m_events[i];
        }

        delete[] m_events;
        m_events = newEvents;
    }

}

