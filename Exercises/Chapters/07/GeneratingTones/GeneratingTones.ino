const int pin = 4;
const int frequency = 500;
const int duration = 5000;

void setup() {

  # https://forum.arduino.cc/t/arduino-due-and-tone/133302/13

  Serial.begin(115200);

  pinMode(pin, OUTPUT);
  
  Serial.println("\n==== Simple Due tone example ====\n");

  beep();  delay(1000);                             // 1 beep
  beep2(); delay(1000);                             // 2
  beep3(); delay(1000);                             // 3
  beep4();          
                                  // 4
  Serial.println("done...\n");
}

void loop() {}

void beep()  {tone(50);}
void beep2() {beep(); delay(150); beep();}
void beep3() {beep(); delay(150); beep(); delay(150); beep();}
void beep4() {beep(); delay(150); beep(); delay(150); beep(); delay(150); beep();}

volatile static int32_t toggles;                    // number of ups/downs in a tone burst 

void tone(int32_t duration)
{    
                      // duration in ms
  const uint32_t rcVal = VARIANT_MCK/ 256 / frequency;  // target value for counter, before it resets (= 82 for 4kHz)
  toggles = 2 * frequency * duration / 1000;               // calculate no of waveform edges (rises/falls) for the tone burst
  setupTC(TC1,0,TC3_IRQn,frequency);                 // Start Timer/Counter 1, channel 0, interrupt, frequency
}
  
void setupTC(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t freq){
  pmc_set_writeprotect(false);                       // disable write protection of timer registers
  pmc_enable_periph_clk((uint32_t) irq);             // enable clock / interrupt 
//pmc_enable_periph_clk((uint32_t) ID_TC3);          // alternate syntax, using PMC_id instead
  TC_Configure(tc, channel,            
               TC_CMR_TCCLKS_TIMER_CLOCK4 |          // TIMER_CLOCK4: MCK/128=656,250Hz. 16 bits so 656,250/65,536=~10Hz/bit
               TC_CMR_WAVE |                         // Waveform mode
               TC_CMR_WAVSEL_UP_RC );                // Counter running up and reset when = Register C value (rcVal)
  const uint32_t rcVal = VARIANT_MCK/256/freq;       // target value for counter, before it resets
//Serial << "rcVal: " << rcVal << " toggles: " << toggles << '\n'; 
//TC_SetRA(tc, channel, rcVal/2);                    // could also use Register A for 50% duty cycle square wave
  TC_SetRC(tc, channel, rcVal);
  TC_Start(tc, channel);
  (*tc).TC_CHANNEL[channel].TC_IER =  TC_IER_CPCS;   // IER: CPCS bit enables RC compare interrupt when set 
  (*tc).TC_CHANNEL[channel].TC_IDR = ~TC_IER_CPCS;   // IDR: clear CPCS bit = don't disable RC compare interrupt
  NVIC_EnableIRQ(irq);                               // Enable TC3_IRQn in the Nested Vector Interrupt Controller)
  }

void TC3_Handler(void){                              // timer ISR  TC1 ch 0
  TC_GetStatus(TC1,0);
  if (toggles != 0){
    digitalWrite(pin,!digitalRead(pin));     // invert the pin state (i.e toggle)
    if (toggles > 0) toggles--;
    } 
  //else noTone();                                   // seems superfluous ?
  }
/*
void noTone(){
  TC_Stop(tc,channel);                               // stop timer
  digitalWrite(TONEpin,LOW);                         // no signal on pin
  }*/
