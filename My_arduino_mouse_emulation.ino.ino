# include <Mouse.h>

int horzPin = A1;                                                                                 
int vertPin = A0;                                                                          
int selPin = 9;                                                                            
int leftButton = 3;
int rightButton = 2;
int leftFlag = 0;

int vertZero, horzZero;                                                                     
int vertValue, horzValue;                                                                 
const int sensitivity = 400;                                                                     

void setup()
{
  Serial.begin(9600);
  
  pinMode(horzPin, INPUT);                                                                      
  pinMode(vertPin, INPUT);
  pinMode(selPin, INPUT); 
  pinMode(leftButton, INPUT); 
  pinMode(rightButton, INPUT);  
  
  digitalWrite(leftButton, HIGH);
  digitalWrite(selPin, HIGH);

  
                                                                    
  delay(1000); 
                                                                                     
  vertZero = analogRead(vertPin);                                                                
  horzZero = analogRead(horzPin);                                                                 

  Mouse.begin();
}

void loop()
{
  vertValue = analogRead(vertPin) - vertZero;                                                     
  horzValue = analogRead(horzPin) - horzZero;                                                    


  if (vertValue != 0)
    Mouse.move(0, vertValue/sensitivity, 0);                                                     
  if (horzValue != 0)
    Mouse.move((horzValue/sensitivity)*1, 0, 0);                                       

// joystick button

  if ((digitalRead(leftButton) == 1) && (!leftFlag))  
  {
    leftFlag = 1;
    Mouse.press(MOUSE_LEFT); 
    delay(150);  
  }
  else if ((digitalRead(leftButton)) && (leftFlag)) 
  {
    leftFlag = 0;
    Mouse.release(MOUSE_LEFT); 
    delay(150);  
  }
  
// left/right buttons

   if (digitalRead(selPin) == LOW)                               
  {
    Mouse.click(MOUSE_LEFT);  
    delay(150);                                                              
  }

  if (digitalRead(rightButton) == HIGH)                                
  { 
    Mouse.click(MOUSE_RIGHT);   
    delay(150);                                                          
  }

}


