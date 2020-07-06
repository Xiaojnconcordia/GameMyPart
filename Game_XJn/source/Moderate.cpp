#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

void Moderate::execute(PowerPlant& currentPowerPlant, int& currentPrice,
	vector<PowerPlant>& market, int& numOfPlayerPass,
	int& playerLeft, int& indexOfCard, Player &p, int turn)
{
	if (numOfPlayerPass < playerLeft - 1) {
		cout << "\n---Moderate strategy used by " << p.getName() << "---\n";
		cout << p.getName() << " will automatically finish the auction phase" << endl;
	}

	int capacity = 0; //to stores the max units of resources a player can buy
					  //regardless of type
	int held; //stores the total units of resources a player holds
			  //regardless of type

	for (int j = 0; j < p.getNumOfPowerPlant(); j++)
		capacity = capacity + p.getPowerPlant(j).getNeed();

	capacity = capacity * 2;
	held = p.getCoalNum() + p.getOilNum()
		+ p.getGarbageNum() + p.getUraniumNum();

	int left = capacity - held; //if left == 0, the player's resource is full

	cout << "With his/her current Powerplant cards, "
		<< p.getName() << " can buy " << left << " unit(s) of resources.\n";

	if (left < 0) {
		cout << "The initialized card or resourse is wrong. \n";
		cout << "The program ends abnormally. \n.";
		exit(10);
	}

	if (left > 0)
	{
		cout << p.getName()
			<< " still has " << left
			<< " space to hold resources and will not buy any card this turn. \n";
		p.setAuction(false);
		p.setRoundStatus(false);
		numOfPlayerPass++;
		return;
	}

	//if left == 0, morerate strategy should be done
	int min = 100; //set a big enough number to min
	for (int j = 0; j < p.getNumOfPowerPlant(); j++)
		if (min > p.getPowerPlant(j).getNeed())
			min = p.getPowerPlant(j).getNeed();

	//find the most inefficient card's type
	string minType = "";
	for (int j = 0; j < p.getNumOfPowerPlant(); j++)
		if (min == p.getPowerPlant(j).getNeed())
			minType = p.getPowerPlant(j).getTypeName();

	cout << p.getName()
		<< " needs to buy a more efficient card of type: " << minType << endl;
	string type = minType;


	//if this moderate player is not the only one who hasn't got a card	
	if (playerLeft > 1) {	
		if (currentPowerPlant.getNumber() == 0) { //if I am the first to start a card auction 
			int choice = -1;
			int max = 0;
			//find a card in market. This card is considered as the most efficient card if:
			//1) has the type wanted and 2) has largest needed number of this type
			for (int i = 0; i < 4; i++) {
				if (type == market[i].getTypeName() && max < market[i].getNeed()) {
					max = market[i].getNeed();
					choice = i;
				}					
			}	

			//if "No target type Card found in the market
			if (choice == -1) {
				cout << "A more efficient Card is not found in the market.\n";
				cout << "Will auto choose the cheapest card.\n";
				choice = 0; //choose the cheapest 					
			}

			if (choice != -1)
				cout << p.getName() << " automatically chose the " << type << " type Plant in the market \n";

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
				//if the card others bid is not a target type 
				if (currentPowerPlant.getTypeName() != type) {
					cout << "Other players are not bidding for a " << type << " Card. "
						<< p.getName() << " passed.\n";
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

				//if the moderate player has enough money, 
				//he/she will always continue bidding for an "eco" card
				else {
					currentPrice = currentPrice + 1;
					cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;
				}
			}
		}
	}
	
	//if this moderate player is the only one who hasn't got a card
	if (playerLeft == 1) {
		cout << p.getName() << " is the last Player who hasn't got a card. \n";
		cout << p.getName() << " will automatically choose the eco card in the market \n";
		int choice = -1;

		int max = 0;
		// find a card in market. This card is considered as the most efficient card if:
		// 1) has the type wanted and 2) has largest needed number of this type
		for (int i = 0; i < 4; i++) {
			if (type == market[i].getTypeName() && max < market[i].getNeed()) {
				max = market[i].getNeed();
				choice = i;
			}
		}

		//if a more efficient Card is not found in the market
		if (choice == -1) {
			cout << "a more efficient Card is not found in the market.\n";
			if (turn == 1) {
				cout << "But it is turn 1, " << p.getName()
					<< " must buy a card and automatically chose cheapest card.\n";
				choice = 0;
			}
			else {
				cout << "Thus, " << p.getName()
					<< " will not buy any card this turn.\n";
				p.setAuction(false);
				numOfPlayerPass++;
				p.setRoundStatus(false);
				return;
			}			
		}

		//if the money is not enough to buy target type card
		else if (p.getMoney() < market[choice].getNumber())
		{
			cout << "You cannot afford this card.\n";
			p.setAuction(false);
			numOfPlayerPass++;
			return; //terminate the function execute
		}
		if (choice != -1) {
			cout << p.getName() << " automatically chose a more efficient Plant in the market \n";
		}
		
		currentPowerPlant = market[choice];
		indexOfCard = choice;
		cout << p.getName() << " has chosen " << currentPowerPlant.toString() << endl;
		currentPrice = market[choice].getNumber();
		cout << p.getName() << " bid " << currentPrice << " Elektroes!!\n" << endl;
		
	}	
}

//case 1: strategy player chose card and give first bid.
//should choose the type of card that the player currently has the least resource capacity.  (checked)
//if no such card of the type, the player still need to choose a card.  (checked)
//should choose the cheapest Plant.  (checked)


//case 2: strategy player follow others' bid
//if others are bidding the card of target type, should always follow, or pass for not enough money. (checked)
//if others are not bidding target type card, the strategy player should pass. (checked)

//case 3: strategy player is the last one who has not got a card
//should choose the target type card card and bid same price as card number, wins the bid immidiately.  (checked)
//in turn 1, the moderate strategy player has to buy a card, should buy the cheapest. (checked)
//from turn 2, if no target type card in market, should choose not to buy any card.  (checked)


