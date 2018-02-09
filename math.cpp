/*
    Introduction to Discrete Mathematics help tool
    Author: Collin Rumpca
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
struct condition{
    int pre;
    int b;
    int n;
};

int FindInverse(int newN, int mod){
    for(int i = 1; i < mod; i++){
        if ((newN * i) % mod == 1)
            return i;
    }
    return -1;
}
bool isPrimeLong(unsigned long long n){
    if(n==2)
        return true;
    for(int i = 2; i < n; i++)
        if(n%i == 0)
            return false;
    return true;
}

bool isPrime(int n){
    if(n==2)
        return true;
    for(int i = 2; i < n; i++)
        if(n%i == 0)
            return false;
    return true;
}

int FindX(int mod, int n){
    int newN = n / mod;
    return FindInverse(newN, mod);
}
int ChineseRemainderTheorem(vector<int> x, vector<int> mod, vector<int> condition, int n){
    int tmp = 0;
    for(int i = 0; i < x.size(); i++){
        tmp = tmp + (x[i]*(n/mod[i])*condition[i]);
    }
    return tmp;
}
int returnGCDLong(unsigned long long n, unsigned long long mod){
    vector<unsigned long long> q;
    vector<unsigned long long> r;
    q.push_back(mod/n);
    r.push_back(mod%n);
    if(r[0]!=0){
        q.push_back(n/r[0]);
        r.push_back(n%r[0]);
    }
    else{
        return n;
    }
    for(int i = 1; r[r.size() - 1] != 0; i++){
        q.push_back(r[i-1]/r[i]);
        r.push_back(r[i-1]%r[i]);
    }
    return r[r.size()-2];
}

int returnGCD(int n, int mod){
    vector<int> q;
    vector<int> r;
    q.push_back(mod/n);
    r.push_back(mod%n);
    if(r[0]!=0){
        q.push_back(n/r[0]);
        r.push_back(n%r[0]);
    }
    else{
        return n;
    }
    for(int i = 1; r[r.size() - 1] != 0; i++){
        q.push_back(r[i-1]/r[i]);
        r.push_back(r[i-1]%r[i]);
    }
    return r[r.size()-2];
}
int ReturnChineseRemainder(vector<condition> v){
    int n = 1;
    for(int i = 0; i < v.size(); i++){
        n = n * v[i].n;
    }
    vector<int> x;
    for(int i = 0; i < v.size(); i++){
        x.push_back(FindX(v[i].n,n));
        if(x[x.size()-1] == -1){
            cout << "ERROR NO INVERSE FOR: " << n <<"(mod"<<v[i].n<<")"<<endl;
            return -1;
        }
     //   cout << "Inverse of " << n/v[i].n <<"(mod" << v[i].n << ") = "<< x[i] << endl;
    }
    int tmp = 0;
    for(int i = 0; i < x.size(); i++){
        tmp = tmp + (x[i]*(n/v[i].n)*v[i].b);
    }
    cout << "x = " << tmp%n << " + " << n <<"k" << endl;
    return tmp;
}

void ChineseRemainder(){
    cout << "how many conditions: ";
    int n,tmp;
    vector<int> condition;
    vector<int> mod;
    vector<int> x;
    cin >> n;
    while(n--){
        cout << "x = (  )(modn): ";
        cin >> tmp;
        condition.push_back(tmp);
        cout << "x = " << tmp <<"(mod( )): ";
        cin >> tmp;
        mod.push_back(tmp);
    }
    n = 1;
    for(int i = 0; i < condition.size(); i++){
        n = n * mod[i];
    }

    for(int i = 0; i < condition.size(); i++){
        x.push_back(FindX(mod[i],n));
        if(x[x.size()-1] == -1){
            cout << "ERROR NO INVERSE FOR: " << n <<"(mod"<<mod[i]<<")"<<endl;
            return;
        }
        cout << "Inverse of " << n/mod[i] <<"(mod" << mod[i] << ") = "<< x[i] << endl;;
    }

    int answer;
    answer = ChineseRemainderTheorem(x,mod,condition,n);
    cout << "x = " << answer%n << " + " << n <<"k" << endl;
}

void EuclideanGCD(int n, int mod){
    vector<int> q;
    vector<int> r;
    //n = xQ + r
    //Euclidean Algorithm:
    //cout << n << " " << mod << endl;
    cout << mod << " = " << n << "q + r" << endl;
    q.push_back(mod/n);
    r.push_back(mod%n);
    cout << "q: " << q[0]<<" r: "<<r[0]<<endl<<endl;
    if(r[0]!=0){
        cout << n <<" = "<<r[0]<<"q + r" << endl;
        q.push_back(n/r[0]);
        r.push_back(n%r[0]);
    }
    else{
        return;
    }
    cout << "q: " << q[1]<<" r: "<<r[1]<<endl<<endl;
    for(int i = 1; r[r.size() - 1] != 0; i++){
        cout << r[i-1] <<" = "<<r[i]<<"q + r" << endl;
        q.push_back(r[i-1]/r[i]);
        r.push_back(r[i-1]%r[i]);
        cout << "q: " << q[i+1]<<" r: "<<r[i+1]<<endl<<endl;
    }
    cout << "GCD(" <<n<<","<<mod<<")"<<" = "<<r[r.size()-2]<<endl;
    return;
}

void EuclideanInverse(int n, int mod){
    vector<int> q;
    vector<int> r;
    if(n == 1){
        cout << "Inverse = 1"<<endl;
        return;
    }
    //n = xQ + r
    //Euclidean Algorithm:
    //cout << n << " " << mod << endl;
    cout << mod << " = " << n << "q + r" << endl;
    q.push_back(mod/n);
    r.push_back(mod%n);
    cout << "q: " << q[0]<<" r: "<<r[0]<<endl;
    if(r[0]!=0){
        cout << n <<" = "<<r[0]<<"q + r" << endl;
        q.push_back(n/r[0]);
        r.push_back(n%r[0]);
        cout << "q: " << q[1]<<" r: "<<r[1]<<endl;
    }
    /*else{
        return;
    }
    */
    for(int i = 1; r[r.size() - 1] != 0; i++){
        cout << r[i-1] <<" = "<<r[i]<<"q + r" << endl;
        q.push_back(r[i-1]/r[i]);
        r.push_back(r[i-1]%r[i]);
        cout << "q: " << q[i+1]<<" r: "<<r[i+1]<<endl<<endl;
    }
    cout << "GCD(" <<n<<","<<mod<<")"<<" = "<<r[r.size()-2]<<endl;
    if(r[r.size()-2] != 1)
    {
        cout <<"ERROR They are not relatively prime"<<endl;
        return;
    }
    int A,B,x,y;
    //1 = 3 - 2
    //1 = 3 - (5 - 3)
    //GCD = Ax + By
    int count = 1;
    y = 0;
    x = 1;
    for(int i = r.size() - 2; i >= 2; i--){
        cout << r[i] << " = " << r[i-2] <<" - "<< r[i-1] << "(" << q[i] << ")" << endl;
        if(count % 2 == 1){
            A = r[i-2];
            B = r[i-1];
            y = y + (q[i] * x);
        }
        else{
            B = r[i-2];
            A = r[i-1];
            x = x +(q[i] * y);
        }
        cout << r[r.size()-2] << " = (" <<x<<")"<<A<<" - ("<<y<<")"<<B<<endl<<endl;
        count++;
    }
    cout << r[1] << " = " <<n<<" - "<<r[0] <<"(" << q[1] <<")"<<endl;
    if(count % 2 == 1){
        A = n;
        B = r[0];
        y = y + (q[1] * x);
    }
    else{
        B = n;
        A = r[0];
        x = x +(q[1] * y);
    }
    cout << r[r.size()-2] << " = (" <<x<<")"<<A<<" - ("<<y<<")"<<B<<endl<<endl;
    count++;

    cout << r[0] << " = " <<mod<<" - "<<n <<"(" << q[0] <<")"<<endl;
    if(r.size() <= 2){
            cout << "Inverse is: " << (((mod*100) - q[0])%mod) <<endl;
        cout << endl << endl;
        return;
    }
    if(count % 2 == 1){
        A = mod;
        B = n;
        y = y + (q[0] * x);
    }
    else{
        B = mod;
        A = n;
        x = x +(q[0] * y);
    }
        cout << r[r.size()-2] << " = (" <<x<<")"<<A<<" - ("<<y<<")"<<B<<endl<<endl;
    count++;

    if(A == mod){
        cout << "Inverse is: " << (((mod*100) - y)%mod) <<endl;
    }
    else{
        cout << "Inverse is: "<<x<<endl;
    }
    cout << endl << endl;
}

