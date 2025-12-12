#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca {

	class Logger {
		Event* m_events{};
		size_t m_size;
		size_t m_capacity;
	public:
		Logger();
		~Logger();

		Logger(const Logger& other) = delete;
		Logger& operator=(Logger& other) = delete;

		Logger(Logger&& other) noexcept;
		Logger& operator=(Logger&& other)noexcept;

		void addEvent(const Event& event);
		friend std::ostream& operator<<(std::ostream& ostr, const Logger& other);
		void changes();
	};


}

#endif 
