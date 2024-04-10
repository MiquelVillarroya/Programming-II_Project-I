#pragma once
#include<cstring>
#include <string>

//Add classes here

class Book {
private:
	const char* author;
	const char* title;

protected:
	int nPages;

public:
	Book() : nPages(0), author("unknown"), title("newTitle") {}
	Book(const char* auth, const char* tit, int p) : nPages(p), author(auth), title(tit) {}
	int GetPages() {
		return nPages;
	}
	const char* GetAuthor() {
		return author;
	}
	const char* GetTitle() {
		return title;
	}
	virtual const char* ReadPage(const int p) {
		return "Reading a random page";
	}
	bool operator==(Book b2) {
		if (author == b2.GetAuthor() && title == b2.GetTitle() && nPages == b2.GetPages()) return true;
		return false;
	}
	bool operator!=(Book b2) {
		if (author != b2.GetAuthor() || title != b2.GetTitle() || nPages != b2.GetPages()) return true;
		return false;
	}
};

	class Entry {
	private:
		const char* key;
		const char* definition;

	public:
		void Set(const char* k, const char* def) {
			key = k;
			definition = def;
		}

		friend class Dictionary;
	};

	class Dictionary : public Book {
	protected:
		Entry* entries;

	public:
		Dictionary() : Book() {}
		Dictionary(const char* auth, const char* tit, int p) : Book(auth, tit, p) {
			entries = new Entry[p];
		}

		void AddEntry(int p, const char* k, const char* def) {
			if (p >= 0 && p <= nPages) {
				entries[p].Set(k, def);
			}
		}
		void ChangeDefinition(int p, const char* def) {
			if (p >= 0 && p <= nPages) {
				entries[p].definition = def;
			}
		}
		const char* ReadPage(const int p) override {
			if (p >= 0 && p <= nPages) {
				return entries[p].definition;
			}
			else return "404";
		}
	};