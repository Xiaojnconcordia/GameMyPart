1. To run the game:
1) Double click Game_XJn.sln
2) In Visual studio, press ctrl + F5 on your keyboard
3) The game will run in Windos console. 

2. Program explaination:
The game idea is from the board game “POWER GRID”. 
This project is finished by a group. 

The part of MY work is:

A map as a connected graph is implemented, where each node represents a city. Edges between nodes represent adjacency between cities. 

The map has 6 areas. If the number of player is less than 4, some areas can be removed from the map, and the map is ensured still as a connected graph. 

Players can buy cities in this game. When one player owns city A and wants buy City B (not necessarily ajacent) , he/she must also pay for the route between the two cities. There might be many paths from A to B, and the shortest path can be found when this player pays for City B.

In the game, players can buy powerplants from a deck of shuffle powerplant cards. Instead, AI players are designed to bid with three different strategies:
1) An aggressive player: anytime a good power plant becomes available, this player continues to bid.
2) A moderate player: this player will try to avoid a situation that one players owns too many powerplants, including himself/herself.
3) An environmentalist player: In this game, a type of powerPlants is called environmental plants. Ordinary powerplants need resources but this kind of plant does not need any. This player favors buying environmental plants at the end of the round whenever possible.
