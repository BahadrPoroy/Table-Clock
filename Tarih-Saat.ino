#include <virtuabotixRTC.h>
#include <U8glib.h>

// I/O pin and device setups

#define btSet 3
#define btOk 4
virtuabotixRTC myRTC(5, 6, 7);

int sec = 00, mnt = 00, clk = 00, dayofweek = 0, dd = 1, mm = 1, yyyy = 2025;  //Date and time variables
long int nowMillis = 0, lastMillis = 0, nowMillisAyar = 0, lastMillisAyar = 0;        //time control variables

int is_changed = 0;  //0: hours, 1: minutes, 2: dayofweek, 3: dayofmonth, 4: month, 5: year
bool setting = false;

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

//Page's settings

void setup() {
  u8g.begin();
  u8g.setFont(u8g_font_fur35n);
  Serial.begin(9600);
  if (myRTC.year == 2000) {
    myRTC.setDS1302Time(sec, mnt, clk, dayofweek, dd, mm, yyyy);  //Just set the time by running it on the first installation, then comment line and upload again
  }
  pinMode(btSet, INPUT_PULLUP);
  pinMode(btOk, INPUT_PULLUP);
  nowMillis = millis();
  while ((lastMillis - nowMillis) < 3000) {
    u8g.firstPage();
    do {
      sayfaMarka();
    } while (u8g.nextPage());
    lastMillis = millis();
  }
  pageChange();
}

void ayar() {
  setting = true;
  switch (is_changed) {
    case (0):
      u8g.firstPage();
      do {
        saatAyar();
      } while (u8g.nextPage());
      break;
    case (1):
      u8g.firstPage();
      do {
        dakikaAyar();
      } while (u8g.nextPage());
      break;
    case (2):
      u8g.firstPage();
      do {
        gunAyar();
      } while (u8g.nextPage());
      break;
    case (3):
      u8g.firstPage();
      do {
        ay_gunuAyar();
      } while (u8g.nextPage());
      break;
    case (4):
      u8g.firstPage();
      do {
        ayAyar();
      } while (u8g.nextPage());
      break;
    case (5):
      u8g.firstPage();
      do {
        yilAyar();
      } while (u8g.nextPage());
      break;
    case (6):
      is_changed = 0;
      setting = false;
      break;
  }
}

void pageChange() {
  lastMillis = millis();
  u8g.firstPage();
  do {
    sayfaTarih();
  } while (u8g.nextPage());
}
unsigned long int max = 0;
void loop() {
  myRTC.updateTime();
  nowMillis = millis();
  if ((nowMillis - lastMillis >= 59999) && !setting) {
    pageChange();
  }
  if((nowMillis - lastMillis) > max){
    max = nowMillis - lastMillis;
  }
  Serial.println(max);
  if (digitalRead(btSet) == LOW || (digitalRead(btOk) == LOW)) {
    ayar();
  }
}