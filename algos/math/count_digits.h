

int count_digits(int num) {
    int digits = 0;
    while(num != 0) {
        digits++;
        num=num/10;
    };
    return digits;
}