void encryptFunc()
{
        cout << "Enter the string you would like to encrypt: ";
        string x;
        getline(cin,x);
        for(int i = 0; i < x.size(); i++)
        {
                if(x[i] < 'A' || x[i] > 'Z' )
                {
                        cout << "input must only be capital letters" << endl;
                        return;
                }
        }
        int a, b;
        cout << "Enter A and B whre A*(string)+B: ";
        cin >> a >> b;
        if(a%2==0 || a%13==0)
        {
                cout << "A cannot share multiples with 26" << endl;
                return;
        }
        if(a<1 || b<0)
        {
                cout << "A cannot be below 1 and B cannot be negative" << endl;
                return;
        }
        int boolian;
        cout << "Does A = 0 or A = 1: ";
        cin >> boolian;
        cout << "Encrypted string: ";
        if(boolian == 0)
            for(int i = 0; i < x.length(); i++)
                    cout << char((((x[i] - 'A') * a + b) % 26) + 'A');
        if(boolian == 1)
              for(int i = 0; i < x.length(); i++)
                     cout << char((((((x[i] - 'A') + 1) * a + b) % 26) + 'A') - 1);
        cout << endl;
}

void decryptFunc()
{
        cout << "Enter the string you would like to decrypt(all caps): ";
        string x;
        getline(cin,x);
        for(int i = 0; i < x.size(); i++)
        {
                if(x[i] < 'A' || x[i] > 'Z' )
                {
                        cout << "input must only be capital letters" << endl;
                        return;
                }
        }
        int a, b,a2,b2,tmp,n=0;
        cout << "Enter the original A and B whre A*(string)+B: ";
        cin >> a >> b;
        if(a%2==0 || a%13==0)
        {
                cout << "A cannot share multiples with 26" << endl;
                return;
        }
        if(a<1 || b<0)
        {
                cout << "A cannot be below 1 and B cannot be negative" << endl;
                return;
        }
        tmp = 2;
    while(tmp != 1)
    {
        n++;
        tmp = (a * n)%26;
    }
        b2 = ((26 - b) * n)%26;
        a2 = n;
        cout << "New A: " << a2 << endl << "New B: " << b2 << endl;
        int boolian;
        cout << "Does A = 0 or A = 1: ";
        cin >> boolian;
        cout << "Decrypted string: ";
        if(boolian == 0)
            for(int i = 0; i < x.length(); i++)
                    cout << char((((x[i] - 'A')*a2 + b2) % 26) + 'A');
        else if(boolian == 1){
            for(int i = 0; i < x.length(); i++)
                   cout << char((((((x[i] - 'A') + 1)*a2 + b2) % 26) + 'A') - 1);
        }
        cout << endl;
}


