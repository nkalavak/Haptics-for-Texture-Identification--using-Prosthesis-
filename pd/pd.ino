//Peak Detect and Running Average for EE 589 Project

//variables for peak detect
int delta=45; //Step size for detection, change for diff type of signals
float min_=10000; //Want to start well above 4096 to ensure min and max initial detect
float max_=-10000;
int min_ind=0; //indexing for testing only
int max_ind=0;
bool find_max=true; //checks if min or max was found
int sensorPin = A0; 
float maxtab_pos=0;
float maxtab_max=0;
float mintab_min=0;
float mintab_pos=0;
int ind=1;
int data;
int count=0;
const int num_samples=10;
int values[num_samples];//array for storing values
int Index=0; //indexing for array
int average=0;//holder for average values
int value_sum=0;//sum of value array
const int analogOutPin = 3;
int olddata=0;
int err_count;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {

  
  // put your main code here, to run repeatedly:
data=analogRead(sensorPin);
//Start Peak Detect, saves min and max values as well as their indices for testing
  if (data>max_){
      max_=data;
      max_ind=ind;
  }
if (data<min_){
      min_=data;
      min_ind=ind;
}
 if (find_max==true){ //check to see if min or max was last found
  if (data<max_-delta){
    maxtab_pos=max_ind;
    maxtab_max=max_;
    min_=data; //update min, needed to update max
    min_ind=ind;
    find_max=false;
    }
 }
    if(data>min_+delta){
      mintab_pos=min_ind;
      mintab_min=min_;
      max_=data; // update max 
      max_ind=ind;
      find_max=true;
    }

    //Running average of peak values
    value_sum=value_sum-values[Index];//shift old value out
  values[Index]=maxtab_max;
  value_sum=value_sum+values[Index];//sum values
  Index++;
  if (Index>=num_samples){
    Index=0;
    
  }

average=value_sum/num_samples;
//outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:


if (olddata==average){
  err_count++;
}
if (err_count==50){
  average=0;
  err_count=0;
}


olddata=average;
analogWrite(analogOutPin, 5*average);

  
ind++;
count++;
  Serial.print(data);
  Serial.print(',');
  Serial.print(maxtab_max);
  Serial.print(',');
  
  Serial.println(mintab_min);
 // Serial.print(',');
  //Serial.print(count);
  //Serial.print(',');
  //Serial.println(average);
delay(100);// delay for 100 for troubleshooting

}


