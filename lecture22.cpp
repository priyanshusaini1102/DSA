#include <iostream>
#include <vector>

using namespace std;

int getLength(char str[]){
    int count = 0;
    for(int i=0; str[i] != '\0'; i++) count++;
    return count;
}

string reverse(string str ){
    int i = 0;
    int j = str.length()-1;

    while(i<j){
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

//To print an array
void printArr(int arr[], int size){
    cout<<"Array : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"."<<endl;
}

void reverseVec(vector<char>& str){
    int i=0;
    int j=str.size()-1;

    while(i<j){
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

//To print a vector.
void printVector(vector<char> v){
    cout<<"Vector : ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

//To print a vector with given size.
void printVector(vector<char> v, int size){
    cout<<"Vector : ";
    for(int i = 0; i < size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

//🙋‍♂️Ques-97 ✅ : To check palindrome
bool isPalindrome(string str){
    int i=0;
    int j=str.length()-1;

    while(i<j){
        if(str[i]!=str[j]){
            return 0;
        }
        i++;
        j--;
    }

    return 1;

}

char toLowerCase(char ch){
    if(ch>='A' && ch<='Z'){
        ch+=('a'-'A');
    }
    return ch;
}

bool isValid(char ch){
    // if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))return 1;
    bool res = ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) ? 1 : 0;
    return res;
}

bool arrayEqual(int arr1[],int arr2[], int size){
    for(int i=0; i<size; i++){
        if(arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

// 🙋‍♂️Ques-98 ✅ : To check palindrome with filteration : only alphanumeric characters are allowed. 
string filterAndToLowerCase(string s){
    string res;
    for(int i=0; i<s.length(); i++){
        if(isValid(s[i])){
            res.push_back(toLowerCase(s[i]));
        }
    }
    return res;
}

// 🙋‍♂️Ques-99 ✅ : To reverse words in a string.
string revWordsInStr(string str){
    string ans;
    string word;
    
    for(int i=0; i<str.length(); i++){
        if(str[i]==' ' || i==str.length()-1){
            if(i==str.length()-1){
                word.push_back(str[i]);
            }
            string revWord = reverse(word);
            ans.append(revWord+' ');
            word.clear();
        }else{
            word.push_back(str[i]);
        }
    }

    return ans;
}

//🙋‍♂️Ques-100 ✅ : To get the maximum occurence letter in string.
char maxOcc(string str){
    int arr[26] = {0};
    for(int i=0; i<str.length(); i++){
        int number = str[i] - 'a';
        arr[number]++;
    }
    printArr(arr, 26);

    char ans = -1;
    int max = 0;
    for(int i=0; i<26; i++) {
        if(arr[i] > arr[max]) {
            max=i;
        }
    }
    ans = max+'a';
    return ans;
}

//🙋‍♂️Ques-101(a) ✅ : Replace Spaces with @40
string replaceSpaces(string str) {
    string temp;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }else{
            temp.push_back(str[i]);
        }
    }
    return temp;
}

//🙋‍♂️Ques-101(b) ✅ : Replace spaces with string inplace.
string replaceSpacesInPlace(string str){

    string s2 = "@40";

    for(int i=0; i<str.size(); i++){
        if(str[i]==' '){
            str.replace(i,1,s2);
        }
    }
    return str;

}

//🙋‍♂️Ques-102 ✅ : To remove all occurence of substring. 
string removeAllInstances(string str,string part){

    while(str.length() > 0 && str.find(part) < str.length()){
        int found = str.find(part);
        str.erase(found,part.length());
    }

    return str;
}

//🙋‍♂️Ques-103 ✅ : Permutations in string.
bool permutationInString(string str1, string str2){

    //count 1 initialise
    int count1[26] = {0};
    for(int i = 0; i < str1.length(); i++){
        int index = str1[i] - 'a';
        count1[index]++;
    }

    //count2 ready - only for the first window
    int i=0;
    int count2[26] = {0};
    while(i<str1.length() && i<str2.length()){
        int index = str2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(arrayEqual(count2, count1,26)){
        return 1;
    }

    //count2 ready for next other windows for length str1.length
    while(i<str2.length()){
        int oldCharIndex = i-str1.length();
        int index = str2[oldCharIndex]-'a';
        count2[index]--;

        int newCharIndex = i;
        index = str2[newCharIndex]-'a';
        count2[index]++;

        i++;

        if(arrayEqual(count1,count2,26)) return 1;
    }

    return 0;

}

//🙋‍♂️Ques-104 ✅ : To remove same adjacent duplicates.
string removeAdjacentDuplicates(string s){

    int i=0;
    while(i<s.length()-1 && s.length()>0){
        
        if(s[i] == s[i+1]){
            
            cout<<"ye mila: "<<i<<s[i]<<endl;
            s.erase(i,2);
            cout<<"ye hua: "<<i<<s[i]<<endl;
            if(i!=0){
                i--;
            }
            continue;
        }
        i++;        
    }
    return s;

}

//🙋‍♂️Ques-105(a) ✅ : String Compression using string - abbb - ab3
string stringCompression(string s) {
    int ansIndex = 0;
    int i =0;
    while(i<s.length()) {
        int j=i+1;
        while(j<s.length() && s[i]==s[j]){
            j++;
        }
        s[ansIndex++] = s[i];

        int count = j-i;
        if(count>1){
            string countStr = to_string(count);
            for(int k=0; k<countStr.length(); k++){
                s[ansIndex++] = countStr[k];
            }
        }
        i=j;
    }

    cout<<ansIndex<<endl;

    return s;
}

//🙋‍♂️Ques-105(b) ✅ : String Compression using vector<char> - abbb - ab3
int stringCompressionVector(vector<char>& chars) {
    int ansIndex = 0;
    int i =0;
    while(i<chars.size()) {
        int j=i+1;
        while(j<chars.size() && chars[i]==chars[j]){
            j++;
        }
        chars[ansIndex++] = chars[i];

        int count = j-i;
        if(count>1){
            string countStr = to_string(count);
            for(int k=0; k<countStr.length(); k++){
                chars[ansIndex++] = countStr[k];
            }
        }
        i=j;
    }

    if(ansIndex==0){
        ansIndex++;
    }

    return ansIndex;
}

int main(){
    cout<<endl<<"~~~~~~~~START~~~~~~~~~~"<<endl<<endl;
    cout<<"Run successfully"<<endl;
    
    // char str[5];
    // cin>>str;
    // cout<<"String : "<<str<<endl;

    //✔️To get length of string.
    // cout<<"Length : "<<getLength(str)<<endl;

    //✔️To reverse the string.
    // reverse(str);
    // cout<<"Reverse : "<<str<<endl;

    //✔️To reverse a string using vector.
    // vector<char> strVec = {'p','r','o','t','o','c','o','l'};
    // reverseVec(strVec);
    // printVector(strVec);

    //🙋‍♂️Ques-97 ✅ : To check palindrome
    // bool res = isPalindrome(str);
    // if(res){
    //     cout<<"Yes,It is palindrome."<<endl;
    // }else{
    //     cout<<"No,It is not palindrome."<<endl;
    // }

    //🙋‍♂️Ques-98 ✅ : To check palindrome only for alphanumeric values.
    // string s;
    // cin>>s;
    // string ans = filterAndToLowerCase(s);
    // cout<<ans<<endl;
    // bool res = isPalindrome(ans);
    // if(res){
    //     cout<<"Yes,It is palindrome."<<endl;
    // }else{
    //     cout<<"No,It is not palindrome."<<endl;
    // }

    //🙋‍♂️Ques-99 ✅ : To reverse words in a string.
    // string s = "This is my name";
    // string revWordsInString = revWordsInStr(s);
    // cout<<s<<endl;
    // cout<<revWordsInString<<endl;

    //🙋‍♂️Ques-100 ✅ : To print max occurence of letter.
    // string s;
    // cin>>s;
    // char ans = maxOcc(s);
    // cout<<"maxOcc: "<<maxOcc(s)<<endl;

    //✔️ To get input a character array with spaces or a sentence we can say.
    // char str[256];
    // int length = 256;
    // cin.getline(str, length,'\n');   //delimiter - \n means enter
    // cout<<str<<endl;

    //✔️ To get the sentence as a string (included spaces).
    // string s;
    // getline(cin, s);
    // cout<<s<<endl;

    //🙋‍♂️Ques-101(a) ✅ : Replace spaces
    // string s;
    // getline(cin, s);
    // cout<<replaceSpaces(s);

    //🙋‍♂️Ques-101(b) ✅ : Replace spaces (in place)3
    // string s;
    // getline(cin, s);
    // cout<<replaceSpacesInPlace(s)<<endl;

    //🙋‍♂️Ques-102 ✅ : To remove all occurence of a substring.
    // string str,part;
    // cout<<"Enter string: ";
    // getline(cin, str);
    // cout<<"Enter the substring: ";
    // getline(cin, part);
    // cout<<removeAllInstances(str,part);

    //🙋‍♂️Ques-103 ✅ : Permutation in string
    // string s1;  //small string eg- s1='ab'
    // cin>>s1;
    // string s2;  //big string eg- s2='ebdbaooo'
    // cin>>s2;
    // bool res = permutationInString(s1,s2);
    // if(res){
    //     cout<<"Yes "<<s1<<" is exist in "<<s2<<"."<<endl;
    // }else{
    //     cout<<"No "<<s1<<" is not exist in "<<s2<<"."<<endl;
    // }

    //🙋‍♂️Ques-104 ✅ : Remove adjacent same characters
    // string s;
    // cout<<"Enter string: ";
    // cin>>s;
    // string ans = removeAdjacentDuplicates(s);
    // cout<<ans<<endl;

    //🙋‍♂️Ques-105(a) ✅ : String Compression using string
    // string str;
    // cin>>str;
    // string ans = stringCompression(str);
    // cout<<ans<<endl;
    
    //🙋‍♂️Ques-105(b) ✅ : String COmpression using vector<char> 
    // vector<char> str;
    // char ch = 'a';
    // while(ch!='0'){      //to get input vector str . here 0 as delimiter
    //     cin>>ch;
    //     if(ch!='0'){
    //     str.push_back(ch);
    //     }
    // }
    // int ans = stringCompressionVector(str);
    // cout<<"ans: "<<ans<<endl;
    // printVector(str,ans);    //print the vector

    cout<<endl<<"~~~~~~~~~END~~~~~~~~~~~"<<endl;
}