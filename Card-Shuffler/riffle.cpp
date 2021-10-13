#include <iosteam>
#include <random>
using namespace std;

void calculate(string deck [52]){
    int nums = 0, suits = 0, repeat = 0;
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
    cout << "Consecutive numbers: " << nums << endl;
    cout << "Consecutive suits: " << suits << endl;
}

int random(int low, int high){
    random_device set;
    mt19937 xset(set());
    uniform_int_distribution<int> randx(low, high);
    int temp = randx(xset);
    return temp;
}

void riffle(){
    int state = 0, temp = 0, high, ttop, tbot, token, moves, shufs = 0;
    string suits [4] = {"H", "C", "D", "S"};
    string nums [] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string deck [52];
    string top [26];
    string bottom [26];
    for(auto & suit : suits){
        for(auto & num : nums){
            deck[temp]+=suit;
            deck[temp]+=num;
            temp++;
        }
    }
    while(state != 1){
        shufs++;
        for(int x = 0; x < 26; x++){
            top[x] = deck[x];
            bottom[x] = deck[x+26];
        }
        cout << "Enter 0 for game continue/start; 1 to terminate program" << endl;
        cin >> state;
        if(state != 0 && state != 1){
            cout << "Input is invalid" << endl;
            continue;
        }
        cout << "Enter shuffle rate (how many cards at max will fall into the receiving pile)" << endl;
        cout << "Constraints 2 <= input <= 9" << endl;
        cin >> high;
        if(high > 9 || high < 2){
            cout << "Shuffle rate is too high" << endl;
            continue;
        }
        temp = 0, ttop = 0, tbot = 0, token = 0;
        while(ttop < 26 || tbot < 26){
            moves = random(1, high);
            if(token%2 == 0){
                if(ttop + moves >= 26) {
                    moves = 26 - ttop;
                }
            }else{
                if(tbot + moves >= 26){
                    moves = 26-tbot;
                }
            }
            for(int x = 0; x < moves; x++){
                if(token%2 == 0 && ttop < 26){
                    deck[temp] = top[ttop];
                    ttop++;
                }else if(tbot < 26){
                    deck[temp] = bottom[tbot];
                    tbot++;
                }
                temp++;
            }
            token++;
        }
        cout << "Shuffle number " << shufs << endl;
        for(string x:deck)
            cout << x << " ";
        cout << endl;
        calculate(deck);
    }
}

int main() {
    riffle();
    return 0;
}
