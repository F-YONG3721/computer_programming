#include<iostream>
#include <string>

using namespace std;

int main(){
    string s; // 記錄 輸入的字串
    string f; // 記錄 s 前後加空格
    long long int num, sum; // num 記錄 讀取到的數字; sum 運算後的結果
    string action = "Nnoe"; // 記錄將要運算的符號ex: plus, minus
    

while(cin >> s){
    f = ' ' + s + ' ';
    // cout << f << endl;

    // 初始化
    num = 0;
    sum = 0;

    // analyze
    for(char c: f){

        if(isdigit(c)){
            num = num * 10 + (int)(c - '0');
        }      
        else if(isalpha(c)){ // 遇到英文字母 選擇要進行的運算
            switch(c){
                case 'k':
                    num *= 1000;
                    break;
                case 'K':
                    num *= 1024;
                    break;
                case 'm':
                    num *= 1000*1000;
                    break;
                case 'M':
                    num *= 1024*1024;
                    break;
                case 'g':
                    num *= 1000*1000*1000;
                    break;
                case 'G':
                    num *= 1024*1024*1024;
                    break;
            }
        }
        else{
            // 如果不是英文字母, 檢查是否需要運算
            if(action == "plus"){
                sum += num;
                num = 0;
            }
            else if(action == "minus"){
                sum -= num;		
                num = 0;
            }
        }

        // 當 c 是以下運算符號，則記錄下一次要做的運算
        switch(c){
            case '+':
                action = "plus";
                break;
            case '-':
                action = "minus";
                break;
            case ' ':
                action = "plus";
                break;
        }
    }

    cout << sum << endl; // 印出答案
}

return 0;
}


/*
#include <iostream>
#include <string>

using namespace std;

int main(){
string s, action = "none";
int num = 0, ans = 0;

while(cin >> s){
s = ' ' + s + ' ';

for(char c : s){
if(isdigit(c)){
num = num*10 + (int)(c - '0');
}
else if(isalpha(c)){
switch(c){
case 'k':
num *= 1000;
break;

}

}
else{
if(action == "plus"){
ans += num;
num = 0;
}
else if(action == "minus"){
ans -= num;
num = 0;
}

}

}

}
}
*/