# 코드의 기능
###  사용자로부터 입력받은 두 수의 합과 차 출력
------------------------------------------------------------
# 코드의 구성
### * main.cpp: util.cpp에 있는 함수를 사용해 코드의 진행 통제
* util.cpp
#### * enterNumber(): 사용자로부터 숫자 2개를 입력받음
* sumNumber(): 입력받은 두 수를 더해 sumStr에 저장
* subNumber(): 입력받은 두 수를 빼 subStr에 저장
* printResult(): 두 수의 합과 차를 저장한 sumStr과 subStr을 출력
------------------------------------------------------------
# 실행방법
```
git clone https://github.com/stynun/cpp-week3-bigint bigint
cd bigint
g++ -Werror -c main.cpp util.cpp
g++ -o main.exe main.o util.o
./main.exe
```