void cypherAlgorithm(){
    string x,y;
    string junk;
            cout << "Enter e for encrypt or d for decrypt: ";
            char encrypt;
            cin >> encrypt;
            getline(cin,junk);
                    if(encrypt == 'e')
                            encryptFunc();
                    else if(encrypt == 'd')
                            decryptFunc();
                    else
                            cout <<"ERROR: not valid input"<<endl;
}

void findFactors(vector<int> &v, int b){
    for(int i = 1; i <= b ; i++)
        if(b % i == 0)
            v.push_back(i);
}

void findFirstFactors(vector<int> &v, int b){
    cout << b << endl;
    for(int i = 2; i < b ; i++)
    {
        if(b % i == 0){
            v.push_back(i);
            v.push_back(b/i);
            return;
        }
    }
}


void findRelativePrimes(vector<int> v, int d, vector<int> &actual){
    for(int i = v.size()-1; i >= v.size()/2; i--){

    }
}

void FermatsLittleTheorem(){

    int base, power, n;
    cout << " ____ to the (x) power (mod n) : ";
    cin >> base;
    cout << base << " to the ___ power (mod n) : ";
    cin >> power;
    cout << base <<" to the ("<<power<<") power (mod ___) : ";
    cin >> n;
    if(isPrime(n)){
        if(base%n != 0){
            cout << endl;
            cout << n <<" - 1 = "<<n-1<<endl;
            cout << power << " divided by " << n-1 << " = " << power/(n-1) <<" with a remainder of " << power%(n-1)<<endl;
            cout << base << " to the (" << power/(n-1) << ") power (mod " << n << ") = 1"<<endl;
            double x = (pow((double)base,(double)(power%(n-1))));
            cout << base << " to the (" << power%(n-1) << ") power = " << pow(base,(power%(n-1)))<<endl;
            cout << base << " to the (" << power%(n-1) << ") power (mod " << n << ") = "<<fmod(x,n) << endl;
            cout << endl << endl;
        }
        else{
            cout <<"ERROR: " << n << " divides " << base<<endl<<endl;
            return;
        }
    }
    else{
        cout << "ERROR: "<< n <<" is not prime"<<endl<<endl;
        return;
    }
}

void FindXFactors(vector<int> &primes){
    if(primes.size() == 1)
        return;
    else{
        int i;
        do{
            if(primes.size() == 1)
                return;
            i = 0;
            for(int i = 0; i < primes.size()-1; i++){
                if(primes[i]%primes[i+1] == 0){
                    primes[i] = primes[i] * primes[i+1];
                    primes.erase(primes.begin()+i+1);
                    i = 1;
                }
            }
        }while(i);
        }
    cout << "Relatively Prime Factorization: ";
    for(int x = 0; x <primes.size(); x++)
        cout << primes[x] << " ";
    cout << endl;
    return;
    }
