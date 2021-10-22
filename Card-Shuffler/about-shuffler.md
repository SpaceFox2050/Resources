# Introduction 

The overhand shuffle has not be added and will be when it is finished

There are three cars shuffler algorithms I made for my grade 9 science project on "What is the most efficient way to sufficiently shuffle a deck of cards from 
factory state?"

The three shuffling techniques included are riffle, the overhand, and the smoosh (messpile) shuffle.

All three algorithms work by randomly generating numbers using C++'s <random> library found in C++ 11.

# Smoosh (messpile) Shuffle

The smoosh (messpile) shuffle works by spreading the deck of cards out on a surface and moving it around. After you think it is enough, the deck of cards is 
combined back into a deck. 

My algorithm starts by initilizing the random number generator, then setting other variables and the factory condition deck of cards itself. It then runs while the user does not enter a `1`, which terminates the program. The program then askes for the shuffle rate, which is how many places `deck [x]` will move up or down in the deck while being shuffled. If the card cannot move up or down anywhere between 0 and `shuffle rate` places in the deck, it is placed in the nearest open place in the deck.
  
The algorithm randomly generates a number of places the card could move up or down in the deck (0 <= place <= shuffle rate). If the card can move up or down that many places in the deck, it will be placed in that location. If not, the program will randomly generate another number of spaces the card can move up or down in the deck. The number generated will not be equal to any numbers it previously generated in the current loop. 
  
After the program has located a place to place all the cards (all card position changes will be temporary stored in the `next` array), it will transfer all the data from the `next` array to the `deck` array. It will then print the shuffled deck and call the `calculate` function.
  
The `calculate` function goes through the entire deck to check how many consecutive numbers and suits there are, and then prints then out after looping through the entire deck.
  
Oct 13 Update:
  
Changed old local number generator to a function that returns a random int. This reduces repeated code and a long initializing line.
  
# Riffle Shuffle
  
The riffle shuffle works by splitting the deck into two appox equal decks and holding each split deck in each hand. The thumb then slowly lets cards fall down onto each other, creating a shuffled deck.
  
My algorithm starts the same way as the smoosh shuffle, by initlizing the factory setting deck of cards and runs while the user does not enter `1`. The program then asks for the shuffle rate, which is how many cards at max will fall from each thumb before being covered by the other pile of cards, which uses the same shuffle rate logic. The shuffle rate has a constraint of 2 <= input <= 9 and the constant lowest shuffle rate (already implemented in the code) is 1. 
  
There is then a `while` loop that runs while there are still cards left in the two seperated smaller decks. It generates a random shuffle rate `moves` and see if it will shuffle more cards than there are in the two seperate decks. It checks this by seeing if `ttop/tbot + moves >= 26`, if it is true, the moves will be lowered so that if added to ttop or tbot, it will not go over 25. 
  
There is a for loop inside the while loop to add the cards from the seperated decks into the full deck. In real life we would have it drop down onto the table, but in the algorithm we insert each variable into the `deck` array, which stored the last shuffled deck.
  
Since there is no need for a `next` array, we print the shuffled deck of cards and call the `calculate` function to calculate consecutive numbers and suits.
  
Oct 14 Update:
  
Removed repeated cards for loop from calculate function

# Overhand Shuffle
  
The overhand shuffle works by holding the deck in one hand, while lowering it into the other hand over and over while the other hand pulls down a few cards at a time. This continues until the deck cannot be pulled down anymore and puts the rest of the cards on top of the shuffled deck.
  
My algorithm starts the say way as the previous two shuffles, by initlzing the factory setting deck of cards and runs while the user does not enter `1`. The program then asks for the shuffle rate, which is how many cards at max will be pulled from the deck being shuffled, which uses the same shuffle rate logic. The shuffle rate has a constraint of 2 <= input <= 9 and the constant lowest shuffle rate (already implemented in the code) is 1. 
  
  unfinished
