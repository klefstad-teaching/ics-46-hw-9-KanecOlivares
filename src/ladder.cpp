#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << "ERROR in " << word1 << " and " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    // case they are exactly equal to
    if (str1 == str2)
        return true; 
    // check if they are either same size or only d difference
    str1_sz = str1.size();
    str2_sz = str2.size();
    if (abs(str1_sz - str2_sz) > d)
        return false;
    int diff_cnt = 0;
    int i = 0;
    int j = 0;
    while (i < len1 && j < len2){
        if (str1[i] != str2[j]){
            ++diff_cnt;
            if (diff_cnt > d)
                return false;
            if (len1 > len2)
                ++i;
            else if (len1 < len2)
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
    if (i < len1 || j < len2)
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){

}

void load_words(set<string> & word_list, const string& file_name){

}

void print_word_ladder(const vector<string>& ladder){

}

void verify_word_ladder(){

}