void primeFactorizationReturn(vector<int> &factors,int num){
    if(isPrime(num)){
        cout << num << "is a prime number"<<endl;
        factors.push_back(num);
    }
    findFirstFactors(factors, num);
    for(int i = 0; i < factors.size(); i++){
        if(!isPrime(factors[i])){
            findFirstFactors(factors,factors[i]);
            factors.erase(factors.begin()+i);
            i--;
        }
    }
    sort(factors.begin(),factors.end());
    cout << factors[0];
    for(int i = 1; i < factors.size(); i++)
        cout<<" * " << factors[i];
    cout << endl << endl;
}

void linearCongruence(){
    int pre, b, n,mod;
    cout <<"___x = b (mod n): ";
    cin >> pre;
    cout << pre <<"x = ___ (mod n): ";
    cin >> b;
    cout << pre << "x = "<<b<<" (mod ___): ";
    cin >> n;

        int gcd = returnGCD(pre,n);
        if(b%gcd != 0){
                cout <<"ERROR: NO SOLUTIONS" << endl;
                return;
        }
        cout <<"There are "<<gcd<<" solutions"<<endl<<endl;
    vector<int> primes;
    primeFactorizationReturn(primes,n);
    FindXFactors(primes);
    mod = n;
    int pre1 = pre,b1 = b;
    while(!primes.empty()){
        n = primes[0];
        pre = pre1;
        b = b1;
        primes.erase(primes.begin());
        if(pre%n != 0){
        int inverse = -1;
        cout << pre<<" (mod "<< n <<") = "<<pre%n<<endl;
        pre = pre % n;
        if(pre != 1){
        inverse = FindInverse(pre,n);
        if(inverse == -1){
            cout <<"ERROR: no inverse"<<endl;
            return;
        }
    }
        else{
            inverse = 1;
        }
        cout <<"Inverse of "<<pre<<"(mod "<<n<<") = "<<inverse<<endl;
        cout <<inverse << " * " << b <<" = "<<inverse*b<<endl;
        inverse = inverse * b;
        cout <<"x = "<<inverse<<" (mod "<<n<<")"<<endl;
        cout <<"x = "<<inverse%n<<" (mod "<<n<<")"<<endl<<endl;
        inverse = inverse % n;
            int counter = 0,tmp = n;
            while(n < mod){
                counter++;
                n += tmp;
            }
            cout << "solutions: "<<endl;
            for(int i = 0;i <= counter; i++){
                    cout <<"x = "<<(inverse+(tmp*(i)))%n<<" (mod "<<n<<")"<<endl;
            }
            cout <<"End of set of solutions"<<endl<<endl;
    }
        else{
            cout << pre <<"x = " << b << "(mod " << n<<")"<<" = 0, thus x can be any number"<<endl<<endl;
            }
    }
        return;
}

void linearCongruence2(int &pre,int &b,int &n,vector<vector<condition>> &v){
        int gcd = returnGCD(pre,n);
        if(b%gcd != 0){
                cout <<"ERROR: NO SOLUTIONS" << endl;
                return;
    }
    vector<condition> temp;
        cout <<"There are "<<gcd<<" solutions"<<endl<<endl;
        cout << pre <<" divide "<<gcd<<" = "<<pre/gcd<<endl;
        cout << n <<" divide "<<gcd<<" = "<<n/gcd<<endl;
    vector<int> primes;
    primeFactorizationReturn(primes,n);
    FindXFactors(primes);
    int mod;
    mod = n;
    int pre1 = pre,b1 = b;
    while(!primes.empty()){
        n = primes[0];
        primes.erase(primes.begin());
        pre = pre1;
        b = b1;
        int inverse = -1;
        cout << pre<<" (mod "<< n <<") = "<<pre%n<<endl;
    if(pre%n != 0){
        if(pre != 1){
        inverse = FindInverse(pre,n);
        cout <<"INVERSE: " <<inverse << endl;
        }
        else{
            inverse = 1;
        }
        if(inverse == -1){
            cout <<"ERROR: no inverse"<<endl;
            return;
        }
        condition node;
        inverse = (inverse * b) % n;
        int counter = 0,tmp = n;
        while(n < mod){
            counter++;
            n += tmp;
        }
        for(int i = 0; i <= counter; i++){
            cout <<"x = "<<(inverse+(tmp*i))%(tmp*(i+1))<<" (mod "<<n<<")"<<endl;
            node.pre = 1;
            node.b = (inverse+(tmp*i))%n;
            node.n = n;
            temp.push_back(node);
            }
        v.push_back(temp);
            cout << endl;
            return;
        }
        else{
            cout << pre <<"x = " << b << "(mod " << n<<")"<<" = 0, thus x can be any number"<<endl<<endl;
        }
        }
}

