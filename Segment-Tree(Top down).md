구간의 대표 값(합, 최대, 최소, GDC 등)을 Top down 방식으로 구함

이진트리로 구현

루트가 전체 범위에 대한 대표 값을 가지고 자식들이 범위를 반씩 나누어 대표 값을 저장

부모의 범위를 반씩 나누어 자식들이 해당 범위의 대표 값을 저장

Leaf노드의 Index번호를 따로 구해야 함

범위를 반씩 나누어 가지기 때문에 Leaf노드의 Index번호가 어떻게 나올지 모름

Index 구해서 따로 index저장 배열에 저장해야 함
