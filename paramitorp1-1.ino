int step_in_x[] = {5,4,3,2,1,0,-1,-2,-3,-4,-5};
  

int step_in_y[] = {5,4,3,2,1,0,-1,-2,-3,-4,-5};
void setup(){
  Serial.begin(9600);
}
void loop(){
  for(int i = 1;i<=11;i++){
  Serial.print(step_in_x[i]);
  
  Serial.println(step_in_y[i]);
}
}
