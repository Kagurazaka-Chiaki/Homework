int climbStairs(int n){

    int a = 1;
    int b = 1;
    int temp = 0;
    if (n < 2) {
        return 1;
    } else {
        for (int i = 0; i < n - 1; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return temp;
    }

    /*
    if (n < 2) {
        return 1;
    } else {
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    */
}