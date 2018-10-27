#include<iostream>
#include<stdlib.h>
#include<ctime>
#include "BlackJackCards.h"
using namespace std;

BlackJackCards::BlackJackCards()
{
    srand(time(NULL));
    cout<<"The game blackjack has initialized"<<"\n";
    cout<<"Welcome to Black Jack"<<"\n"<<"Please enter the total amount you want to bet"<<"\n"<<"The amount should not exceed 50000 and should be multiples of 100"<<"\n";
    cin>>InitialBet;
    while(1)
	{
	if(InitialBet>50000 || InitialBet%100!=0)
	{
		cout<<"The amount should not exceed 50000 and should be multiples of 100"<<"\n";
		cin>>InitialBet;
	}
	else if(InitialBet<=50000 && InitialBet%100==0)
		break;
	}
}
void BlackJackCards::Cards()
{
    Numbers.insert(Numbers.begin(),"A");
	Numbers.insert(Numbers.begin(),"2");
	Numbers.insert(Numbers.begin(),"3");
	Numbers.insert(Numbers.begin(),"4");
	Numbers.insert(Numbers.begin(),"5");
	Numbers.insert(Numbers.begin(),"6");
	Numbers.insert(Numbers.begin(),"7");
	Numbers.insert(Numbers.begin(),"8");
	Numbers.insert(Numbers.begin(),"9");
	Numbers.insert(Numbers.begin(),"10");
	Numbers.insert(Numbers.begin(),"J");
	Numbers.insert(Numbers.begin(),"Q");
	Numbers.insert(Numbers.begin(),"K");
	Types.insert(Types.begin(),"Spades");
	Types.insert(Types.begin(),"Hearts");
	Types.insert(Types.begin(),"Diamonds");
	Types.insert(Types.begin(),"Flowers");
	return;

}
void BlackJackCards::cardValues()
{
    CardValues.insert(pair <string,int> ("2",2));
	CardValues.insert(pair <string,int> ("3",3));
	CardValues.insert(pair <string,int> ("4",4));
	CardValues.insert(pair <string,int> ("5",5));
	CardValues.insert(pair <string,int> ("6",6));
	CardValues.insert(pair <string,int> ("7",7));
	CardValues.insert(pair <string,int> ("8",8));
	CardValues.insert(pair <string,int> ("9",9));
	CardValues.insert(pair <string,int> ("10",10));
	CardValues.insert(pair <string,int> ("J",10));
	CardValues.insert(pair <string,int> ("Q",10));
	CardValues.insert(pair <string,int> ("K",10));
	CardValues.insert(pair <string,int> ("A",11));
	return;
}


