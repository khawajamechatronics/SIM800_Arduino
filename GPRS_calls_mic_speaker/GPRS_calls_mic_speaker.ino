#include <SIM800.h>

unsigned long bauds = 19200;

void setup() {
  char number[20] ="+51999999999;"; //+51<#celular> número a llamar
  Serial.begin(bauds);  
  while (!Serial) {;}
  SIM.begin(bauds);
  delay(100);

  SIM.setTimeout(3000);
  SIM.cmdBenchmark(true);
  
  SIM.test                ();
  SIM.repeatLastCmd       ();
  SIM.answerCall          ();
   SIM.ringerVolume      (100);
   SIM.loudSpeakerVol    (100);
   Serial.println(number);
  SIM.originCall          (number);
  delay(50000);
  SIM.redialLastAddr      ();
  SIM.setCmdEcho          ("1");
  delay(20000);
  SIM.endCall             ();
  SIM.getDeviceID         ();
//  SIM.setSpeakerVol      ("9");
  //SIM.setSpeakerMode     ("9");
  //SIM.toCmdMode          ();
  //SIM.toDataMode         ();
  SIM.pulseDialing        ();
  SIM.setResultMode       ("0");
  SIM.autoAnswerAfter     (GET);
  SIM.cmdlnEndChar        ();
  SIM.cmdlnFormatChar     ();
  SIM.cmdlnEditChar       ();
  SIM.blindDialPause      (GET);
  SIM.connWaitTime        (GET);
  SIM.commaWaitTime       (GET);
  SIM.carrierLostDelay    (GET);
  SIM.toneDialing         ();
  SIM.setResponseFormat   ("1");
  SIM.setCallMonitor      ("4");
  SIM.userReset           ();
  SIM.setDcdMode          ("1");
  SIM.setDtrMode          ("1");
  SIM.factoryReset        ();
  //SIM.setSlicePoint(1600);
  SIM.getActiveCfg        ();
  SIM.saveActiveCfg       ();
  SIM.getGsmSupport       ();
  SIM.getMakerID          (EXE);
  SIM.getDeviceModelID    (EXE);
  SIM.getSoftwareID       (EXE);
  SIM.getGOI              (EXE);
  SIM.getIMEI             (EXE);
  SIM.serialFraming       (GET);
  SIM.serialFlowCtrl      (GET);
  SIM.serialBauds         (GET);
  SIM.endCallOnly         ();
}

void loop() {}
