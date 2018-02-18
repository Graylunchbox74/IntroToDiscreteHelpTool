#include <iostream>
#include <stdio.h>
using namespace std;
/*Practice problems                             */
/*Introduction to Discrete Mathematics Help Tool*/
void TruthTablePractice(){
    while(1){
    system("clear");
    cout <<"Problems: "<<endl
    <<"Show the truth table for the following: "<<endl
    <<"1. P -> Q"<<endl
    <<"2. ¬(P -> (Q v R))"<<endl
    <<"3. (P ^ ¬Q) v ¬R"<<endl
    <<"4. P v (¬Q -> ¬R)"<<endl
    <<"5. (P -> ¬Q) ^ ¬R"<<endl
    <<"Enter the number you want to see the solution to, or 0 to quit: ";
    int n,x;
    cin >> n;
    if(n == 0){
        cout <<"Quitting Truth Table Practice Problems"<<endl;
        return;
    }
    else if(n == 1){
        system("clear");
        cout<<"1. P -> Q"<<endl<<endl
        <<"|P | Q | P -> Q |"<<endl
        <<"+--+---+--------+"<<endl
        <<"|T | T |   T    |"<<endl
        <<"|T | F |   F    |"<<endl
        <<"|F | T |   T    |"<<endl
        <<"|F | F |   T    |"<<endl<<endl
        <<"Enter any integer to return to problems: ";
        cin >> x;
    }
    else if(n == 2){
        system("clear");
        cout<<"2. ¬(P -> (Q v R))"<<endl<<endl
        <<"|P | Q | R | Q v R | P -> (Q v R) | ¬(P -> (Q v R))|"<<endl
        <<"+--+---+---+-------+--------------+----------------+"<<endl
        <<"|T | T | T |   T   |       T      |        F       |"<<endl
        <<"|T | T | F |   T   |       T      |        F       |"<<endl
        <<"|T | F | T |   T   |       T      |        F       |"<<endl
        <<"|T | F | F |   F   |       F      |        T       |"<<endl
        <<"|F | T | T |   T   |       T      |        F       |"<<endl
        <<"|F | T | F |   T   |       T      |        F       |"<<endl
        <<"|F | F | T |   T   |       T      |        F       |"<<endl
        <<"|F | F | F |   F   |       T      |        F       |"<<endl
        <<"+--+---+---+-------+--------------+----------------+"<<endl<<endl
        <<"Enter any integer to return to problems: ";
        cin >> x;
    }
    else if(n == 3){
        system("clear");
        cout<<"3. (P ^ ¬Q) v ¬R"<<endl
        <<"|P | Q | R | ¬Q | P ^ ¬Q | ¬R | (P ^ ¬Q) v ¬R |"<<endl
        <<"+--+---+---+----+--------+----+---------------+"<<endl
        <<"|T | T | T | F  |   F    |  F |       F       |"<<endl
        <<"|T | T | F | F  |   F    |  T |       T       |"<<endl
        <<"|T | F | T | T  |   T    |  F |       T       |"<<endl
        <<"|T | F | F | T  |   T    |  T |       T       |"<<endl
        <<"|F | T | T | F  |   F    |  F |       F       |"<<endl
        <<"|F | T | F | F  |   F    |  T |       T       |"<<endl
        <<"|F | F | T | T  |   F    |  F |       F       |"<<endl
        <<"|F | F | F | T  |   F    |  T |       T       |"<<endl
        <<"+--+---+---+----+--------+----+---------------+"<<endl<<endl
        <<"Enter any integer to return to problems: ";
        cin >> x;        
    }
    else if(n==4){
        system("clear");
        cout <<"4. P v (¬Q -> ¬R)"<<endl
        <<"|P | Q | R | ¬Q | ¬R | ¬Q -> ¬R | P v (¬Q -> ¬R) |"<<endl
        <<"+--+---+---+----+----+----------+----------------+"<<endl
        <<"|T | T | T | F  | F  |     T    |       T        |"<<endl
        <<"|T | T | F | F  | T  |     T    |       T        |"<<endl
        <<"|T | F | T | T  | F  |     F    |       T        |"<<endl
        <<"|T | F | F | T  | T  |     T    |       T        |"<<endl
        <<"|F | T | T | F  | F  |     T    |       T        |"<<endl
        <<"|F | T | F | F  | T  |     T    |       T        |"<<endl
        <<"|F | F | T | T  | F  |     F    |       F        |"<<endl
        <<"|F | F | F | T  | T  |     T    |       T        |"<<endl
        <<"+--+---+---+----+----+----------+----------------+"<<endl<<endl
        <<"Enter any integer to return to problems: ";
        cin >> x;        
    }
    else if(n==5){
        system("clear");
        cout <<"5. (P -> ¬Q) ^ ¬R"<<endl
        <<"|P | Q | R | ¬Q | P -> ¬Q | ¬R | (P -> ¬Q) ^ ¬R |"<<endl
        <<"+--+---+---+----+---------+----+----------------+"<<endl
        <<"|T | T | T | F  |    F    | F  |        F       |"<<endl
        <<"|T | T | F | F  |    F    | T  |        F       |"<<endl
        <<"|T | F | T | T  |    T    | F  |        F       |"<<endl
        <<"|T | F | F | T  |    T    | T  |        T       |"<<endl
        <<"|F | T | T | F  |    T    | F  |        F       |"<<endl
        <<"|F | T | F | F  |    T    | T  |        T       |"<<endl
        <<"|F | F | T | T  |    T    | F  |        F       |"<<endl
        <<"|F | F | F | T  |    T    | T  |        T       |"<<endl
        <<"+--+---+---+----+---------+----+----------------+"<<endl<<endl
        <<"Enter any integer to return to problems: ";
        cin >> x;
    }
    else{
        system("clear");
        cout <<"ERROR: Invalid input"<<endl;
        cout <<"Enter any integer to return to problems: ";
        cin >> x;
    }
}
}

