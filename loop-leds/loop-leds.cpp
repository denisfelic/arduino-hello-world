#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int loop_count = 0;

void setup()
{
    cout << "Setup" << endl;
}

void loop()
{
    if (loop_count < 5)
    {
        delay(1000);
        cout << "Loop: Int value: " << loop_count << endl;
    }

    loop_count++;
}

int main()
{
    cout << "Program started" << endl
         << flush;
    setup();

    cout << "Loop starts" << endl;
    while (true)
    {
        loop();
    }

    return 0;
}
