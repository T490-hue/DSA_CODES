#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Sample sorted vector
    vector<int> arr = {1, 2, 4, 4, 5, 6, 7, 9};

    int x = 4;

    // auto lower=lower_bound(arr.begin(),arr.end(),x);
    // cout<<"lower bound is located at index "<<(lower-arr.begin())<<"and value is "<<*lower<<endl;

        auto upper=upper_bound(arr.begin(),arr.end(),x);
    cout<<"upper bound is located at index "<<(upper-arr.begin())<<"and value is "<<*upper<<endl;

    return 0;
}