void BlackJackCards::UI()
{
    cout<<"Enter the Amount you want to bet"<<"\n"<<"The amount should not exceed 50000 and should be multiples of 100"<<"\n";
	cin>>Amount;
	while(1)
	{
	if(Amount>50000 || Amount%100!=0)
	{
		cout<<"The amount should not exceed 50000 and should be multiples of 100"<<"\n";
		cin>>Amount;
	}
	else if(Amount>InitialBet)
    {
        cout<<"The amount should not exceed the initial bet"<<"\n";
		cin>>Amount;
    }
	else if(Amount<=50000 && Amount%100==0)
		break;
	}
	InitialBet=InitialBet-Amount;
	return;
}
void BlackJackCards::dealerCards()
{

	UpcardNumber=Numbers[rand()%Numbers.size()];
	for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==UpcardNumber)
		UpcardValue=itr->second;
	}
	UpcardType=Types[rand()%Types.size()];
	hiddencardNumber=Numbers[rand()%Numbers.size()];
	for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==hiddencardNumber)
		hiddencardValue=itr->second;
	}
	hiddencardType=Types[rand()%Types.size()];
	cout<<"The Up card of the dealer is "<<UpcardNumber<<" -"<<UpcardType<<"\n";
	return;
}
int BlackJackCards::playerCards()
{

	FirstcardNumber=Numbers[rand()%Numbers.size()];
	for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==FirstcardNumber)
		FirstcardValue=itr->second;
	}
	FirstcardType=Types[rand()%Types.size()];
	SecondcardNumber=Numbers[rand()%Numbers.size()];
	for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==SecondcardNumber)
		SecondcardValue=itr->second;
	}
	SecondcardType=Types[rand()%Types.size()];
	cout<<"The First card of the player is "<<FirstcardNumber<<" -"<<FirstcardType<<" The Second card of the player is "<<SecondcardNumber<<" -"<<SecondcardType<<"\n";
	sumPlayer=FirstcardValue+SecondcardValue;
	cout<<"The sum of the player cards are "<<sumPlayer<<"\n";
	if(sumPlayer==21)
	{
	cout<<"BlackJack"<<"\n"<<"The player wins"<<"\n";
	Amount=Amount*2;
	InitialBet=InitialBet+Amount;
	cout<<"The total amount is "<<InitialBet<<"\n";
	return 1;
	}
	else if(sumPlayer>21)
    {
        cout<<"Its a bust"<<"\n";
        InitialBet=InitialBet-Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return 1;
    }
    return 0;
}
void BlackJackCards::Hit()
{

    cout<<"The player value is "<<sumPlayer<<"\n";
    NewCardNumber=Numbers[rand()%Numbers.size()];
    NewCardType=Types[rand()%Types.size()];
    cout<<"The new card is "<<NewCardNumber<<"-"<<NewCardType<<"\n";
    for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==NewCardNumber)
        {
            NewCardValue=itr->second;
        }
	}
	NewCards.insert(NewCards.begin(),NewCardValue);
	sumPlayer=sumPlayer+NewCardValue;
	cout<<" The sumPlayer is "<<sumPlayer<<"\n";
	if(sumPlayer==21)
    {
        cout<<"BlackJack"<<"\n";
        cout<<"You Won"<<"\n";
        Amount=Amount*2;
        InitialBet=InitialBet+Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
    }
    else if(sumPlayer>21)
    {
        cout<<"Bust"<<"\n";
        cout<<"You Lost"<<"\n";
        InitialBet=InitialBet-Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
    }
    else
    {
        while(1)
        {
        cout<<"Select an Option "<<"\n"<<"1)Hit 2)Stand"<<"\n";
        cin>>Option;
        if(Option==1)
        {
            Hit();
            break;
        }
        else if(Option==2)
        {
            Stand();
            break;
        }
        else
        {
            cout<<"Please select a valid option"<<"\n";
            cin>>Option;
        }
        }

    }
    return;
}
void BlackJackCards::Stand()
{
    cout<<"The hidden card of the dealer is "<<hiddencardNumber<<"-"<<hiddencardType<<"\n";
    sumDealer=UpcardValue+hiddencardValue;
    cout<<"The dealer value is "<<sumDealer<<"\n"<<"The player value is "<<sumPlayer<<"\n";
    if(sumDealer<sumPlayer)
    {
        while(sumDealer<sumPlayer)
        {
        NewCardNumber=Numbers[rand()%Numbers.size()];
    NewCardType=Types[rand()%Types.size()];
    cout<<"The new card of the dealer is "<<NewCardNumber<<"-"<<NewCardType<<"\n";
    for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==NewCardNumber)
        {
            NewCardValue=itr->second;
            break;
        }
	}
	NewCards.insert(NewCards.begin(),NewCardValue);
	sumDealer=sumDealer+NewCardValue;
	cout<<"The sum dealer is "<<sumDealer<<"\n";
	if(sumDealer==sumPlayer)
    {
        cout<<"Its a push"<<"\n";
        InitialBet=InitialBet+Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }

    else if(sumDealer>21)
    {
        cout<<"Its a bust"<<"\n"<<"You won"<<"\n";
        Amount=Amount*2;
        InitialBet=InitialBet+Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }
    else if(sumDealer==21)
        {
        cout<<"BlackJack"<<"\n"<<"The house won"<<"\n";
        InitialBet=InitialBet-Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }
    else if(sumDealer>sumPlayer)
    {
        cout<<"The house won"<<"\n";
        InitialBet=InitialBet-Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }
    }
    }
    else if(sumDealer==sumPlayer)
    {
        cout<<"Its a push"<<"\n";
        InitialBet=InitialBet+Amount;
        cout<<"The total Amount is "<<InitialBet<<"\n";
        return;
    }
    else if(sumDealer>21)
        {
        cout<<"Its a bust"<<"\n"<<"You won"<<"\n";
        Amount=Amount*2;
        InitialBet=InitialBet+Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }
    else if(sumDealer==21)
        {
        cout<<"BlackJack"<<"\n"<<"The House won"<<"\n";
        InitialBet=InitialBet-Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }
    else if(sumDealer>sumPlayer)
    {
        cout<<"The House won"<<"\n";
        InitialBet=InitialBet-Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
        return;
    }
    return;

}
void BlackJackCards::DoubleDown()
{


    Amount=Amount*2;
    InitialBet=InitialBet-(Amount/2);
    cout<<"The Amount is "<<Amount<<"\n";
    while(1)
        {
        if(CaseNO==1 || CaseNO==2 || CaseNO==3 || CaseNO==4)
        {
        cout<<"Select an Option "<<"\n"<<"1)Hit 2)Stand 3)Split()"<<"\n";
        cin>>Option;
        if(Option==1)
        {
            Hit();
            break;
        }
        else if(Option==2)
        {
            Stand();
            break;
        }
        else if(Option==3)
        {
            Split();
            break;
        }
        else
        {
        	cout<<"Please select a valid Option"<<"\n";
        	cin>>Option;
		}
        }
    	else
    	{
    	cout<<"Select an Option "<<"\n"<<"1)Hit 2)Stand"<<"\n";
        cin>>Option;
        while(1)
        {
        if(Option==1)
        {
            Hit();
            break;
        }
        else if(Option==2)
        {
            Stand();
            break;
        }
        else
        {
            cout<<"Please select a valid option"<<"\n";
            cin>>Option;
        }
        }
	}
	break;
}
return;

}
void BlackJackCards::Split()
{
	NewCardNumber=Numbers[rand()%Numbers.size()];
    NewCardType=Types[rand()%Types.size()];
    for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==NewCardNumber)
        {
            NewCardValue=itr->second;
            break;
        }
	}
	NewCards.insert(NewCards.begin(),NewCardValue);
	cout<<"The First card of the player is "<<FirstcardNumber<<" -"<<FirstcardType<<"\nThe New card of the player is "<<NewCardNumber<<" -"<<NewCardType<<"\n";
	SplitSecondCardValue=SecondcardValue;
	SplitSecondCardNumber=SecondcardNumber;
	SecondcardValue=NewCardValue;
	SecondcardNumber=NewCardNumber;
	sumPlayer=FirstcardValue+SecondcardValue;
	DifferentCases();
    Options();
    SelectOptions();
	NewCardNumber=Numbers[rand()%Numbers.size()];
    NewCardType=Types[rand()%Types.size()];
    for(itr=CardValues.begin();itr!=CardValues.end();itr++)
	{
		if(itr->first==NewCardNumber)
        {
            NewCardValue=itr->second;
            break;
        }
	}
	NewCards.insert(NewCards.begin(),NewCardValue);
	cout<<"The Second card of the player is "<<SplitSecondCardNumber<<" -"<<SecondcardType<<"\nThe New card of the player is "<<NewCardNumber<<" -"<<NewCardType<<"\n";
	FirstcardValue=SplitSecondCardValue;
	FirstcardNumber=SplitSecondCardNumber;
	SecondcardValue=NewCardValue;
	SecondcardNumber=NewCardNumber;
	sumPlayer=FirstcardValue+SecondcardValue;
	DifferentCases();
    Options();
    SelectOptions();
    return;
}
int BlackJackCards::DifferentCases()
{
    CaseNO=0;
    if(FirstcardNumber==SecondcardNumber && (UpcardValue==10 || UpcardValue==11) )
       CaseNO=1;
    else if(FirstcardNumber==SecondcardNumber && UpcardValue==10)
       CaseNO=2;
    else if(FirstcardNumber==SecondcardNumber && UpcardValue==11)
       CaseNO=3;
    else if(FirstcardNumber==SecondcardNumber)
       CaseNO=4;
    else if(UpcardValue==10)
        CaseNO=5;
    else if(UpcardValue==11)
        CaseNO=6;
        return 0;
}
int BlackJackCards::Options()
{
    switch(CaseNO)
        {
        case 1:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down 4)Split 5)Surrender 6)Insurance"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>6)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        case 2:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down 4)Split 5)Surrender"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>5)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        case 3:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down 4)Split 5)Insurance"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>5)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        case 4:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down 4)Split"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>4)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        case 5:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down 4)Surrender"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>4)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        case 6:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down 4)Insurance"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>4)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        default:
            while(1)
            {
            cout<<"Please enter one of the options"<<"\n"<<"1)Hit 2)Stand 3)Double Down"<<"\n";
            cin>>OptionNo;
            if(OptionNo<1 || OptionNo>3)
                {
                cout<<"Please enter a valid option Number"<<"\n";
                cin>>OptionNo;
                }
                else
                    break;
            }
            break;
        }
        return 0;
}
int BlackJackCards::SelectOptions()
{
    switch(OptionNo)
        {
        case 1:
            Hit();
            break;
        case 2:
            Stand();
            break;
        case 3:
            DoubleDown();
            break;
        case 4:
            if(CaseNO==1 || CaseNO==2 || CaseNO==3 || CaseNO==4)
                Split();
            else if(CaseNO==5)
                Surrender();
            else if(CaseNO==6)
                Insurance();
            break;
        case 5:
            if(CaseNO==1 || CaseNO==2)
                Surrender();
            else if(CaseNO==3)
                Insurance();
            break;
        case 6:
            Insurance();
            break;
        }
        return InitialBet;
}
void BlackJackCards::Surrender()
{
    Amount=Amount/2;
    InitialBet=InitialBet-Amount;
    cout<<"The total Bet is "<<InitialBet<<"\n";
    return;
}
void BlackJackCards::Insurance()
{
    cout<<"The hidden card is "<<hiddencardValue<<" -"<<hiddencardType<<"\n";
    sumDealer=UpcardValue+hiddencardValue;
    if(sumDealer==21)
    {
        cout<<"You won The Insurance"<<"\n";
        Amount=Amount*2;
        InitialBet=InitialBet+Amount;
        cout<<"The total amount is "<<InitialBet<<"\n";
    }
    else
    {
        cout<<"No Insurance claimed"<<"\n";
    }
    return;
}
BlackJackCards::~BlackJackCards()
{
    cout<<"The game blackjack is over"<<"\n";
    cout<<"The total Amount is "<<InitialBet<<"\n";
    cout<<"Thank you for playing"<<"\n";
}
int main()
{
    int Choice,result,RemainingAmount;
    BlackJackCards B1;
    B1.Cards();
    B1.cardValues();
    while(1)
    {
        B1.UI();
    B1.dealerCards();
    result=B1.playerCards();
    if(result==1)
        {
        cout<<"Do you want to quit the game?"<<"\n"<<"Enter 1 for yes or 2 for no"<<"\n";
    cin>>Choice;
    if(Choice==1)
        break;
    else
        continue;
        }
    B1.DifferentCases();
    B1.Options();
    RemainingAmount=B1.SelectOptions();
    if(RemainingAmount<=0)
    {
        break;
    }
    cout<<"Do you want to quit the game?"<<"\n"<<"Enter 1 for yes or 2 for no"<<"\n";
    cin>>Choice;
    if(Choice==1)
        break;
    else
        continue;

    }

}



