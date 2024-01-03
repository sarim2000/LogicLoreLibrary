// bit manipulation

#include <bits/stdc++.h>
using namespace std;

/*Obtain the remainder (modulo) of S when it is divided by N (N is a power of 2)
e.g., S = (7)10 % (4)10 = (111)2 % (100)2 = (11)2 = (3)10.*/

int remainder(int n1,int n2){
    return n1 & (n2 - 1);
}

/*Determine if S is a power of 2.
e.g., S = (7)10 = (111)2 is not a power of 2, but (8)10 = (1000)2 is a power of 2.*/

bool isPowerOfTwo(int x)
{
    if (x < 0)
        return false;
    /* First x in the below expression is for the case when
     * x is 0 */
    return x && (!(x & (x - 1)));
}

// Turn of the last one in S, e.g., S
int lastOneBitOff(int x){
    return x & (x - 1);
}


// turn on last zero
int turnOnLastZero(int S){
    // S => 9 => 1 0 0 1
    // find complement ~S 0 1 1 0
    // get mask ~S & (S + 1) => 0 1 1 0 && (1 0 0 1) => 0 0 1 0
    // turn last zero S | mask => 1 0 1 1
    int comp = ~S;
    int mask = comp & (S + 1);
    return S | mask;

}

// Turn o↵ the last consecutive run of ones in S

int turnConsecutiveOnes(int S){
    return S & (S + 1);
}

int main(){
    cout << turnConsecutiveOnes(39);
    return 0;
}


