/*
* PROGRAM: CS 202 Project 7
* AUTHOR: Saharath Kleips
* DATE: 03/25/2014
* PURPOSE: To recreate the basic structure of the Crazy Eights game with copy constructor and const functions
*/

class Card
{
	public: 
		Card();
		Card(const char*, int, const char*);
		Card(const Card&);
		~Card();
		bool setSuit(const char*);
		char* getSuit() const;
		bool setRank(int);
		int getRank() const;
		bool setLocation(const char*);
		char* getLocation() const;
		
		//NOTE: This is CardCopy.
		bool setCard(const char*, int, const char*);
		bool setCard(Card);

		void print() const;
	private:
		char *suit;
		int rank;
		char *location;
};

class Player
{
	public:
		Player();
		~Player();
		bool setName(const char*);
		char* getName() const;
		bool setID(int*);
		int* getID() const;
		bool setHand(Card*);
		Card* getHand() const;

		void print();
	private:
		char *name;
		int *id;
		Card *hand;
};
