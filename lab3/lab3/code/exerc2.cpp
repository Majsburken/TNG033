/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm> //transform



// A function to test the output of the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

/***************************
 * Main function           *
 **************************/

     //auto = std::pair<std::string, int>
bool compare(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) {
    if (lhs.second == rhs.second) {
        return lhs.first < rhs.first;
    }
    return lhs.second > rhs.second;
}







int main() {  
    std::cout << "Text file: ";
	std::string file_name;
	std::cin >> file_name;

	std::ifstream in_File{"../code/" + file_name};  // modify path, if needed

	if (!in_File) {
		std::cout << "Could not open input file!!\n";
		return 0;
	}

    //string first, sorted alphabetacally
    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

    //ADD CODE to build table
    std::string word;
    //in_File >> word, skips leading white-spaces, reads char into words until ws, ws after word not read
    //include algorithm for transform
    while (in_File >> word) {
        //              start       end         lagra transformed   vad för transform
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        //   vad görs               start       end        om det finns c = true
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            //          flyttar punctuations längst back och returnar pointer till första punctuation som vi vill ta bort.
            //                                                                                                                                  end
            return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == '/' || c == '"' || c == ')' || c == '(' || c == ';'; }), word.end());
    
        //emplace, som pushback för map
        //om word inte finns -> lägg till i table med counter (för word) = 0
        //Om word finns -> gå vidare, ersätter alltå inte redan existerande word i table, har kvar första isntansen
        table.emplace(word, 0);

        //Plussar totala ord counter
        counter++;

        //Om word redan finns i table -> pluss counter (för word)
        if (table.contains(word)) {
            table[word]++;
        }

    }

    std::vector<std::pair<std::string, int>> freq;

    //ADD CODE to build vector freq


    //copies elements from table begin to end, inserts to back of container freq
    std::copy(table.begin(), table.end(), std::back_inserter(freq));

    //auto = std::pair<std::string, int>
    //sorts from freq begin to end, comparison cirteria lhs.second > rhs.second

    //Fråga om d stämmer
    //Gråga Samuel varför bara compare
    std::sort(freq.begin(), freq.end(), compare);
  

    // for (auto e : freq) {
    //     std::cout << e.first << " " << e.second << std::endl;
    // }
    /* ************** Testing **************** */

    //test(table, freq, name, counter);
}


/*******************************
 * Test implementation         *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"../code/out_" + file_name}; //modify path, if needed

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }

    /*
     * uppgift1_kort: 69 words
     * uppgift1.txt: 1063 words
     */

    assert(total == n);    // test if total number of words is correct
    assert(t == result1);  // test if map/table contents are correct

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    assert(v == result2);  // test if vector contents are correct

    std::cout << "\nPassed all tests successfully!!\n";
}
