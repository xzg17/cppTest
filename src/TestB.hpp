class Test_Class{
public:
    Test_Class();
    Test_Class(int num);
    int num;
};
Test_Class::Test_Class(){
    this->num = 0;
};
Test_Class::Test_Class(int num){
    this->num = num;
};
