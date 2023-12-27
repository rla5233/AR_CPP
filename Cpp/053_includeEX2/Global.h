#pragma once

// 선언만 놔둠으로 중복을 피한다
// 이러이러한 함수가 있을거야
void TestFunction();


// 헤더에서는 전역변수의 초기화를 해선 안된다.
// 중복 선언이 될 수 있다
// extern int A = 0;

// 이러이러한 변수가 있을꺼야
extern int A;

// 구현은 cpp에서 한다.