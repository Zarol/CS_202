#ifndef CARD_H_
#define CARD_H_
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Card
{
	public: 
		Card();
		Card(string, int, string);
		Card(const Card&);
		~Card();
		bool setSuit(string);
		string getSuit() const;
		bool setRank(int);
		int getRank() const;
		bool setLocation(string);
		string getLocation() const;
		void reset();
		
		Card operator=(const Card&);
		bool operator>(const Card&) const;
		bool operator<(const Card&) const;
		friend bool operator>=(const Card&, const Card&);
		friend bool operator<=(const Card&, const Card&);
		friend ifstream& operator>>(ifstream&, Card&);
		friend ostream& operator<<(ostream&, Card&);

	private:
		string suit;
		int rank;
		string location;
};

#endif
