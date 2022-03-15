


int numWaterBottles(int numBottles, int numExchange){
    int ans = 0;
    int full = numBottles;
    int empty = 0;
    int total = 0;
    while (full + empty >= numExchange) { //
        ans = ans + full;                 //
        total = full + empty;             //
        full = total / numExchange;       //
        empty = total % numExchange;      //
    }
    return ans + full;
}