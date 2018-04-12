/* X_Car */
/* Thuật toán dò đường */
#define tocdo 200
/* Chân tín hiệu của 2 cảm biến dò đường */
#define lineLeft 19
#define lineCenter 18
#define lineRight 17

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

void setup()
{
    /* Chân cảm biến nhận tín hiệu vào */
    pinMode(lineLeft, INPUT);
    pinMode(lineCenter, INPUT);
    pinMode(lineRight, INPUT);
    
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
    int line_trai = digitalRead(lineLeft);
    int line_giua = digitalRead(lineCenter);
    int line_phai = digitalRead(lineRight);
    
    if (digitalRead(lineLeft) == 0 && digitalRead(lineCenter) == 0 && digitalRead(lineRight) == 0)
    {
        moterAll (150);
        delay (500);
        if (digitalRead(lineLeft) == 0 && digitalRead(lineCenter) == 0 && digitalRead(lineRight) == 0)
        {
            while (digitalRead(lineCenter) == 1)
            {
                moterLeft (100);
                moterRight (-100);
            }
        }
    }
    else
    {
        if ((digitalRead(lineLeft) == 1 && digitalRead(lineCenter) == 1 && digitalRead(lineRight) == 0) || (digitalRead(lineLeft) == 1 && digitalRead(lineCenter) == 1 && digitalRead(lineRight) == 1))
        {
            moterLeft (-100);
            delay (500);
            while (digitalRead(lineCenter) == 1)
            {
                moterRight (100);
            }
        }
        else
        {
            if (digitalRead(lineLeft) == 0 && digitalRead(lineCenter) == 1 && digitalRead(lineRight) == 1)
            {
                moterRight (-100);
                delay (500);
                while (digitalRead(lineCenter) == 1)
                {
                    moterLeft (100);
                }
            }
        }
        if (digitalRead(lineLeft) == 0 && digitalRead(lineCenter) == 1 && digitalRead(lineRight) == 0)
        {
            while (digitalRead(lineCenter == 0))
            {
                moterAll (100);
            }
        }
        if (digitalRead(lineLeft) == 0 && digitalRead(lineCenter) == 0 && digitalRead(lineRight) == 1)
        {
            while (digitalRead(lineCenter) == 1)
            {
                moterRight (100);
            }
        }
        if (digitalRead(lineLeft) == 1 && digitalRead(lineCenter) == 0 && digitalRead(lineRight) == 0)
        {
            while (digitalRead(lineCenter) == 1)
            {
                moterLeft (100);
            }
        }
    }
}

/* Hàm tiến thẳng
 * Tham số: giá trị PWM (0-255)
 * Trả về: Không */
void moterAll (int speed)
{
    if (speed < 0)
    {
        /* Động cơ trái quay tiến */
        digitalWrite(leftMotor1, HIGH);
        digitalWrite(leftMotor2, LOW);
        /* Xung PWM điều khiển tốc độ quay */
        analogWrite(leftPWM, -speed);
    
        /* Động cơ phải quay tiến */
        digitalWrite(rightMotor1, HIGH);
        digitalWrite(rightMotor2, LOW);
        /* Xung PWM điều khiển tốc độ quay */
        analogWrite(rightPWM, -speed);
    }
    else
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
}

  /* Hàm rẽ trái
   * Tham số: giá trị PWM của động cơ phải (0-255)
   * Trả về: Không */
void moterLeft (int speed)
{
    if (speed < 0)
    {
        /* Động cơ trái dừng */
        digitalWrite(leftMotor1, HIGH);
        digitalWrite(leftMotor2, LOW);
        analogWrite(leftPWM, 0);
    
        /* Động cơ phải quay tiến */
        digitalWrite(rightMotor1, HIGH);
        digitalWrite(rightMotor2, LOW);
        analogWrite(rightPWM, speed);
    }
    else
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
void motorRight (int speed)
{
    if (speed < 0)
    {
        /* Động cơ trái quay tiến */
        digitalWrite(leftMotor1, HIGH);
        digitalWrite(leftMotor2, LOW);
        analogWrite(leftPWM, speed);
    
        /* Động cơ phải dừng */
        digitalWrite(rightMotor1, HIGH);
        digitalWrite(rightMotor2, LOW);
        analogWrite(rightPWM, 0);
    }
    else
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
}

void stop ()
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
