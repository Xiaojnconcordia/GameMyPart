#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

void Aggressive::execute(PowerPlant& currentPowerPlant, int& currentPrice, 
	vector<PowerPlant>& market, int& numOfPlayerPass, 
	int& playerLeft, int& indexOfCard, Player &p, int turn)
{
	if (numOfPlayerPass < playerLeft - 1) {
		cout << "\n---Aggressive strategy used by " << p.getName() << "---\n";
		cout << p.getName() << " will automatically finish the auction phase" << endl;
	}

	//if this environmental player is not the only one who hasn't got a card	
	if (playerLeft > 1) {
		//if the player is the one that chooses a card to bid, cannot pass 
		if (currentPowerPlant.getNumber() == 0) {
		//Print the cards in the market
			cout << "------------------------------Market------------------------------"
				<< endl;
			for (size_t i = 0; i < market.size(); i++) {
				cout << market[i].toString() << endl;
			}
			cout << endl;

			//automatically choose when a good card becoms availale
			//a good card is considered to be the card at the last position in current market
			cout << p.getName() << " automatically chose the 4th card in the current market \n";
			int choice = 3;		

			//In turn 1, a player always has enough money
			//From turn 2, if a player does not have enough money 
			if (turn != 1 && p.getMoney() < market[choice].getNumber())
			{
				cout << "You cannot afford this card.\n";
				p.setAuction(false);
				numOfPlayerPass++;
				//p.setRoundStatus(false);
				return;
			}
			indexOfCard = choice;
			currentPowerPlant = market[choice];
			cout << p.getName() << " has chosen " << currentPowerPlant.toString() << endl;
			currentPrice = market[choice].getNumber();
			cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;
		}

		//if the player follow others' bid 
		else {
			if (numOfPlayerPass < playerLeft - 1) {  //if there are more than two player bidding
				
				//if the card others bid is not a good card (4th card in current market)
				if (currentPowerPlant.getNumber() != market[3].getNumber()) {
				cout << "This is not a good enough card. "
					<< p.getName() << " Passed.\n";
				p.setAuction(false);
				numOfPlayerPass++;
				return;
				}

				//if the player doesn't have enough money
				else if (p.getMoney() <= currentPrice) {
					cout << p.getName() << " doesn't have enough money to continue bidding. "
						<< p.getName() << " passed.\n";
					p.setAuction(false);					
					numOfPlayerPass++;
					return;
				}				

				//if the aggressive player has enough money, 
				//he/she will always continue bidding for a good card
				else {
					currentPrice = currentPrice + 1;					
					cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;
				}				
			}
		}
	}
	
	//if this aggressive player is the only one who hasn't got a card
	if (playerLeft == 1) {
		cout << p.getName() << " is the last Player who hasn't got a card. \n";
		cout << p.getName() << " automatically chose the 4th card in the market \n";
		int choice = 3;
		//if the money is not enough to buy 4th card

		//In turn 1, a player always has enough money
		//From turn 2, if a player does not have enough money 
		if (turn != 1 && p.getMoney() < market[choice].getNumber())
		{
			cout << "You cannot afford this card.\n";
			p.setAuction(false);
			numOfPlayerPass++;
			p.setRoundStatus(false);
			return;
		}
		currentPowerPlant = market[choice];
		cout << p.getName() << " has chosen " << currentPowerPlant.toString() << endl;

		currentPrice = market[choice].getNumber();
		indexOfCard = choice;
		cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;
		
	}	
}

//case 1: strategy player chose card and give first bid.
//should choose the 4th card and bid same price as card number.  (checked)

//case 2: strategy player follow others' bid
//if others are bidding a 4th card, the strategy player should always follow, or pass for not enough money (checked)
//if others are not bidding a 4th card, the strategy player should pass. (checked)

//case 3: strategy player is the last one who has not got a card
//should choose the 4th card and bid same price as card number, wins the bid immidiately. (checked)