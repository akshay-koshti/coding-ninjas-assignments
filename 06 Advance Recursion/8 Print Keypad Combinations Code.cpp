1
#include <iostream>
2
#include <string>
3
using namespace std;
4
5
void printKeypadHelper(int num, string output, string options[10]){
6
    if(num == 0){
7
        cout << output << endl;
8
        return;
9
    }
10
    int digit = num % 10;
11
    int i = 0;
12
    while(i < options[digit].length()){
13
        printKeypadHelper(num / 10, options[digit][i] + output, options);
14
        i++;
15
    }
16
    return;
17
}
18
19
void printKeypad(int num){
20
    string options[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
21
    printKeypadHelper(num, "", options);
22
    return;
23
}
24