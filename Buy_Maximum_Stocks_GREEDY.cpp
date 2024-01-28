/*
In a stock market, there is a product with its infinite stocks. The stock prices are given for N days,
 where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day.
  If the customer has k amount of money initially, find out the maximum number of stocks a customer can buy. 
For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.
*/

/*
Input : price[] = { 10, 7, 19 }, 
              k = 45.
Output : 4
A customer purchases 1 stock on day 1 for 10 rs, 
2 stocks on day 2 for 7 rs each and 1 stock on day 3 for 19 rs.Therefore total of
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 }, 
               k = 100.
Output : 6
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
 int main()
 {
     int n;
     cin>>n;
      vector<int>a(n);
      for (int i=0;i<n;i++)
      cin>>a[i];
      int p;
      cin>>p;
      int now=p;
      vector<pair<int,int> >t;//vector of pairs
      for (int i=0;i<n;i++)
      {
          t.push_back(make_pair(a[i],i+1));
      }
      sort(t.begin(),t.end());//sort acc to their price in ascending order 
      int item=0;
       for (int i=0;i<n;i++)
      {
          if(p<0)
          break;//money exhausted
         if(t[i].first*t[i].second<=p)
         {
            p=p-t[i].first*t[i].second;
           item=item+t[i].second;
         }
         else//do not have enough money to buy
         {
           while(p>=t[i].first)
           {
               p=p-t[i].first; 
               item++;//no. of items
           }
         }
      }
      cout<<"items : "<<item<<" price  :"<<now-p<<endl;
 }