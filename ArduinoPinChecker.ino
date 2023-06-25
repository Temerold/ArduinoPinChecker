// Config
int delayMilliseconds = 3000;

typedef struct
{
    const char *name;
    uint8_t *value;
} pinArray;

const pinArray analogPins[] = {
    {"A0", A0},
    {"A1", A1},
    {"A2", A2},
    {"A3", A3},
    {"A4", A4},
    {"A5", A5}};

const pinArray digitalPins[] = {
    {"0", 0},
    {"1", 1},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"11", 11},
    {"12", 12},
    {"13", 13}};

void setup()
{
    Serial.begin(9600);
}

template <typename Func>
void printData(const pinArray *pins, size_t size, Func function)
{
    // Serial.print(">>");
    // Serial.println(digitalRead(3));
    for (size_t i = 0; i < size; i++)
    {
        Serial.print(pins[i].name);
        Serial.print(": ");
        Serial.print(function(pins[i].value));
        Serial.println();
    }
}

void loop()
{
    for (int i = 0; i < 10; i++)
    {
        Serial.print("-");
    }
    Serial.println();
    printData(analogPins, sizeof(analogPins) / sizeof(pinArray), analogRead);
    printData(digitalPins, sizeof(digitalPins) / sizeof(pinArray), digitalRead);
    delay(delayMilliseconds);
}
