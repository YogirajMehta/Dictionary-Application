/*
Name-Yogiraj Mehta
email-ymehta4@myseneca.ca
id-162867238
date-04-10-2025
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "dictionary.h"
#include "settings.h"
using namespace std;

namespace seneca {

	
	Dictionary::Dictionary() : m_words{ nullptr }, m_size{ 0 }, m_capacity{ 0 } {}

	Dictionary::Dictionary(const char* filename)
{
    ifstream file(filename);

    if (file) {
        string temp;
        size_t count = 0;

        // Count number of lines
        while (getline(file, temp)) {
            count++;
        }

        file.clear();
        file.seekg(0);

        m_capacity = count > 0 ? count : 10;
        m_words = new Word[m_capacity];
        m_size = 0;

        string line, word, pos, definition;

        while (getline(file, line) && m_size < m_capacity) {
            istringstream ss(line);
            getline(ss, word, ',');
            getline(ss, pos, ',');
            getline(ss, definition);

            PartOfSpeech posField = PartOfSpeech::Unknown; // default

            if (pos == "n." || pos == "n. pl.") {
                posField = PartOfSpeech::Noun;
            }
            else if (pos == "pron.") {
                posField = PartOfSpeech::Pronoun;
            }
            else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") {
                posField = PartOfSpeech::Verb;
            }
            else if (pos == "adv.") {
                posField = PartOfSpeech::Adverb;
            }
            else if (pos == "a.") {
                posField = PartOfSpeech::Adjective;
            }
            else if (pos == "interj.") {
                posField = PartOfSpeech::Interjection;
            }
            else if (pos == "prep." || pos == "Prep.") {
                posField = PartOfSpeech::Preposition;
            }
            else if (pos == "conj.") {
                posField = PartOfSpeech::Conjunction;
            }

            m_words[m_size].m_word = word;
            m_words[m_size].m_definition = definition;
            m_words[m_size].m_pos = posField;
            m_size++;
        }
    }
    else {
        m_words = nullptr;
        m_capacity = 0;
        m_size = 0;
    }
}

	void Dictionary::searchWord(const char* word)
{
    bool found = false;
    size_t indentation = strlen(word);

    for (size_t i = 0; i < m_size; i++) {
        if (m_words[i].m_word == word) {
            if (!found) {
                cout << m_words[i].m_word << " -";

                if (g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
                    cout << " (";
                    switch (m_words[i].m_pos) {
                    case PartOfSpeech::Noun:        cout << "noun"; break;
                    case PartOfSpeech::Pronoun:     cout << "pronoun"; break;
                    case PartOfSpeech::Verb:        cout << "verb"; break;
                    case PartOfSpeech::Adverb:      cout << "adverb"; break;
                    case PartOfSpeech::Adjective:   cout << "adjective"; break;
                    case PartOfSpeech::Interjection:cout << "interjection"; break;
                    case PartOfSpeech::Preposition: cout << "preposition"; break;
                    case PartOfSpeech::Conjunction: cout << "conjunction"; break;
                    case PartOfSpeech::Unknown:
                    default:                        cout << "unknown"; break;
                    }
                    cout << ")";
                }
                cout << " " << m_words[i].m_definition << endl;
                found = true;
            }
            else if (g_settings.m_show_all) {
                for (size_t j = 0; j < indentation; j++) {
                    cout << " ";
                }
                cout << " - ";

                if (g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
                    cout << "(";
                    switch (m_words[i].m_pos) {
                    case PartOfSpeech::Noun:        cout << "noun"; break;
                    case PartOfSpeech::Pronoun:     cout << "pronoun"; break;
                    case PartOfSpeech::Verb:        cout << "verb"; break;
                    case PartOfSpeech::Adverb:      cout << "adverb"; break;
                    case PartOfSpeech::Adjective:   cout << "adjective"; break;
                    case PartOfSpeech::Interjection:cout << "interjection"; break;
                    case PartOfSpeech::Preposition: cout << "preposition"; break;
                    case PartOfSpeech::Conjunction: cout << "conjunction"; break;
                    case PartOfSpeech::Unknown:
                    default:                        cout << "unknown"; break;
                    }
                    cout << ") ";
                }

                cout << m_words[i].m_definition << endl;
            }

            if (!g_settings.m_show_all) {
                return;
            }
        }
    }

    if (!found) {
        cout << "Word '" << word << "' was not found in the dictionary." << endl;
    }
}	Dictionary::Dictionary(const Dictionary& other) : m_size(other.m_size), m_capacity(other.m_capacity)
	{
		m_words = new Word[m_capacity];
		for (size_t i = 0; i < m_size; ++i) {
			m_words[i] = other.m_words[i];
		}
	}

	Dictionary& Dictionary::operator= (const Dictionary& other) {
		if (this == &other) {
			return *this;
		}
		delete[] m_words;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_words = new Word[m_capacity];

		for (size_t i = 0; i < m_size; ++i) {
			m_words[i] = other.m_words[i];
		}
		return *this;
	}

	Dictionary::Dictionary(Dictionary&& other) noexcept : m_words(other.m_words), m_size(other.m_size), m_capacity(other.m_capacity)
	{
		other.m_words = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;

	}

	Dictionary& Dictionary::operator= (Dictionary&& other) noexcept
	{
		if (this != &other) {
			delete[] m_words;

			m_words = other.m_words;
			m_size = other.m_size;
			m_capacity = other.m_capacity;

			other.m_words = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;

		}
		return *this;

	}

	Dictionary::~Dictionary()
	{
		delete[] m_words;

	}
}

