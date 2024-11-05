// Problem Link: https://leetcode.com/problems/maximum-swap/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "Enter a number: \n";
    int num;
    cin >> num;
    string str = to_string(num);
    int digits[str.length()] = {0};

    int length = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c >= '0' && c <= '9') {
            digits[i] = c - 48;
        }
    }

   

    int start_index = str.length() - 1;
    int min_index = 0;
    int max = -1;
    int maxIndex = str.length() - 1;
    bool isSwapable = false;

    while (start_index > -1) 
    {
        for (int i = start_index; i > (min_index -1); i--) 
        {
            if (digits[i] > max)
            {
                max = digits[i];
                maxIndex = i;
            }
        }

        if (max != digits[min_index])
        {
            isSwapable = true;
            int temp = digits[min_index];
            digits[min_index] = max;
            digits[maxIndex] = temp;
            break;
        }
        else
        {
            if (maxIndex == 0) {
                min_index++;
            } else {
                start_index--;
            }
        }
    }
    
    
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        result += to_string(digits[i]);
    }

    cout << "Output:" << endl;
    cout << result;
    
    


    return 0;
}