void findAnswers(vector<vector<condition>> v, int x,vector<int> &place){
    if(x == v.size() - 1){
        for(int i = 0; i < v[x].size(); i++){
            place[x] = i;
            vector<condition> here;
            condition node;
            for(int y = 0; y <v.size(); y++){
                node = v[y][place[y]];
                here.push_back(node);
            }
            int answer = ReturnChineseRemainder(here);
        }
        return;
    }
    else{
        for(int i = 0; i < v[x].size(); i++){
            place[x] = i;
            findAnswers(v,x+1,place);
        }
    }
}

void simultaneousCongruence(){
    cout <<"How many conditions: ";
    int n;
    cin >> n;
    condition tmp;
    vector<vector<condition>> b;
    vector<condition> v;
    for(int i = 0; i < n; i++){
        cout <<"___x = b (mod n): ";
        cin >> tmp.pre;
        cout << tmp.pre <<"x = ___ (mod n): ";
        cin >> tmp.b;
        cout << tmp.pre << "x = "<<tmp.b<<" (mod ___): ";
        cin >> tmp.n;
        v.push_back(tmp);
    }


    cout <<"Solve each condition as a linear congruence"<<endl;
    int inverse;
    for(int i = 0; i < n; i++){
        linearCongruence2(v[i].pre,v[i].b,v[i].n,b);
        }
    int answer = 1;
    for(int i = 0; i < b.size(); i++)
        answer = answer * b[i].size();
    cout << "There are "<<answer<<" solutions: "<<endl;
    vector<int> places;
    for(int i = 0; i < b.size(); i++)
        places.push_back(0);
    findAnswers(b,0,places);
}

void primeFactorization(){
    cout << "Number to find factors of: ";
    int num;
    cin >> num;
    vector<int> factors;
    if(isPrime(num)){
        cout << num << "is a prime number"<<endl;
    }
    findFirstFactors(factors, num);
    for(int i = 0; i < factors.size(); i++){
        if(!isPrime(factors[i])){
            findFirstFactors(factors,factors[i]);
            factors.erase(factors.begin()+i);
            i--;
        }
    }
    sort(factors.begin(),factors.end());
    cout << factors[0];
    for(int i = 1; i < factors.size(); i++)
        cout<<" * " << factors[i];
    cout << endl << endl;
}
void RSA(){
    unsigned long long p,q,n,T,k;
    cout <<"Enter first positive prime number: ";
    cin >> p;
    cout << "Enter first positive prime number: ";
    cin >> q;
    if(!isPrimeLong(p)){
        cout <<"ERROR: "<< p << " is not a prime number"<<endl;
        return;
    }
    if(!isPrimeLong(q)){
        cout <<"ERROR: "<< q << " is not a prime number"<<endl;
        return;
    }
    n = p * q;
    cout << "n = "<<p<<" * "<<q<<" = "<<n<<endl;
    T = (p-1)*(q-1);
    cout << "T = "<<p-1<<" * "<<q-1<<" = "<<T<<endl;
    k = T;
    bool tested[T+1] = {false};
    while(1){
        k = rand() % T + 1;
        if(tested[k] == false){
            if(returnGCDLong(k,T) == 1)
                break;
            else
                tested[k] = true;
        }
    }
    cout <<"k ="<<k<<" since GCD(T,k) = 1"<<endl;
    cout <<"Is message a number(0) or characters(1): ";
    int input;
    if(input == 0){
        cout <<"input number(can only be up to 19 digits): ";
        unsigned long long M;
        cin >> M;
    }
    else if(input == 1){

    }
    else{
        cout << "ERROR: Invalid input"<<endl;
        return;
    }
}

