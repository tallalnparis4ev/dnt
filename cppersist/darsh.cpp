#include "local.hpp"
#include "other.cpp"
#include <iostream>
//Fibonacci Sequence Example
class FibonacciSolver: public PersistentMemoizable<int, int>{
  public:
    int solve(int n) override {
      std::cout << "Original" << std::endl;
      if(n==0) return 0;
      if(n==1) return 1;
      return solve(n-1) + solve(n-2);
    }
};

int strtoi(string x){
  return std::stoi(x);
}
string intostr(int x){
  return std::to_string(x);
}

string keymaker(int x){
  return std::to_string(x);
}
#include <thread>         // std::this_thread::sleep_for
#include <chrono> 
using namespace std;
int main(){
  PersistentMemoized memoizedFib = getLocalMemoizedObj<FibonacciSolver>(keymaker,intostr,strtoi,"fib");
  PersistentMemoized memoizedFib2 = getLocalMemoizedObj<different::FibonacciSolver2>(keymaker,intostr,strtoi,"fib");
  int z = memoizedFib(3);
  std::cout << z << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  z = memoizedFib2(3);
  std::cout << z << std::endl;
}