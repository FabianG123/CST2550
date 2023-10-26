#include <vector>
#include <iostream>

int main(){
  std::vector<int> nums = {1,2,3,4,5};
  std::cout<<"nums vector contains: \n";
  for (int i=0; i<nums.size(); ++i)
    std::cout <<nums[i] <<'\n';

}
