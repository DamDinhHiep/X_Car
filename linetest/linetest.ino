/* X_Car */
/* Thuật toán dò đường đơn giản */

/* Chân tín hiệu của 2 cảm biến dò đường */
#define leftLineSensor 19
#define centerLineSensor 18
#define rightLineSensor 17

/* Chân nguồn điều khiển động cơ trái */
#define leftMotor1 4
#define leftMotor2 7
/* Chân PWM điều khiển tốc độ động cư trái */
#define leftPWM 5

/* Chân nguồn điều khiển động cơ phải */
#define rightMotor1 8
#define rightMotor2 9
/* Chân PWM điều khiển tốc độ động cư phải */
#define rightPWM 6

int leftValue = 1;
int centerValue = 1;
int rightValue = 1;

int preLeftValue = 0;
int preCenterValue = 0;
int preRightValue = 0;

void setup()
{
  /* Chân cảm biến nhận tín hiệu vào */
  pinMode(leftLineSensor, INPUT);
  pinMode(centerLineSensor, INPUT);
  pinMode(rightLineSensor, INPUT);

  /* Các chân điều khiển động cơ phát tín hiệu */
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftPWM, OUTPUT);

  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightPWM, OUTPUT);
}

void loop()
{
  /* Đọc giá trị từ cảm biến dò đường */
  int leftValue = !digitalRead(leftLineSensor);
  int centerValue = !digitalRead(centerLineSensor);
  int rightValue = !digitalRead(rightLineSensor);



  /* Trường hợp cả 2 cảm biến ở vùng trắng 
   -> robot nằm đúng theo vạch */
  if (leftValue == 1 && centerValue == 0 && rightValue == 1)
  {
    /* Đi thẳng */
    forward(145.5);
  }
  /* Trường hợp cảm biến trái ở vùng đen, cảm biến phải ở vùng trắng 
   -> robot lệch trái */
  else if (leftValue == 0 && centerValue == 1 && rightValue == 1 || leftValue == 0 && centerValue == 0 && rightValue == 1)
  {
    /* Rẽ trái */
    turnLeft(100);
  }
  /* Trường hợp cảm biến trái ở vùng trắng, cảm biến phải ở vùng đen 
   -> robot lệch phải */
  else if (leftValue == 1 && centerValue == 1 && rightValue == 0 || leftValue == 1 && centerValue == 0 && rightValue == 0)
  {
    /* Rẽ phải */
    turnRight(100);
  }
  /* Trường hợp cả 2 cảm biến ở vùng đen 
   -> robot dừng lại */
  else if (leftValue ==  0 && centerValue == 0 && rightValue == 0)
  {
    stop();
  }
}

/* Hàm tiến thẳng
 * Tham số: giá trị PWM (0-255)
 * Trả về: Không */
void forward(int speed)
{
  /* Động cơ trái quay tiến */
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  /* Xung PWM điều khiển tốc độ quay */
  analogWrite(leftPWM, speed);

  /* Động cơ phải quay tiến */
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  /* Xung PWM điều khiển tốc độ quay */
  analogWrite(rightPWM, speed);
}

/* Hàm rẽ trái
 * Tham số: giá trị PWM của động cơ phải (0-255)
 * Trả về: Không */
void turnLeft(int speed)
{
  /* Động cơ trái dừng */
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);

  /* Động cơ phải quay tiến */
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(rightPWM, speed);
}

/* Hàm rẽ phải
 * Tham số: giá trị PWM của động cơ trái (0-255)
 * Trả về: Không */
void turnRight(int speed)
{
  /* Động cơ trái quay tiến */
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(leftPWM, speed);

  /* Động cơ phải dừng */
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}

void stop()
{
  /* Động cơ trái dừng */
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftPWM, 0);
  /* Động cơ phải dừng */
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightPWM, 0);
}

