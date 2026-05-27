class Solution {
public:
    string intToRoman(int num) {

        static string thousands[] = {"", "M", "MM", "MMM"};
        static string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return thousands[num/1000] +
               hundreds[(num%1000)/100] +
               tens[(num%100)/10] +
               ones[num%10];
    }
};
