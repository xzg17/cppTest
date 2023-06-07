class MoveStack{
public:
    MoveStack();
    void push(int x);
    int pop();
private:
    int top;
    int stack[200]; 
};
/*
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
