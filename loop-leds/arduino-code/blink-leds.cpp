
int loop_count = 0;
const int INITIAL_BLINK_LIMIT = 5;
const int TOTAL_LOOP_COUNT = 10;
const int LOOP_DELAY_MS = 1000; 
const int LEED_SWITCH_DELAY_MS = 50;

void setup()
{
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // Loop continue, but the code below
    // this statement is not executed
    if (loop_count == TOTAL_LOOP_COUNT)
    {
        return;
    }

    delay(LOOP_DELAY_MS);
    loop_count++;

    if (loop_count <= INITIAL_BLINK_LIMIT)
    {
        digitalWrite(13, HIGH);
        delay(LEED_SWITCH_DELAY_MS);
        digitalWrite(13, LOW);
    }

    // Initial blink end information
    if (loop_count == INITIAL_BLINK_LIMIT + 1)
    {
        Serial.print("End initial \"");
        Serial.print(INITIAL_BLINK_LIMIT);
        Serial.println("\" blinks");
    }

    Serial.print("V: ");
    Serial.println(loop_count);

    if (loop_count == TOTAL_LOOP_COUNT)
    {
        Serial.println("End of loop");
    }
}