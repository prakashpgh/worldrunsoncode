//find reverse and check if reverse == number

bool is_palindrome_number(int num) {
    int actual_num = num;
    std::cout << "num " << num;
    int reverse_number = 0;
    while(num != 0) {
        reverse_number = reverse_number*10 + (num % 10);
        num = num/10;
    }
    std::cout << "reverse_number: " << reverse_number << " num: " << num;
    if(reverse_number == actual_num) {
        std::cout << "equal " << reverse_number << " " << num;
        return true;
    }
    return false;
}