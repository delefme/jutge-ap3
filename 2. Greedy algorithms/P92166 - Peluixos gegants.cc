/*
  ________________________
 / \                      \
 \_|        P92166        |
   |                      |
   |      Tomas Gadea     |
   |   ___________________|__
    \_/_____________________/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Returns the optimum price to pay when, from a set of 3n products, we are allowed to take a 3x2 offer, i.e. for every 3 products, the least expensive it's free.

Greedy Algo:

    1- Sort prices in decreasing order.
    2- Slice the vector by grouping 3 prices at a time, from first element to last.
    3- Reject the third element of every group created previously, as it will be the least expensive of the three, and add up the rest of the prices. Do this for each group and it will add up to the minimum price.

Graphical representation:

    prices:   42 23 17 23 42 100 100 100 1
    sorted:   100 100 100 42 42 23 23 17 1
    grouping: 100 100 100 | 42 42 23 | 23 17 1
    reject:   ✅  ✅  ❌   ✅ ✅ ❌  ✅ ✅ ❌
    Add up:       200     +    84    +   40     =   324
*/
int optimum_price(vector<int>& prices, int n) {
  sort(prices.begin(), prices.end(), greater<int>());

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    for(int j = 0; j < 2; ++j) {
      sum += prices[3*i + j];
    }
  }

  return sum;
}

int main() {
  int n;
  /* consider multiple input cases */
  while (cin >> n) {
    vector<int> prices;
    /* read up to 3n prices */
    for (int i = 0; i < 3*n; ++i) {
      int price;
      cin >> price;
      prices.push_back(price);
    }
    cout << optimum_price(prices, n) << endl;
  }
}
