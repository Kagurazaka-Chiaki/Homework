
int get_id(int n) {
    int sum = 0;
    while (n) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit) {
    int max = 0;
    int hash[46];
    memset(hash, 0, sizeof(hash));
    for (int i = lowLimit; i <= highLimit; i++) {
        ++hash[get_id(i)];
    }
    for (int i = 0; i < 46; i++) {
        if (hash[i] > max) {
            max = hash[i];
        }
    }
    return max;
}