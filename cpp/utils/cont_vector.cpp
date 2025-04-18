
void copy_vector() {
    std::vector<int> originalVector = {1, 2, 3, 4, 5};
    std::cout << "copy constructor " << std::endl;
    //copy constructor
    std::vector<int> copy1 = originalVector;    
    print_vector(copy1);
    
    //using assignment operator
    std::cout << "assignment opeator " << std::endl;
    std::vector<int> copy2;
    copy2 = originalVector;
    print_vector(copy2);

    //std::copy
    std::cout << "std copy " << std::endl;
    std::vector<int> copy3(originalVector.size());
    std::copy(originalVector.begin(), originalVector.end(), copy3.begin());
    print_vector(copy3);

    std::cout << "range constructor " << std::endl;
    std::vector<int> copy4(originalVector.begin(), originalVector.end());
    print_vector(copy4);
}





int main() {
    //vector_demo();

    //erase_from_iterator();

    copy_vector();
}