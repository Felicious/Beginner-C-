#include <iostream>
#include <sstream>
#include <stack>
#include <string>

std::string postfix_to_prefix(const std::string & postfix);

using namespace std;

int main(){
    cout << postfix_to_prefix(string("3 4 +")) << endl;
    cout << postfix_to_prefix(string("10 5 / 4 +")) << endl;
    cout << postfix_to_prefix(string("10 5 / 2 3 * +")) << endl;
    cout << postfix_to_prefix(string("3 10 5 / + 2 3 * -")) << endl;
    cout << postfix_to_prefix(string("2 3 * 10 2 / + 7 * 6 3 + 6 3 * * 2 + -")) << endl;

    return 0;
}
string postfix_to_prefix(const string & postfix){
    //only changes strings into tokens of one character /:
    istringstream is(postfix); //takes a string and converts it to a stream of strings sep by " "
    string token;
    std::stack<string> stack;
    string ans; //will serve as a holder for an expression as well as the answer
    string lhs, rhs; //left and right operands

    while(is >> token){
        switch(token[0]){
        case '+':
            if(token.size() > 1){ //treat as a number
                ans = " ";
                ans += token;
                stack.push(ans);
            }else{
                ans = " "; //clears whatever was inside
                rhs = stack.top();
                stack.pop();
                lhs = stack.top();
                stack.pop();
                ans += "+ "+lhs+" "+rhs;
                stack.push(ans);
            }
            break;
        case '-':
            if(token.size() > 1){ //treat as a number
                ans = " ";
                ans += token;
                stack.push(ans);
            }else{
                ans = " ";
                rhs = stack.top();
                stack.pop();
                lhs = stack.top();
                stack.pop();
                ans += "- "+lhs+" "+rhs;
                stack.push(ans);
            }
            break;
        case '*':
            ans = " ";
            rhs = stack.top();
            stack.pop();
            lhs = stack.top();
            stack.pop();
            ans += "* "+lhs+" "+rhs;
            stack.push(ans);
            break;
        case '/':
            ans = " ";
            rhs = stack.top();
            stack.pop();
            lhs = stack.top();
            stack.pop();
            ans += "/ "+lhs+" "+rhs;
            stack.push(ans);
            break;
        default:
            ans = " ";
            ans += token;
            stack.push(ans);
        }
    }
    ans = " ";
    ans = stack.top();
return ans;
}
