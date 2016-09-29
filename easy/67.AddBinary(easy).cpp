/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
            string c;
            int flag=0;
            int lena = a.size();
            int lenb = b.size();
            int len = abs(lena-lenb);
            string append(len,'0');
            if(lena>lenb){
                b = append + b;
                c.resize(lena,'0');
            }else{
                a = append + a;
                c.resize(lenb,'0');  
            }
            for(int j=c.size()-1;j>=0;j--){
                int current = (a[j]-'0') ^(b[j]-'0') ^flag;
                if((a[j]-'0') +(b[j]-'0') +flag >1)
                    flag = 1;
                else
                    flag = 0;
                c[j] = current+'0';
            }
            if(flag == 1)
                c = '1'+ c;

            return c;

    }
};
