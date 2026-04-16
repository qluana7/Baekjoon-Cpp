# Baekjoon-Cpp

백준 C++ 도전기

---

백준 서비스 종료에 대해 매우 안타갑게 생각합니다.
그동안 백준을 서비스 해주신 최백준님 너무 감사드리고, 난이도 체계 서비스 제공해주신 shiftpsh께도 감사드리고 싶네요.

이 레포는 백준 문제 풀이용으로 제작되긴 하였으나, 차후 [정올](jungol.ac.kr)나 다른 사이트를 이용하여 지속될 예정입니다.

또한, atcoder는 매주 하고 있기 때문에, 특별한 일이 없다면 Contest 폴더도 지속적으로 업데이트 될 예정입니다.

그동안 백준 풀면서 재밌었고 많은걸 얻어갈 수 있었던것 같네요. 다시 한번 지금까지 서비스 운영해주신 두분께 감사드립니다.

---

## Directories
<h4> 156 : 156/0 (memory 156kb, time 0ms)를 위한 라이브러리 제작 프로젝트</h4>

<h4>Algorithm : 알고리즘 구현체 모음</h4>

<details>
<summary>알고리즘 구현 리스트</summary>

| Category | Algorithm | Description |
|----------|------------|-------------|
| **Math** | [FFT](Algorithm/math/FFT.cpp) | 고속 푸리에 변환 알고리즘 |
|          | [MillerRabin](Algorithm/math/MillerRabin.cpp) | 밀러-라빈 소수 판별법 |
|          | [PollardRho](Algorithm/math/PollardRho.cpp) | 폴라드 로 소인수 분해 알고리즘 |
|          | [modulo](Algorithm/math/modulo.cpp) | 모듈로 연산 알고리즘 집합 |
|          |            |             |
| **String** | [KMP](Algorithm/string/KMP.cpp) | KMP 문자열 검색 알고리즘 |
|            | [Manacher](Algorithm/string/Manacher.cpp) | Manacher의 팰린드롬 알고리즘 |
|            |            |             |
| **DP** | [LCS](Algorithm/dp/LCS.cpp) | 최장 공통 부분 수열 알고리즘 |
|        |            |             |
| **Graph** | [DFS_BFS](Algorithm/graph/DFS_BFS.cpp) | 깊이 우선 탐색 및 너비 우선 탐색 |
|           | [Dijkstra](Algorithm/graph/Dijkstra.cpp) | 다익스트라 최단 경로 알고리즘 |
|           | [TopologySort](Algorithm/graph/TopologySort.cpp) | 위상 정렬 알고리즘 |
|           | [MST](Algorithm/graph/MST.cpp) | 최소 신장 트리 알고리즘 |
|           |            |             |
| **Tree** | [FenwickTree](Algorithm/tree/FenwickTree.cpp) | 펜윅 트리 |
|          | [SegmentTree](Algorithm/tree/SegmentTree.cpp) | 세그먼트 트리 |
|          | [Trie](Algorithm/tree/Trie.cpp) | 트라이 자료구조 |
|          |            |             |
| **Geometry** | [ConvexHull](Algorithm/geometry/ConvexHull.cpp) | 볼록 껍질 알고리즘 |
|              | [line-intersection](Algorithm/geometry/line-intersection.cpp) | 선분 교차 판정 알고리즘 |
|              |            |             |
| **struct** | [pmint](Algorithm/struct/pmint.cpp) | 소수 p & 나머지 연산 기반 정수 타입 |
|          |            |            |
| **Misc** | [Mos](Algorithm/misc/Mos.cpp) | Mo's 알고리즘 |

</details>

<h4>Bronze ~ Ruby : 티어별 문제풀이 소스파일</h4>

## 달성 날짜 기록

| Achievement | Date |
|-------------|------|
| <div style="display: flex; align-items: center;"><img src="https://static.solved.ac/tier_small/16.svg" height=32 alt="Platinum V"/> <span style="margin-left: 8px; font-weight: bold;">달성</span></div> | 2022/06/04 01:15:38 |
| <div style="display: flex; align-items: center;"><img src="https://solved.ac/_next/image?url=https%3A%2F%2Fstatic.solved.ac%2Fprofile_badge%2F120x120%2Fsolves_00500.png%3F&w=32&q=75" height=32 alt="500 Solve"/> <span style="margin-left: 8px; font-weight: bold;">달성</span></div> | 2022/06/17 21:21:09 |
| <div style="display: flex; align-items: center;"><img src="https://static.solved.ac/class/c5.svg" height=32 alt="Class 5"/> <span style="margin-left: 8px; font-weight: bold;">달성</span></div> | 2022/08/25 09:44:40 |
| <div style="display: flex; align-items: center;"><img src="https://static.solved.ac/class/c6.svg" height=32 alt="Class 6"/> <span style="margin-left: 8px; font-weight: bold;">달성</span></div> | 2024/09/30 23:00:06 |
| <div style="display: flex; align-items: center;"><img src="https://static.solved.ac/tier_small/11.svg" height=32 alt="Gold"/> <span style="margin-left: 8px; font-weight: bold;">청소</span></div> | 2024/09/30 23:16:00 |
| <div style="display: flex; align-items: center;"><img src="https://static.solved.ac/tier_small/21.svg" height=32 alt="Diamond V"/> <span style="margin-left: 8px; margin-right: 6px; font-size: 16pt; font-weight: bold;"> / </span> <img src="https://solved.ac/_next/image?url=https%3A%2F%2Fstatic.solved.ac%2Fprofile_badge%2F120x120%2Fsolves_01000.png%3F&w=32&q=75" height=32 alt="1000 Solve"/> <span style="margin-left: 8px; font-weight: bold;">달성</span></div> | 2024/10/03 16:36:50 |
| <div style="display: flex; align-items: center;"><img src="https://solved.ac/_next/image?url=https%3A%2F%2Fstatic.solved.ac%2Fprofile_badge%2F120x120%2Fsolves_02000.png%3F&w=32&q=75" height=32 alt="2000 Solve"/> <span style="margin-left: 8px; font-weight: bold;">달성</span></div> | 2025/11/21 18:52:19 |

## Status
[![LSolveRank1](https://github-readme-solvedac-hyp3rflow.vercel.app/api/?handle=lukince)](https://solved.ac/profile/lukince)

[![LSolveRank2](http://mazassumnida.wtf/api/v2/generate_badge?boj=lukince)](https://solved.ac/profile/lukince)

**주의 : 상당히 난해한 코드가 존재할 수 있음.**
