#include<bits/stdc++.h>
using namespace std;
template<typename T> T myMax(T a, T b){
    return a>b? a:b;
}
template<typename T> T myMin(T a, T b){
    return a<b? a:b;
}
int main(){
cout<< myMax<int>(3,7)<<endl;
cout<< myMax<float>(3.9,7.1)<<endl;
cout<< myMax<char>('a','s')<<endl<<endl;

cout<< myMin<int>(3,7)<<endl;
cout<< myMin<float>(3.9,7.8)<<endl;
cout<< myMin<char>('a','f')<<endl;

}
