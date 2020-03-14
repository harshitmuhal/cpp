#include<stdio.h>
#include<string.h>
#define maxsize 100
struct stack{
    int top;
    int arr[maxsize];
};
void initialise(struct stack *s){
    s->top=-1;
}
int isempty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isfull(struct stack *s){
    if(s->top==(maxsize-1)){
        return 1;
    }
    return 0;
}
void push(struct stack *s,int data){
    if(isfull(s)){
        printf("overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}
void pop(struct stack *s){
    if(isempty(s)){
        printf("underflow\n");
    }
    else
        s->top--;
}
int gettop(struct stack s){
    return s.arr[s.top];
}

void display(struct stack s){
    while(!isempty(&s)){
        char x=gettop(s);
        pop(&s);
        printf("%c ",x);
    }
    printf("\n");
}
int prec(char ch){
    switch (ch) {
        case '$':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return -1;
    }
}
void intopos(char infix[100],char postfix[100]){
    struct stack op;
    int p=0;int i;
    initialise(&op);
    for(i=0;infix[i]!='\0';i++){
        if(isalpha(infix[i])){
            postfix[p]=infix[i];
            p++;
        }
        else if(infix[i]=='('){
            push(&op,'(');
        }
        else if(infix[i]==')'){
            while(!isempty(&op) && gettop(op)!='('){
                char ch=gettop(op);
                postfix[p]=ch;
                p++;
                pop(&op);
                //ch=gettop(op);
            }
            if(gettop(op)=='('){
                pop(&op);
            }
        }
        else{
            while((prec(infix[i])<=prec(gettop(op))) && !isempty(&op)){
                char ch=gettop(op);
                postfix[p]=ch;
                p++;
                pop(&op);
            }
            push(&op,infix[i]);
        }
        //display(op);
    }
    while(!isempty(&op)){
        char ch=gettop(op);
        postfix[p]=ch;
        p++;
        pop(&op);
    }
}
int main(){
    //struct stack s;
    char infix[100]="A$B*C-D+E/F/(G+H)";
    char postfix[100];
    intopos(infix,postfix);
    puts(postfix);
    return 0;
}