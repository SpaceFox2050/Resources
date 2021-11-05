# Introduction 

There are three cars shuffler algorithms I made for my grade 9 science project on "What is the most efficient way to sufficiently shuffle a deck of cards from 
factory state?"

The three shuffling techniques included are riffle, the overhand, and the smoosh (messpile) shuffle.

All three algorithms work by randomly generating numbers using C++'s <random> library found in C++ 11.
  
If you want to learn more about shuffling, you can go to the [wikipedia shuffling page](https://en.wikipedia.org/wiki/Shuffling)

Nov 2 Update:

Updated `calculate` function: brought back `for loops` to check for repeating cards and a for loop to check for the average number of spaces a card has moved up or down. This is calculated by comparing the current deck and last deck and getting the distance between the two cards. The algorithm adds all these numbers up and divides it by 52 at the end to get the average. 

Also removed where code asks for `shuffle rate` every shuffle cycle, now the `shuffle rate` is only asked for at the start of every code exection and remains constant throughout all shuffle cycles. If the inputed number is not within the constraints of the current shuffle, the algorithm will continously ask for a new `shuffle rate` until a number within the constraints is entered.

Nov 5 Update:

Updated `calculate` function, added same cards dished out to same player function in the nested for loop that checks for average number of spaces moved up and down. This added part checks how many cards are handed out to the same person in a 2, 3, or 4 player game. It works by first finding identical cards in `deck` and `last`, it then gets the absolute value of the index where the card was found in `deck` and the index where the card was found in `last`. It then sees if both indexs modulus (%) is equal to each other. Modulus returns the remainder after dividing by `x`, written after `%` (index%`x`). We check the mod of 2, 3, and 4 to check how many cards are handed out to the same person in an either 2, 3, or 4 person game. Modulus by 2 checks for a 2 player game, mod 3 checks for a 3 player game, and so on.

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
  
We then copy `deck` into `split`, where `split` is the deck being held in one hand and `deck` will have its card numbers changed when the `split` deck drops down onto the other hand, we then run while `split` is not empty. A random number `sec` is generated with the constraints 1 <= `sec` <= `high`, and then drops `sec` many cards from the top of the `split` deck into the `deck` deck. If 'sec' is larger compared to `split.size()`, we stop when `split.size()` is 0 to not get an `sigsegv` error (out of bounds). 
  
We then print out the shuffled `deck` and transfer it into an array becuase th `calculate` function only accepts array while we have been using a vector for `deck`.
