#include <iostream>
#include <vector>
#include <random>
using namespace std;

void calculate(string deck [52], string last [52]){
    int nums = 0, suits = 0, repeat = 0, doub = 0, triple = 0, quad = 0;
    double average = 0.0;
    for(int x = 1; x < 52; x++){
        if(deck[x].size() == deck[x-1].size() && deck[x].size() == 3){
            nums++;
        }else{
            if(deck[x].back() == deck[x-1].back())
                nums++;
        }
        if(deck[x].front() == deck[x-1].front()){
            suits++;
        }
    }
    for(int x = 0; x < 51; x++){
        for(int y = x+1; y < 52; y++){
            if(deck[x] == deck[y]){
                repeat++;
                cout << deck[x] << " " << deck[y] << endl;
            }
        }
    }
     for(int x = 0; x < 52; x++){
        for(int y = 0; y < 52; y++){
            if(deck[x] == last[y]){
                //check average
                average+=abs(x-y);
                //check number of cards given out to same person (2-4 player games)
                if((x+1)%4 == (y+1)%4){
                    quad++;
                    doub++;
                }else if((x+1)%3 == (y+1)%3){
                    triple++;
                }else if((x+1)%2 == (y+1)%2){
                    doub++;
                }
            }
        }
    }
    average/=52;
    cout << "Consecutive numbers: " << nums << endl;
    cout << "Consecutive suits: " << suits << endl;
    cout << "Average spaces moved up and down " << average << endl;
}

//new random number generator func
int random(int low, int high){
    random_device set;
    mt19937 xset(set());
    uniform_int_distribution<int> randx(low, high);
    int temp = randx(xset);
    return temp;
}

void smoosh(){
    
    //random_device set;
    //mt19937 xset (set());
    int state = 0, temp = 0, high, place, count = 1;
    string suits [4] = {"H", "C", "D", "S"};
    string nums [] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};
    string deck [52];
    string next[52];
    string last[52];
    vector<int> swap;
    for(auto & suit : suits){
        for(auto & num : nums){
            deck[temp]+=suit;
            deck[temp]+=num;
            temp++;
        }
    }
    while(true){
        cout << "Enter shuffle rate (max places cards will move up/down in the deck)" << endl;
        cout << "Constraints 2 <= input < 20" << endl;
        cin >> high;
        if(high > 19 || high < 2){
            cout << "Shuffle rate is invalid" << endl;
            continue;
        }
        break;
    }
    while(state != 1){
        cout << "Enter 0 for game continue/start; 1 to terminate program" << endl;
        cin >> state;
        if(state != 0 && state != 1){
            cout << "Input is invalid" << endl;
            continue;
        }
    
        for(int x = 0; x < 52; x++){
            next[x] = "not";
            last[x] = deck[x];
        }
        for(int x = 0; x < 52; x++){
            for(int y = 0; y < high+1; y++)
                swap.push_back(y);
            for(int pop = 0; pop < high+1; pop++){
                //uniform_int_distribution<int> placex(0, swap.size()-1); 
                //old random number generator
                place = random(0, swap.size()-1);
                if(x+swap[place] < 52){
                    if(next[x+swap[place]] == "not") {
                        next[x+swap[place]] = deck[x];
                        break;
                    }
                }
                if(x-swap[place] >= 0){
                    if(next[x-swap[place]] == "not"){
                        next[x-swap[place]] = deck[x];
                        break;
                    }
                }
                swap.erase(swap.begin()+place);
                if(swap.empty()){
                    temp = high;
                    while(true){
                        temp++;
                        if(x+temp < 52){
                            if(next[x+temp] == "not") {
                                next[x+temp] = deck[x];
                                break;
                            }
                        }
                        if(x-temp >= 0){
                            if(next[x-temp] == "not"){
                                next[x-temp] = deck[x];
                                break;
                            }
                        }
                    }
                }
            }
            swap.clear();
        }
        for(int x = 0; x < 52; x++){
            deck[x] = next[x];
        }
        cout << "Shuffle number " << count << endl;
        count++;
        for(string x:next)
            cout << x << " ";
        cout << endl;
        calculate(deck, last);
    }
}

int main() {
    smoosh();
    return 0;
}
  
