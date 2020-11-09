int powerPin = 3;
int feedbackPin = 4;
int rightPin = 9;
int leftPin = 10;

////定义试验2中的3组对照试验数据
//int lab2ControlledTrial[3][5][2][2] = {
//  {{{1000, 200}, {0, 0}}, {{0, 0}, {1000, 200}}, {{100, 200}, {0, 0}}, {{0, 0}, {100, 200}}, {{100, 255}, {100, 255}}},
//  {{{1500, 200}, {0, 0}}, {{0, 0}, {1500, 200}}, {{250, 200}, {0, 0}}, {{0, 0}, {250, 200}}, {{250, 255}, {250, 255}}},
//  {{{2000, 200}, {0, 0}}, {{0, 0}, {2000, 200}}, {{200, 200}, {0, 0}}, {{0, 0}, {200, 200}}, {{200, 255}, {200, 255}}},
//};
////定义试验1强度切换数组
//int lab1Powerlels[3][1] = {{150}, {190}, {255}};
void setup() {
    pinMode(rightPin, OUTPUT);
    pinMode(leftPin, OUTPUT);
    pinMode(feedbackPin, INPUT_PULLUP);
    pinMode(22, INPUT_PULLUP);
    pinMode(24, INPUT_PULLUP);
    pinMode(26, INPUT_PULLUP);
    
    Serial.begin(9600);
    
}

void loop() {
    //  // put your main code here, to run repeatedly:
    //  button22Click();
    //  button24Click();
    //  button26Click();
    button28Click();
    button30Click();
    button32Click();
    
}

//反馈按钮点击事件
void feedbackButtonClick(){
    //当串口打开时且电机信号进行通信时 记录第一个开始时间
    //当反馈按钮高电平的时候记录第二个时间
    //第三个数据是后者时间减去前者时间做差
    
}

//震动点击控制开关的独立事件封装
void motorButtonClick(int motorsPin, int deraction, int powerStreghen, int buttonsPin) {
    analogWrite(powerPin, powerStreghen);
    if (digitalRead(buttonsPin) == LOW) {
        delay(80);
        if (digitalRead(motorsPin) == LOW) {
            digitalWrite(motorsPin, HIGH);
            delay(deraction);
            digitalWrite(motorsPin, LOW);
        } else {
            digitalWrite(motorsPin, LOW);
        }
    }
}

//试验1：强度对比试验
void strengthContrastTest(int motorsPin, int deraction, int powerStreghen, int buttonsPin) {
    motorButtonClick(motorsPin, deraction, powerStreghen, buttonsPin);
}

//
//void button22Click() {
//  strengthContrastTest(rightPin, 1000, lab1Powerlels[0][0], 22);
//}
//
//void button24Click() {
//  strengthContrastTest(rightPin, 1000, lab1Powerlels[0][1], 24);
//}
//
//void button26Click() {
//  strengthContrastTest(rightPin, 1000, lab1Powerlels[0][2], 26);
//}

void button28Click() {
    strengthContrastTest(leftPin, 1000, 200, 22);
    delay(300);
    strengthContrastTest(leftPin, 1000, 200, 22);
    delay(300);
    strengthContrastTest(leftPin, 1000, 200, 22);
    delay(5000);
    
    strengthContrastTest(rightPin, 1000, 200, 22);
    delay(300);
    strengthContrastTest(rightPin, 1000, 200, 22);
    delay(300);
    strengthContrastTest(rightPin, 1000, 200, 22);
    delay(5000);
    
    strengthContrastTest(leftPin, 200, 200, 22);
    delay(300);
    strengthContrastTest(leftPin, 200, 200, 22);
    delay(300);
    strengthContrastTest(leftPin, 200, 200, 22);
    delay(5000);
    
    strengthContrastTest(rightPin, 200, 200, 22);
    delay(300);
    strengthContrastTest(rightPin, 200, 200, 22);
    delay(300);
    strengthContrastTest(rightPin, 200, 200, 22);
    delay(5000);
    
    
    strengthContrastTest(leftPin, 200, 255, 22), strengthContrastTest(rightPin, 200, 255, 22);
    delay(300);
    strengthContrastTest(leftPin, 200, 255, 22), strengthContrastTest(rightPin, 200, 255, 22);
    delay(300);
    strengthContrastTest(leftPin, 200, 255, 22), strengthContrastTest(rightPin, 200, 255, 22);
}


void button30Click() {
    strengthContrastTest(leftPin, 1500, 200, 24);
    delay(300);
    strengthContrastTest(leftPin, 1500, 200, 24);
    delay(300);
    strengthContrastTest(leftPin, 1500, 200, 24);
    delay(5000);
    
    strengthContrastTest(rightPin, 1500, 200, 24);
    delay(300);
    strengthContrastTest(rightPin, 1500, 200, 24);
    delay(300);
    strengthContrastTest(rightPin, 1500, 200, 24);
    delay(5000);
    
    strengthContrastTest(leftPin, 500, 200, 24);
    delay(300);
    strengthContrastTest(leftPin, 500, 200, 24);
    delay(300);
    strengthContrastTest(leftPin, 500, 200, 24);
    delay(5000);
    
    strengthContrastTest(rightPin, 500, 200, 24);
    delay(300);
    strengthContrastTest(rightPin, 500, 200, 24);
    delay(300);
    strengthContrastTest(rightPin, 500, 200, 24);
    delay(5000);
    
    
    strengthContrastTest(leftPin, 500, 255, 24), strengthContrastTest(rightPin, 500, 255, 24);
    delay(300);
    strengthContrastTest(leftPin, 500, 255, 24), strengthContrastTest(rightPin, 500, 255, 24);
    delay(300);
    strengthContrastTest(leftPin, 500, 255, 24), strengthContrastTest(rightPin, 500, 255, 24);
}

void button32Click() {
    strengthContrastTest(leftPin, 2000, 200, 26);
    delay(300);
    strengthContrastTest(leftPin, 2000, 200, 26);
    delay(300);
    strengthContrastTest(leftPin, 2000, 200, 26);
    delay(5000);
    
    strengthContrastTest(rightPin, 2000, 200, 26);
    delay(300);
    strengthContrastTest(rightPin, 2000, 200, 26);
    delay(300);
    strengthContrastTest(rightPin, 2000, 200, 26);
    delay(5000);
    
    strengthContrastTest(leftPin, 750, 200, 26);
    delay(300);
    strengthContrastTest(leftPin, 750, 200, 26);
    delay(300);
    strengthContrastTest(leftPin, 750, 200, 26);
    delay(5000);
    
    strengthContrastTest(rightPin, 750, 200, 26);
    delay(300);
    strengthContrastTest(rightPin, 750, 200, 26);
    delay(300);
    strengthContrastTest(rightPin, 750, 200, 26);
    delay(5000);
    
    
    strengthContrastTest(leftPin, 750, 255, 26), strengthContrastTest(rightPin, 750, 255, 26);
    delay(300);
    strengthContrastTest(leftPin, 750, 255, 26), strengthContrastTest(rightPin, 750, 255, 26);
    delay(300);
    strengthContrastTest(leftPin, 750, 255, 26), strengthContrastTest(rightPin, 750, 255, 26);
}
