/*
* PROGRAM: CS 202 Project 6
* AUTHOR: Saharath Kleips
* DATE: 03/01/2014
* PURPOSE: To recreate the basis structure of the Crazy Eights game with Classes
*/
class Player
{
	public:
		Player();
		~Player();
		bool setName(const char*);
		char* getName();
		bool setID(int*);
		int* getID();

		void print();
	private:
		char *name;
		int *id;
		//No Hand
};

class Card
{
	public: 
		Card(const char* = "suit", int = 0, const char* = "location");
		~Card();
		bool setSuit(const char*);
		char* getSuit();
		bool setRank(int);
		int getRank();
		bool setLocation(const char*);
		char* getLocation();
		
		//NOTE: This is CardCopy.
		bool setCard(const char*, int, const char*);
		bool setCard(Card);

		void print();
	private:
		char *suit;
		int rank;
		char *location;
};
