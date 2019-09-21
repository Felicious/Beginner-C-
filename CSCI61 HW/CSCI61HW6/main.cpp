#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

void insertion_sort(std::vector<std::pair<std::string,int>> &a);

int main(){
   size_t k = 0;
   std::cout << "Please enter a minimum word frequency:";
   std::cin >> k;

   //reading in the words and counting the repeated words
   std::ifstream book;
   //book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input0.txt");
   //book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input1.txt");
   //book.open("/Users/freak/OneDrive/Documents/CSCI61 HW/CSCI61HW5/input2.txt");
   book.open("input3.txt");
   if (book.fail()){
       std::cout<< "Error with opening book"<<std::endl;
       exit(1);
   }
       std::string word;
       std::unordered_map<std::string,int> a; //map storing the different words

       while(book >> word){
            std::string w;
            //if word has a punct in it, function will remove it
            //parameters are: begin,end,where to save it to (empty string w), is punct is a function that shows if string has punct
            std::remove_copy_if(word.begin(),word.end(),std::back_inserter(w), ::ispunct);
            ++a[w];
       }
   book.close();

   //printing
   if(k > a.size())
       k = a.size();
   std::vector<std::pair<std::string,int>> v; //copy map into vector
       for(auto e: a){
           std::pair<std::string, int> p;
           p.first = e.first;
           p.second = e.second;
           v.push_back(p);
       }
   insertion_sort(v);
   for(size_t i = 0; i < k; ++i)
       std::cout << v[i].first << " : " << v[i].second << std::endl;

   return 0;
}
//sort map that's been copied into vector
void insertion_sort(std::vector<std::pair<std::string,int>> &a){
    for (size_t i = a.size()-1; i > 0; --i)
        //swap if the second part of the pair is larger than left neighbor
        for (size_t j = i-1; j >= 1 && a[j].second > a[j-1].second; ++j)
            std::swap(a[j], a[j-1]);
}
