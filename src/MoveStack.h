class MoveStack{
private:
    int top;
    //int stack[200];
public:
    void MoveStack();
    void push(int x);
    int pop();   
};
//*
void MoveStack::MoveStack(){
    this->top=-1;
};

void MoveStack::push(int x){
    this->top++;
    this->stack[this->top]=x;
};

int MoveStack::pop(){
    int x = this->stack[this->top];
    this->top--;
    return x;
};
//*/
