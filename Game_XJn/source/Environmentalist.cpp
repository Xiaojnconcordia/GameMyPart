#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

void Environmentalist::execute(PowerPlant& currentPowerPlant, int& currentPrice,
	vector<PowerPlant>& market, int& numOfPlayerPass,
	int& playerLeft, int& indexOfCard, Player &p, int turn)
{
	if (numOfPlayerPass < playerLeft - 1) {
		cout << "\n---Environmentalist strategy used by " << p.getName() << "---\n";
		cout << p.getName() << " will automatically finish the auction phase" << endl;
	}
	
	
	//if this environmental player is not the only one who hasn't got a card	
	if (playerLeft > 1) {
		if (currentPowerPlant.getNumber() == 0) { //if I am the first to start a card auction 
		//Print the cards in the market
			cout << "------------------------------Market------------------------------"
				<< endl;
			for (size_t i = 0; i < market.size(); i++) {
				cout << market[i].toString() << endl;
			}
			cout << endl;

			//set a negative number, meaning choice is not decided yet
			int choice = -1;

			//if there is a environmental card in the market, choose it
			for (int i = 0; i < 4; i++) {
				if (market[i].getTypeName() == "eco")
					choice = i;
			}

			
			//if "No environmental Card found in the market
			if (choice == -1) {
				cout << "No environmental Card found in the market.\n";
				cout << "Will auto choose the cheapest card.\n";
				choice = 0; //choose the cheapest 					
			}

			if (choice != -1)
				cout << p.getName() << " automatically chose the environmental Plant in the market \n";

						
			currentPowerPlant = market[choice];
			cout << p.getName() << " has chosen " << currentPowerPlant.toString() << endl;
			currentPrice = market[choice].getNumber();
			indexOfCard = choice;
			cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;			
		}

		//if the player follow others' bid 
		else
		{ 
			if (numOfPlayerPass < playerLeft - 1) {
				//if the card others bid is not a eco card
				if (currentPowerPlant.getTypeName() != "eco") {
					cout << "Other players are bidding for a non-environmental Card. "
						<< p.getName() << " passed.\n";
					p.setAuction(false);
					numOfPlayerPass++;
					return;
				}

				//if the player doesn't have enough money
				else if (p.getMoney() <= currentPrice) {
					cout << p.getName() << " doesn't have eno111ugh money to continue bidding. "
						<< p.getName() << " passed.\n";
					p.setAuction(false);
					numOfPlayerPass++;
					return;
				}

				//if the environmentalist player has enough money, 
				//he/she will always continue bidding for an "eco" card
				else {
					currentPrice = currentPrice + 1;
					cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;
				}
			}						
		}
	}

	//if this environmental player is the only one who hasn't got a card
	if (playerLeft == 1) {
		cout << p.getName() << " is the last Player who hasn't got a card. \n";
		cout << p.getName() << " will automatically choose the eco card in the market \n";
		int choice = -1;
		
		//if there is a environmental card in the market, choose it
		for (int i = 0; i < 4; i++) {
			if (market[i].getTypeName() == "eco")
				choice = i;
		}
		if (choice != -1) {
			cout << p.getName() << " automatically chose the environmental Plant in the market \n";
		}
		

		//if "No environmental Card found in the market
		if (choice == -1) {
			cout << "No environmental Card found in the market.\n";
			
			if (turn == 1) {
				cout << "But it is turn 1, " << p.getName()
					<< " must buy a card and automatically chose cheapest card.\n";					
				choice = 0;				
			}
			

			else { //from turn 2, the player will choose not to buy a card if there is no "eco" in market
				cout << "Thus, " << p.getName()
					<< " will not buy any card this turn.\n";				
				p.setAuction(false);
				numOfPlayerPass++;
				p.setRoundStatus(false);
				return;
			}
				
		}

		//if the money is not enough to buy environmental card
		else if (p.getMoney() < market[choice].getNumber())
		{
			cout << "You cannot afford the environmental card.\n";
			p.setAuction(false);
			numOfPlayerPass++;
			return; //terminate the function execute
		}
		indexOfCard = choice;
		currentPowerPlant = market[choice];
		cout << p.getName() << " has chosen " << currentPowerPlant.toString() << endl;
		currentPrice = market[choice].getNumber();
		cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;

		
		
	}	
}


//case 1: strategy player chose card and give first bid.
//should choose the "eco" card and bid same price as card number.  (checked)
//if no "eco" card in the current market, the player still need to choose a card. (checked)
//should choose the cheapest Plant (checked)


//case 2: strategy player follow others' bid
//if others are bidding an "eco" card, should always follow, or pass for not enough money. (checked)
//if others are not bidding an "eco" card, the strategy player should pass. (checked)

//case 3: strategy player is the last one who has not got a card
//should choose the "eco" card and bid same price as card number, wins the bid immidiately. (checked)
//in turn 1, if no "eco" in market, the strategy player has to buy a card, should buy the cheapest. (checked)
//from turn 2, if no "eco" in market, should choose not to buy any card. (checked)

