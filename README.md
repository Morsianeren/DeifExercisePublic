# Card game exercise

The purpose of the test is not only to get a game working which meets the requirements, but to do design a solution which is still valid in the face of changing requirements. 

In this test you will design and implement a simple game of cards. Basically, a Player is dealt some Cards from a Deck. When a number of cards have been dealt, the Player with the highest sum of card values is the winner of the game.

## Exercise 1
Draw a domain model of the card game

On the following picture I have designed a domain model, using UML syntax. All 

![Domain model](assets/Domain%20model.drawio.svg)

## Exercise 2
Create a design of the system.

For this task i have chosen to use sequence diagrams. These show how the different objects interact with eachother. Also from what i understand, the game unfolds linear, which can be shown in the diagrams.

The use case for this exercise is assumed to be that the user can only start the program and define a few values, such as the number of players. Hereafter the game will run, show a winner and exterminate.

![Referenced sequence diagram](assets/sd%20Card%20Game.drawio.svg)

Each "state" of the game is shown on the sequence diagram above, where there is a linear progression between the states.

First the Start Game sequence. Here the game is initialized and the user defines how many players and how many cards should be dealt.

![sd Start Game](assets/sd%20Start%20Game.drawio.svg)

Next the game will start and deal cards to all the players initialized by the GameMaster class.

![sd Play Game](assets/sd%20Play%20Game.drawio.svg)

Lastly, the game will end and evaluate the players.
 
![sd Determine winner](assets/sd%20Determine%20winner.drawio.svg)


## Exercise 3
Implement your game and test it

For the style i follow Google's public style guide: [link](https://google.github.io/styleguide/cppguide.html)

I have included a makefile to compile this project in Windows or Linux.

### Example 

INSERT GIF HERE