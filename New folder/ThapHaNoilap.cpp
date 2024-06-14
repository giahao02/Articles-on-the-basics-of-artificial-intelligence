#include<iostream>
using namespace std;

template <typename T>
void move(int disk, T start, T finish, T temp)
{
  int swap;
  while(disk > 0){
    move(disk - 1, start, temp, finish);
    cout << "Move disk " << disk << " from " << start << " to " << finish << "  ." << endl;
    disk--;
    swap = start;
    start = temp;
    temp = swap;
  }
}
 
int main()
{
  int number_disk;
  char peg1 = 'a',
       peg2 = 'b',
       peg3 = 'c';
 
  std::cout << "Input number disks : ";
  std::cin >> number_disk;
  move(number_disk, peg1, peg3, peg2);
  return 0;
}
