/*
Name-Yogiraj Mehta
email-ymehta4@myseneca.ca
id-162867238
date-04-10-2025
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
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