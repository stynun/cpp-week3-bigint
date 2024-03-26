#include <iostream>
#include <string>
#include <cstring>

std::string n1, n2, tmpStr, sumStr, subStr;
int lensub;
bool change = false;

void enterNumber() {
    std::cout << "First number  >> ";
    getline(std::cin, n1);

    std::cout << "Second number >> ";
    getline(std::cin, n2);

    lensub = n1.length() - n2.length();
    
    if (lensub == 0) {
        for (int i = 0; i < n1.length(); i++) {
            if (n1[i] -'0' < n2[i] -'0') {
                tmpStr.append(n1);
                n1.clear();
                n1.append(n2);
                n2.clear();
                n2.append(tmpStr);
                change = true;
                break;
            }
        }

        n1.insert(0, "0");
        n2.insert(0, "0");
        for (int i = 0; i < n2.length(); i++) {
            sumStr.insert(0, "0");
            subStr.insert(0, "0");

        }
    }  
    else {
        if (lensub < 0) {
            tmpStr.append(n1);
            n1.clear();
            n1.append(n2);
            n2.clear();
            n2.append(tmpStr);
        }

        int times = n1.length() - n2.length();
        for (int i = 0; i <= times; i++) {
            n2.insert(0, "0");
        }
        n1.insert(0, "0");
        for (int i = 0; i < n1.length(); i++) {
            sumStr.insert(0, "0");
            subStr.insert(0, "0");

        }
    }
}

void sumNumber() {
    int tmp1, tmp2, tmp3, tmp4, tmp5, sum = 1;
    for (int i = sumStr.length() - 1; i >= 1; i--) {
        tmp1 = n1[i] -'0';
        tmp2 = n2[i] -'0';
        tmp3 = sumStr[i] - '0';
        sum = tmp1 + tmp2;
        tmp4 = (tmp3 + sum) / 10;
        tmp5 = (tmp3 + sum) % 10;
        
        sumStr[i - 1] = tmp4 + '0';
        sumStr[i] = tmp5 + '0';
    }

    if (sumStr[0] == '0')
        sumStr.erase(0, 1);
}

void subNumber() {
    int tmp1, tmp2, tmp3, sub;
    for (int i = subStr.length() - 1; i >= 0; i--) {
        tmp1 = n1[i] - '0';
        tmp2 = n2[i] - '0';
        tmp3 = n1[i - 1] - '0';
        sub = tmp1 - tmp2;
        if (sub < 0) {
            n1[i - 1] = (tmp3 - 1) + '0';
            sub += 10;
        }

        subStr[i] = sub + '0';
    }

    int j = subStr.length() - 1;
    while (j != 0) {
        if (subStr[0] == '0') 
            subStr.erase(0, 1);
        j--;
    }

    if (lensub < 0 || change)
        subStr.insert(0, "-");
}

void printResult() {
    std::cout << "Sum           >> ";
    for (int i = 0; i < sumStr.length(); i++) {
        std::cout << sumStr[i];
    }  
    std::cout << std::endl;

    std::cout << "Sub           >> ";
    for (int i = 0; i < subStr.length(); i++) {
        std::cout << subStr[i];
    }  
    std::cout << std::endl;
}
