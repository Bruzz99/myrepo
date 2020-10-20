///
/// NOTE On Desktop systems, compile with -D NO_PI flag
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>

#ifndef NO_PI
#include <wiringPi.h>
#endif

using namespace std;

///
/// Configuration
///
const int red = 0;
const int yellow = 2;
const int green = 3;
const int timeoutMs = 1000; //1 second 
const int time1S = 10; // 5 second
const int time2S = 10; // 5 second
const int time3S = 5; // 3 second
unsigned int count = 0;

///
/// Utils
///
void init()
{
#ifndef NO_PI
    wiringPiSetup();
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
#endif
}

void setLed(int ledNumber, bool value)
{
#ifndef NO_PI
    digitalWrite(ledNumber, value);
#else
    cout << "Setting led " << ledNumber << " to " << (value ? "ON" : "OFF") << endl;
#endif
}

int main()
{
    init();

    // Ok, inited. Now do your work...
    //bool = onoff = true;
    while(1)
    {   

        while(count < time1S )       // status red on
        {
       	
        setLed(red, true);
        
        count++; 
    #ifndef NO_PI
        delay(timeoutMs);
    #else
        usleep(timeoutMs * 1000);
    #endif
        } 

    count = 0;
    setLed(red, false);


        while(count < time2S )       //status green on
        {
       	
        setLed(green, true);
       

        count++; 
    #ifndef NO_PI
        delay(timeoutMs);
    #else
        usleep(timeoutMs * 1000);
    #endif
        } 

    count = 0;
    setLed(green, false);



        while(count < time3S )       //status yellow on
        {
       	
        setLed(yellow, true);
        

        count++; 
    #ifndef NO_PI
        delay(timeoutMs);
    #else
        usleep(timeoutMs * 1000);
    #endif
        } 


    count = 0;
    setLed(yellow, false);
    
    }   //main loop

return 0;

}
