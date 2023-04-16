/*Chef has two piles of stones with him, one has n1 stones and the other has n2 stones. Fired up by boredom, he invented a game with the two piles.

Before the start of the game Chef chooses an integer m.

In the j-th move:

He chooses a number xj such that 1 ≤ xj ≤ m, and removes xj stones from both the piles (this is only possible when both the piles have ≥ xj stones).
The number chosen must be unique over all the moves in the game. That is, for all k < j, xj ≠ xk.
The game stops when Chef is unable to make any more moves.

Chef wants to make the moves in such a way that the sum of the number of stones remaining in the two piles is minimized. Please help Chef find this.*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	   long long int a,b,m;
	    cin>>a>>b>>m;
	     long long int min1=min(a,b);
	     long long int sum=m*(m+1)/2;
	     long long int x=min(min1,sum);
	    cout<<a+b-2*x<<endl;
	}
	return 0;
}
