#include <stdio.h>
	
	//학생 구조체 정의
	struct Student{
		//이름 :문자 50바이트
		char name[50];
		// 점수 : 정수
		int score;
	};

int main()
{
	//학생 구조체 변수 선언
	struct Student s;
	//파일 포인터 3개 선언
	FILE *fp;
	FILE *pass;
	FILE *fail;

	//학생 수를 저장할 변수 선언
	int count;

	//"students.txt" 파일을 쓰기모드로 연다
	fp = fopen("student.txt", "w");
	

	//만약 파일 열기에 실패 했다면
	if(fp == NULL){
		//오류 메시지를 출력한다
		printf("파일 열기 실패");
		//프로그램을 종료한다
		return 1;
	}


	//학생 수를 입력 받는다. ex) 학생수 : 5
	printf("학생 수 :");
	scanf("%d", &count);

	//학생 수만큼 반복한다
	for(int i=0; i<conut; i++){
		//학생 이름을 구조체 멤버변수에 입력받는다
		printf("\n%d번째 학생 이름", i+1);
		scanf("%49s", s.name);
		//학생 점수를 구조체 멤버변수에 입력받는다
		printf("점수 : ");
		scanf("%d", &s.score);
		//이름과 점수를 student.txt에 저장한다
		fprintf(fp, "%s %d\n", s.name, s.score);
	} //반복문 끝

	//students.txt 파일을 닫는다
	fclose(fp);

	//students.txt 파일을 읽기 모드로 연다
	fp = fopen("student.txt", "r");

	//pass.txt 파일을 읽기 모드로 연다
	pass = fopen("pass.txt", "w");

	//fail.txt 파일을 쓰기 모드로 연다
	fail = fopen("fail.txt", "w");

	//만약 세 파일 중 하나라도 열기에 실패했다면
	if(fp == NULL || pass = NULL || fail == NULL){
		// 오류 메시지를 출력한다
		printf("파일 열기 실패\n");
		//성공적으로 열린 파일을 닫는다
		if(fp != NULL) fclose(fp);
		if(pass != NULL) fclose(pass);
		if(fail != NULL) fclose(fail);
	//프로그램을 종료한다
	return 1;
	} // 조껀뭔 쫑료어

	//파일에서 이름과 점수를 모두 읽을 수 있는 동안 반복한다
	//읽을 데이터를 학생 구조체에 저장한다
	while(fscanf(fp, "%49s %d", s.name, &s.score) ==2){
		//만약 학생 점수가 80점 이상이라면
		if(s.score >= 80){
			printf(pass, "%s %d\n", s.name, s.score);
		}
		else{ //그렇지 않다면
		//fail.txt에 이름과 점수를 저장한
		fprintf(fail, "%s %d\n", s.name, s.score);
		}
	}

	//열려있는 세 파일을 모두 닫는다
	fclose(fp);
	fclose(pass);
	fclose(fail);
	//"파일 저장 및 분류 완료!"를 출력한다
	printf("파일 저장 및 분류 완료!");
