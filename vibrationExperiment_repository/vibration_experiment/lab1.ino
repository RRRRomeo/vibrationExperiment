//定义串口
int powerPin = 3;
int leftPin = 10;
int rightPin = 9;
//int leftButtonPin = 8;
//int rightButtonPin = 7;
//int powerLevelIndex = 0;
//int currentPowerLel = 100;

//定义试验1强度切换数组
int lab1Powerlels[3][1] = {{160}, {190}, {255}};

//定义试验2中的3组对照试验数据
//int lab2ControlledTrial[3][5] = {
//    {{{1000,200}, {0, 0}}, {{0, 0}, {1000, 200}}, {{100,200}, {0, 0}}, {{0, 0}, {100, 200}}, {{100, 255}, {100, 255}}},
//    {{{1500,200}, {0, 0}}, {{0, 0}, {1500, 200}}, {{250,200}, {0, 0}}, {{0, 0}, {250, 200}}, {{250, 255}, {250, 255}}},
//    {{{2000,200}, {0, 0}}, {{0, 0}, {2000, 200}}, {{200,200}, {0, 0}}, {{0, 0}, {200, 200}}, {{200, 255}, {200, 255}}}};

//试验1：强度对比试验
void strengthContrastTest(int motorsPin, int deraction, int powerStreghen, int buttonsPin) {
    motorButtonClick(motorsPin, deraction, powerStreghen, buttonsPin);
}

void button22Click() {
    strengthContrastTest(rightPin, 1000, lab1Powerlels[0][0], 22);
}

void button24Click() {
    strengthContrastTest(rightPin, 1000, lab1Powerlels[0][1], 24);
}

void button26Click() {
    strengthContrastTest(rightPin, 1000, lab1Powerlels[0][2], 26);
}


//void button28Click() {
//    strengthTestA();
//}

//实验2的第一组
//void strengthTestA() {
//    //左转信号 左手长震动1s
//    actionSignal(leftPin, lab2ControlledTrial[0][0][0][0], lab2ControlledTrial[0][0][0][1]);
//
//    //右转 右手长震动1s
//    actionSignal(rightPin, lab2ControlledTrial[0][1][1][0], lab2ControlledTrial[0][1][1][1]);
//
//    //直行 左手短震动100ms
//    actionSignal(leftPin, lab2ControlledTrial[0][2][0][0], lab2ControlledTrial[0][2][0][1]);
//
//    //停止 右手短震动100ms
//    actionSignal(rightPin, lab2ControlledTrial[0][3][1][0], lab2ControlledTrial[0][3][1][1]);
//
//    //紧急停止 左右高频率震动100ms
//    actionSignal(leftPin, lab2ControlledTrial[0][4][0][0], lab2ControlledTrial[0][4][0][1]);
//    actionSignal(rightPin,lab2ControlledTrial[0][4][1][0], lab2ControlledTrial[0][4][1][1]);
//}

//void actionSignal(int motorsPin, int deraction, int powerStreghen) {
//    //直行震动第一组：左手短震动
//    if (digitalRead(motorsPin) == LOW) {
//        delay(2000);
//        motorButtonClick(motorsPin, deraction, powerStreghen, 52);
//    }
//    delay(3000);
//}

//震动点击控制开关的独立事件封装
void motorButtonClick(int motorsPin, int deraction, int powerStreghen, int buttonsPin) {
    analogWrite(powerPin, powerStreghen);
    if (digitalRead(buttonsPin) == LOW) {
        delay(80);
        if (digitalRead(buttonsPin) == LOW) {
            digitalWrite(motorsPin, HIGH);
            delay(deraction);
            digitalWrite(motorsPin, LOW);
        } else {
            digitalWrite(motorsPin, LOW);
        }
    }
}

//直行信号

//设置板载输出
void setup() {
    //  pinMode(powerPin, OUTPUT);
    //  pinMode(motor1Pin, OUTPUT);
    pinMode(rightPin, OUTPUT);
    pinMode(leftPin, OUTPUT);
    pinMode(22, INPUT_PULLUP);
    pinMode(24, INPUT_PULLUP);
    pinMode(26, INPUT_PULLUP);
    //  pinMode(button2Pin, INPUT_PULLUP);
    Serial.begin(9600);
    
}


//主循环函数
void loop() {
  button22Click();
  button24Click();
  button26Click();
    
    
}


//button按钮切换事件
//void buttonChageMotor(void) {
//    //  analogWrite(powerPin, 160);
//    powerLelChange();
//    //  if (powerLevelIndex < 40) {
//    if (digitalRead(buttonPin) == LOW) {
//        //消除信号传输延迟
//        delay(80);
//        if (digitalRead(buttonPin) == LOW) {
//            digitalWrite(motor2Pin, HIGH);
//            delay(1000);
//        }
//    }
//    else {
//        digitalWrite(motor2Pin, LOW);
//    }
//    //  }
//    //  powerLevelIndex += 30;
//}


//void powerLelChange(void) {
//    if (currentPowerLel <  255) {
//        analogWrite(powerPin, currentPowerLel);
//    } else {
//        analogWrite(powerPin, 0);
//    }
//    currentPowerLel += powerLevelIndex;
//    powerLevelIndex += 30;
//}


//测试代码
//void demo1(void) {
//    digitalWrite(motor1Pin, HIGH);
//    digitalWrite(motor2Pin, HIGH);
//    delay(100);
//    digitalWrite(motor1Pin, LOW);
//    digitalWrite(motor2Pin, LOW);
//    delay(100);
//}


////button2按钮切换事件
//void button2ChageMotor(void) {
//    analogWrite(powerPin, 255);
//    //  powerLelChange();
//    //  if (powerLevelIndex < 40) {
//    if (digitalRead(button2Pin) == LOW) {
//        //消除信号传输延迟
//        delay(80);
//        if (digitalRead(button2Pin) == LOW) {
//            digitalWrite(motor2Pin, HIGH);
//            delay(1000);
//        }
//    }
//    else {
//        digitalWrite(motor2Pin, LOW);
//    }
//    //  }
//    //  powerLevelIndex += 30;
//}



//
//int demo3 (int frama) {
//    frama += 3;
//    return frama;
//}
//
//
//void demo5() {
//    int result = demo3(4);
//}
//
//
//void button30Click() {
//  strengthContrastTest(leftPin, 1500, 200, 28);
//  delay(1000);
//  strengthContrastTest(rightPin, 1500, 200, 28);
//  delay(1000);
//  strengthContrastTest(leftPin, 500, 200, 28);
//  delay(1000);
//  strengthContrastTest(rightPin, 500, 200, 28);
//  delay(1000);
//  strengthContrastTest(leftPin, 500, 255, 28);
//  strengthContrastTest(rightPin,500, 255, 28);
//}
//
//void button32Click() {
//  strengthContrastTest(leftPin, 2000, 200, 28);
//  delay(1000);
//  strengthContrastTest(rightPin, 2000, 200, 28);
//  delay(1000);
//  strengthContrastTest(leftPin, 750, 200, 28);
//  delay(1000);
//  strengthContrastTest(rightPin, 750, 200, 28);
//  delay(1000);
//  strengthContrastTest(leftPin, 750, 255, 28);
//  strengthContrastTest(rightPin,750, 255, 28);
//}
