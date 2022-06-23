# Welcome to My Mastermind
***

## Task
Implementation of mastermind game. 
Mastermind is a game composed of 8 pieces of different colors. A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces. A misplaced piece is a piece that is present in the secret code but that is not in a good position.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops. 

The program accepts the following parameters: 
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated. 
-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.

## Description
Create a set of functions:
    - to find the appropriate arguments
    - to check the validity of the given code
    - to set the code for the game
    - to find the number of well placed and misplaced pieces
    - to check the end of the game

## Installation
make

## Usage

./my_mastermind -c code -t numberOfRounds
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
