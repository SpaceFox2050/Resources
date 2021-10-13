# Introduction (Unfinished)

There are three cars shuffler algorithms I made for my grade 9 science project on "What is the most efficient way to sufficiently shuffle a deck of cards from 
factory state?"

The three shuffling techniques included are riffle, a modified version of the overhand, and the smoosh (messpile) shuffle.

All three algorithms work by randomly generating numbers using C++'s <random> library found in C++ 11.

# Smoosh (messpile) Shuffle

The smoosh (messpile) shuffle works by spreading the deck of cards out on a surface and moving it around. After you think it is enough, the deck of cards is 
combined back into a deck. 

My algorithm starts by initilizing the random number generator, then setting other variables and the factory condition deck of cards itself. It then runs while the user does not enter a `0`, which terminates the program. The program then askes for the shuffle rate, which is how many places `deck [x]` will move up or down in the deck while being shuffled. If the card cannot move up or down anywhere between 0 and `shuffle rate` places in the deck, it is placed in the nearest open place in the deck.
  
The algorithm randomly generates a number of places the card could move up or down in the deck (0 <= place <= shuffle rate). If the card can move up or down that many places in the deck, it will be placed in that location. If not, the program will randomly generate another number of spaces the card can move up or down in the deck. The number generated will not be equal to any numbers it previously generated in the current loop. 
  
After the program has located a place to place all the cards (all card position changes will be temporary stored in the `next` array), it will transfer all the data from the `next` array to the `deck` array. It will then print the shuffled deck and call the `calculate` function.
  
The `calculate` function goes through the entire deck to check how many consecutive numbers and suits there are, and then prints then out after looping through the entire deck.
  
Oct 13 Update:
  
Changed old local number generator to a function that returns a random int. This reduces repeated code and a long initializing line.
