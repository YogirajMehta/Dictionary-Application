/*
Name-Yogiraj Mehta
email-ymehta4@myseneca.ca
id-162867238
date-04-10-2025
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
#include <string>


namespace seneca {
	struct settings {
		bool m_show_all = false;
		bool m_verbose = false;
		std::string m_time_units = "nanoseconds";

	};
	extern settings g_settings;
}

#endif