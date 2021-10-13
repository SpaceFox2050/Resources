#include <iostream>
#include <vector>
#include <random>
using namespace std;

void calculate(string deck [52]){
    int nums = 0, suits = 0;
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
    cout << "Consecutive numbers: " << nums << endl;
    cout << "Consecutive suits: " << suits << endl;
}

//new random number generator func
int random(int low, int high){
    random_device set;
    mt19937 xset(set());
    uniform_int_distribution<int> randx(low, high);
    int temp = randx(xset);
    return temp;
}

void messpileshuf(){
    
    //random_device set;
    //mt19937 xset (set());
    int state = 0, temp = 0, high, place, count = 1;
    string suits [4] = {"H", "C", "D", "S"};
    string nums [] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};
    string deck [52];
    string next[52];
    vector<int> swap;
    for(auto & suit : suits){
        for(auto & num : nums){
            deck[temp]+=suit;
            deck[temp]+=num;
            temp++;
        }
    }
    while(state != 1){
        cout << "Enter 0 for game continue/start; 1 to terminate program" << endl;
        cin >> state;
        if(state != 0 && state != 1){
            cout << "Input is invalid" << endl;
            continue;
        }
        cout << "Enter shuffle rate (max places cards will move up/down in the deck)" << endl;
        cout << "Constraints: 0 <= input < 20" << endl;
        cin >> high;
        if(high > 19 || high < 0){
            cout << "Shuffle rate is too high" << endl;
            continue;
        }
        for(string& x:next)
            x = "not";
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
        calculate(deck);
    }
}

int main() {
    messpileshuf();
    return 0;
}
  
