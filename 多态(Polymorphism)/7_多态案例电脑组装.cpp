#include "iostream"
#include <string> 
using namespace std; 

//抽象CPU类
class CPU{
private:

public:
    virtual void calculate() = 0;
};

//抽象GPU类
class GPU{
private:

public:
    virtual void display() = 0;
};

//抽象Memory类
class Memory{
private:

public:
    virtual void storage() = 0;
};

class Computer{
private:
    CPU* cpu;
    GPU* gpu;
    Memory* memory;

public:
    Computer(CPU* cpu, GPU* gpu, Memory* memory){
        this->cpu = cpu;
        this->gpu = gpu;
        this->memory = memory;
    }

    void Run(){
        cpu -> calculate();
        gpu -> display();
        memory -> storage();
    }

    ~Computer(){
        if(cpu != NULL)
        {
            delete this->cpu;
            cpu = NULL;
        }

        if(gpu != NULL)
        {
            delete this->gpu;
            gpu = NULL;
        }
        
        if(memory != NULL)
        {
            delete this->memory;
            memory = NULL;
        }
    }

};

//具体厂商
//INTEL厂商
class IntelCPU : public CPU{
private:

public:
    void calculate()
    {
        cout << "Intel CPU is working... " << endl; 
    }
};

class IntelGPU : public GPU{
private:

public:
    void display()
    {
        cout << "Intel GPU is working... " << endl; 
    }
};

class IntelMemory : public Memory{
private:

public:
    void storage()
    {
        cout << "Intel memory is working... " << endl; 
    }
};


void test()
{
    CPU* cpu = new IntelCPU;
    GPU* gpu = new IntelGPU;
    IntelMemory* memory = new IntelMemory;
    Computer* computer = new Computer(cpu, gpu, memory);
    computer->Run();
    
    delete computer; 
}

int main(){
    test();
    return 0;
}