#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << "ERROR in " << word1 << " and " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    // case they are exactly equal to
    if (str1 == str2)
        return true; 
    // check if they are either same size or only d difference
    int str1_sz = str1.size();
    int str2_sz = str2.size();

    if (abs(str1_sz - str2_sz) > d)
        return false;

    int diff_cnt = 0;

    int i = 0;
    int j = 0;

    while (i < str1_sz && j < str2_sz){
        if (str1[i] != str2[j]){
            ++diff_cnt;
            if (diff_cnt > d)
                return false;
            if (str1_sz > str2_sz)
                ++i;
            else if (str1_sz < str2_sz)
                ++j;
            else{
                ++j;
                ++i;
            }
        }
        else{
            ++j;
            ++i;
        }
    }
    if (i < str1_sz || j < str2_sz)
        ++diff_cnt;

    return diff_cnt == d;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    if (begin_word == end_word){
        error(begin_word, end_word, "Start and end words must be different.");
        return {};
    }
    queue<vector<string>> ladder_queue;
    set<string> visited;
    ladder_queue.push({begin_word});
    visited.insert(begin_word);
    
    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        string last_word = ladder.back();
        ladder_queue.pop();

        for (const string& word : word_list ) {
            if (is_adjacent(last_word, word) && 
                visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
            }
        }
       
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream file(file_name);
    string word;
    while (file >> word)
        word_list.insert(word);
    file.close();
}

void print_word_ladder(const vector<string>& ladder){
    if (ladder.empty()){
        cout << "No word ladder found." << endl;
    }
    cout << "Word ladder found: ";
    for (int i = 0; i < ladder.size(); ++i){
        cout << ladder[i] << " ";
    }
    cout << endl;
}

void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, "../src/words.txt");

    string begin_word, end_word;
    cout << "Enter start word: ";
    cin >> begin_word;
    cout << "Enter end word: ";
    cin >> end_word;
    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);
    if (ladder.empty()){
        cout << "No valid word ladder found." << endl; 
        return;
    }
    print_word_ladder(ladder);

    int ladder_sz = ladder.size();

    for (int i = 1; i < ladder_sz; ++i){
        if (word_list.find(ladder[i]) == word_list.end()){
            error("", ladder[i], "Not in the dictionary");
            return;
        }
    }
    for (int i = 1; i < ladder_sz; ++i){
        if (!is_adjacent(ladder[i-1], ladder[i])){
            error(ladder[i-1], ladder[i], "Not a valid path found");
            return; 
        }
    }

    cout << "Word ladder verfied" << endl;

}