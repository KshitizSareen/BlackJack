#ifndef BLACKJACKCARDS_H_INCLUDED
#define BLACKJACKCARDS_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>
using namespace std;
class BlackJackCards
{
	public:
	    BlackJackCards();
		void cardValues();
	    void Cards();
		void UI();
		void dealerCards();
		int playerCards();
		int DifferentCases();
    int Options();
    int SelectOptions();
    void Hit();
    void Stand();
    void DoubleDown();
    void Split();
    void Surrender();
    void Insurance();
    ~BlackJackCards();
    int Amount,CaseNO,OptionNo,InitialBet;
    protected:
        int Option,SplitSecondCardValue;
		int sumDealer,sumPlayer,UpcardValue,hiddencardValue,FirstcardValue,SecondcardValue,NewCardValue;
		vector<string> Numbers;
		vector<string> Types;
		vector<int> NewCards;
		string UpcardNumber,hiddencardNumber,FirstcardNumber,SecondcardNumber,NewCardNumber,SplitSecondCardNumber;
		string UpcardType,hiddencardType,FirstcardType,SecondcardType,NewCardType;
		map <string,int> CardValues;
		map <string, int> :: iterator itr;
};


#endif // BLACKJACK_H_INCLUDED
