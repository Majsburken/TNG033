/************************************************************************
 * TNG03: set 1                                                         *
 * Exercise 3: merge two sorted sequences                               *
 * The merge algorithm (function merge_seq) used here can be useful for *
 * implementing Set::set_union, Lab 1                                   *
 * **********************************************************************/

// Test data:
// seq1: 1 3 5 7 9 stop
// seq2: 2 5 6 7 9 12 15 20 stop

#include <iostream>
#include <string>
#include <vector>

/****************************************
 * Function declarations                *
 ****************************************/

// Re-set the stream in to good state
void clean_up_stream(std::istream& in);

// Read a sequence of integers and store them in a vector
// Return a vector with the sequence read
std::vector<int> read_seq();

// Merge S1 with S2
// Return a vector with the merged sequence, without repetitions
// Vectors S1 and S2 are sorted
std::vector<int> merge_seq(const std::vector<int>& S1, const std::vector<int>& S2);

// Display the values stored in vector V
void display_seq(const std::vector<int>& S);

/**************************
 * MAIN                   *
 **************************/

int main() {
    std::cout << "Enter sequence 1: ";
    std::vector<int> seq1 = read_seq();

    clean_up_stream(std::cin);

    std::cout << "\nEnter sequence 2: ";
    std::vector<int> seq2 = read_seq();

    std::vector<int> seq3 = merge_seq(seq1, seq2);

    std::cout << "\nMerged sequence: ";
    display_seq(seq3);
}

/*************************************
 * Function definitions               *
 **************************************/

// Re-set the stream in to good state
void clean_up_stream(std::istream& in) {
    in.clear();  // Reset the stream error flags, i.e. put stream in back to good state

    // Extract the non-valid input from the stream’s buffer
    auto trash = std::string{};
    std::getline(in, trash);
}

// Read a sequence of integers and store them in a vector
// Return a vector with the sequence read
std::vector<int> read_seq() {
    std::vector<int> S;

    int value;
    while (std::cin >> value) {
        S.push_back(value);
    }
    return S;
}

// Merge a list of unique values store in S1 with another list of unique values store in S2
// Return a vector with the merged sequence, without repetitions
// Vectors S1 and S2 are sorted
std::vector<int> merge_seq(const std::vector<int>& S1, const std::vector<int>& S2) {
    std::vector<int> S3;  // to store the merged sequence

    // ADD CODE






    int count1 = 0;
    int count2 = 0;
    // Merge S1 with S2
    while (count1 < std::ssize(S1) && count2 < std::ssize(S2)) {
        if (S1[count1] < S2[count2]) {
            S3.push_back(S1[count1]);
            std::cout << "\n S1 på plats[" << count1 << "]" << S1[count1];
            ++count1;
        }
        else if (S2[count2] < S1[count1]) {
            S3.push_back(S2[count2]);
            ++count2;
        }
        else {  // S1[count1] == S2[count2]
            S3.push_back(S1[count1]);
            ++count1;
            ++count2;
        }
    }

    // copy any remaining values from S1 to S3
    while (count1 < std::ssize(S1)) {
        S3.push_back(S1[count1]);
        ++count1;
    }

    // copy any remaining values from S2 to S3
    while (count2 < std::ssize(S2)) {
        S3.push_back(S2[count2]);
        ++count2;
    }

   

    

    return S3;
}

// Display the values stored in vector V
void display_seq(const std::vector<int>& S) {
    for (int v : S) {
        std::cout << v << " ";
    }
    std::cout << '\n';
}
