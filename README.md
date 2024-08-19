# Card game exercise

The purpose of the test is not only to get a game working which meets the requirements, but to do design a solution which is still valid in the face of changing requirements. 

In this test you will design and implement a simple game of cards. Basically, a Player is dealt some Cards from a Deck. When a number of cards have been dealt, the Player with the highest sum of card values is the winner of the game.

## Exercise 1
Draw a domain model of the card game

On the following picture I have designed a domain model, using UML syntax.

![Domain model](assets/Domain%20model.drawio.svg)

The picture describes itself, but you can read more about the different domains below.

### Game
Knowledge: The game object knows of what players are in the game, and owns a deck. 
Responsibility: The game object starts and stops the game, and determines a winner. It controls whatever is associated to that specific game.

### Deck
Knowledge: The deck only knows what cards are in itself. It is important that the container for the cards can be dynamically expanded, since we dont know how many cards it should hold. 
Responsibility: The deck is responsible for distributing Card objects to the players. The Game decides how many and to who.

### Player
Knowledge: The player knows of their own hand and name. Again, it is important that the container for the cards can be dynamically expanded.
Responsibility: The player is responsible for keeping track of their cards, and share their total value when necessary.

### Card
Knowledge: Only knows it's suit, number and total value. They could be implemented with a getter and setter, however, these values should never change and is therefore just const public variables.
Responsibility: Share it's value when needed.

## Exercise 2
Create a design of the system.

For this task i have chosen to use sequence diagrams. These show how the different objects interact with eachother. Also the game unfolds linear, which can be shown in the diagrams.

The use case for this exercise is assumed to be that the user can only start the program and define a few values, such as the number of players. Hereafter the game will run, show a winner and exterminate.

Each "state" of the game is shown on the sequence diagram below, where there is a linear progression between the states. I have chosen to include main, since it will function as the interface between the user and the Game.

![Referenced sequence diagram](assets/sd%20Card%20Game.drawio.svg)

First the Start Game sequence. Here the game is initialized and the user defines how many players and how many cards should be dealt.

![sd Start Game](assets/sd%20Start%20Game.drawio.svg)

Next the game will start and deal cards to all the players initialized by the GameMaster class.

![sd Play Game](assets/sd%20Play%20Game.drawio.svg)

Lastly, the game will end and evaluate the players.
 
![sd Determine winner](assets/sd%20Determine%20winner.drawio.svg)

For the future, it could make sense to make an interface for the Game class, so different gamemodes could be implemented without much change for the code in main. 

## Exercise 3
Implement your game and test it

For the style i follow Google's public style guide: [link](https://google.github.io/styleguide/cppguide.html)

I have included a makefile to compile this project in both Windows or Linux. Simply run make in your CLI.

The implementation follows the sequence diagrams created in exercise 2, and the classes are the same as the ones on the Domain diagram.

### Example 

![Demo gif](assets/Demo.gif)