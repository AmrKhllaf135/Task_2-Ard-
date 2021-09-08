#define PR_1 A0
#define PR_2 A1
#define Buz 13
const int PR_Minimum=400;

bool PR1=LOW;
bool PR2=LOW;

int The_Number_Of_In_out_People=0;

void setup() {
  pinMode(Buz , OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(The_Number_Of_In_out_People == 5)
  {
     tone(Buz, 1000); 
  delay(1000);        
  noTone(Buz);     
  delay(1000);  
  }
  
  if(analogRead(PR_1)<PR_Minimum && analogRead(PR_2)>PR_Minimum && PR1==LOW && PR2==LOW)
    PR1=HIGH;
  if(analogRead(PR_1)>PR_Minimum && analogRead(PR_2)<PR_Minimum && PR1==HIGH && PR2==LOW)
   {
      while(analogRead(PR_2)<PR_Minimum )
      { } 
       The_Number_Of_In_out_People++;
       Serial.println("Room size : " + (String)The_Number_Of_In_out_People);
       PR1=LOW;
       PR2=LOW;
   }
  
  if(analogRead(PR_1)>PR_Minimum && analogRead(PR_2)<PR_Minimum && PR1==LOW && PR2==LOW)
    PR2=HIGH;

  if(analogRead(PR_1)<PR_Minimum && analogRead(PR_2)>PR_Minimum  && PR1==LOW && PR2==HIGH)
   {
      while(analogRead(PR_1)<PR_Minimum)
      { }
      The_Number_Of_In_out_People = The_Number_Of_In_out_People >0?The_Number_Of_In_out_People-1:0;
      Serial.println("Room size : " + (String)The_Number_Of_In_out_People);
      PR2=LOW;
      PR1=LOW;
   }
}
