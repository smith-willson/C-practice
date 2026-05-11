#include <iostream>
using namespace std;

class Worker {
public:
    void work() {
        cout << "Working as an employee\n";
    }
};

class Freelancer {
public:
    void work() {
        cout << "Working independently\n";
    }
};

class HybridWorker : public Worker, public Freelancer {};
//Solving it as scope resolution.........

// int main() {
//     HybridWorker h;
//     h.Worker::work();
//     h.Freelancer::work();
// }

class HybridWorker : public Worker, public Freelancer {
public:
    void work() {
        cout << "Working both ways\n";
    }
};

int main() {
    HybridWorker h;
    h.work();
}