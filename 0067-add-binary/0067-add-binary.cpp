class Solution {
public:
    string addBinary(string a, string b) {
        string sum="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0||j>=0||carry==1)
        {
            if(i>=0)
            {
                carry=carry+(a[i]-'0');
                i--;
            }
            if(j>=0)
            {
                carry=carry+(b[j]-'0');
                j--;
            }
            sum=to_string(carry%2)+sum;
            carry=carry/2;
        }
        return sum;
    }
};