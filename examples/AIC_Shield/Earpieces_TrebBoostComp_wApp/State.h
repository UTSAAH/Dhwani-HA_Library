
#ifndef State_h
#define State_h

// define structure for tracking state of system (for GUI)
extern "C" char* sbrk(int incr);
class State {
  public:
    //State(void) {};
    State(AudioSettings_F32 *given_settings, Print *given_serial) {
      local_audio_settings = given_settings; 
      local_serial = given_serial;
    }
    
    enum INPUTS {NO_STATE, INPUT_PCBMICS, INPUT_MICJACK_MIC, INPUT_MICJACK_LINEIN, INPUT_LINEIN_SE, INPUT_PDMMICS};
    //enum GAIN_TYPE {INPUT_GAIN_ID, OUTPUT_GAIN_ID};
    enum MIC_CONFIG_TYPE {MIC_FRONT, MIC_REAR, MIC_BOTH_INPHASE, MIC_BOTH_INVERTED, MIC_AIC0_LR, MIC_AIC1_LR, MIC_BOTHAIC_LR};
    
    int input_source = NO_STATE;
    int digital_mic_config = MIC_FRONT;
    int analog_mic_config = MIC_AIC0_LR; //what state for the mic configuration when using analog inputs

    float inputGain_dB = 0.0;
    float volKnobGain_dB = 0.0;
    bool flag_printCPUandMemory = false;
    float hp_cutoff_Hz = 1000.f;

    void printCPUandMemory(unsigned long curTime_millis = 0, unsigned long updatePeriod_millis = 0) {
       static unsigned long lastUpdate_millis = 0;
      //has enough time passed to update everything?
      if (curTime_millis < lastUpdate_millis) lastUpdate_millis = 0; //handle wrap-around of the clock
      if ((curTime_millis - lastUpdate_millis) > updatePeriod_millis) { //is it time to update the user interface?
        printCPUandMemoryMessage();
        lastUpdate_millis = curTime_millis; //we will use this value the next time around.
      }
    }
    
    int FreeRam() {
      char top; //this new variable is, in effect, the mem location of the edge of the heap
      return &top - reinterpret_cast<char*>(sbrk(0));
    }
    void printCPUandMemoryMessage(void) {
      local_serial->print("CPU Cur/Pk: ");
      local_serial->print(local_audio_settings->processorUsage(), 1);
      local_serial->print("%/");
      local_serial->print(local_audio_settings->processorUsageMax(), 1);
      local_serial->print("%, ");
      local_serial->print("MEM Cur/Pk: ");
      local_serial->print(AudioMemoryUsage_F32());
      local_serial->print("/");
      local_serial->print(AudioMemoryUsageMax_F32());
      local_serial->print(", FreeRAM(B) ");
      local_serial->print(FreeRam());
      local_serial->println();
    }

    void printGainSettings(void) {
      local_serial->print("Gains (dB): ");
      local_serial->print("In ");  local_serial->print(inputGain_dB,1);
      local_serial->print(", Out "); local_serial->print(volKnobGain_dB,1);
      local_serial->println();
    }
  private:
    Print *local_serial;
    AudioSettings_F32 *local_audio_settings;
};

#endif
