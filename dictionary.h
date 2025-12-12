/*
Name-Yogiraj Mehta
email-ymehta4@myseneca.ca
id-162867238
date-04-10-2025
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include <string>

namespace seneca {
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};
	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};

	class Dictionary {
		Word* m_words{};
		size_t m_size;
		size_t m_capacity;

	public:
		
		Dictionary();
		Dictionary(const char* filename);
		virtual ~Dictionary();

		Dictionary(const Dictionary& other);
		Dictionary& operator = (const Dictionary& other);

		Dictionary(Dictionary&& other) noexcept;
		Dictionary& operator=(Dictionary&& other) noexcept;

		void searchWord(const char* word);
	};


}



#endif