/* X_Car */
/* Hàm đọc cảm biến siêu âm HC-SR04 */

/* Chân trig của HC-SR04 */
#define trigPin 12
/* Chân echo của HC-SR04 */
#define echoPin 16
 
void setup()
{
  /* Giao tiếp Serial với baudrate 9600 */
  Serial.begin(9600);

  /* chân trig sẽ phát tín hiệu */
  pinMode(trigPin, OUTPUT);
  /* chân echo sẽ nhận tín hiệu */
  pinMode(echoPin, INPUT);
}
 
void loop()
{
  /* Đọc và in kết quả ra Serial Monitor */
  Serial.print(readUltrasonicSensor(trigPin, echoPin));
  Serial.println("cm");
  delay(200);
}

/* Hàm đọc cảm biến 
 * Tham số: Chân trig và echo của cảm biến
 * Trả về: Khoảng cách đo được, đơn vị cm */
float readUltrasonicSensor(int trig, int echo)
{
  /* Biến đo thời gian */
  unsigned long duration;
  /* Biến lưu khoảng cách */
  float distance;
    
  /* Phát xung từ chân trig */
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  /* Xung có độ dài 5 microSeconds */
  delayMicroseconds(5); 
  digitalWrite(trig, LOW);
    
  /* Tính toán thời gian */
  /* Đo độ rộng xung HIGH ở chân echo */ 
  duration = pulseIn(echo, HIGH);  
  /* Tính khoảng cách đến vật */
  distance = duration/2/29.412;

  return distance;
}