void setUnion(){
    cout << "Set Union (using integers no characters)"<<endl<<endl;
    cout <<"how long is first set: ";
    int tmp,a,b;
    cin >> tmp;
    vector<int> first;
    cout << "Enter "<<tmp<<" numbers that are in the set: ";
    for(int i = 0; i < tmp; i++){
        cin >> a;
        first.push_back(a);
    }
    vector<int> second;
    cout <<"how long is second set: ";
    cin >> tmp;
    cout << "Enter "<<tmp<<" numbers that are in the set: ";
    for(int i = 0; i < tmp; i++){
        cin >> a;
        second.push_back(a);
    }
    cout << endl << endl;
    cout <<" First set: {"<<first[0];
    for(int i = 1; i < first.size(); i++)
        cout <<", "<<first[i];
    cout <<"}"<<endl;

    cout <<"Second set: {"<<second[0];
    for(int i = 1; i < second.size(); i++)
        cout <<", "<<second[i];
    cout <<"}"<<endl;
    if(first.size() == 0){
     cout <<"A union B: { "<<second[0];
     for(int i = 1; i < second.size(); i++)
         cout <<", "<<second[i];
    }
    else if(second.size() == 0){
        cout <<"A union B: { "<<first[0];
        for(int i = 1; i < first.size(); i++)
            cout <<", "<<first[i];
       }
    else{
        vector<int> u;
        for(int i = 0; i < first.size(); i++){
            int m = first[i];
            u.push_back(m);
        }
        for(int i = 0; i < u.size(); i++){
            for(int x = 0; x < u.size(); x++){
                if(u[i] == u[x] && i != x){
                    u.erase(u.begin()+x);
                    i = 0;
                    break;
                }
            }
        }
        for(int i = 0; i < second.size(); i++){
            int test = 0;
            for(int x = 0; x < u.size(); x++){
                if(u[x] == second[i])
                    test = 1;
            }
            if(!test)
                u.push_back(second[i]);
        }
        sort(u.begin(),u.end());
        cout <<"Union of A and B: {";
        cout << u[0];
        for(int i = 1; i < u.size(); i++)
            cout <<", "<<u[i];
        cout <<"}"<<endl<<endl;
    }
}

void setIntersection(){
    cout <<"Set Intersection"<<endl;
    cout <<"how long is first set: ";
    int tmp,a,b;
    cin >> tmp;
    vector<int> first;
    cout << "Enter "<<tmp<<" numbers that are in the set: ";
    for(int i = 0; i < tmp; i++){
        cin >> a;
        first.push_back(a);
    }
    vector<int> second;
    cout <<"how long is second set: ";
    cin >> tmp;
    cout << "Enter "<<tmp<<" numbers that are in the set: ";
    for(int i = 0; i < tmp; i++){
        cin >> a;
        second.push_back(a);
    }
    cout << endl << endl;
    cout <<" First set: {"<<first[0];
    for(int i = 1; i < first.size(); i++)
        cout <<", "<<first[i];
    cout <<"}"<<endl;

    cout <<"Second set: {"<<second[0];
    for(int i = 1; i < second.size(); i++)
        cout <<", "<<second[i];
    cout <<"}"<<endl;
    vector<int> intersect;
    for(int i = 0; i < first.size(); i++){
        int test = 0;
        for(int x = 0; x < second.size(); x++){
            if(first[i] == second[x] && i != x)
                test = 1;
        }
        if(test)
            intersect.push_back(first[i]);
    }
    for(int i = 0; i < intersect.size(); i++){
        for(int x = 0; x < intersect.size(); x++){
            if(intersect[i] == intersect[x]&&i!=x){
                intersect.erase(intersect.begin()+x);
                i = 0;
                break;
            }
        }
    }
    sort(intersect.begin(),intersect.end());
    cout <<"Intersesction of First and Second Set:{";
    if(!intersect.empty())
        cout << intersect[0];
    for(int i = 1; i < intersect.size(); i++){
        cout <<", "<<intersect[i];
    }
    cout <<"}"<<endl<<endl;
    
}

void setDifference(){
        cout <<"Set Difference"<<endl;
        cout <<"how long is first set: ";
        int tmp,a,b;
        cin >> tmp;
        vector<int> first;
        cout << "Enter "<<tmp<<" numbers that are in the set: ";
        for(int i = 0; i < tmp; i++){
            cin >> a;
            first.push_back(a);
        }
        vector<int> second;
        cout <<"how long is second set: ";
        cin >> tmp;
        cout << "Enter "<<tmp<<" numbers that are in the set: ";
        for(int i = 0; i < tmp; i++){
            cin >> a;
            second.push_back(a);
        }
        cout << endl << endl;
        cout <<" First set: {"<<first[0];
        for(int i = 1; i < first.size(); i++)
            cout <<", "<<first[i];
        cout <<"}"<<endl;
    
        cout <<"Second set: {"<<second[0];
        for(int i = 1; i < second.size(); i++)
            cout <<", "<<second[i];
        cout <<"}"<<endl;
        vector<int> difference;
        for(int i = 0; i < first.size(); i++){
            int test = 0;
            for(int x = 0; x < second.size(); x++){
                if(first[i] == second[x] && i != x)
                    test = 1;
            }
            if(!test)
                difference.push_back(first[i]);
        }
        for(int i = 0; i < difference.size(); i++){
            for(int x = 0; x < difference.size(); x++){
                if(difference[i] == difference[x]&&i!=x){
                    difference.erase(difference.begin()+x);
                    i = 0;
                    break;
                }
            }
        }
        sort(difference.begin(),difference.end());
        cout <<"Difference of First and Second Set:{";
        if(!difference.empty())
            cout << difference[0];
        for(int i = 1; i < difference.size(); i++){
            cout <<", "<<difference[i];
        }
        cout <<"}"<<endl<<endl;
        
    }

