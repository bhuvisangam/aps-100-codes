#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    long long toh(int N, int from, int to, int aux) {
        long long count = pow(2,N);
        if(N==1){
            cout<<"move disk "<< N <<" from rod "<< from <<" 	to rod "<< to<<endl;
            return 1;
        }

        toh(N-1,from,aux,to);
         cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(N-1,aux,to,from);

        return count-1;
    }

};

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {

        int N;
        cin >> N;
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}
