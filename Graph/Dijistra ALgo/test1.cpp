#include <bits/stdc++.h>
using namespace std;
// int main(){
// // {string a="ab";
// // unordered_map <string,vector<vector<variant<string,int>>>> test;
// // vector<variant<string,int>> vec;
// // vec.push_back('a');
// // vec.push_back(1);
// // vec.push_back(2);
// // test[a].push_back(vec);
// // // for (string  i:test[a].begin())
// // // {
// // auto j=test.at(a);
// // for ( auto  f : test[a]) 
// // {   
// //      auto nn=f[1];
// //      int llll=get<int>(nn);
// //      cout<<llll+1;
// //      if (holds_alternative<string>(nn))
// // {   string k=string(get<string>(nn));
// //     cout<<k;}
// //      else {
// //         //   int h=get<int>(nn);
// //         //   char mnb=(char) h;
// //         //   string hh=string(mnb);
// //         //   cout << hh << " ";
// //         }
// // //     for (const auto& inner_vec : f) {
// // //          if (holds_alternative<string>(inner_vec))
// // //        { string h=get<string>(inner_vec);
// // //         cout<<h;}
// // //         if (holds_alternative<string>(inner_vec)) {
// // //           cout << get<string>(inner_vec) << " ";
// // //         } else {
          
// // //           cout << get<int>(inner_vec) << " ";
// // //         }
// // //       }
// // //       cout << endl;
    
// // // } 

// // //   return 0;
// // // }
// //  string fgg="107";
// //  char bhbh=(char) (fgg);
// // }
// // unordered_map <string,list<pair<string,int>>> uza;
// // uza['aa'].push_back(make_pair('dddd',1));

// }
int main()
{
    unordered_map <string,list<pair<string,int>>> uza;
    uza["aa"].push_back(make_pair("dddd",1));
    auto  p=uza["aa"];
    auto it = p.begin();
    // advance(it, 1);
    auto pp=*it;
    cout<<pp.second;
    return 0;
}