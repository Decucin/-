#pragma once

#define	RANGE	10
typedef	int	directiveType;

typedef	struct {
	int r, c;
}PosType;

typedef	struct {
	int r, c;
	int	arr[RANGE][RANGE];
}MazeType;

typedef struct {
	int step;				//��ǰλ����·���ϵ����
	PosType seat;			//��ǰ������λ��
	directiveType	di;		//����һ����λ�õķ���
}MSElemType;				//ջ��Ԫ������

typedef	struct NodeType {
	MSElemType	data;
	NodeType* next;
}NodeType, * LinkType;		//������ͣ�ָ������

typedef struct {
	LinkType top;
	int	size;
}MazeStack;					//ջ����

void InitMazeStack(MazeStack*);
bool MazeStackEmpty(MazeStack*);
void Push(MazeStack*, MSElemType);
void Pop(MazeStack*, MSElemType*);

void InitMazeStack(MazeStack* S) {
	S->top = NULL;
	S->size = 0;
	return;
}

bool MazeStackEmpty(MazeStack* S) {
	if (S->top == NULL)
		return true;
	return false;
}

void Push(MazeStack* S, MSElemType e) {
	LinkType p = (LinkType)malloc(sizeof(NodeType));
	if (p == NULL)
		exit(OVERFLOW);
	p->data = e;
	p->next = S->top;
	S->top = p;
	S->size++;
	return;
}

void Pop(MazeStack* S, MSElemType *e) {
	LinkType p = (LinkType)malloc(sizeof(NodeType));
	if (S->top == NULL)
		exit(1);
	//e = S->top->data;
	p = S->top;
	*e = p->data;
	S->top = S->top->next;
	free(p);
	S->size--;
	return;
}