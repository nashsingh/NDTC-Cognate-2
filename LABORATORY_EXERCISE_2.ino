
#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys [ROWS] [COLS] = {
  {'1','2','3', '+'},
  {'4','5','6', '-'},
  {'7','8','9', '*'},
  {'C','0','=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Adafruit_LiquidCrystal lcd_1(0);

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer = 0;
char op;


void setup(){
    lcd_1.begin(16, 2);
}

void loop(){
  char key = myKeypad.getKey();

  if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
  {
    if (presentValue != true)
    {
      num1 = num1 + key;
      int numLength = num1.length();
      lcd_1.setCursor(0, 0); 
      lcd_1.print(num1);
    }
    else
    {
      num2 = num2 + key;
      int numLength = num2.length();
      int numLength1 = num1.length();
      lcd_1.setCursor(1 + numLength1, 0);
      lcd_1.print(num2);
      final = true;
    }
  }

  else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+'))
  {
    if (presentValue == false)
    {
      int numLength = num1.length();
      presentValue = true;
      op = key;
      lcd_1.setCursor(0 + numLength, 0);
      lcd_1.print(op);
    }
  }

  else if (final == true && key != NO_KEY && key == '=') {
      
    if (op == '+') {
      answer = num1.toInt() + num2.toInt();
    }
    else if (op == '-') {
      answer = num1.toInt() - num2.toInt();
    }
    else if (op == '*') {
      answer = num1.toInt() * num2.toInt();
    }
    else if (op == '/') {
      answer = num1.toInt() / num2.toInt();
    }
    lcd_1.clear();
    lcd_1.setCursor(16, 1);
    lcd_1.autoscroll();
    lcd_1.print(answer);
    lcd_1.noAutoscroll();
    
  }
  else if (key != NO_KEY && key == 'C') {
    lcd_1.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
  }
}
