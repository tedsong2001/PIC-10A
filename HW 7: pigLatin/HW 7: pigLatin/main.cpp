#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


// Function declarations

/**
 Checks if a character is a letter from the alphabet
 @param alpha the character
 @return true if the character is a letter, false if the character is not
 */
bool is_alpha(char alpha);


/**
 Helper function: Checks if a character matches one of the elements from a given array
 @param c the character
 @param my_array array that contains certain elements
 @param my_size the size of the array
 @return true if the character is present in the array, false if the character is not
 */
bool is_in_array(char c, const char my_array[], size_t my_size);


/**
 Checks if a character is a punctuation, by using the helper function is_in_array
 @param punc the character
 @return true if the character is a punctuation, false if the character is not
 */
bool is_punc(char punc);


/**
 Changes upper case letters of a string into lower case
 @param str the string
 */
void make_lower(string& str);


/**
 Places words in a large string into a vector
 @param large_str the large string
 @return a vector that contains the words in the large string
 */
vector<string> words(const string& large_str);


/**
 Helper function: Checks if a character is a vowel
 @param letter the character
 @return true if a character is a vowel, false if a character is not
 */
bool is_vowel(char letter);


/**
 Translates word to Pig Latin
 @param original word in English
 @return word in Pig Latin
 */
string word_to_PL(const string& original);


/**
 Translates each word in a vector into Pig Latin and then places each word into a new vector
 @param original_vector vector with words in English
 @return new vector with words in Pig Latin
 */
vector<string> vec_to_PL(const vector<string>& original_vector);


/**
 Builds a paragraph out of the words in a vector
 @param word_vector a vector with words
 @return the paragraph (in a string)
 */
string build_paragraph(const vector<string>& word_vector);


/**
 Builds a paragraph out of the words in a vector
 @param word_vector a vector with words
 @return the paragraph (in a string)
 */
string build_paragraph(const vector<string>& word_vector);


/**
 Translates user's input into Pig Latin
 @param input user's input
 @return user's input translated into Pig Latin
 */
string translate(string& input);




int main() {
    
    
    ifstream in_file; // creates new stream
    in_file.open("Gettysburg.txt"); // opens Gettysburg.txt file
    
    if (in_file.fail()) { // checks if in_file failed to open
        cout << "error" << endl;
        return 1;
    }
    
    string line; // declare new string
    getline(in_file, line); // assigns line in in_file to string
    
    cout << translate(line); // translates the line into pig latin and outputs it onto console (just for checking purposes)
    
    ofstream out_file; // creates new stream
    out_file.open("ettysburggay.txt"); // creates new file
    
    out_file << translate(line); // translates the line into pig latin and outputs it onto the ettysburggay.txt file
        
    return 0;
}



// Function Definitions

// 1
bool is_alpha(char alpha) {
    return ((alpha >= 65 && alpha <= 90) || (alpha >= 97 && alpha <= 122));
    // returns true if character is A-Z or a-z
}


// HELPER FUNCTION
bool is_in_array(char c, const char my_array[], size_t my_size) {
    for (size_t i = 0; i < my_size; ++i) { // goes through each element of an array
        if (my_array[i] == c) { // if the character matches one of the elements in the array
            return true;
        }
    }
    return false; // if the character matches none of the elements in the array
}


// 2
bool is_punc(char punc) {
    char punctuations[] = { '(', ')', '.', ',', '!', ';', ':', '?', '\"', '\'', '-' }; // list of punctuations
    size_t size = sizeof(punctuations) / sizeof(char); // size of the array punctuations[]
    return is_in_array(punc, punctuations, size); // uses helper function is_in_array to find whether a character is a punctuation
}


// 3
void make_lower(string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] >= 65 && str[i] <= 90) { // if a character is an upper case letter
            char temp = str[i] + 32; // assigns lower case version of the letter into a temporary variable
            str[i] = temp; // changes upper case letter to lower case
        }
    }
}


// 4
vector<string> words(const string& large_str) {
    // used for helper function is_in_array
    char end_of_word[] = { ' ', '\n', '\t' }; // list of "characters" that mark the end of a word
    size_t size = sizeof(end_of_word) / sizeof(char); // size of the array end_of_word[]
    
    // putting words from large_str into a vector
    vector<string> list_of_words;
    string temp = ""; // temporary holder of a string
    for (size_t i = 0; i < large_str.length(); ++i) { // goes through each character in the string
        if (!is_in_array(large_str[i], end_of_word, size)) { // if a character does not mark the end of a word
            temp += large_str[i]; // adds the character into a temporary string
        }
        else { // if a character marks the end of a word
            list_of_words.push_back(temp); // places the content of the temporary string into the vector
            temp = ""; // resets the temporary string
        }
    }
    
    // places the existing content of the temporary string into the vector, because the previous if statements do not accomodate the very last word
    list_of_words.push_back(temp);
    
    return list_of_words;
}