void sets(){
    while(1){
    cout << "Set Math"<<endl;
    cout <<"+------------------------+"<<endl
    <<"| 0 : Quit Set Math      |"<<endl
    <<"| 1 : Union              |"<<endl
    <<"| 2 : Intersection       |"<<endl
    <<"| 3 : Difference         |"<<endl
    <<"+------------------------+"<<endl;
    int n;
    cout << "Enter a number according to what you want to do: ";
    cin >> n;
    if(n == 0){
        cout << "Quitting"<<endl;
        return;
    }
    else if(n == 1){
        system("clear");
        setUnion();
    }
    else if(n == 2){
        system("clear");
        setIntersection();
    }
    else if(n == 3){
        system("clear");
        setDifference();
    }
    else{
        cout <<"ERROR: Invalid Input"<<endl;
    }
    }
}

void truthTables(){
    system("clear");
    cout
    <<"Truth Tables"<<endl
    <<"Definition: A table used to show the end result of every possible outcome of a given statement"<<endl
    <<"For example: P -> Q"<<endl
    <<"+---+---+--------+"<<endl
    <<"| P | Q | P -> Q |"<<endl
    <<"+---+---+--------+"<<endl
    <<"| T | T |   T    |"<<endl
    <<"| T | F |   F    |"<<endl
    <<"| F | T |   T    |"<<endl
    <<"| F | F |   T    |"<<endl
    <<"+---+---+--------+"<<endl<<endl;
    cout <<"Enter any integer to return to Into To Discrete Notes: ";
    int n;
    cin >> n;
    return;
}

void logicalEquivalencies(){
    system("clear");
    cout << "Logical Equivalencies"<<endl<<endl
    <<"De Morgan's Law:"<<endl
    <<"+--------------------+"<<endl
    <<"| 1 : ¬(PvQ) = ¬P^¬Q |"<<endl
    <<"| 2 : ¬(P^Q) = ¬Pv¬Q |"<<endl
    <<"+--------------------+"<<endl<<endl
    <<"Not De Morgan's but still true:"<<endl
    <<"  3 : P -> Q = ¬Q -> ¬P"<<endl
    <<"  4 : ¬(P -> Q) = P^¬Q"<<endl
    <<"  5 : P -> Q = ¬PvQ"<<endl
    <<"  6 : ¬(¬P) = P"<<endl
    <<"  7 : P^(QvR) = (P^Q)V(P^R) "<<endl
    <<"  8 : Pv(Q^R) =(PvQ)^(PvR)"<<endl
    <<"  9 : P -> (QvR) = (P^¬Q) -> R"<<endl
    <<"  10: (PvQ) -> R = (P -> R)^(Q -> R)"<<endl<<endl
    <<"Biconditional statement:"<<endl
    <<" P <-> Q = (P -> Q)^(Q -> P)"<<endl
    <<endl<<"Negation: P -> Q = P ^¬Q"<<endl
    <<"Contrapositive: P -> Q = ¬Q -> ¬P"<<endl
    <<"Converse: P -> Q = Q -> P"<<endl
    <<"Inverse: ¬P -> ¬Q"<<endl<<endl    
    <<"Enter any integer to return to Intro to Discrete Notes page: ";
    int n;
    cin >> n;
    return;
}
void Proofs(){
    system("clear");
    cout <<"Proofs"<<endl;
    cout <<"There are several types of proofs:"<<endl;
    cout <<"Direct Proof: a proof showing a direct coorolation between P and Q, the proof would start at P and end at P"<<endl<<endl
    <<"Contrapositive: using logical equivalencies we know P -> Q = ¬Q -> ¬P, so we can start at ¬Q and end at ¬P"<<endl<<endl
    <<"Contradiction: we can prove using the negation of P -> Q which would be P ^ ¬Q, so we can start with either, except our goal is to break math in some way"<<endl
    <<"Induction: we use this when we have a list or set of infinite numbers, there are three steps to induction: "<<endl
    <<"         Step 1: Base Case - show the proof is true using the smallest(base) case possible"<<endl
    <<"         Step 2: Induction Hypothesis - We can assume true for N numbers in the sequence"<<endl
    <<"         Step 3: Solve - show proof is still true for N+1"<<endl<<endl
    <<"Strong Induction: we use this when we have a list or set of infinite numbers, there are three steps to strong induction: "<<endl
    <<"         Step 1: Base Case - show the proof is true using the smallest(base) case possible"<<endl
    <<"         Step 2: Induction Hypothesis - We can assume true for k <= N numbers in the sequence"<<endl
    <<"         Step 3: Solve - show proof is still true for N+1"<<endl<<endl
    <<"Enter any integer to return to Intro to Discrete Notes page: ";
    int n;
    cin >> n;
    return;
}

