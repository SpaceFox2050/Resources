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
    cout << "Average spaces moved up or down: " << average << endl;
}

int random(int low, int high){
    random_device set;
    mt19937 xset(set());
    uniform_int_distribution<int> randx(low, high);
    int temp = randx(xset);
    return temp;
}

void overhand(){
    int temp = 0, state = 0, shufs = 0, high;
    string suits [4] = {"H", "C", "D", "S"};
    string nums [] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    vector<string> deck;
    vector<string> split;
    string e[52];
    string last[52];
    for(auto & suit : suits){
        for(auto & num : nums){
            deck.push_back(suit);
            deck[temp] += num;
            temp++;
        }
    }
    while(true){
        cout << "Enter shuffle rate (how many cards at max will fall into the receiving deck per shuffle)" << endl;
        cout << "Constraints 2 <= input <= 9" << endl;
        cin >> high;
        if(high > 9 || high < 2){
            cout << "Shuffle rate is too high" << endl;
            continue;
        }
        break;
    }
    while(state != 1){
        shufs++;
        cout << "Enter 0 for game continue/start; 1 to terminate program" << endl;
        cin >> state;
        if(state != 0 && state != 1){
            cout << "Input is invalid" << endl;
            continue;
        }
        for(int x = 0; x < 52; x++){
            split.push_back(deck[x]);
            last[x] = deck[x];
        }
        while(!split.empty()){
            temp = random(1, high);
            if(temp > split.size()){
                temp = split.size();
            }
            for(int x = temp-1; x > -1; x--){
                deck.insert(deck.begin(), split[x]);
                split.erase(split.begin()+x);
            }
        }
        cout << "Shuffle number: " << shufs << endl;
        for(int x = 0; x < 52; x++){
            cout << deck[x] << " ";
            e[x] = deck[x];
        }
        cout << endl;
        calculate(e, last);
    }

}

int main() {
    overhand();
    return 0;
}
