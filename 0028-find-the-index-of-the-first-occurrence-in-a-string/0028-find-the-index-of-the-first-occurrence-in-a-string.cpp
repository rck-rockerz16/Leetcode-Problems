class Solution {
public:
    int strStr(string haystack, string needle) {
        int sizeOfHaystack = haystack.size();
        int sizeOfNeedle = needle.size();

        if (sizeOfNeedle == 0)
            return 0;

        if (sizeOfNeedle > sizeOfHaystack)
            return -1;

        int n = sizeOfHaystack - sizeOfNeedle;
        for (int baseptr = 0; baseptr <= n; baseptr++) {
            int fwdptr = 0;
            while (fwdptr < sizeOfNeedle &&
                   haystack[baseptr + fwdptr] == needle[fwdptr]) {
                fwdptr++;
            }
            if (fwdptr == sizeOfNeedle)
                return baseptr;
        }
        return -1;
    }
};