// HELPER FUNCTION
bool is_vowel(char letter) {
    char vowels[] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u' }; // list of vowels
    size_t size = sizeof(vowels) / sizeof(char); // size of array vowels[]
    return is_in_array(letter, vowels, size);
}


// 5
string word_to_PL(const string& original) {
    char first_letter = ' ';
    size_t start_punc = 0;
    string punc_at_start = "";
    for (size_t i = 0; i < original.length(); ++i) { // goes through characters of string to find first letter
        if (is_alpha(original[i])) { // if the character is a letter
            first_letter = original[i]; // character is assigned to first_letter
            break; // breaks after the first letter found in the string
        }
        else if (is_punc(original[i])) { // in case someone starts the string with a punctuation for some bizarre reason
            start_punc++; // counts the number of punctuation occurring at the start of the string
            punc_at_start += original[i]; // adds the punctuation to string punc_at_start
        }
    }
    
    char last_letter = ' ';
    size_t end_punc = 0;
    for (size_t i = original.length() - 1; i >= 0; --i) { // goes through characters, starting at the end of the string
        if (is_alpha(original[i])) { // if the character is a letter
            last_letter = original[i]; // character is assigned to last_letter
            break; // breaks after the first letter found in the string
        }
        else if (is_punc(original[i])) { // if there is punctuation(s) at the end
            end_punc++; // counts the number of punctuation occurring at the end of the string
        }
    }
    size_t position_of_last_letter = original.length() - 1 - end_punc; // position of the last letter
    
    string pig_latin = ""; // holds the translated word
    if (!is_vowel(first_letter)) { // if first letter is a consonant
        // for loop goes through characters in string original
        for (size_t i = 1 + start_punc; i < original.length(); ++i) { // starts at start_punc + 1 in case there is punctuation at beginning
            // the 1 accounts for the fact that pig latin starts on the second letter if the first letter is a consonant
            if (start_punc > 0) { // if there is punctuation at beginning
                pig_latin += punc_at_start; // adds the punctuation[s] into pig_latin
                start_punc = 0; // sets start_punc into 0 to ensure this if statement is not repeated
            }
            pig_latin += original[i]; // adds the letter into pig_latin
            if (i == position_of_last_letter) { // if i reaches the position of the last letter
                pig_latin = pig_latin + first_letter + "ay"; // adds the first letter + "ay" after last letter
            }
        }
    }
    else { // if first letter is a vowel
        // for loop goes through characters in string original
        for (size_t i = 0 + start_punc; i < original.length(); ++i) { // starts at start_punc + 0 in case there is punctuation
            // pig latin starts on first letter if first letter is a vowel, hence the 0
            if (start_punc > 0) { // if there is punctuation at the beginning
                pig_latin += punc_at_start; // adds the punctuation[s] into pig_latin
                start_punc = 0; // sets start_punc into 0 to ensure this if statement is not repeated
            }
            pig_latin += original[i]; // adds the letter into pig_latin
            if (i == position_of_last_letter) { // if i reaches the position of the last letter
                if (is_vowel(last_letter)) { // if last letter is a vowel
                    pig_latin += "yay"; // adds "yay" after the last letter
                }
                else { // if last letter is a consonant
                    pig_latin += "ay";
                }
            }
        }
    }
    
    return pig_latin;
}


// 6
vector<string> vec_to_PL(const vector<string>& original_vector) {
    vector<string> pig_latin_vector;
    for (size_t i = 0; i < original_vector.size(); ++i) { // goes through each element in the vector
        string translated = word_to_PL(original_vector[i]); // translates the word to pig latin
        pig_latin_vector.push_back(translated); // places the translated word into a new vector
    }
    return pig_latin_vector;
}


// 7
string build_paragraph(const vector<string>& word_vector) {
    string paragraph = "";
    for (size_t i = 0; i < word_vector.size(); ++i) { // goes through each element in the vector
        if (i != word_vector.size() - 1) { // if i is not the last element of the vector
            paragraph = paragraph + word_vector[i] + " "; // adds the word followed by a space
        }
        else { // if i reaches the last element of the vector
            paragraph += word_vector[i]; // just adds the word to paragraph
        }
    }
    return paragraph;
}


// my own function that combines the other functions
string translate(string& input) {
    make_lower(input);
    return build_paragraph(vec_to_PL(words(input)));
}