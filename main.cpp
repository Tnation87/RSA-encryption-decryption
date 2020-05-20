//
//  main.cpp
//  Sec-A3-20166052
//
//  Created by Toka Magdy on 3/27/20.
//  Copyright © 2020 Toka Magdy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int gcd(int x, int y){
    int a, b, r;
    if (x > y) {
        a = x;
        b = y;
    }
    else {
        a = y;
        b = x;
    }
    
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int main(int argc, const char * argv[]) {
    int p, q, n, e, d, phyN, message, encryptedMessage, originalMessage;
    vector<int> eCandidates;
    p = rand() % 1000;
    q = rand() % 1000;
    while (!isPrime(p))
        p++;
    while (!isPrime(q))
        q++;
    n = p * q;
    phyN = (p-1) * (q-1);
    
    for (int i = 2; i < phyN; i++) {
        int temp = gcd(i,phyN);
        if (temp == 1)
            eCandidates.push_back(temp);
    }
    
    e = eCandidates[rand() % eCandidates.size()];
    message = rand() % n;
    
    //encryption
    int x = pow(message, e);
    encryptedMessage = x % n;
    
    //decryption
    d = (1 % phyN)/e;
    x = pow(encryptedMessage, d);
    originalMessage = x % n;
    
    if (message == originalMessage)
        cout << "success" << endl;
    
    return 0;
}
