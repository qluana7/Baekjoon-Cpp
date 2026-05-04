/*

문제 :
주어진 N에 대해 1 ≤ i < j ≤ N를 만족할 때
아래 조건을 만족하는 수열 찾기.

조건 1 : Ai ≠ Aj
조건 2 : P ∤ Q { P = Ai + Aj, Q = Ai * Aj }


풀이 :
홀수인 배열을 출력하기.


증명 :

어떤 수 Ai와 Aj에 대해 다음과 같은 식을 세우고
Ai = 2A + 1
Aj = 2B + 1

Ai + Aj와 Ai * Aj일때, 각각의 식을 정리하면
Ai + Aj = 2(A + B + 1)
Ai * Aj = (2A+1)(2B+1) = 4AB + 2(A+B) + 1

2(A+B+1) = 짝수
4AB + 2(A+B) + 1 = 홀수

짝수는 분해했을 때, 2를 소인수로 갖는 반면, 홀수는 불가능하므로,
짝수는 홀수의 약수가 될 수 없다.
* 반대의 경우엔 가능할 수 있음.

따라서, 어떤 A, B를 선택해도 조건 2를 만족시킬 수 있다.

결과적으로 조건 1을 만족하는 "홀수" 배열을 출력하여 이를 해결할 수 있음.

가장 간단한 홀수 배열의 형태인, Ai = i * 2 - 1의 형태를 이용.

∴ Answer = [1, 3, 5, 7, 9, ...]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
        cout << i * 2 + 1 << " ";
}