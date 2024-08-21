# Card Game Exercise

The purpose of the test is not only to get a game working that meets the requirements but also to design a solution that remains valid in the face of changing requirements.

In this test, you will design and implement a simple card game. Essentially, a Player is dealt some Cards from a Deck. When a number of cards have been dealt, the Player with the highest sum of card values is the winner of the game.

## Exercise 1
Draw a domain model of the card game

In the following picture, I have designed a domain model using UML syntax.

![Domain model](assets/Domain%20model.drawio.svg)

The picture describes itself, but you can read more about the different domains below.

### Game
**Knowledge:** The game object knows which players are in the game and owns a deck.  
**Responsibility:** The game object starts and stops the game and determines a winner. It controls everything associated with that specific game.

### Deck
**Knowledge:** The deck only knows which cards are in it. It is important that the container for the cards can be dynamically expanded since we don’t know how many cards it should hold.  
**Responsibility:** The deck is responsible for distributing Card objects to the players. The Game decides how many cards and to whom they are dealt.

### Player
**Knowledge:** The player knows their own hand and name. Again, it is important that the container for the cards can be dynamically expanded.  
**Responsibility:** The player is responsible for keeping track of their cards and sharing their total value when necessary.

### Card
**Knowledge:** The card only knows its suit, number, and total value. These could be implemented with getters and setters; however, these values should never change and are therefore just constant public variables.  
**Responsibility:** Share its value when needed.

## Exercise 2
Create a design of the system.

For this task, I have chosen to use sequence diagrams. These diagrams show how the different objects interact with each other. Additionally, the game unfolds linearly, which can be shown in the diagrams.

The use case for this exercise assumes that the user can only start the program and define a few values, such as the number of players. After that, the game will run, show a winner, and terminate.

Each "state" of the game is shown in the sequence diagram below, where there is a linear progression between the states. I have included the main method since it will function as the interface between the user and the Game.

![Referenced sequence diagram](assets/sd%20Card%20Game.drawio.svg)

First, the Start Game sequence. Here, the game is initialized, and the user defines how many players and how many cards should be dealt.

![sd Start Game](assets/sd%20Start%20Game.drawio.svg)

Next, the game will start and deal cards to all the players, as initialized by the GameMaster class.

![sd Play Game](assets/sd%20Play%20Game.drawio.svg)

Lastly, the game will end and evaluate the players.

![sd Determine winner](assets/sd%20Determine%20winner.drawio.svg)

A problem with this design is that the Deck is initialized outside the Game, even though it is only used here. To solve this I have designed a new domain model, where the Game class becomes an interface. This way it is possible to easily implement different gamemodes, and implement specific functionality for the different modes.

![Extended domain model](assets/Extended%20domain%20diagram.drawio.svg)

Note that functions written in *italic* are abstract. This means that the CardGame class must implement StartGame() and DetermineWinner(). The CardGame class must also set its settings, that later can be get and set by whatever user interface will be implemented. <ins>This also means that how many cards each player should get can be defined here.</ins>

## Exercise 3
Implement your game and test it

For the style, I follow Google's public style guide: [link](https://google.github.io/styleguide/cppguide.html)

I have included a Makefile to compile this project on both Windows and Linux. Simply run `make` in your CLI.

The implementation follows the sequence diagrams created in exercise 2, and the classes are the same as those in the Domain model in exercise 1. I have chosen not to implement the extended domain diagram, because of my limited time to do this assignment.

### Example 

![Demo gif](assets/Demo.gif)
