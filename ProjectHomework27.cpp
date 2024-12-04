#include <iostream>

using namespace std;

namespace First { // Анонімний простір імен
    class Automobile {
        int speed;
        int size;
    public:

        Automobile() {
            this->speed = 90;
            this->size = 2;
        }

        int GetSpeed() {
            return this->speed;
        }

        int GetSize() {
            return this->size;

        }

        void SetSpeed(int speed) {
            this->speed = speed;
        }

        void SetSize(int size) {
            this->size = size;
        }
    };
}

namespace Second {
    class Automobile {
        int speed;
        int size;
    public:

        Automobile() {
            this->speed = 90;
            this->size = 2;
        }

        Automobile(First::Automobile& other) {
            this->speed = other.GetSpeed();
            this->size = other.GetSize();
        }

        void PrintInfo() {
            cout << speed << endl;
            cout << size << endl;
        }
    };
}

using namespace First;
using namespace Second;

void main() {
    First::Automobile obj;
    Second::Automobile obj2 = Second::Automobile(obj);

    obj2.PrintInfo();
}