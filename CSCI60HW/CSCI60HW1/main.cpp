#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct Word_Attribute{ //struct that keeps the word and its count together
    std::string word_itself;
    int word_count;
};

bool same_word(std::string word, Word_Attribute distinct_words[], int num_of_diff_words);
void word_search(std::string word, Word_Attribute distinct_words[], int num_of_diff_words);

int main(){
    int num = 0;
    std::cout << "Please enter a minimum word frequency:" << std::endl;
    std::cin >> num;

    //reading in the words and counting the repeated words
    std::ifstream book;
    book.open("/Users/freak/OneDrive/Documents/CSCI60HW1/input.txt");
    if (book.fail()){
        std::cout<< "Error with opening book"<<std::endl;
    exit(1);
    }
        std::string word;
        Word_Attribute distinct_words[50000]; //an array storing the different words
        int num_of_diff_words = 0; //current number of different words in distinct words array

        while(book >> word){
            if(same_word(word,distinct_words,num_of_diff_words)){ //the word exists in the array
                word_search(word,distinct_words,num_of_diff_words); //increments the word count
            }else{//the word does not exist in the array
                Word_Attribute new_word;
                new_word.word_itself = word;
                new_word.word_count = 1;
                distinct_words[num_of_diff_words] = new_word;
                num_of_diff_words++;
            }
        }
    book.close();

    //printing
    for (int i = 0; i < num_of_diff_words; i++){
        if(num < distinct_words[i].word_count){
            std::cout<<distinct_words[i].word_itself<<": "<<distinct_words[i].word_count<<std::endl;
        }
    }

    return 0;
}

bool same_word(std::string word, Word_Attribute distinct_words[], int num_of_diff_words){
    bool equals = false;
    for(int i = 0; i < num_of_diff_words; i++){
        if (word == distinct_words[i].word_itself){
            equals = true;
            break;
        }
    }
    return equals;
}

void word_search(std::string word, Word_Attribute distinct_words[], int num_of_diff_words){
    for(int i = 0; i < num_of_diff_words; i++){
        if(word == distinct_words[i].word_itself){
            distinct_words[i].word_count++;
            break;
        }
    }
}