void LogicalEquivPractice(){
    while(1){
        system("clear");
        cout <<"Show that the following statements are equivalent to each other: "<<endl<<endl
        <<"1. ¬(Pv(¬P ^ Q) is equivalent to ¬P ^ ¬Q"<<endl
        <<"2. (P ^ Q) -> R is equivalent to P -> (Q -> R)"<<endl
        <<"3. (Q v R) -> P is equivalent to (Q -> P) ^ (R -> P)"<<endl
        <<endl<<"Enter the number you want to see the solution to, or 0 to quit: "<<endl;
        int n,x;
        cin >> n;
        system("clear");
        if(n == 0){
            cout <<"QUITTING"<<endl;
            return;
        }
        else if(n == 1){
            cout <<"1. ¬(Pv(¬P ^ Q) is equivalent to ¬P ^ ¬Q"<<endl<<endl
            <<"(¬P ^ ¬(¬P ^ Q) - DeMorgan's law"<<endl
            <<"¬P ^ (P v ¬Q) - DeMorgan's law"<<endl
            <<"(¬P ^ P) v (¬P ^ ¬Q) - distributive law"<<endl
            <<"¬P ^ ¬Q - since ¬P ^ P is a contradiction and can never happen"<<endl<<endl;
            cout <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else if(n == 2){
            cout << "2. (P ^ Q) -> R is equivalent to P -> (Q -> R)"<<endl<<endl
            <<"¬(P ^ Q) v R using rule 5"<<endl
            <<"¬P v ¬Q v R using DeMorgan's law"<<endl
            <<"¬P v (Q -> R) using rule 5"<<endl
            <<"P -> (Q -> R) using rule 5"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else if(n == 3){
            cout <<"3. (Q v R) -> P is equivalent to (Q -> P) ^ (R -> P)"<<endl<<endl
            <<"¬(Q v R) v P using rule 5" << endl
            <<"(¬Q ^ ¬R) v P using DeMorgan's law"<<endl
            <<"(¬Q v P) ^ (¬R v P) using distributive laws"<<endl
            <<"(Q -> P) ^ (R -> P) using rule 5"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else{
            cout <<"ERROR: Invalid input"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
    }
}

void DividesModuloPractice(){
    while(1){
        system("clear");
        cout <<"Given x and y solve for q and r in the form x = y(q) + r:"<<endl
        <<"1. x = 20   y = 4"<<endl
        <<"2. x = 13   y = 20"<<endl
        <<"3. x = 45   y = 6"<<endl
        <<"4. x = 90   y = 7"<<endl
        <<"5. x = 100  y = 90"<<endl<<endl
        <<"Enter the number you want to see the answer to, or 0 to quit: ";
        int x,n;
        cin >> n;
        system("clear");
        if(n==0){
            cout <<"QUITTING"<<endl;
            return;
        }
        else if(n==1){
            cout <<"20 = 4(q) + r"<<endl
            <<"q = 5   r = 0"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else if(n == 2){
            cout <<"13 = 20(q) + r"<<endl
            <<"q = 0   r = 13"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else if(n == 3){
            cout <<"45 = 6(q) + r"<<endl
            <<"q = 7   r = 3"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else if(n == 4){
            cout <<"90 = 7(q) + r"<<endl
            <<"q = 12   r = 6"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else if(n == 5){
            cout <<"100 = 90(q) + r"<<endl
            <<"q = 1   r = 10"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
        else{
            cout <<"ERROR: Invalid Input"<<endl<<endl
            <<"Enter any integer to go back to problems: ";
            cin >> x;
        }
    }
}

void DirectProofPractice(){
    while(1){
        system("clear");
        cout <<"Make a formal proof for the following: "<<endl
        <<"1. If n is even, then n squared is also even"<<endl
        <<"2. The sum of two odd integers is even"<<endl
        <<"3. for twin primes other than 3 and 5, the number between the primes is divisible by 6"<<endl
        <<endl<<"Enter the number you want to see the answer to, or 0 to quit: ";
    int n,x;
    cin >> n;
    system("clear");
    if(n == 0){
        cout <<"QUITTING"<<endl;
        return;
    }
    else if(n == 1){
        cout <<"If n is even then n squared is even"<<endl<<endl
        <<"Proof:"<<endl
        <<"Given an even integer n we know that n = 2k for some integer k"<<endl
        <<"Thus n squared is equal to 4k squared which is equal to 2 times (2k squared)"<<endl
        <<"due to the closure of integers in multiplication we know 2k squared is equal to some integer m"<<endl
        <<"thus we can rewrite this as n squared = 2(m), thus we know that n squared is even."<<endl<<endl
        <<"Enter any integer to go back to problems: ";
        cin >> x;
    }
    else if(n == 2){
        cout <<"The sum of two odd integers is even"<<endl<<endl
        <<"Proof:"<<endl
        <<"Given two odd integers m and n we know that m = 2k + 1 for some integer k and"<<endl
        <<"n = 2x + 1 for some integer x since m and n are odd. m + n = 2k + 2x + 2"<<endl
        <<"using algebra: m+n = 2(k + x + 1)"<<endl
        <<"through the closure of integers under addition we know k + x + 1 = some integer p, thus"<<endl
        <<"we can rewrite it as m + n = 2(p), thus m + n is even."<<endl<<endl
        <<"Enter any integer to go back to problems: ";
        cin >> x;
    }
    else if(n == 3){
        cout <<"For twin primes other than 3 and 5, the number between the primes is divisible by 6"<<endl<<endl
        <<"Proof:"<<endl
        <<"Given prime numbers n and n+2 we know n+1 is even since n and n+2 are prime, thus 2|n+1. since n"<<endl
        <<"and n+2 are prime and cannot equal 3: Given 3 consecutive integers n, n+1 and n+2, one must be divisible by 3. since n and "<<endl
        <<"n+2 are prime, then n+1 must be divisible by 3. since 2|n+1 and 3|n+1 then 6|n+1."<<endl<<endl
        <<"Enter any integer to go back to problems: ";
        cin >> x;
    }
}
}

void ContrapositiveProofPractice(){
    while(1){
        cout <<"Make a formal proof for the following: "<<endl
        <<"1. If x and y are two integers whose product is even, then at least one of the two must be even."<<endl
        <<"2. If x and y are two integers whose product is odd, then both must be odd."<<endl
        <<"3. If a and b a real numbers such that the product a b is an irrational number, then either a or b must be an irrational number"<<endl<<endl
        <<"Enter the number of problem you want the answer to, or 0 to quit: ";
        int n,x;
        cin >> n;
        system("clear");
        if(n == 0){
            cout <<"QUITTING"<<endl;
            return;
        }
        else if(n == 1){
            cout<<"If x and y are two integers whose product is even, then at least one of the two must be even"<<endl<<endl
            <<"Proof:"<<endl
            <<"We will prove the following using contrapositive: "<<endl
            <<"If x and y are not even numbers, then the product is odd"<<endl<<endl
            <<"Given two odd numbers x and y we know they can be written as: "<<endl
            <<"x = 2k + 1   for some integer k"<<endl
            <<"y = 2m + 1   for some integer m"<<endl
            <<"using algebra:"<<endl
            <<"x*y = (2k + 1) *(2m + 1)"<<endl
            <<"    = 4mk + 2k + 2m + 1"<<endl
            <<"    = 2(2mk + k + m) + 1"<<endl
            <<"knowing that 2mk + k + m is an integer p this can be rewritten as:"<<endl
            <<"    =2(p) + 1"<<endl
            <<"thus the product of x and y is odd."<<endl<<endl
            <<"Enter any integer to go back to the problems: ";
            cin >> x;
        }
        else if(n == 2){
            cout <<"If x and y are two integers whose product is odd, then both must be odd."<<endl<<endl
            <<"Proof:"<<endl
            <<"We will prove the following using contrapositive: "<<endl
            <<"If x or y is even, then the product is even"<<endl<<endl
            <<"We are given at least one even integer, so we can solve by cases:"<<endl<<endl
            <<"Case 1: only one even number:"<<endl
            <<"     2k * (2m + 1) = 4km + 2k"<<endl
            <<"                   =2(km + k)"<<endl
            <<"     Thus the product is even"<<endl<<endl
            <<"Case 2: two even numbers:"<<endl
            <<"     2k * 2m = 2(2mk) which is also even"<<endl<<endl
            <<"Thus the product of two numbers where at least one is even is even"<<endl<<endl
            <<"Enter any integer to go back to the problems: ";
            cin >> x;
        }
        else if(n == 3){
            cout << "If a and b a real numbers such that the product a b is an irrational number, then either a or b must be an irrational number"<<endl<<endl
            <<"Proof:"<<endl
            <<"We will prove the following using contrapositive:"<<endl
            <<"If both a and b are rational numbers, then the product of a and b is rational"<<endl<<endl
            <<"since a and b are rational we can set a = m/n for integers m and n and b = x/k for integers x and k"<<endl
            <<"thus the product of the two equals:"<<endl
            <<"(mx)/(nk)"<<endl
            <<"since the product can be written in the form of a fraction of integers the product is rational."<<endl<<endl
            <<"Enter any integer to go back to the problems: ";
            cin >> x;
        }
        else{
            cout << "ERROR: Invalid input"<<endl<<endl
            <<"Enter any integer to go back to the problems: ";
            cin >> x;
        }
    }
}

void ContradictionProofPractice(){
    while(1){
        system("clear");
        cout <<"Make a formal proof for the following: "<<endl
        <<"1."<<endl
        <<"2."<<endl
        <<"3. if p is prime then the square root of p is irrational"<<endl<<endl
        <<"Enter the number of problem you want the answer to, or 0 to quit: ";
        int x, n;
        cin >> n;
        system("clear");
    if(n==0){
        cout << "QUITTING"<<endl;
        return;
    }
    else if(n == 1){

    }
    else if(n == 2){

    }
    else if(n == 3){
        cout <<"if p is prime then the square root of p is irrational"<<endl<<endl
        <<"Proof:"<<endl
        <<"We will prove the following by contradiction:"<<endl
        <<"if p is prime then the square root of p is rational"<<endl<<endl
        <<"We can set a rational number r squared equal to p since the square root of p is rational"<<endl
        <<"By the definition of rational numbers we can set p = (a squared / b squared) for integers a and b "<<endl
        <<"Which we can assume is reduced"<<endl
        <<"We can use algebra to determing : a squared = p (b squared)"<<endl
        <<"Thus by definition p divides a squared with means p divides a"<<endl
        <<"By definition of divides pk = a for some integer k"<<endl
        <<"We can subsitute this into the equation to get: (pk)squared = p(b squared)"<<endl
        <<"We divide both sides by p to get: p (k squared) = b squared"<<endl
        <<"Thus by definition we know that p divides b squared and thus p divides b"<<endl
        <<"Thus our original fraction is not reduced which breaks our assumption"<<endl<<endl
        <<"Enter any integer to go back to problems: ";
        cin >> x;
    }
    else{
        cout <<"ERROR: Invalid input"<<endl<<endl;
        cout <<"Enter any integer to go back to problems: ";
        cin >> x;
    }
}
}

void PracticeProblems(){
    system("clear");
    while(1){
    cout <<"Practice Problem Topics: "<<endl<<endl
    <<"+-------------------------------+"<<endl
    <<"| 0 : Quit Practice Problems    |"<<endl
    <<"| 1 : Truth Tables              |"<<endl
    <<"| 2 : Logical Equivalencies     |"<<endl
    <<"| 3 : Divides/Modulo            |"<<endl
    <<"| 4 : Direct Proofs             |"<<endl
    <<"| 5 : Proof by Contrapositive   |"<<endl
    <<"| 6 : Proof by Contradiction    |"<<endl
    <<"| 7 : Proof by Induction        |"<<endl
    <<"| 8 : Proof by Strong Induction |"<<endl
    <<"| 9 : Greatest Common Divisor   |"<<endl
    <<"| 10: Cipher Algorithm          |"<<endl
    <<"| 11: Extended Euclideans       |"<<endl
    <<"| 12: Fermat's Little Theorem   |"<<endl
    <<"| 13: Linear Congruences        |"<<endl
    <<"| 14: Simultanious Congruences  |"<<endl
    <<"+-------------------------------+"<<endl<<endl
    <<"Enter integer that matches what problems you want to practice: ";
    int n;
    cin >> n;
    if(n == 0){
        cout <<"Quitting Practice Problems"<<endl;
        return;
    }
    else if(n == 1){
        system("clear");
        TruthTablePractice();
    }
    else if(n == 2){
        system("clear");
        LogicalEquivPractice();
    }
    else if(n == 3){
        system("clear");
        DividesModuloPractice();
    }
    else if(n == 4){
        system("clear");
        DirectProofPractice();
    }
}
}
int main(){
    PracticeProblems();
    return 0;
}