void Notes(){
    while(1){
    system("clear");
    cout
    <<"+----------------------------------+"<<endl
    <<"| 0 : Quit Intro To Discrete Notes |"<<endl
    <<"| 1 : Truth Tables                 |"<<endl
    <<"| 2 : Logical Equivalencies        |"<<endl
    <<"| 3 : Proofs                       |"<<endl
    <<"|                                  |"<<endl<<endl
    <<"Enter a number according to what you want to do: ";
    int n;
    cin >> n;
    if(n == 0){
        cout << "Redirecting to Home Page"<<endl;
        return;
    }
    else if(n == 1){
        truthTables();
    }
    else if(n == 2){
        logicalEquivalencies();
    }
    else if(n == 3){
        Proofs();
    }
}
}

int main(){
    system("clear");
    while(1){
    cout
    <<"+--------------------------------------------------+"<<endl
    <<"| 0 : quit                                         |"<<endl
    <<"| 1 : Euclidean's to find GCD                      |"<<endl
    <<"| 2 : Chinese Remainder Theorem                    |"<<endl
    <<"| 3 : Find the inverse using Euclidean's           |"<<endl
    <<"| 4 : Solve for x in the form Nx=y(modb)           |"<<endl
    <<"| 5 : Cypher Algorithm                             |"<<endl
    <<"| 6 : Fermat's Little Theorem                      |"<<endl
    <<"| 7 : Linear Congruence                            |"<<endl
    <<"| 8 : simultaneous Congruence                      |"<<endl
    <<"| 9 : Intro To Discrete Notes                      |"<<endl
    <<"| 10: Prime factorization                          |"<<endl
    <<"| 11: Original RSA Algorithm                       |"<<endl
    <<"| 12: Set Math                                     |"<<endl
    <<"+--------------------------------------------------+"<<endl
    <<"Enter a number according to what you want to do: ";
    int i;
    cin >> i;
    if(i == 0){
        cout << "quitting" << endl;
        system("clear");
        return 0;
    }
    else if(i == 1){
        system("clear");
        cout << "EuclideanGCD"<<endl;
        int y,x;
        cout << "Enter First Value: ";
        cin >> y;
        cout << "Enter Second Value: ";
        cin >> x;
        EuclideanGCD(x,y);
        cout<<endl<<endl;
    }
    else if(i == 2){
        system("clear");
        cout << "Chinese Remainder Theorem"<<endl;
        ChineseRemainder();
        cout << endl << endl;
    }
    else if(i == 3){
        system("clear");
        cout << "Extended Euclidean's to find inverse";
        int y,x;
        cout << "____(modn): ";
        cin >> y;
        cout << y <<"(mod____): ";
        cin >> x;
        EuclideanInverse(y,x);
    }
    else if(i == 4){
        system("clear");
        cout <<"Solve for X in the form Px = b(mod n)"<<endl;
        cout << endl <<"Number of conditions: ";
        int u;
        cin >> u;
        if(u > 1){
            simultaneousCongruence();
        }
        else if(u == 1){
            linearCongruence();
        }
        else{
            cout << "ERROR: invalid input"<<endl;
        }
    }
    else if(i == 5){
        system("clear");
        cout << "Cypher Algorithm"<<endl;
        cypherAlgorithm();
    }
    else if(i == 6){
        system("clear");
        cout <<"Fermat's Little Theorem"<<endl;
        FermatsLittleTheorem();
    }
    else if(i == 7){
        system("clear");
        cout <<"Linear Congruence"<<endl;
        linearCongruence();
    }
    else if(i == 8){
                system("clear");
                cout <<"Simultaneous Congruence"<<endl;
                simultaneousCongruence();
    }
    else if(i == 9){
        system("clear");
        Notes();
    }
    else if(i == 10){
        system("clear");
        cout << "prime Factorization"<<endl;
        primeFactorization();
    }
    else if(i == 11){
        system("clear");
        cout << "Original RSA Algorithm:"<<endl;
        RSA();
    }
    else if(i == 12){
        system("clear");
        sets();
    }
    else
        cout << "NOT VALID INPUT"<<endl;
    }
    return 0;
}