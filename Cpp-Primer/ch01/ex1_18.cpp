// Exercise 1.18
//
// Compile and run the program from this section giving it only equal values as input. Run it 
// again giving it values in which no number is repeated.
//

#include <iostream>

int main() {
    // currVal is the number we're counting; we'll read new values into val
    int currVal = 0, val = 0;
    // read first number and ensure that we have data to process
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) { // read the remaining numbers
            if (val == currVal) { // if the value are the same
                cnt++;            // add 1 to cnt
            }
            else { // otherwise, print tbe count for the previous value
                std::cout << currVal << " occurs " << cnt 
                << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        } // while loop ends here
        // remember to print the count for the last value in the file
        std::cout << currVal << " occurs " 
        << cnt << " times" << std::endl;
    }
    return 0;
}