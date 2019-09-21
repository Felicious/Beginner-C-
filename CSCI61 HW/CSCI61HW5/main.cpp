#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

struct Word_Attribute{ //struct that keeps the word and its count together
   std::string word_itself;
   int word_count;
};

bool word_search(std::string word, std::vector<Word_Attribute> &a);
std::string ispunct(std::string word);
void insertion_sort(std::vector<Word_Attribute> &a);

int main(){
   size_t k = 0;
   std::cout << "Please enter a minimum word frequency:";
   std::cin >> k;

   //reading in the words and counting the repeated words
   std::ifstream book;
   book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input3.txt");
   //book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input1.txt");
   //book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input2.txt");
   //book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input3.txt");
   if (book.fail()){
       std::cout<< "Error with opening book"<<std::endl;
       exit(1);
   }
       std::string word;
       std::vector<Word_Attribute> a; //vector storing the different words
       //the type for a.size() is size_t;

       while(book >> word){
           if(!word_search(word,a)){ //the word doesn't exist in the array
               Word_Attribute new_word;
               new_word.word_itself = ispunct(word);
               new_word.word_count = 1;
               a.push_back(new_word);
           }//else: bool word_search increments the word count.
       }
   book.close();

   //printing
   if(k > a.size())
       k = a.size();
   insertion_sort(a);
   for (size_t i = 0; i < k; i++)
       std::cout<<a[i].word_itself<<": "<<a[i].word_count<<std::endl;

   return 0;
}
std::string ispunct(std::string word){
    std::string new_word;
    for(size_t i = 0; i < word.size(); ++i){
        char c(word[i]);
        if((('a'<= c)&&(c <= 'z'))||(('A' <= c)&&(c <= 'Z'))){
            new_word += c;
        }
    }
    return new_word;
}
bool word_search(std::string word, std::vector<Word_Attribute> &a){
   bool equals = false;
    for(size_t i = 0; i < a.size(); i++){
       if(word == a[i].word_itself){ //finds if theres the same word in there
           a[i].word_count++;
           return true;
       }
    }
    return equals;
}
void insertion_sort(std::vector<Word_Attribute> &a){
    for (size_t i = a.size()-1; i > 0; --i)
        for (size_t j = i-1; j >= 1 && a[j].word_count > a[j-1].word_count; ++j)
            std::swap(a[j], a[j-1]);
}




