/*
ID: dhm_blo2
PROG: preface
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
const int N=3500+1;
string roman[N];
map<int,string> dic;
map<string,int> counter;
string num[]={"I","V","X","L","C","D","M"};
void init(){
  dic[1]="I";dic[2]="II";dic[3]="III";dic[4]="IV";dic[5]="V";dic[6]="VI";dic[7]="VII";dic[8]="VIII";dic[9]="IX";
  dic[10]="X";dic[20]="XX";dic[30]="XXX";dic[40]="XL";dic[50]="L";dic[60]="LX";dic[70]="LXX";dic[80]="LXXX";dic[90]="XC";
  dic[100]="C";dic[200]="CC";dic[300]="CCC";dic[400]="CD";dic[500]="D";dic[600]="DC";dic[700]="DCC";dic[800]="DCCC";dic[900]="CM";
  dic[1000]="M";dic[2000]="MM";dic[3000]="MMM";
}
void change_number_to_roman(int n){
  int i=1;
  string ans="";
  while(n>0){
    int cur=n%10;
    cur*=i;
    ans+=dic[cur];
    i*=10;
    n/=10;
  }
  
  for(int j=0;j<ans.size();j++){
    string index="";
    index+=ans[j];
    counter[index]++;
  }
}
int main(){
  int n;
  fin>>n;
  init();
  for(int i=1;i<=n;i++){
    change_number_to_roman(i);
  }
  for(int i=0;i<7;i++)
    if(counter[num[i]]!=0)
      fout<<num[i]<<" "<<counter[num[i]]<<endl;
  return 0;
}
