#include <iostream>
#include <string>
using namespace std;


bool is_palindrome(string t){
    if(t.size()<=1){
        return true;
    }

    if(t[0]!=t[t.size()-1]){
        return false;
    }

    return is_palindrome(t.substr(1,t.size()-2));
}


bool pal(string st){
    
    if(st.size()==1||st.size()==0){
        return true;
    }
    if(st[0]!=st[st.size()-1]){
        if(is_palindrome(st.substr(1, st.size()-1))||is_palindrome(st.substr(0, st.size()-1))){
            return true;
        }
        else{
            return false;
        }
    }
    if(st[0]==st[st.size()-1]){
        
        return pal(st.substr(1, st.size()-2));
    }
    return false;
}

/*int main(){
    string x;
    cin>> x;
    cout<< '\n';
    cout<< '\n';
    cout<< '\n';
    cout<< pal(x);
    cout<< '\n';
    cout<< '\n';
    cout<< '\n';
    return 0;

}*/
