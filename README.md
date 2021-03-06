## 목적
본 프로젝트의 목적은 CCTV를 통해 범죄에 이용된 차량의 번호판을 조회하는 시스템을 OPEN CV로 구현하는 것이다.

### 설명
사용자가 지정한 Mouse의 시작점과 끝점의 x,y좌표를 고려하여 사각형 영역을 생성한다. 사용자로부터 'S'키를 입력 받아 확대된 번호판 이미지를 저장한다. 

###### C언어로 구축  
: 수동으로 메모리를 관리해야하므로, 개발자가 메모리 할당 및 해제를 담당해야한다. 코드의 규모가 커지면 메모리 관리가 어려워진다는 점이 있다.  
###### C++언어로 구축   
: 메모리 해제가 자동으로 호출되므로 사용자가 포인터를 관리할 필요가 없으며, 생성자 소멸자 기능을 사용해 메모리를 자동으로 관리할 수 있다. 동적 메모리 관리에 신경쓰지 않아도 된다는 장점이 있다. 

***
### 결과
![image](https://user-images.githubusercontent.com/76280200/148173530-8846f5fb-d39c-4b1c-8399-067d0ae55b3d.png)
***
#### 이미지 출처
(여러 차의 번호판 이미지를 구하기 어려워 유튜브 번호판 소개 영상의 이미지를 토대로 영상을 작동시켰습니다.)

개인프로젝트
(2021.01.07)
