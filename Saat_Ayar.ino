int btSetState = 1, lastBtSetState = 1, btOkState = 1, lastBtOkState = 1;

void saatAyar() {
  btSetState = digitalRead(btSet);
  btOkState = digitalRead(btOk);
  myRTC.updateTime();
  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(0, 0, 128, 64);
  u8g.setPrintPos(10, 40);
  if (myRTC.hours >= 0 && myRTC.hours <= 9) {
    u8g.print("0");
  }
  u8g.print(myRTC.hours);
  u8g.print(":  ");
  if (btSetState != lastBtSetState) {
    if (btSetState == LOW) {
      myRTC.setDS1302Time(myRTC.seconds, myRTC.minutes, ((myRTC.hours + 1) % 24), myRTC.dayofweek, myRTC.dayofmonth, myRTC.month, myRTC.year);
    }
    lastBtSetState = btSetState;
    ayar();
  }

  if (btOkState != lastBtOkState) {
    if (btOkState == LOW) {
      is_changed = 1;
    }
    lastBtOkState = btOkState;
    ayar();
  }
}


void dakikaAyar() {
  btSetState = digitalRead(btSet);
  btOkState = digitalRead(btOk);
  myRTC.updateTime();
  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(0, 0, 128, 64);
  u8g.setPrintPos(10, 40);
  u8g.print("  :");
  if (myRTC.minutes >= 0 && myRTC.minutes <= 9) {
    u8g.print("0");
  }
  u8g.print(myRTC.minutes);
  if (btSetState != lastBtSetState) {
    if (digitalRead(btSet) == LOW) {
      myRTC.setDS1302Time(myRTC.seconds, ((myRTC.minutes + 1) % 60), myRTC.hours, myRTC.dayofweek, myRTC.dayofmonth, myRTC.month, myRTC.year);
    }
    lastBtSetState = btSetState;
    ayar();
  }
  if (btOkState != lastBtOkState) {
    if (btOkState == LOW) {
      is_changed = 2;
    }
    lastBtOkState = btOkState;
    ayar();
  }
}


void gunAyar() {
  btSetState = digitalRead(btSet);
  btOkState = digitalRead(btOk);
  myRTC.updateTime();
  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(0, 0, 128, 64);
  u8g.setPrintPos(10, 40);
  if (myRTC.dayofweek == 1) {
    u8g.print("Pazartesi");
  } else if (myRTC.dayofweek == 2) {
    u8g.print("Sali");
  } else if (myRTC.dayofweek == 3) {
    u8g.print("Carsamba");
  } else if (myRTC.dayofweek == 4) {
    u8g.print("Persembe");
  } else if (myRTC.dayofweek == 5) {
    u8g.print("Cuma");
  } else if (myRTC.dayofweek == 6) {
    u8g.print("Cumartesi");
  } else {
    u8g.print("Pazar");
  }
  if (btSetState != lastBtSetState) {
    if (digitalRead(btSet) == LOW) {
      myRTC.setDS1302Time(myRTC.seconds, myRTC.minutes, myRTC.hours, ((myRTC.dayofweek + 1) % 7), myRTC.dayofmonth, myRTC.month, myRTC.year);
    }
    lastBtSetState = btSetState;
    ayar();
  }
  if (btOkState != lastBtOkState) {
    if (btOkState == LOW) {
      is_changed = 3;
    }
    lastBtOkState = btOkState;
    ayar();
  }
}

void ay_gunuAyar() {
  int day;
  btSetState = digitalRead(btSet);
  btOkState = digitalRead(btOk);
  myRTC.updateTime();
  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(0, 0, 128, 64);
  u8g.setPrintPos(10, 40);
  if (myRTC.dayofmonth > 0 && myRTC.dayofmonth <= 9) {
    u8g.print("0");
  }
  u8g.print(myRTC.dayofmonth);
  u8g.print("/");

  //Month printer

  u8g.print("  /    ");
  
  if (btSetState != lastBtSetState) {
    if (digitalRead(btSet) == LOW) {
      day = (myRTC.dayofmonth + 1) % 31;
      if (day == 0) {
        day = 31;
      }
      myRTC.setDS1302Time(myRTC.seconds, myRTC.minutes, myRTC.hours, myRTC.dayofweek, day, myRTC.month, myRTC.year);
    }
    lastBtSetState = btSetState;
    ayar();
  }
  if (btOkState != lastBtOkState) {
    if (btOkState == LOW) {
      is_changed = 4;
    }
    lastBtOkState = btOkState;
    ayar();
  }
}

void ayAyar() {
  int ay;
  btSetState = digitalRead(btSet);
  btOkState = digitalRead(btOk);
  myRTC.updateTime();
  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(0, 0, 128, 64);
  u8g.setPrintPos(10, 40);
  u8g.print("  /");
  if (myRTC.month > 0 && myRTC.month <= 9) {
    u8g.print("0");
  }

  //Month printer

  u8g.print(myRTC.month);
  u8g.print("/    ");

  if (btSetState != lastBtSetState) {
    if (digitalRead(btSet) == LOW) {
      ay = (myRTC.month + 1) % 12;
      if (ay == 0) {
        ay = 12;
      }
      myRTC.setDS1302Time(myRTC.seconds, myRTC.minutes, myRTC.hours, myRTC.dayofweek, myRTC.dayofmonth, ay, myRTC.year);
    }
    lastBtSetState = btSetState;
    ayar();
  }
  if (btOkState != lastBtOkState) {
    if (btOkState == LOW) {
      is_changed = 5;
    }
    lastBtOkState = btOkState;
    ayar();
  }
}

void yilAyar() {
  btSetState = digitalRead(btSet);
  btOkState = digitalRead(btOk);
  myRTC.updateTime();
  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(0, 0, 128, 64);
  u8g.setPrintPos(10, 40);

  u8g.print("  /  /");

  //Month printer

  u8g.print(myRTC.year);

  if (btSetState != lastBtSetState) {
    if (digitalRead(btSet) == LOW) {
      myRTC.setDS1302Time(myRTC.seconds, myRTC.minutes, myRTC.hours, myRTC.dayofweek, myRTC.dayofmonth, myRTC.month, (myRTC.year + 1));
    }
    lastBtSetState = btSetState;
    ayar();
  }
  if (btOkState != lastBtOkState) {
    if (btOkState == LOW) {
      is_changed = 6;
    }
    lastBtOkState = btOkState;
    ayar();
  }
}